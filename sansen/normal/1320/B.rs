//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
        k: usize,
        p: [usize1; k],
    }
    let mut g = vec![vec![]; n];
    let mut ig = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        ig[b].push(a);
    }
    let mut dp = vec![n; n];
    let dst = p[k - 1];
    dp[dst] = 0;
    let mut q = std::collections::VecDeque::new();
    q.push_back(dst);
    while let Some(v) = q.pop_front() {
        for &u in ig[v].iter() {
            if dp[u] > dp[v] + 1 {
                dp[u] = dp[v] + 1;
                q.push_back(u);
            }
        }
    }
    let mut min = 0;
    let mut max = 0;
    for p in p.windows(2) {
        let f = p[0];
        let t = p[1];
        if dp[f] <= dp[t] {
            min += 1;
            max += 1;
            continue;
        }
        let mut cnt = 0;
        for &u in g[f].iter() {
            if dp[u] == dp[f] - 1 {
                cnt += 1;
            }
        }
        if cnt > 1 {
            max += 1;
        }
    }
    println!("{} {}", min, max);
}

fn main() {
    run();
}
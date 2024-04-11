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
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
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
        k: usize,
        s: usize,
        a: [usize1; n],
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut ans = vec![];
    for k in 0..k {
        let mut q = std::collections::VecDeque::new();
        let mut dp = vec![n; n];
        for (i, a) in a.iter().enumerate() {
            if *a == k {
                dp[i] = 0;
                q.push_back(i);
            }
        }
        while let Some(v) = q.pop_front() {
            let d = dp[v] + 1;
            for &u in g[v].iter() {
                if d < dp[u] {
                    dp[u] = d;
                    q.push_back(u);
                }
            }
        }
        ans.push(dp);
    }
    let mut out = String::new();
    for i in 0..n {
        let mut a = vec![];
        for ans in ans.iter() {
            a.push(ans[i]);
        }
        a.sort();
        a.truncate(s);
        let sum = a.into_iter().sum::<usize>();
        out.push_str(&format!("{} ", sum));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
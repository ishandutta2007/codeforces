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
        d: [usize; m],
        g: usize,
        r: usize,
    }
    let mut d = d;
    d.sort();
    d.dedup();
    let mut dp = vec![vec![None; g]; d.len()];
    dp[0][0] = Some(0);
    let mut q = std::collections::VecDeque::new();
    q.push_back((0, 0));
    while let Some((v, p)) = q.pop_front() {
        let t = dp[v][p].unwrap();
        if v + 1 < d.len() {
            let w = d[v + 1] - d[v];
            if p + w == g && dp[v + 1][0].is_none() {
                dp[v + 1][0] = Some(t + 1);
                q.push_back((v + 1, 0));
            } else if p + w < g && dp[v + 1][p + w].is_none() {
                dp[v + 1][p + w] = Some(t);
                q.push_front((v + 1, p + w));
            }
        }
        if v > 0 {
            let w = d[v] - d[v - 1];
            if p + w == g && dp[v - 1][0].is_none() {
                dp[v - 1][0] = Some(t + 1);
                q.push_back((v - 1, 0));
            } else if p + w < g && dp[v - 1][p + w].is_none() {
                dp[v - 1][p + w] = Some(t);
                q.push_front((v - 1, p + w));
            }
        }
    }
    let mut ans = std::usize::MAX;
    for v in 0..d.len() {
        if let Some(t) = dp[v][0] {
            if n - d[v] <= g {
                ans = std::cmp::min(t * (g + r) + n - d[v], ans);
            }
        }
    }
    if ans == std::usize::MAX {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    run();
}
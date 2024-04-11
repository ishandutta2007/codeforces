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
        k: usize,
        p: [(usize1, usize, usize, u64); k],
    }
    let mut g = vec![vec![]; n];
    for (s, t, d, w) in p {
        g[s].push((t, d, w));
    }
    let mut h = std::collections::BinaryHeap::new();
    let mut trans = vec![];
    for (i, g) in g.into_iter().enumerate() {
        for (t, d, w) in g {
            h.push((w, d, t));
        }
        while let Some((w, d, t)) = h.pop() {
            if i < t {
                trans.push((d, w));
                h.push((w, d, t));
                break;
            }
        }
        if trans.len() == i {
            trans.push((i + 1, 0));
        }
    }
    let inf = 1_000_000_000u64 * 100_000 + 1;
    let mut dp = vec![inf; n + 1];
    dp[0] = 0;
    for (i, &(d, w)) in trans.iter().enumerate() {
        dp[d] = std::cmp::min(dp[d], dp[i] + w);
    }
    let mut ans = dp[n];
    for _ in 0..m {
        let mut next = vec![inf; n + 1];
        for i in 0..n {
            next[i + 1] = std::cmp::min(next[i + 1], dp[i]);
        }
        dp = next;
        for (i, &(d, w)) in trans.iter().enumerate() {
            dp[d] = std::cmp::min(dp[d], dp[i] + w);
        }
        ans = std::cmp::min(ans, dp[n]);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
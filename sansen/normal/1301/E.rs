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

use std::cmp::*;
use std::io::Write;

fn calc(sum: &Vec<Vec<usize>>, u: usize, d: usize, l: usize, r: usize) -> usize {
    assert!(u < d && l < r);
    sum[u][l] + sum[d][r] - sum[d][l] - sum[u][r]
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        h: usize,
        w: usize,
        q: usize,
        s: [chars; h],
        ask: [(usize1, usize1, usize, usize); q],
    }
    let mut sum = vec![vec![vec![0; w + 1]; h + 1]; 4];
    for (c, sum) in "RGBY".chars().zip(sum.iter_mut()) {
        for (i, s) in s.iter().enumerate().rev() {
            for (j, s) in s.iter().enumerate().rev() {
                sum[i][j] = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
                if *s == c {
                    sum[i][j] += 1;
                }
            }
        }
    }
    let ask: Vec<_> = ask
        .into_iter()
        .enumerate()
        .map(|(k, p)| (p.0, p.1, p.2, p.3, k))
        .collect();
    let mut ans = vec![0; q];
    let mut dfs = vec![(0, min(h, w) / 2 + 1, ask)];
    while let Some((ok, ng, ask)) = dfs.pop() {
        if ok + 1 == ng {
            for a in ask {
                ans[a.4] = 4 * ok * ok;
            }
            continue;
        }
        let m = (ok + ng) / 2;
        let mut dp = vec![vec![0; w + 1]; h + 1];
        for i in (0..h).rev() {
            for j in (0..w).rev() {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
                if i + 2 * m <= h
                    && j + 2 * m <= w
                    && calc(&sum[0], i, i + m, j, j + m) == m * m
                    && calc(&sum[1], i, i + m, j + m, j + 2 * m) == m * m
                    && calc(&sum[3], i + m, i + 2 * m, j, j + m) == m * m
                    && calc(&sum[2], i + m, i + 2 * m, j + m, j + 2 * m) == m * m
                {
                    dp[i][j] += 1;
                }
            }
        }
        let mut left = vec![];
        let mut right = vec![];
        for ask in ask {
            let (u, l, d, r, _) = ask;
            if d - u < 2 * m || r - l < 2 * m {
                left.push(ask);
            } else if calc(&dp, u, d - 2 * m + 1, l, r - 2 * m + 1) == 0 {
                left.push(ask);
            } else {
                right.push(ask);
            }
        }
        dfs.push((ok, m, left));
        dfs.push((m, ng, right));
    }
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
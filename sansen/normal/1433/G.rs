// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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
// ---------- end input macro ----------

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        e: [(usize1, usize1, u64); m],
        ask: [(usize1, usize1); k],
    }
    let mut g = vec![vec![]; n];
    for &(a, b, w) in e.iter() {
        g[a].push((b, w));
        g[b].push((a, w));
    }
    let dijkstra = |r: usize| -> Vec<u64> {
        let mut dp = vec![std::u64::MAX / 10; n];
        dp[r] = 0;
        let mut h = std::collections::BinaryHeap::new();
        h.push(Reverse((0, r)));
        while let Some(Reverse((d, v))) = h.pop() {
            if d > dp[v] {
                continue;
            }
            for &(u, w) in g[v].iter() {
                let d = d + w;
                if d < dp[u] {
                    dp[u] = d;
                    h.push(Reverse((d, u)));
                }
            }
        }
        dp
    };
    let mut dp = vec![];
    for i in 0..n {
        dp.push(dijkstra(i));
    }
    let mut ans = std::u64::MAX;
    for &(a, b, _) in e.iter() {
        let mut sum = 0;
        for &(x, y) in ask.iter() {
            sum += min(dp[x][y], min(dp[a][x] + dp[y][b], dp[a][y] + dp[x][b]));
        }
        ans = min(ans, sum);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
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

use std::io::Write;

fn root(parent: &[usize], mut x: usize) -> usize {
    while parent[x] != x {
        x = parent[x];
    }
    x
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        k: usize,
        q: usize,
        e: [(usize1, usize1, i64); m],
        p: [(usize1, usize1); q],
    }
    let mut g = vec![vec![]; n];
    for (a, b, c) in e {
        g[a].push((b, c));
        g[b].push((a, c));
    }
    let mut dp = vec![(std::i64::MAX, 0); n];
    let mut h = std::collections::BinaryHeap::new();
    for i in 0..k {
        dp[i].0 = 0;
        dp[i].1 = i;
        h.push((0, i));
    }
    while let Some((d, v)) = h.pop() {
        let d = -d;
        if d > dp[v].0 {
            continue;
        }
        for &(u, c) in &g[v] {
            let d = d + c;
            if dp[u].0 > d {
                dp[u] = (d, dp[v].1);
                h.push((-d, u));
            }
        }
    }
    let mut e = vec![];
    for v in 0..n {
        for &(u, c) in &g[v] {
            if dp[v].1 != dp[u].1 {
                e.push((dp[v].1, dp[u].1, c + dp[v].0 + dp[u].0));
            }
        }
    }
    e.sort_by_key(|e| e.2);
    let mut parent: Vec<usize> = (0..k).collect();
    let mut size = vec![1; k];
    let mut cost = vec![std::i64::MAX; k];
    for (a, b, c) in e {
        let mut a = root(&parent, a);
        let mut b = root(&parent, b);
        if a == b {
            continue;
        }
        if size[a] < size[b] {
            std::mem::swap(&mut a, &mut b);
        }
        size[a] += size[b];
        parent[b] = a;
        cost[b] = c;
    }
    for (mut x, mut y) in p {
        let mut ans = 0;
        while x != y {
            if cost[x] < cost[y] {
                ans = cost[x];
                x = parent[x];
            } else {
                ans = cost[y];
                y = parent[y];
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
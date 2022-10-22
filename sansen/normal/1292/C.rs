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

fn dfs(v: usize, p: usize, size: &mut [u16], parent: &mut [u16], g: &[Vec<usize>]) -> u16 {
    parent[v] = p as u16;
    for &u in g[v].iter() {
        if u != p {
            size[v] += dfs(u, v, size, parent, g);
        }
    }
    size[v]
}

fn calc(a: usize, b: usize, size: &[Vec<u16>], parent: &[Vec<u16>], dp: &mut [Vec<u32>]) -> u32 {
    if dp[a][b] != std::u32::MAX {
        return dp[a][b];
    }
    let mut val = max(calc(parent[b][a] as usize, b, size, parent, dp), calc(a, parent[a][b] as usize, size, parent, dp));
    val += size[a][b] as u32 * size[b][a] as u32;
    dp[a][b] = val;
    val
}

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for &(a, b) in e.iter() {
        g[a].push(b);
        g[b].push(a);
    }
    let mut size = vec![vec![1; n]; n];
    let mut parent = vec![vec![0; n]; n];
    for (v, (size, parent)) in size.iter_mut().zip(parent.iter_mut()).enumerate() {
        dfs(v, v, size, parent, &g);
    }
    let mut dp = vec![vec![std::u32::MAX; n]; n];
    for &(a, b) in e.iter() {
        let val = size[a][b] as u32 * size[b][a] as u32;
        dp[a][b] = val;
        dp[b][a] = val;
    }
    let mut ans = 0;
    for i in 0..n {
        for j in 0..i {
            ans = max(ans, calc(i, j, &size, &parent, &mut dp));
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
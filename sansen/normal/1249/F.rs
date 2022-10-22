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

use std::cmp::max;

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [u32; n],
        e: [(usize1, usize1); n - 1],
    }
    let mut d = vec![vec![200; n]; n];
    for i in 0..n {
        d[i][i] = 0;
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        d[a][b] = 1;
        d[b][a] = 1;
        g[a].push(b);
        g[b].push(a);
    }
    for k in 0..n {
        for i in 0..n {
            for j in 0..n {
                d[i][j] = std::cmp::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    let mut q = vec![];
    let mut stack = vec![(0, 0)];
    while let Some((v, p)) = stack.pop() {
        q.push(v);
        for &u in &g[v] {
            if u == p {
                continue;
            }
            stack.push((u, v));
        }
        for i in 0..g[v].len() {
            if g[v][i] == p {
                g[v].swap_remove(i);
                break;
            }
        }
    }
    let mut dp = vec![vec![0; k + 2]; n];
    for &v in q.iter().rev() {
        dp[v][0] = a[v];
        for &u in &g[v] {
            dp[v][0] += dp[u][k];
        }
        for i in (1..=k).rev() {
            dp[v][i] = dp[v][i + 1];
            let mut sum = 0;
            for &u in &g[v] {
                sum += dp[u][max(i - 1, k - i)];
            }
            for &u in &g[v] {
                dp[v][i] = max(dp[v][i], dp[u][i - 1] + sum - dp[u][max(i - 1, k - i)]);
            }
        }
        dp[v][0] = max(dp[v][0], dp[v][1]);
    }
    let ans = dp.iter().map(|dp| dp.iter().max().unwrap()).max().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
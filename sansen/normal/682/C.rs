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

fn run() {
    input! {
        n: usize,
        a: [i64; n],
        e: [(usize1, i64); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (i, &(p, c)) in e.iter().enumerate() {
        g[p].push((i + 1, c));
        g[i + 1].push((p, c));
    }
    let mut topo = vec![0];
    let mut dp = vec![(0i64, 0i64); n];
    for i in 0..n {
        let v = topo[i];
        let (d, min) = dp[v];
        for (u, c) in g[v].clone() {
            let x = g[u].iter().position(|p| p.0 == v).unwrap();
            g[u].remove(x);
            dp[u] = (d + c, min.min(d + c));
            topo.push(u);
        }
    }
    let mut ok = vec![true; n];
    let mut dfs = vec![];
    for (i, (&a, &(d, min))) in a.iter().zip(dp.iter()).enumerate() {
        if d - min > a {
            ok[i] = false;
            dfs.push(i);
        }
    }
    while let Some(v) = dfs.pop() {
        for &(u, _) in g[v].iter() {
            if ok[u] {
                ok[u] = false;
                dfs.push(u);
            }
        }
    }
    let ans = ok.iter().filter(|p| !**p).count();
    println!("{}", ans);
}

fn main() {
    run();
}
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
        e: [(usize1, usize1, bytes); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b, c) in e {
        let c = (c[0] - b'a') as usize;
        g[a].push((b, c));
        g[b].push((a, c));
    }
    let mut topo = vec![0];
    let mut depth = vec![0; n];
    for i in 0..n {
        let v = topo[i];
        for (u, _) in g[v].clone() {
            let x = g[u].iter().position(|p| p.0 == v).unwrap();
            g[u].remove(x);
            topo.push(u);
            depth[u] = depth[v] + 1;
        }
    }
    let g = g.into_iter().map(|g| {
        let mut child = [n; 26];
        for &(u, c) in g.iter() {
            child[c] = u;
        }
        child
    }).collect::<Vec<_>>();
    let mut dp = vec![0; n];
    for &v in topo.iter().rev() {
        let mut ini = vec![];
        for &u in g[v].iter() {
            if u != n {
                ini.push(u);
            }
        }
        let mut val = ini.len();
        let mut dfs = vec![ini];
        while let Some(p) = dfs.pop() {
            if p.len() <= 1 {
                continue;
            }
            for i in 0..26 {
                let mut a = vec![];
                for &p in p.iter() {
                    if g[p][i] != n {
                        a.push(g[p][i]);
                    }
                }
                if a.len() > 0 {
                    val += a.len() - 1;
                    dfs.push(a);
                }
            }
        }
        dp[depth[v]] += val;
    }
    let mut ans = (0, 0);
    for (i, dp) in dp.iter().enumerate() {
        if *dp > ans.0 {
            ans = (*dp, i + 1);
        }
    }
    println!("{}\n{}", n - ans.0, ans.1);
}

fn main() {
    run();
}
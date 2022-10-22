// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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
        h: [u64; n],
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for &(a, b) in e.iter() {
        g[a].push(b);
        g[b].push(a);
    }
    let topo = |root: usize| -> (Vec<usize>, Vec<Vec<usize>>) {
        let mut g = g.clone();
        let mut ord = vec![root];
        for i in 0..n {
            let v = ord[i];
            for u in g[v].clone() {
                g[u].retain(|p| *p != v);
                ord.push(u);
            }
        }
        (ord, g)
    };
    let mut root = (0..n).max_by_key(|v| h[*v]).unwrap();
    let mut ans = 0;
    for _ in 0..2 {
        let (ord, mut g) = topo(root);
        let mut dp = h.clone();
        for &v in ord.iter().rev() {
            if !g[v].is_empty() {
                g[v].sort_by_key(|u| !dp[*u]);
                dp[v] = dp[v].max(dp[g[v][0]]);
            }
        }
        let v = dp[root];
        let mut dp = h.clone();
        dp[root] = v;
        for &v in ord.iter() {
            if !g[v].is_empty() {
                let u = g[v][0];
                dp[u] = dp[u].max(dp[v]);
            }
        }
        ans = (0..n).filter(|v| *v == root || g[*v].is_empty()).map(|v| dp[v]).sum::<u64>();
        while g[root].len() > 0 {
            root = g[root][0];
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
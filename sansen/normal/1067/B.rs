// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
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
        k: usize,
        e: [(usize1, usize1); n - 1],
    }
    let cond = |b: bool| {
        if !b {
            println!("No");
            std::process::exit(0);
        }
    };
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let dfs = |v: usize| -> Vec<usize> {
        let mut s = vec![];
        s.push(v);
        let mut dp = vec![n; n];
        dp[v] = 0;
        while let Some(v) = s.pop() {
            let d = dp[v] + 1;
            for &u in g[v].iter() {
                if dp[u] > d {
                    dp[u] = d;
                    s.push(u);
                }
            }
        }
        dp
    };
    let mut dp = vec![0; n];
    let mut root = 0;
    for _ in 0..3 {
        let d = dfs(root);
        let mut next = (0, 0);
        for (i, (dp, d)) in dp.iter_mut().zip(d.iter()).enumerate() {
            dp.chmax(*d);
            next.chmax((*d, i));
        }
        root = next.1;
    }
    let (v, &d) = dp.iter().enumerate().min_by_key(|p| p.1).unwrap();
    cond(d == k);
    cond(g[v].len() >= 3);
    let mut s = vec![v];
    let mut depth = vec![n; n];
    depth[v] = 0;
    while let Some(v) = s.pop() {
        if depth[v] == k {
            cond(g[v].len() == 1);
        } else if depth[v] > 0 {
            cond(g[v].len() >= 3 + 1);
        }
        let d = depth[v] + 1;
        for &u in g[v].iter() {
            if depth[u].chmin(d) {
                s.push(u);
            }
        }
    }
    println!("Yes");
}

fn main() {
    run();
}
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
        edge: usize,
        e: [(usize1, usize1, i64); edge],
        query: usize,
        ask: [(usize1, usize1, i64); query],
    }
    let inf = 10i64.pow(15) + 1;
    let mut dp = vec![vec![inf; n]; n];
    for (i, dp) in dp.iter_mut().enumerate() {
        dp[i] = 0;
    }
    let mut g = vec![vec![]; n];
    for (i, &(a, b, c)) in e.iter().enumerate() {
        g[a].push((b, c, i));
        g[b].push((a, c, i));
        dp[a][b] = c;
        dp[b][a] = c;
    }
    for k in 0..n {
        for i in 0..n {
            for j in 0..n {
                let v = dp[i][k] + dp[k][j];
                dp[i][j].chmin(v);
            }
        }
    }
    let mut cond = vec![vec![]; n];
    for &(u, v, l) in ask.iter() {
        cond[u].push((v, l));
    }
    let mut ok = vec![false; edge];
    for (_, (cond, x)) in cond.iter().zip(dp.iter()).enumerate() {
        for (_, (g, y)) in g.iter().zip(dp.iter()).enumerate() {
            let rhs = cond.iter().map(|&(v, l)| l - y[v]).max().unwrap_or(-inf);
            for &(a, c, k) in g.iter() {
                ok[k] |= x[a] + c <= rhs;
            }
        }
    }
    let ans = ok.into_iter().filter(|p| *p).count();
    println!("{}", ans);
}

fn main() {
    run();
}
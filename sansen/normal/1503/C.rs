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
        p: [(i64, i64); n],
    }
    let mut p = p;
    p.sort_by_key(|p| (p.0, p.1));
    let inf = std::i64::MAX / 10;
    let mut dp = vec![inf; n];
    dp[0] = 0;
    let mut h = std::collections::BinaryHeap::new();
    h.push((0, 0));
    while let Some((d, v)) = h.pop() {
        let d = -d;
        if d > dp[v] {
            continue;
        }
        if v > 0 && dp[v - 1].chmin(d) {
            h.push((-d, v - 1));
        }
        let (a, b) = p[v];
        let x = p.binary_search_by_key(&(a + b, 1), |p| (p.0, 0)).unwrap_err();
        if x > 0 && dp[x - 1].chmin(d) {
            h.push((-d, x - 1));
        }
        if x < n && dp[x].chmin(p[x].0 - a - b + d) {
            h.push((-dp[x], x));
        }
    }
    let ans = dp[n - 1] + p.iter().fold(0, |s, a| s + a.1);
    println!("{}", ans);
}

fn main() {
    run();
}
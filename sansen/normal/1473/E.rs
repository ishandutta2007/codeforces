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

use std::io::Write;

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1, i64); m],
    }
    let mut g = vec![vec![]; n];
    for (a, b, c) in e {
        g[a].push((b, c));
        g[b].push((a, c));
    }
    let inf = std::i64::MAX;
    let mut dp = vec![vec![inf; n]; 4];
    dp[0][0] = 0;
    let mut h = std::collections::BinaryHeap::new();
    h.push((0, 0, 0));
    while let Some((d, x, v)) = h.pop() {
        let d = -d;
        if d > dp[x][v] {
            continue;
        }
        for &(u, w) in g[v].iter() {
            let c = d + w;
            if dp[x][u].chmin(c) {
                h.push((-c, x, u));
            }
            let c = d;
            if x & 1 == 0 && dp[x | 1][u].chmin(c) {
                h.push((-c, x | 1, u));
            }
            let c = d + 2 * w;
            if x & 2 == 0 && dp[x | 2][u].chmin(c) {
                h.push((-c, x | 2, u));
            }
            let c = d + w;
            if x == 0 && dp[3][u].chmin(c) {
                h.push((-c, 3, u));
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (i, d) in dp[3][1..].iter().enumerate() {
        if i > 0 {
            write!(out, " ").ok();
        }
        write!(out, "{}", *d).ok();
    }
    writeln!(out).ok();
}

fn main() {
    run();
}
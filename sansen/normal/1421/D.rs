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

use std::cmp::*;
use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(i64, i64, [i64; 6]); t],
    }
    let d: [(i64, i64); 6] = [(1, 1), (0, 1), (-1, 0), (-1, -1), (0, -1), (1, 0)];
    for (x, y, c) in ask {
        let mut ans = std::i64::MAX;
        for (i, (&da, &ca)) in d.iter().zip(c.iter()).enumerate() {
            if da.0.signum() == x.signum() && da.1.signum() == y.signum() {
                let a = if da.0 == 0 { -1 } else { x / da.0 };
                let b = if da.1 == 0 { -1 } else { y / da.1 };
                if a == -1 || b == -1 || a == b {
                    let q = max(a, b);
                    ans.chmin(q * ca);
                }
            }
            for (&db, &cb) in d.iter().zip(c.iter()).take(i) {
                if da.0 + db.0 == 0 && da.1 + db.1 == 0 {
                    continue;
                }
                let det = da.0 * db.1 - db.0 * da.1;
                let a = (db.1 * x - db.0 * y) / det;
                let b = (-da.1 * x + da.0 * y) / det;
                let cost = if a >= 0 && b >= 0 {
                    a * ca + b * cb
                } else {
                    std::i64::MAX
                };
                ans.chmin(cost);
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
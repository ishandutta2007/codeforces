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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        p: [(u64, u64); n],
    }
    for (l, r) in p {
        // popcnt, min_val
        // [l < v][v < r]
        type Map = std::collections::BTreeMap<(bool, bool), (u64, u64)>;
        let mut dp = Map::new();
        dp.insert((false, false),(0, 0));
        for k in (0..60).rev() {
            let mut next = Map::new();
            let l = (l >> k) & 1;
            let r = (r >> k) & 1;
            for ((x, y), (cnt, val)) in dp {
                for b in 0..2 {
                    if !x && b < l {
                        continue;
                    }
                    if !y && r < b {
                        continue;
                    }
                    let po = next.entry((x || l < b, y || b < r)).or_insert((0, std::u64::MAX));
                    if po.0 < cnt + b {
                        *po = (cnt + b, 2 * val + b);
                    } else if po.0 == cnt + b {
                        po.1.chmin(2 * val + b);
                    }
                }
            }
            dp = next;
        }
        let mut ans = (0, std::u64::MAX);
        for ((_, _), (cnt, val)) in dp {
            if ans.0 < cnt {
                ans = (cnt, val);
            } else if ans.0 == cnt {
                ans.1.chmin(val);
            }
        }
        writeln!(out, "{}", ans.1).ok();
    }
}

fn main() {
    run();
}
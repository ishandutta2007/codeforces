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
        op: [(u8, u64, usize); n],
    }
    let mut dp = vec![(n + 1, 1000000); m + 1];
    let div = 100000;
    dp[0] = (1, 0);
    for i in 0..m {
        if dp[i].0 == n + 1 {
            continue;
        }
        let (t, c) = dp[i];
        for (k, &(op, x, y)) in op[(t - 1)..].iter().enumerate() {
            let t = t + k;
            if k == 0 {
                if c < y {
                    if op == 1 {
                        let x = ((x + div - 1) / div) as usize;
                        dp.get_mut(i + x).map(|p| p.chmin((t, c + 1)));
                    } else {
                        let po = (i as u64 * x + div - 1) / div;
                        if po <= m as u64 {
                            dp[po as usize].chmin((t, c + 1));
                        }
                    }
                }
            } else {
                let c = 0;
                if op == 1 {
                    let x = ((x + div - 1) / div) as usize;
                    dp.get_mut(i + x).map(|p| p.chmin((t, c + 1)));
                } else {
                    let po = (i as u64 * x + div - 1) / div;
                    if po <= m as u64 {
                        dp[po as usize].chmin((t, c + 1));
                    }
                }
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for i in 1..=m {
        if i > 1 {
            write!(out, " ").ok();
        }
        let v = dp[i].0;
        if v == n + 1 {
            write!(out, "-1").ok();
        } else {
            write!(out, "{}", v).ok();
        }
    }
    writeln!(out).ok();
}

fn main() {
    run();
}
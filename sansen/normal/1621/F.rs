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
// ---------- begin Run Length Encoding ----------
fn run_length_encoding<T: Eq>(a: Vec<T>) -> Vec<(T, usize)> {
    let mut a = a.into_iter().map(|a| (a, 1)).collect::<Vec<_>>();
    a.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 += a.1;
            true
        }
    });
    a
}
// ---------- end Run Length Encoding ----------
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
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 1. 00 -> 0, +a
// 2. 11 -> 1, +b
// 3. 0 -> phi, -c
// parity
//  (13)2(13)2 or 2(13)2(13)... 
// 
//
// 

fn run() {
    input! {
        t: usize,
        ask: [(usize, i64, i64, i64, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, a, b, c, s) in ask {
        let z = run_length_encoding(s);
        let mut add = vec![];
        for z in z.windows(3) {
            if z[1].0 == b'0' {
                let need = z[1].1 - 1;
                add.push(need);
            }
        }
        let mut geta = 0;
        if z[0].0 == b'0' {
            geta += 1;
        }
        if z.len() > 1 && z.last().unwrap().0 == b'0' {
            geta += 1;
        }
        let mut zero = 0;
        let mut one = 0;
        for z in z.iter() {
            if z.0 == b'0' {
                zero += z.1 - 1;
            } else {
                one += z.1 - 1;
            }
        }
        add.sort();
        add.insert(0, 0);
        for i in 1..add.len() {
            add[i] += add[i - 1];
        }
        let (zero, one, add, geta) = (zero as i64, one as i64, add, geta);
        let mut ans = 0;
        if zero >= one {
            ans.chmax(a * zero.min(one + 1) + b * one);
        } else {
            for i in 0..=geta {
                ans.chmax(a * zero + b * one.min(zero + 1 + i) - i * c);
            }
        }
        for i in 1..add.len() {
            let need = add[i] as i64;
            let sub = i as i64;
            if need <= one {
                let one = one + sub;
                if zero + sub >= one {
                    ans.chmax(a * zero.min(one - sub + 1) + b * one - c * sub);
                } else {
                    ans.chmax(a * zero + b * one.min(zero + sub) - c * sub);
                }
            }
            if need + 1 <= one {
                let one = one + sub;
                for i in 0..=geta {
                    let sub = i + sub;
                    if one <= zero + sub {
                        ans.chmax(a * zero.min(one - sub) + b * one - c * sub);
                    } else {
                        ans.chmax(a * zero + b * one.min(zero + sub + 1) - c * sub);
                    }
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
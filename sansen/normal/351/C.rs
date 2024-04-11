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

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        m: usize,
        a: [i64; n],
        b: [i64; n],
    }
    let inf = std::i64::MAX / 10;
    let mut dp = Map::new();
    dp.insert((0i32, 0i32), 0);
    for (a, b) in a.iter().zip(b.iter()) {
        let mut next = Map::new();
        for ((d, p), w) in dp {
            next.entry((d, p + 1)).or_insert(inf).chmin(w + a);
            next.entry((d.min(p - 1), p - 1)).or_insert(inf).chmin(w + b);
        }
        dp = next;
    }
    let size = 2 * n;
    let mut mat = vec![vec![inf; size]; size];
    for i in 0..size {
        for (&(d, p), &w) in dp.iter() {
            if i as i32 + d >= 0 && i as i32 + p < size as i32 {
                mat[i][i + p as usize].chmin(w);
            }
        }
    }
    let mul = |a: &[Vec<i64>], b: &[Vec<i64>]| -> Vec<Vec<i64>> {
        let mut c = vec![vec![inf; size]; size];
        for (c, a) in c.iter_mut().zip(a) {
            for (a, b) in a.iter().zip(b) {
                for (c, b) in c.iter_mut().zip(b) {
                    c.chmin(*a + *b);
                }
            }
        }
        c
    };
    let mut t = vec![vec![inf; size]; size];
    for i in 0..size {
        t[i][i] = 0;
    }
    let mut m = m;
    while m > 0 {
        if m & 1 == 1 {
            t = mul(&t, &mat);
        }
        mat = mul(&mat, &mat);
        m >>= 1;
    }
    println!("{}", t[0][0]);
}

fn main() {
    run();
}
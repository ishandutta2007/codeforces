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
    input! {
        n: usize,
        k: usize,
        a: [u64; n],
    }
    let cost = |a: u64, d: u64| -> u64 {
        if a < d {
            return a;
        }
        let q = a / d;
        let r = a % d;
        (q + 1).pow(2) * r + q.pow(2) * (d - r)
    };
    let mut h = std::collections::BinaryHeap::new();
    for &a in a.iter() {
        let x = cost(a, 1);
        let y = cost(a, 2);
        h.push((x - y, a, 0));
    }
    for _ in 0..(k - n) {
        let (_v, a, d) = h.pop().unwrap();
        let x = cost(a, d + 2);
        let y = cost(a, d + 3);
        h.push((x - y, a, d + 1));
    }
    let mut ans = 0;
    while let Some((_, a, d)) = h.pop() {
        ans += cost(a, d + 1);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
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

// 2piR / v 1
// d  2piR  

fn run() {
    input! {
        n: usize,
        rad: f64,
        v: f64,
        ask: [(f64, f64); n],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let pi = std::f64::consts::PI;
    let cycle = 2.0 * pi * rad;
    let t = cycle / v;
    for (s, f) in ask {
        let d = f - s;
        let q = (d / cycle).floor();
        let rem = d - q * cycle;
        let f = |p: f64| rad * (p - p.sin());
        let mut ng = 0f64;
        let mut ok = pi;
        for _ in 0..60 {
            let mid = (ok + ng) * 0.5;
            let v = f(pi + mid) - f(pi - mid);
            if v < rem {
                ng = mid;
            } else {
                ok = mid;
            }
        }
        let ans = q * t + ok / pi * t;
        writeln!(out, "{:.7}", ans).ok();
    }
}

fn main() {
    run();
}
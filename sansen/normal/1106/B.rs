//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use std::io::Write;
use std::cmp::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        a: [u64; n],
        c: [u64; n],
        ask: [(usize1, u64); m],
    }
    let mut a = a;
    let mut h = std::collections::BinaryHeap::new();
    for (i, c) in c.iter().enumerate() {
        h.push(Reverse((*c, i)));
    }
    for (x, mut d) in ask {
        let mut ans = 0u64;
        let v = std::cmp::min(a[x], d);
        ans += v * c[x];
        a[x] -= v;
        d -= v;
        while d > 0 && !h.is_empty() {
            let Reverse((c, k)) = h.pop().unwrap();
            let v = std::cmp::min(a[k], d);
            ans += c * v;
            a[k] -= v;
            d -= v;
            if a[k] > 0 {
                h.push(Reverse((c, k)));
            }
        }
        if d > 0 {
            ans = 0;
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
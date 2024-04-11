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

use std::cmp::{max, min};

fn run() {
    input! {
        n: usize,
        p: [(i32, i32, i32, i32); n],
    }
    let inf = 1_000_000_000;
    let mut l = vec![(-inf, -inf, inf, inf); n + 1];
    let mut r = vec![(-inf, -inf, inf, inf); n + 1];
    for i in 0..n {
        let (a, b, c, d) = l[i];
        let (x, y, z, w) = p[i];
        l[i + 1] = (max(a, x), max(b, y), min(c, z), min(d, w));
    }
    for i in (0..n).rev() {
        let (a, b, c, d) = r[i + 1];
        let (x, y, z, w) = p[i];
        r[i] = (max(a, x), max(b, y), min(c, z), min(d, w));
    }
    for i in 0..n {
        let (a, b, c, d) = l[i];
        let (x, y, z, w) = r[i + 1];
        let (p, q, r, s) = (max(a, x), max(b, y), min(c, z), min(d, w));
        if p <= r && q <= s {
            println!("{} {}", p, q);
            return;
        }
    }
}

fn main() {
    run();
}
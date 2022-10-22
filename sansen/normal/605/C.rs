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

//

use std::collections::*;

fn run() {
    input! {
        n: usize,
        s: (i64, i64),
        a: [(i64, i64); n],
    }
    let mut a = a;
    a.sort();
    let mut p: Vec<(i64, i64)> = vec![];
    for (e, f) in a {
        while p.last().map_or(false, |p| p.1 <= f) {
            p.pop();
        }
        while p.len() > 1 {
            let len = p.len();
            let (c, d) = p[len - 1];
            let (a, b) = p[len - 2];
            if (f - b) * (c - a) < (d - b) * (e - a) {
                break;
            } else {
                p.pop();
            }
        }
        p.push((e, f));
    }
    let len = p.len();
    let ans = if p[0].0 * s.1 - p[0].1 * s.0 >= 0 {
        s.1 as f64 / p[0].1 as f64
    } else if s.0 * p[len - 1].1 - s.1 * p[len - 1].0 >= 0 {
        s.0 as f64 / p[len - 1].0 as f64
    } else {
        let mut val = std::f64::MAX;
        for p in p.windows(2) {
            let (c, d) = p[0];
            let (a, b) = p[1];
            if a * s.1 - b * s.0 >= 0 && s.0 * d - s.1 * c >= 0 {
                let det = a * d - b * c;
                val = ((d * s.0 - c * s.1) + (-b * s.0 + a * s.1)) as f64 / det as f64;
                break;
            }
        }
        val
    };
    println!("{:.7}", ans);
}

fn main() {
    run();
}
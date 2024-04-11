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

fn run() {
    input! {
        n: usize,
        t: usize,
        p: [(usize, usize); n],
    }
    let mut p = p.into_iter().enumerate().map(|(k, p)| (p.0, p.1, k)).collect::<Vec<_>>();
    p.sort();
    let mut h = BinaryHeap::new();
    let mut sum = 0;
    for i in (1..=n).rev() {
        while p.last().map_or(false, |p| p.0 == i) {
            let (_, t, x) = p.pop().unwrap();
            sum += t;
            h.push((t, x));
        }
        while sum > t {
            sum -= h.pop().unwrap().0;
        }
        if h.len() >= i {
            let a = h.into_iter().take(i).map(|p| (p.1 + 1).to_string()).collect::<Vec<_>>().join(" ");
            println!("{}", i);
            println!("{}", i);
            println!("{}", a);
            return;
        }
    }
    println!("0\n0\n");
}

fn main() {
    run();
}
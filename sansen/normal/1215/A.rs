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
        a: i32,
        b: i32,
        x: i32,
        y: i32,
        n: i32,
    }
    let mut f = n;
    let mut g = 0;
    for i in 0..=n {
        if x * a < i || y * b < n - i{
            continue;
        }
        let mut p = 0;
        let mut q = 0;
        if (x - 1) * a < i {
            p += i - (x - 1) * a;
        }
        q += i / x;
        if (y - 1) * b < n - i {
            p += n - i - (y - 1) * b;
        }
        q += (n - i) / y;
        f = min(f, p);
        g = max(g, q);
    }
    println!("{} {}", f, g);
}

fn main() {
    run();
}
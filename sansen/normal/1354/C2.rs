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

fn run() {
    input! {
        t: usize,
        n: [usize; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for n in n {
        let rad = 2.0 * std::f64::consts::PI / (2 * n) as f64;
        let len = 0.5 / (rad / 2.0).sin();
        let f = |p: f64| -> f64 {
            (len * p.sin().abs()).max(len * p.cos())
        };
        let func = |p: f64| -> f64 {
            let mut ans = 0f64;
            for i in 0..(2 * n) {
                ans = ans.max(f(p + rad * (i as f64)));
            }
            ans
        };
        let mut l = 0.0;
        let mut r = rad;
        for _ in 0..53 {
            let ll = (2.0 * l + r) / 3.0;
            let rr = (l + 2.0 * r) / 3.0;
            if func(ll) < func(rr) {
                r = rr;
            } else {
                l = ll;
            }
        }
        let ans = func(l) * 2.0;
        writeln!(out, "{:.7}", ans).ok();
    }
}

fn main() {
    run();
}
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

fn run() {
    input! {
        n: usize,
        p: (f64, f64),
        a: [(f64, f64); n],
    }
    let mut a = a;
    for a in a.iter_mut() {
        a.0 -= p.0;
        a.1 -= p.1;
    }
    let mut max = 0f64;
    let mut min = std::f64::MAX;
    for &(x, y) in a.iter() {
        let d = (x.powi(2) + y.powi(2)).sqrt();
        max = max.max(d);
        min = min.min(d);
    }
    let mut a = a;
    let s = a[0];
    a.push(s);
    for a in a.windows(2) {
        let c = a[0];
        let d = a[1];
        let (p, q) = (d.0 - c.0, d.1 - c.1);
        let x = (c.0 * d.1 - c.1 * d.0) * q / (p * p + q * q);
        let y = (c.0 * d.1 - c.1 * d.0) * p / (p * p + q * q);
        let m = if p.abs() > 1f64 - 0.1 {
            (x - c.0) / p
        } else {
            (y - c.1) / q
        };
        if 0f64 < m && m < 1f64 {
            min = min.min((c.0 * d.1 - c.1 * d.0).abs() / ((c.1 - d.1).powi(2) + (c.0 - d.0).powi(2)).sqrt());
        }
    }
    let ans = std::f64::consts::PI * (max.powi(2) - min.powi(2));
    println!("{:.7}", ans);
}

fn main() {
    run();
}
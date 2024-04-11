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

fn run() {
    input! {
        s: (f64, f64),
        dst: (f64, f64),
        v: f64,
        t: f64,
        a: (f64, f64),
        b: (f64, f64),
    }
    let mut ng = 0f64;
    let mut ok = 10f64.powi(18);
    for _ in 0..200 {
        let mid = (ok + ng) * 0.5;
        let mut s = s;
        let p = t.min(mid);
        s = (s.0 + a.0 * p, s.1 + a.1 * p);
        if t < mid {
            let rem = mid - t;
            s = (s.0 + b.0 * rem, s.1 + b.1 * rem);
        }
        let d = ((s.0 - dst.0).powi(2) + (s.1 - dst.1).powi(2)).sqrt();
        if d / v <= mid {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{:.7}", ok);
}

fn main() {
    run();
}
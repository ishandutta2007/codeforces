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

// acos(1-EPS) 

fn run() {
    input! {
        p: (i64, i64, i64),
        q: (i64, i64, i64),
    }
    let d = (p.0 - q.0).pow(2) + (p.1 - q.1).pow(2);
    if d >= (p.2 + q.2).pow(2) {
        println!("0");
        return;
    }
    if d <= (p.2 - q.2).pow(2) {
        let ans = p.2.min(q.2).pow(2) as f64 * std::f64::consts::PI;
        println!("{:.7}", ans);
        return;
    }
    let calc = |a: i64, b: i64| -> f64 {
        let nu = a * a - b * b + d;
        let de = (2 * a) as f64 * (d as f64).sqrt();
        let theta = if nu as f64 * 1.5 <= de {
            (nu as f64 / de).acos() * 2.0
        } else {
            let nu = (nu as i128).pow(2);
            let de = 4i128 * a.pow(2) as i128 * d as i128;
            let v = (de - nu) as f64 / de as f64;
            v.sqrt().asin() * 2.0
        };
        let mut sum = 0f64;
        for i in (1..10).rev() {
            let fact = (1..=(2 * i + 1)).map(|p| p as f64).product::<f64>();
            let sign = if i % 2 == 1 { 1 } else { -1 } as f64;
            sum += sign / fact * theta.powi(2 * i + 1);
        }
        let mul = a.pow(2) as f64 * 0.5;
        sum * mul
    };
    let ans = calc(p.2, q.2) + calc(q.2, p.2);
    println!("{:.7}", ans);
}

fn main() {
    run();
}
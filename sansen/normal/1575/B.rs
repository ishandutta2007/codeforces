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
        n: usize,
        k: usize,
        p: [(f64, f64); n],
    }
    let mut p = p;
    p.retain(|p| *p != (0f64, 0f64));
    if n - p.len() >= k {
        println!("0");
        return;
    }
    let k = k - (n - p.len());
    let pi = 2.0 * std::f64::consts::PI;
    let mut ng = 0f64;
    let mut ok = 200000f64;
    for _ in 0..40 {
        let mid = (ok + ng) / 2.0;
        let mut event = vec![];
        for &(x, y) in p.iter() {
            let d = (x.powi(2) + y.powi(2)).sqrt();
            if d > 2.0 * mid {
                continue;
            }
            let (cos, sin) = (x / d, y / d);
            let l = (mid.powi(2) - (d / 2.0).powi(2)).sqrt();
            let s = (x / 2.0 + l * sin, y / 2.0 - l * cos);
            let t = (x / 2.0 - l * sin, y / 2.0 + l * cos);
            let mut p = s.1.atan2(s.0);
            let q = t.1.atan2(t.0);
            if p > q {
                p -= pi;
            }
                event.push((p, 1));
                event.push((q, -1));
                event.push((p + pi, 1));
                event.push((q + pi, -1));
                event.push((p + pi + pi, 1));
                event.push((q + pi + pi, -1));
        }
        event.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());
        let mut sum = 0;
        let mut cond = false;
        for (_, v) in event {
            sum += v;
            cond |= sum >= (k as i32);
        }
        if cond {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{:.6}", ok);
}

fn main() {
    run();
}
// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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
        a: f64,
        b: f64,
        c: f64,
        s: (f64, f64),
        t: (f64, f64),
    }
    let mut ans = (s.0 - t.0).abs() + (s.1 - t.1).abs();
    if a.abs() > 0.0 && b.abs() > 0.0 {
        let c = -c;
        for &(sx, sy) in [(s.0, (c - a * s.0) / b), ((c - b * s.1) / a, s.1)].iter() {
            for &(tx, ty) in [(t.0, (c - a * t.0) / b), ((c - b * t.1) / a, t.1)].iter() {
                let mut sum = 0f64;
                sum += (sx - s.0).abs() + (sy - s.1).abs();
                sum += ((sx - tx).powi(2) + (sy - ty).powi(2)).sqrt();
                sum += (tx - t.0).abs() + (ty - t.1).abs();
                ans.chmin(sum);
            }
        }
    }
    println!("{:.7}", ans);
}

fn main() {
    run();
}
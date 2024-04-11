fn main() {
    input! {
        n: usize,
        k: usize,
        p: [(f64, f64); n],
    }
    let mut ng = 5e-7f64;
    let mut ok = 10000f64 * 2f64;
    let c = ((ok / ng).ln() / 1e-6f64.ln_1p()).log2().ceil() as u32;
    for _ in 0..c {
        let mid = (ok * ng).sqrt();
        let mut p = p.clone();
        p.retain(|p| (p.0.powi(2) + p.1.powi(2)).sqrt() > mid);
        let r2 = mid * mid;
        let mut point = vec![];
        for (i, &(x, y)) in p.iter().enumerate() {
            if y != 0.0 {
                let (a, b) = (r2 / y, -x / y);
                let (a, b, c) = (1f64 + b * b, 2f64 * a * b, a * a - r2);
                let det = (b * b - 4f64 * a * c).sqrt();
                for sign in [-1, 1].iter() {
                    let sign = *sign as f64;
                    let p = (-b + sign * det) / (2f64 * a);
                    let q = (r2 - x * p) / y;
                    point.push((q.atan2(p), i));
                }
            } else {
                let (x, y) = (y, x);
                let (a, b) = (r2 / y, -x / y);
                let (a, b, c) = (1f64 + b * b, 2f64 * a * b, a * a - r2);
                let det = (b * b - 4f64 * a * c).sqrt();
                for sign in [-1, 1].iter() {
                    let sign = *sign as f64;
                    let p = (-b + sign * det) / (2f64 * a);
                    let q = (r2 - x * p) / y;
                    point.push((p.atan2(q), i));
                }
            }
        }
        point.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());
        let hit = n - p.len();
        let mut cnt = hit * (hit - 1) / 2 + hit * p.len() + p.len() * (p.len() - 1) / 2;
        let mut pos = vec![0; p.len()];
        let mut bit = Fenwick::new(point.len() + 1, 0);
        for (i, (_, k)) in point.into_iter().enumerate() {
            if pos[k] == 0 {
                bit.add(i + 1, 1);
                pos[k] = i + 1;
            } else {
                cnt -= bit.sum(i + 1) - bit.sum(pos[k]);
                bit.add(pos[k], !0);
            }
        }
        if cnt >= k {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{}", (ok * ng).sqrt());
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
// 1-indexedBIT
// x[1,x], ([1,x])>=s x
// ---------- begin fenwick tree ----------
pub struct Fenwick<T> {
    zero: T,
    a: Box<[T]>,
}

impl<T> Fenwick<T>
where
    T: Copy + std::ops::Add<Output = T>,
{
    pub fn new(size: usize, zero: T) -> Fenwick<T> {
        Fenwick {
            zero: zero,
            a: vec![zero; size + 1].into_boxed_slice(),
        }
    }
    pub fn init(&mut self) {
        for a in self.a.iter_mut() {
            *a = self.zero;
        }
    }
    pub fn add(&mut self, mut x: usize, v: T) {
        assert!(x > 0);
        while let Some(a) = self.a.get_mut(x) {
            *a = *a + v;
            x += x & (!x + 1);
        }
    }
    pub fn sum(&self, mut x: usize) -> T {
        assert!(x < self.a.len());
        let mut res = self.zero;
        while x > 0 {
            res = res + self.a[x];
            x -= x & (!x + 1);
        }
        res
    }
}
// ---------- end fenwick tree ----------
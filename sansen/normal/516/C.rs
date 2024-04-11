// ---------- begin Matrix ----------
#[allow(dead_code)]
mod matrix {
    use std::ops::{Add, Mul};
    pub trait SemiRing: Add<Output = Self> + Mul<Output = Self> + Copy {
        fn zero() -> Self;
        fn one() -> Self;
    }
    pub const SIZE: usize = 3;
    #[derive(Clone)]
    pub struct SquareMatrix<T: SemiRing> {
        buf: [[T; SIZE]; SIZE],
    }
    impl<T: SemiRing> SquareMatrix<T> {
        pub fn zero() -> Self {
            let z = T::zero();
            SquareMatrix {
                buf: [[z; SIZE]; SIZE],
            }
        }
        pub fn identity() -> Self {
            let mut m = Self::zero();
            for i in 0..SIZE {
                m.buf[i][i] = T::one();
            }
            m
        }
        pub fn set_at(&mut self, i: usize, j: usize, v: T) {
            self.buf[i][j] = v;
        }
        pub fn get_at(&self, i: usize, j: usize) -> T {
            self.buf[i][j]
        }
        pub fn matmul(&self, rhs: &Self) -> Self {
            let mut res = Self::zero();
            for (x, a) in res.buf.iter_mut().zip(self.buf.iter()) {
                for (a, b) in a.iter().zip(rhs.buf.iter()) {
                    for (x, b) in x.iter_mut().zip(b.iter()) {
                        *x = *x + *a * *b;
                    }
                }
            }
            res
        }
        pub fn matadd(&self, rhs: &Self) -> Self {
            let mut c = Self::zero();
            for (c, (a, b)) in c.buf.iter_mut().zip(self.buf.iter().zip(rhs.buf.iter())) {
                for (c, (a, b)) in c.iter_mut().zip(a.iter().zip(b.iter())) {
                    *c = *a + *b;
                }
            }
            c
        }
        pub fn matpow(&self, mut n: usize) -> Self {
            let mut t = Self::identity();
            let mut s = self.clone();
            while n > 0 {
                if n & 1 == 1 {
                    t = t.matmul(&s);
                }
                s = s.matmul(&s);
                n >>= 1;
            }
            t
        }
    }
}
// ---------- end Matrix ----------
// 
// 
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T, F> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(&T, &T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            let a = &mut self.a;
            for k in (1..(self.n)).rev() {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            let a = &self.a;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(&p, &a[l]);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(&a[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
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

use std::io::Write;

fn naive() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        d: [i64; n],
        h: [i64; n],
        ask: [(usize1, usize1); m],
    }
    let d = d.into_iter().cycle().take(2 * n).collect::<Vec<_>>();
    let h = h.into_iter().cycle().map(|h| 2 * h).take(2 * n).collect::<Vec<_>>();
    for (a, b) in ask {
        let (l, r) = if a <= b {
            (b + 1, n + a)
        } else {
            (b + 1, a)
        };
        let d = &d[l..r];
        let h = &h[l..r];
        let mut ans = 0;
        let mut p = h[0];
        for (d, h) in d.iter().zip(h.iter().skip(1)) {
            p += *d;
            ans = std::cmp::max(ans, *h + p);
            p = std::cmp::max(p, *h);
        }
        writeln!(out, "{}", ans).ok();
    }
}

#[derive(Copy, Clone)]
struct Val(i64);

impl Val {
    fn new(v: i64) -> Self {
        Val(v)
    }
}

use std::cmp::*;
use std::ops::*;
use matrix::*;

impl Add for Val {
    type Output = Self;
    fn add(self, rhs: Self) -> Self {
        Val::new(max(self.0, rhs.0))
    }
}

impl Mul for Val {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        Val::new(self.0 + rhs.0)
    }
}

impl SemiRing for Val {
    fn one() -> Self {
        Val::new(0)
    }
    fn zero() -> Self {
        Val::new(-1000000000000)
    }
}

type Mat = SquareMatrix<Val>;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        d: [i64; n],
        h: [i64; n],
        ask: [(usize1, usize1); m],
    }
    let d = d.into_iter().cycle().take(2 * n).collect::<Vec<_>>();
    let h = h.into_iter().cycle().map(|h| 2 * h).take(2 * n).collect::<Vec<_>>();
    let mut seg = segment_tree::PURQ::new(2 * n, Mat::identity(), |a, b| a.matmul(b));
    for (i, (d, h)) in d.iter().zip(h.iter().skip(1)).enumerate() {
        let mut mat = Mat::identity();
        mat.set_at(1, 1, Val::new(*d));
        mat.set_at(1, 0, Val::new(*h + *d));
        mat.set_at(2, 1, Val::new(*h));
        seg.update_tmp(i + 1, mat);
    }
    seg.update_all();
    for (a, b) in ask {
        let (l, r) = if a <= b {
            (b + 1, n + a)
        } else {
            (b + 1, a)
        };
        let mat = seg.find(l + 1, r);
        let mut a = [Val::new(0); 3];
        a[1] = Val::new(h[l]);
        let mut ans = Val::zero();
        for i in 0..3 {
            ans = ans + mat.get_at(i, 0) * a[i];
        }
        writeln!(out, "{}", ans.0).ok();
    }
}

fn main() {
    run();
//    naive();
}
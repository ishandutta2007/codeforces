//---------- begin SegmentTree Point update Range query ----------
pub trait PURQ {
    type T: Clone;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T;
    fn fold_option(l: &Option<Self::T>, r: &Option<Self::T>) -> Option<Self::T> {
        match (l.as_ref(), r.as_ref()) {
            (Some(l), Some(r)) => Some(Self::fold(l, r)),
            (Some(l), None) => Some(l.clone()),
            (None, Some(r)) => Some(r.clone()),
            _ => None,
        }
    }
}

struct SegmentTreePURQ<R: PURQ> {
    seg: Vec<Option<R::T>>,
    size: usize,
}

#[allow(dead_code)]
impl<R: PURQ> SegmentTreePURQ<R> {
    fn new(n: usize) -> SegmentTreePURQ<R> {
        let size = n.next_power_of_two();
        SegmentTreePURQ {
            seg: (0..(2 * size)).map(|_| None).collect(),
            size: size,
        }
    }
    fn update(&mut self, x: usize, v: Option<R::T>) {
        let mut x = x + self.size;
        let a = &mut self.seg;
        a[x] = v;
        x >>= 1;
        while x > 0 {
            a[x] = R::fold_option(&a[2 * x], &a[2 * x + 1]);
            x >>= 1;
        }
    }
    fn update_tmp(&mut self, x: usize, v: Option<R::T>) {
        self.seg[self.size + x] = v;
    }
    fn update_all(&mut self) {
        let a = &mut self.seg;
        for i in (1..self.size).rev() {
            a[i] = R::fold_option(&a[2 * i], &a[2 * i + 1]);
        }
    }
    fn find(&self, l: usize, r: usize) -> Option<R::T> {
        let mut x = None;
        let mut y = None;
        let mut l = l + self.size;
        let mut r = r + self.size;
        let a = &self.seg;
        while l < r {
            if l & 1 == 1 {
                x = R::fold_option(&x, &a[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                y = R::fold_option(&a[r], &y);
            }
            l >>= 1;
            r >>= 1;
        }
        R::fold_option(&x, &y)
    }
}
//---------- end SegmentTree Point update Range query ----------
// ---------- begin Matrix ----------
#[allow(dead_code)]
mod matrix {
    use std::ops::{Add, Mul};
    pub trait SemiRing: Add<Output = Self> + Mul<Output = Self> + Copy {
        fn zero() -> Self;
        fn one() -> Self;
    }
    pub const SIZE: usize = 2;
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

use matrix::*;
use std::ops::*;

#[derive(Clone, Copy)]
struct R(i64);
impl Add for R {
    type Output = Self;
    fn add(self, rhs: Self) -> Self::Output {
        R(std::cmp::max(self.0, rhs.0))
    }
}

impl Mul for R {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self::Output {
        R(std::cmp::max(std::i64::MIN / 10, self.0 + rhs.0))
    }
}

impl SemiRing for R {
    fn one() -> Self {
        R(0)
    }
    fn zero() -> Self {
        R(std::i64::MIN / 10)
    }
}

type M = SquareMatrix<R>;

struct DP;
impl PURQ for DP {
    type T = M;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        l.matmul(r)
    }
}

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [i64; n],
        d: [i64; n],
    }
    let mut ans = 0;
    if k == 0 {
        let mut sum = 0;
        for (a, d) in a.iter().zip(d.iter()).rev() {
            sum += *a;
            ans.chmax(sum - *d);
        }
    } else if k == 1 {
        // 1
        //  + 
        // 1+
        // +
        // 1+
        // ?
        {
            let mut sum = a[0];
            let mut min = d[0];
            let mut val = vec![];
            for (a, d) in a.iter().zip(d.iter()).take(n - 1).skip(1) {
                sum += *a;
                min.chmin(*d);
                val.push(sum - min);
            }
            let mut sum = 0;
            let mut max = 0;
            for i in (2..n).rev() {
                sum += a[i];
                max.chmax(sum - d[i]);
                ans.chmax(val[i - 2] + max);
            }
        }
        {
            let mut mat = vec![M::identity(); n];
            for i in 0..n {
                mat[i].set_at(0, 0, R(a[i]));
                mat[i].set_at(1, 0, R(a[i] - d[i]));
            }
            let mut seg = SegmentTreePURQ::<DP>::new(n);
            for i in 0..n {
                seg.update_tmp(i, Some(mat[i].clone()));
            }
            seg.update_all();
            let m = seg.find(1, n).unwrap();
            ans.chmax((m.get_at(1, 0) + m.get_at(1, 1)).0);
            for i in 0..(n - 2) {
                seg.update(i + 1, None);
                let m = seg.find(0, n).unwrap();
                let v = (m.get_at(1, 0) + m.get_at(1, 1)).0;
                ans.chmax(v + std::cmp::max(0, a[i + 1] - d[i + 1]));
                seg.update(i + 1, Some(mat[i + 1].clone()));
            }
        }
    } else {
        let sum = a.iter().sum::<i64>();
        for d in d.iter().rev().skip(1) {
            ans.chmax(sum - *d);
        }
        ans.chmax(a[n - 1] - d[n - 1]);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
// ---------- begin Matrix ----------
#[allow(dead_code)]
mod matrix {
    use std::ops::{Add, Mul};
    pub trait SemiRing: Add<Output = Self> + Mul<Output = Self> + Copy {
        fn zero() -> Self;
        fn one() -> Self;
    }
    pub const SIZE: usize = 10;
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

// 
// kk
// n <= 100
// |S| <= 100
// m <= 100
// binary
//
// K
// 

use matrix::*;
use std::ops::*;

#[derive(Clone, Copy)]
pub struct V(bool);

impl Add for V {
    type Output = Self;
    fn add(self, rhs: Self) -> Self {
        V(self.0 || rhs.0)
    }
}

impl Mul for V {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        V(self.0 && rhs.0)
    }
}

impl SemiRing for V {
    fn zero() -> Self {
        V(false)
    }
    fn one() -> Self {
        V(true)
    }
}

type Mat = SquareMatrix<V>;

fn run() {
    input! {
        n: usize,
        s: [bytes; n],
        m: usize,
        op: [(usize1, usize1); m],
    }
    let mut ans = vec![0; m];
    for len in 1.. {
        let mut ok = vec![true; m];
        for bit in 0usize..(1 << len) {
            let mut one = Mat::zero();
            let mut zero = Mat::zero();
            one.set_at(0, 0, V(true));
            one.set_at(len, len, V(true));
            zero.set_at(0, 0, V(true));
            zero.set_at(len, len, V(true));
            for j in 0..len {
                if bit >> j & 1 == 1 {
                    one.set_at(j, j + 1, V(true));
                } else {
                    zero.set_at(j, j + 1, V(true));
                }
            }
            let mut dp = vec![];
            for s in s.iter() {
                let mut mat = Mat::identity();
                for c in s.iter() {
                    if *c == b'0' {
                        mat = mat.matmul(&zero);
                    } else {
                        mat = mat.matmul(&one);
                    }
                }
                dp.push(mat);
            }
            for (i, &(a, b)) in op.iter().enumerate() {
                let mat = dp[a].matmul(&dp[b]);
                ok[i] &= mat.get_at(0, len).0;
                dp.push(mat);
            }
        }
        if ok.iter().all(|p| !*p) {
            break;
        }
        for (ans, ok) in ans.iter_mut().zip(ok) {
            if ok {
                *ans += 1;
            }
        }
    }
    for a in ans {
        println!("{}", a);
    }
}

fn main() {
    run();
}
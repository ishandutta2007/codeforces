use crate::lib::ds::uf::*;
use crate::lib::gf::conv::*;
use crate::lib::stdio::*;

fn main() {
    scan!(S: bytes, T: bytes);
    let n = S.len();
    let m = T.len();

    let mut uf = vec![UnionFind::new(26); n - m + 1];

    for s in b'a'..=b'f' {
        for t in b'a'..=b'f' {
            let mut s1 = vec![Gf99::ZERO; n * 2];
            let mut t1 = vec![Gf99::ZERO; m * 2];
            if s == t {
                continue;
            }
            for i in 0..n {
                s1[i] = if S[i] == s { Gf99::ONE } else { Gf99::ZERO };
                s1[i + n] = s1[i];
            }
            for i in 0..m {
                t1[i] = if T[m - 1 - i] == t { Gf99::ONE } else { Gf99::ZERO };
            }

            let u1 = Gf99::conv(s1, t1);

            for i in 0..n - m + 1 {
                if !u1[m - 1 + i].is_zero() {
                    uf[i].unite((s - b'a') as usize, (t - b'a') as usize);
                }
            }
        }
    }
    let res = (0..n - m + 1).map(|i| {
        let mut cnt = 0;
        for s in 0..26 {
            if s == uf[i].find(s) {
                cnt += uf[i].size(s) - 1;
            }
        }
        cnt
    });

    prtln!(iter = res);
}



pub mod lib {

pub mod conv {

pub trait Conv: Sized {
    fn conv(mut lhs: Vec<Self>, mut rhs: Vec<Self>) -> Vec<Self> {
        Conv::conv_in_place(&mut lhs, &mut rhs);
        lhs
    }
    /// results assigned in lhs
    fn conv_in_place(lhs: &mut Vec<Self>, rhs: &mut Vec<Self>);
}

}  // mod conv

pub mod ds {

pub mod uf {

#[derive(Clone)]
pub struct UnionFind {
    par: Vec<usize>,
    size: Vec<usize>,
    count: usize,
}

impl UnionFind {
    pub fn new(len: usize) -> Self {
        Self { par: vec![!0; len], size: vec![1; len], count: len }
    }
    pub fn clear(&mut self) {
        self.par.iter_mut().for_each(|e| *e = !0);
        self.size.iter_mut().for_each(|e| *e = 1);
        self.count = self.len();
    }
    pub fn len(&self) -> usize { self.par.len() }
    pub fn find(&mut self, x: usize) -> usize {
        if self.par[x] == !0 {
            x
        } else {
            self.par[x] = self.find(self.par[x]);
            self.par[x]
        }
    }
    pub fn is_same(&mut self, x: usize, y: usize) -> bool { self.find(x) == self.find(y) }
    pub fn size(&mut self, x: usize) -> usize {
        let root = self.find(x);
        self.size[root]
    }
    pub fn unite(&mut self, x: usize, y: usize) -> bool {
        let (mut x, mut y) = (self.find(x), self.find(y));
        if x != y {
            if self.size[x] < self.size[y] {
                std::mem::swap(&mut x, &mut y);
            }
            self.par[y] = x;
            self.size[x] += self.size[y];
            self.count -= 1;
            true
        } else {
            false
        }
    }
    pub fn count(&self) -> usize { self.count }
    pub fn push(&mut self) -> usize {
        let new = self.len();
        self.par.push(new);
        self.size.push(1);
        new
    }
    pub fn groups(&mut self) -> Vec<Vec<usize>> {
        let mut groups = vec![Vec::new(); self.len()];
        for i in 0..self.len() {
            groups[self.find(i)].push(i);
        }
        groups.retain(|v| !v.is_empty());
        groups
    }
}

}  // mod uf

}  // mod ds

pub mod gf {

// modular arithmetics

use crate::lib::zo::ZeroOne;
use std::marker::PhantomData;
use std::{cmp, fmt, iter, ops::*, str};

pub trait Mod: Default + Clone + Copy + PartialEq + Eq {
    const P: u32;
    const K: u32; // -1 / P mod 2^32
    const R2: u32; // 2^64 mod P
}

// montgomery reduction (x -> x / 2^32 mod P)
fn reduce<M: Mod>(x: u64) -> u32 {
    let s = M::K.wrapping_mul(x as u32);
    ((x + s as u64 * M::P as u64) >> 32) as u32
}

#[macro_export]
macro_rules! def_prime {
    ($name:ident, $modu:expr, $k:expr) => {
        #[derive(Default, Clone, Copy, PartialEq, Eq, Debug)]
        pub struct $name;
        impl Mod for $name {
            const P: u32 = $modu;
            const K: u32 = $k;
            const R2: u32 = ((1_u128 << 64) % $modu) as u32;
        }
    };
}

def_prime!(ModA, 1_000_000_007, 2_226_617_417);
def_prime!(ModB, 998_244_353, 998_244_351);
def_prime!(ModC, 1_012_924_417, 1_012_924_415);
def_prime!(ModD, 924_844_033, 924_844_031);

#[repr(transparent)]
#[derive(Default, Clone, Copy)]
pub struct Gf<M: Mod> {
    val: u32,
    _m: PhantomData<M>,
}

pub type GfA = Gf<ModA>;
pub type GfB = Gf<ModB>;
pub type GfC = Gf<ModC>;
pub type GfD = Gf<ModD>;
pub type Gf17 = GfA;
pub type Gf99 = GfB;

impl<M: Mod> Gf<M> {
    pub const P: u32 = M::P;
    pub const ZERO: Self = ZeroOne::ZERO;
    pub const ONE: Self = ZeroOne::ONE;
    pub fn new(val: u32) -> Self { val.into() }
    pub fn zero() -> Self { Self::ZERO }
    pub fn one() -> Self { Self::ONE }
    pub fn is_zero(&self) -> bool { *self == Self::ZERO }
    fn from_raw(val: u32) -> Self { Gf { val, _m: PhantomData } }
    pub fn value(self) -> u32 {
        let v = reduce::<M>(self.val as u64);
        if v >= M::P { v - M::P } else { v }
    }
    pub fn pow(mut self, mut k: u64) -> Self {
        if self.val == 0 && k == 0 { return Self::new(1); }
        k %= (M::P - 1) as u64;
        let mut res = Self::ONE;
        while !k.is_zero() {
            if k % 2 != 0 { res *= self; }
            self *= self; k >>= 1;
        }
        res
    }
    pub fn inv(self) -> Self {
        let (mut a, mut b, mut u, mut v) = (M::P as i32, self.value() as i32, 0, 1);
        while b != 0 {
            let t = a / b;
            a -= t * b; u -= t * v;
            std::mem::swap(&mut a, &mut b); std::mem::swap(&mut u, &mut v);
        }
        debug_assert_eq!(a, 1);
        if u < 0 { debug_assert_eq!(v, M::P as i32); u += v; }
        Self::new(u as u32)
    }
}
impl<M: Mod> From<u32> for Gf<M> {
    fn from(x: u32) -> Self { Gf::from_raw(reduce::<M>(x as u64 * M::R2 as u64)) }
}
macro_rules! impl_from_int {
    ($($t:ty),*) => { $(
        impl<M: Mod> From<$t> for Gf<M> {
            fn from(x: $t) -> Self {
                Gf::from_raw(reduce::<M>(x.rem_euclid(M::P as _) as u64 * M::R2 as u64))
            }
        }
    )* };
}
impl_from_int!(u64, usize, i32, i64, isize);
impl<M: Mod> cmp::PartialEq for Gf<M> {
    fn eq(&self, other: &Self) -> bool {
        let val = |obj: &Gf<M>| {
            if obj.val >= M::P { obj.val - M::P } else { obj.val }
        };
        val(self) == val(other)
    }
}
impl<M: Mod> cmp::Eq for Gf<M> {}
impl<M: Mod, T: Into<Gf<M>>> AddAssign<T> for Gf<M> {
    fn add_assign(&mut self, rhs: T) {
        self.val += rhs.into().val;
        if self.val >= M::P * 2 { self.val -= M::P * 2; }
    }
}
impl<M: Mod, T: Into<Gf<M>>> SubAssign<T> for Gf<M> {
    fn sub_assign(&mut self, rhs: T) {
        let rhs = rhs.into();
        if self.val < rhs.val { self.val += M::P * 2; }
        self.val -= rhs.val;
    }
}
impl<M: Mod, T: Into<Gf<M>>> MulAssign<T> for Gf<M> {
    fn mul_assign(&mut self, rhs: T) {
        self.val = reduce::<M>(self.val as u64 * rhs.into().val as u64);
    }
}
impl<M: Mod, T: Into<Gf<M>>> DivAssign<T> for Gf<M> {
    fn div_assign(&mut self, rhs: T) { *self *= rhs.into().inv(); }
}
macro_rules! impl_binop {
    ($(($Op:ident, $op:ident, $OpAssign:ident, $op_assign:ident)),*) => { $(
        impl<M: Mod, T: Into<Gf<M>>> $Op<T> for Gf<M> {
            type Output = Self;
            fn $op(mut self, rhs: T) -> Self { self.$op_assign(rhs); self }
        }
    )* };
}
impl_binop!(
    (Add, add, AddAssign, add_assign),
    (Sub, sub, SubAssign, sub_assign),
    (Mul, mul, MulAssign, mul_assign),
    (Div, div, DivAssign, div_assign)
);
impl<M: Mod> Neg for Gf<M> {
    type Output = Self;
    fn neg(self) -> Self { Gf::from_raw(M::P * 2 - self.val) }
}
impl<M: Mod> iter::Sum for Gf<M> {
    fn sum<I: Iterator<Item = Self>>(iter: I) -> Self { iter.fold(Self::ZERO, |b, x| b + x) }
}
impl<M: Mod> iter::Product for Gf<M> {
    fn product<I: Iterator<Item = Self>>(iter: I) -> Self { iter.fold(Self::ONE, |b, x| b * x) }
}
impl<M: Mod> fmt::Debug for Gf<M> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result { self.value().fmt(f) }
}
impl<M: Mod> fmt::Display for Gf<M> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result { self.value().fmt(f) }
}
impl<M: Mod> str::FromStr for Gf<M> {
    type Err = <u32 as str::FromStr>::Err;
    fn from_str(s: &str) -> Result<Self, Self::Err> { u32::from_str(s).map(Self::new) }
}
impl<M: Mod> ZeroOne for Gf<M> {
    const ZERO: Self = Self { val: 0, _m: PhantomData };
    const ONE: Self = Self { val: M::P.wrapping_neg() % M::P, _m: PhantomData };
}

pub mod conv {

pub use super::*;
pub use crate::lib::conv::*;

macro_rules! impl_ntt {
    ($module:ident, $modu:ty, $prim:expr) => {
        pub mod $module {
            use super::*;

            type GfType = Gf<$modu>;

            pub fn ntt(a: &mut Vec<GfType>) {
                let n = a.len();
                let r = GfType::new($prim);
                let roots: Vec<_> = (0..n.trailing_zeros())
                    .map(|i| -r.pow(((GfType::P - 1) >> (i + 2)) as u64))
                    .collect();
                let mut m = n >> 1;
                while m != 0 {
                    let mut w = GfType::ONE;
                    for (k, t) in (0..n).step_by(m * 2).zip(1_u32..) {
                        let a = &mut a[..k + m + m];
                        for i in k..k + m {
                            let u = a[i];
                            let v = a[i + m] * w;
                            a[i] = u + v;
                            a[i + m] = u - v;
                        }
                        w *= roots[t.trailing_zeros() as usize];
                    }
                    m >>= 1;
                }
            }

            pub fn inv_ntt(a: &mut Vec<GfType>) {
                let n = a.len();
                let r = GfType::new($prim);
                let inv_roots: Vec<_> = (0..n.trailing_zeros())
                    .map(|i| -r.pow((GfType::P - 1 - ((GfType::P - 1) >> (i + 2))) as u64))
                    .collect();
                let mut m = 1;
                while m < n {
                    let mut w = GfType::ONE;
                    for (k, t) in (0..n).step_by(m * 2).zip(1_u32..) {
                        let a = &mut a[..k + m + m];
                        for i in k..k + m {
                            let u = a[i];
                            let v = a[i + m];
                            a[i] = u + v;
                            a[i + m] = (u - v) * w;
                        }
                        w *= inv_roots[t.trailing_zeros() as usize];
                    }
                    m <<= 1;
                }
                let d = GfType::from(n as u32).inv();
                a.iter_mut().for_each(|e| *e *= d);
            }

            pub fn conv<'a, 'b>(a: &'a mut Vec<GfType>, b: &'b mut Vec<GfType>) {
                let len = a.len() + b.len() - 1;
                fn ilog2(n: usize) -> u32 {
                    std::mem::size_of::<usize>() as u32 * 8 - n.leading_zeros() - 1
                }
                let n: usize = 1 << ilog2(len * 2 - 1);
                a.resize(n, Default::default());
                b.resize(n, Default::default());
                ntt(a);
                ntt(b);
                a.iter_mut().zip(b.iter()).for_each(|(a, b)| *a *= *b);
                b.clear();
                inv_ntt(a);
                a.truncate(len);
            }

            impl Conv for GfType {
                fn conv(mut lhs: Vec<Self>, mut rhs: Vec<Self>) -> Vec<Self> {
                    conv(lhs.as_mut(), rhs.as_mut());
                    lhs
                }
                fn conv_in_place(lhs: &mut Vec<Self>, rhs: &mut Vec<Self>) {
                    conv(lhs.as_mut(), rhs.as_mut());
                }
            }
        }
    };
}

impl_ntt!(impl_b, ModB, 3);
impl_ntt!(impl_c, ModC, 5);
impl_ntt!(impl_d, ModD, 5);

impl Conv for Gf17 {
    fn conv_in_place(lhs: &mut Vec<Self>, rhs: &mut Vec<Self>) {
        let r12 = GfC::from(GfB::P).inv();
        let r13 = GfD::from(GfB::P).inv();
        let r23 = GfD::from(GfC::P).inv();
        fn run<M: Mod>(lhs: &[Gf17], rhs: &[Gf17]) -> Vec<Gf<M>>
        where
            Gf<M>: Conv,
        {
            let lhs = lhs.iter().map(|&e| Gf::from(e.value())).collect();
            let rhs = rhs.iter().map(|&e| Gf::from(e.value())).collect();
            Conv::conv(lhs, rhs)
        }
        let v1: Vec<GfB> = run(lhs, rhs);
        let v2: Vec<GfC> = run(lhs, rhs);
        let v3: Vec<GfD> = run(lhs, rhs);
        lhs.resize(v1.len(), Default::default());
        for (((e0, e1), e2), e3) in lhs.iter_mut().zip(v1).zip(v2).zip(v3) {
            let x1 = e1;
            let x2 = (e2 - x1.value()) * r12;
            let x3 = ((e3 - x1.value()) * r13 - x2.value()) * r23;
            let mut x = GfA::from(x1.value());
            x += GfA::from(x2.value()) * GfB::P;
            x += GfA::from(x3.value()) * GfB::P * GfC::P;
            *e0 = x.value().into();
        }
    }
}

}  // mod conv

}  // mod gf

pub mod stdio {

pub use crate::prtln;
pub use crate::scan;
use std::io::{stdout, BufWriter, StdoutLock};

pub fn stdout_buf() -> BufWriter<StdoutLock<'static>> {
    let out = Box::leak(Box::new(stdout()));
    BufWriter::new(out.lock())
}

#[macro_export]
macro_rules! prtln {
    (@ $dst:expr, iter=$expr:expr) => { $crate::prtln!(@ $dst, iter=$expr, sep=" "); };
    (@ $dst:expr, iter=$expr:expr, sep=$sep:expr) => { {
        let mut iter = $expr.into_iter();
        if let Some(expr) = iter.next() {
            std::write!($dst, "{}", expr).unwrap();
            for expr in iter { std::write!($dst, "{}{}", $sep, expr).unwrap(); }
        }
        $crate::prtln!(@ $dst, "");
    } };
    (@ $dst:expr, $expr:expr, no eol) => { std::write!($dst, "{}", $expr).unwrap(); };
    (@ $dst:expr, $expr:expr) => { std::writeln!($dst, "{}", $expr).unwrap(); };
    (@ $dst:expr, $expr:expr, $($exprs:expr),*) => { {
        std::write!($dst, "{} ", $expr).unwrap();
        $crate::prtln!(@ $dst, $($exprs),*);
    } };
    (new $var:ident $(,)?) => { let mut $var = stdout_buf(); };
    (new $var:ident, $($t:tt)*) => {
        $crate::prtln!(new $var);
        $crate::prtln!(to $var, $($t)*);
    };
    (to $var:ident, $($t:tt)*) => { {
        use std::io::Write;
        $crate::prtln!(@ $var, $($t)*);
    } };
    ($($t:tt)*) => { {
        $crate::prtln!(new __prtln, $($t)*);
        std::mem::drop(__prtln);
    } };
}

#[macro_export]
macro_rules! scan {
    (@ $iter:expr $(,)?) => {};
    (@ $iter:expr, mut $var:ident : $t:tt $($r:tt)*) => {
        #[allow(non_snake_case)]
        let mut $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        #[allow(non_snake_case)]
        let $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $pat:pat in $t:tt $($r:tt)*) => {
        let $pat = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (from $s:expr, $($r:tt)*) => { $crate::scan!(@ $s, $($r)*); };
    (new $var:ident, $($r:tt)*) => {
        let mut __input = String::new();
        std::io::Read::read_to_string(&mut std::io::stdin(), &mut __input).unwrap();
        let $var = &mut __input.split_ascii_whitespace();
        $crate::scan!(@ $var, $($r)*);
    };
    ($($r:tt)*) => { $crate::scan!(new __scan, $($r)*); };
}

#[macro_export]
macro_rules! scan_value {
    ($iter:expr, ( $($t:tt),* )) => { ( $($crate::scan_value!($iter, $t)),* ) };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| $crate::scan_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, bytes) => { $iter.next().unwrap().as_bytes() };
    ($iter:expr, usize1) => { $crate::scan_value!($iter, usize) - 1 };
    ($iter:expr, $t:ty) => { $iter.next().unwrap().parse::<$t>().unwrap() };
}

}  // mod stdio

pub mod zo {

pub trait ZeroOne: Copy + PartialEq {
    const ZERO: Self;
    fn is_zero(self) -> bool {
        self == Self::ZERO
    }
    const ONE: Self;
}

macro_rules! impl_zo {
    ($($t:ty),*) => { $(
        impl ZeroOne for $t {
            const ZERO: Self = 0;
            const ONE: Self = 1;
        }
    )* };
}

impl_zo!(i32, i64, i128, isize, u32, u64, u128, usize);

impl ZeroOne for f64 {
    const ZERO: Self = 0.0;
    const ONE: Self = 1.0;
}

}  // mod zo

}  // mod lib
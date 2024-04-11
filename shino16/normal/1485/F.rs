use crate::lib::stdio::*;
use crate::lib::fp::*;
use std::collections::BTreeMap;

fn main() {
    scan!(new input, t: u32);
    prtln!(new output);
    let mut dp: BTreeMap<i64, F17> = BTreeMap::new();
    for _ in 0..t {
        scan!(from input, n: usize, b: [i64; n]);
        dp.clear();
        dp.insert(0, 1.into());
        let mut b_sum = 0_i64;
        let mut value_sum = 1.into();
        for i in 0..n {
            let r = dp.entry(-b_sum).or_insert(0.into());
            let sum2 = value_sum * 2 - *r;
            *r = value_sum;
            value_sum = sum2;
            b_sum += b[i];
        }
        prtln!(to output, value_sum);
    }
}

/*

A[i] = \sum a[j] over [0, i)

a[i] is either b[i] or b[i] - A[i]

how many times does A[i] == 0 hold?

possible A[i]'s are { B[i] - \sum B[j] for j in S | S is a subset of {0, ..., i - 1} }

dp[i] = dict{ (possible A[i], number of (a)_0^{i-1}'s which achive this) }

for (A, k) in dp[i]:
    if A == 0:
        // a[i] = b[i]
        dp[i + 1][b[i]] += k
    else:
        // a[i] = b[i]
        dp[i + 1][A + b[i]] += k
        // a[i] = b[i] - A
        dp[i + 1][b[i]] += k

<=>

dp[i + 1] = dict{ (A + b[i], k) | (A, k) in dp[i] }
dp[i + 1][b[i]] += sum(k | (A, k) in dp[i], A != 0)


dp2[i] = dict{ (possible A[i] - B[i], number of (a)_0^{i-1}) }

dp[i + 1] = dp[i]
dp[i + 1][-B[i]] += sum(k | (A, k) in dp[i], A != -B[i])
// A[i + 1] == b[i] <=> A[i + 1] - B[i + 1] == b[i] - B[i + 1] == -B[i]

 */



pub mod lib {

pub mod fp {

pub use crate::lib::zo::ZeroOne;
use std::marker::PhantomData;
use std::{cmp, fmt, iter, ops};

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

// modular arithmetics
#[repr(transparent)]
#[derive(Default, Clone, Copy)]
pub struct Fp<M: Mod> {
    val: u32,
    _m: PhantomData<M>,
}

pub type FpA = Fp<ModA>;
pub type FpB = Fp<ModB>;
pub type FpC = Fp<ModC>;
pub type FpD = Fp<ModD>;
pub type F17 = FpA;
pub type F99 = FpB;

impl<M: Mod> Fp<M> {
    pub const P: u32 = M::P;
    pub fn new(val: u32) -> Self { val.into() }
    fn from_raw(val: u32) -> Self { Fp { val, _m: PhantomData } }
    pub fn value(self) -> u32 {
        let v = reduce::<M>(self.val as u64);
        if v >= M::P { v - M::P } else { v }
    }
    pub fn pow(mut self, mut k: u64) -> Self {
        if self.val == 0 && k == 0 {
            return Self::new(1);
        }
        k %= (M::P - 1) as u64;
        let mut res = Self::ONE;
        while !k.is_zero() {
            if k % 2 != 0 { res *= self; }
            self *= self;
            k >>= 1;
        }
        res
    }
    pub fn inv(self) -> Self {
        let (mut a, mut b, mut u, mut v) = (M::P as i32, self.value() as i32, 0, 1);
        while b != 0 {
            let t = a / b;
            a -= t * b;
            u -= t * v;
            std::mem::swap(&mut a, &mut b);
            std::mem::swap(&mut u, &mut v);
        }
        debug_assert_eq!(a, 1);
        if u < 0 {
            debug_assert_eq!(v, M::P as i32);
            u += v;
        }
        Self::new(u as u32)
    }
}

impl<M: Mod> From<u32> for Fp<M> {
    fn from(x: u32) -> Self { Fp::from_raw(reduce::<M>(x as u64 * M::R2 as u64)) }
}

macro_rules! impl_from_int {
    ($($t:ty),*) => { $(
        impl<M: Mod> From<$t> for Fp<M> {
            fn from(x: $t) -> Self {
                Fp::from_raw(reduce::<M>(x.rem_euclid(M::P as _) as u64 * M::R2 as u64))
            }
        }
    )* };
}

impl_from_int!(u64, i32, i64);

impl<M: Mod> cmp::PartialEq for Fp<M> {
    fn eq(&self, other: &Self) -> bool {
        let val = |obj: &Fp<M>| {
            if obj.val >= M::P { obj.val - M::P } else { obj.val }
        };
        val(self) == val(other)
    }
}

impl<M: Mod> cmp::Eq for Fp<M> {}

impl<M: Mod, T: Into<Fp<M>>> ops::AddAssign<T> for Fp<M> {
    fn add_assign(&mut self, rhs: T) {
        self.val += rhs.into().val;
        if self.val >= M::P * 2 { self.val -= M::P * 2; }
    }
}
impl<M: Mod, T: Into<Fp<M>>> ops::SubAssign<T> for Fp<M> {
    fn sub_assign(&mut self, rhs: T) {
        let rhs = rhs.into();
        if self.val < rhs.val { self.val += M::P * 2; }
        self.val -= rhs.val;
    }
}
impl<M: Mod, T: Into<Fp<M>>> ops::MulAssign<T> for Fp<M> {
    fn mul_assign(&mut self, rhs: T) {
        self.val = reduce::<M>(self.val as u64 * rhs.into().val as u64);
    }
}
impl<M: Mod, T: Into<Fp<M>>> ops::DivAssign<T> for Fp<M> {
    fn div_assign(&mut self, rhs: T) { *self *= rhs.into().inv(); }
}

macro_rules! impl_binop {
    ($(($Op:ident, $op:ident, $OpAssign:ident, $op_assign:ident)),*) => { $(
        impl<M: Mod, T: Into<Fp<M>>> ops::$Op<T> for Fp<M> {
            type Output = Self;
            fn $op(mut self, rhs: T) -> Self { ops::$OpAssign::$op_assign(&mut self, rhs); self }
        }
    )* };
}

impl_binop!(
    (Add, add, AddAssign, add_assign),
    (Sub, sub, SubAssign, sub_assign),
    (Mul, mul, MulAssign, mul_assign),
    (Div, div, DivAssign, div_assign)
);

impl<M: Mod> ops::Neg for Fp<M> {
    type Output = Self;
    fn neg(self) -> Self { Fp::from_raw(M::P * 2 - self.val) }
}
impl<M: Mod> iter::Sum for Fp<M> {
    fn sum<I: Iterator<Item = Self>>(iter: I) -> Self { iter.fold(Self::ZERO, |b, x| b + x) }
}
impl<M: Mod> iter::Product for Fp<M> {
    fn product<I: Iterator<Item = Self>>(iter: I) -> Self { iter.fold(Self::ONE, |b, x| b * x) }
}
impl<M: Mod> fmt::Debug for Fp<M> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result { self.value().fmt(f) }
}
impl<M: Mod> fmt::Display for Fp<M> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result { self.value().fmt(f) }
}
impl<M: Mod> ZeroOne for Fp<M> {
    const ZERO: Self = Self { val: 0, _m: PhantomData };
    const ONE: Self = Self { val: M::P.wrapping_neg() % M::P, _m: PhantomData };
}

}  // mod fp

pub mod stdio {

pub use crate::prtln;
pub use crate::scan;
use std::io::{stdout, BufWriter, StdoutLock};

pub fn stdout_buf() -> BufWriter<StdoutLock<'static>> {
    let out = Box::leak(Box::new(stdout()));
    BufWriter::with_capacity(1 << 25, out.lock())
}

#[macro_export]
macro_rules! prtln {
    (@ $dst:expr, iter=$expr:expr) => { $crate::prtln!(@ $dst, iter=$expr, sep=" "); };
    (@ $dst:expr, iter=$expr:expr, sep=$sep:expr) => { {
        let mut iter = $expr.into_iter();
        if let Some(expr) = iter.next() {
            ::std::write!($dst, "{}", expr).unwrap();
            for expr in iter { ::std::write!($dst, "{}{}", $sep, expr).unwrap(); }
        }
        $crate::prtln!(@ $dst, "");
    } };
    (@ $dst:expr, $expr:expr) => { ::std::writeln!($dst, "{}", $expr).unwrap(); };
    (@ $dst:expr, $expr:expr, $($exprs:expr),*) => { {
        ::std::write!($dst, "{} ", $expr).unwrap();
        $crate::prtln!(@ $dst, $($exprs),*);
    } };
    (new $var:ident) => { let mut $var = stdout_buf(); };
    (new $var:ident, $($t:tt)*) => { {
        $crate::prtln!(new $var);
        $crate::prtln!(to $var, $($t)*);
    } };
    (to $var:ident, $($t:tt)*) => { {
        use std::io::Write;
        $crate::prtln!(@ $var, $($t)*);
    } };
    ($($t:tt)*) => { $crate::prtln!(new __prtln, $($t)*); };
}

#[macro_export]
macro_rules! scan {
    (@ $iter:expr $(,)?) => {};
    (@ $iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $pat:pat in $t:tt $($r:tt)*) => {
        let $pat = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (from $s:expr, $($r:tt)*) => { $crate::scan!(@ $s, $($r)*); };
    (new $var:ident, $($r:tt)*) => {
        let s = {
            use ::std::io::Read;
            let mut s = String::new();
            ::std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let $var = &mut s.split_whitespace();
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
    ($iter:expr, bytes) => { $iter.next().as_bytes() };
    ($iter:expr, usize1) => { $crate::scan_value!($iter, usize) - 1 };
    ($iter:expr, $t:ty) => { $iter.next().unwrap().parse::<$t>().unwrap() };
}

}  // mod stdio

pub mod zo {

pub trait ZeroOne: Copy + Eq {
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

}  // mod zo

}  // mod lib
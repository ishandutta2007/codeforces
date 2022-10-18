use crate::lib::stdio::*;
use crate::lib::gf::Gf99 as Int;

fn main() {
    scan!(n: usize);

    let mut lpf: Vec<_> = (0..=n).collect();
    for i in 2..=n {
        if lpf[i] == i {
            for j in (i..=n).step_by(i) {
                lpf[j] = lpf[j].min(i);
            }
        }
    }
    let d = |mut n: usize| {
        let mut now = 0;
        let mut cnt = 0;
        let mut ans = 1;
        while n != 1 {
            if now != lpf[n] {
                ans *= cnt + 1;
                cnt = 0;
                now = lpf[n];
            }
            cnt += 1;
            n /= now;
        }
        ans *= cnt + 1;
        ans
    };
    let mut sum = Int::one();
    let mut now = Int::zero();
    for n in 1..=n {
        now = sum + d(n) - 1;
        sum += now;
    }
    prtln!(now);
}


pub mod lib {

pub mod gf {

// modular arithmetics

use crate::lib::zo::ZeroOne;
use std::marker::PhantomData;
use std::{cmp, fmt, iter, ops::*, str};

pub trait Mod: Default + Clone + Copy {
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
    _m: PhantomData<*const M>,
}

pub type GfA = Gf<ModA>;
pub type GfB = Gf<ModB>;
pub type GfC = Gf<ModC>;
pub type GfD = Gf<ModD>;
pub type Gf17 = GfA;
pub type Gf99 = GfB;

impl<M: Mod> Gf<M> {
    pub const P: u32 = M::P;
    pub fn zero() -> Self { ZeroOne::zero() }
    pub fn one() -> Self { ZeroOne::one() }
    pub fn new(val: u32) -> Self { val.into() }
    pub fn is_zero(&self) -> bool { *self == Self::zero() }
    fn from_raw(val: u32) -> Self { Gf { val, _m: PhantomData } }
    pub fn value(self) -> u32 {
        let v = reduce::<M>(self.val as u64);
        if v >= M::P { v - M::P } else { v }
    }
    pub fn pow(mut self, mut k: u64) -> Self {
        if self.val == 0 && k == 0 { return Self::new(1); }
        k %= (M::P - 1) as u64;
        let mut res = Self::one();
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
    fn sum<I: Iterator<Item = Self>>(iter: I) -> Self { iter.fold(Self::zero(), |b, x| b + x) }
}
impl<M: Mod> iter::Product for Gf<M> {
    fn product<I: Iterator<Item = Self>>(iter: I) -> Self { iter.fold(Self::one(), |b, x| b * x) }
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
    fn zero() -> Self { Self { val: 0, _m: PhantomData } }
    fn one() -> Self { Self { val: M::P.wrapping_neg() % M::P, _m: PhantomData } }
}

}  // mod gf

pub mod stdio {

pub use crate::prtln;
pub use crate::scan;
pub use crate::parse;
pub use  std::io::Write;
use std::io::{stdout, BufWriter, StdoutLock};

pub fn stdout_buf() -> BufWriter<StdoutLock<'static>> {
    let out = Box::leak(Box::new(stdout()));
    BufWriter::new(out.lock())
}

#[macro_export]
macro_rules! prtln {
    (@ $dst:expr, iter=$v:expr) => { $crate::prtln!(@ $dst, iter=$v, sep=" "); };
    (@ $dst:expr, iter=$v:expr, sep=$sep:expr) => { {
        let mut iter = $v.into_iter();
        if let Some(expr) = iter.next() {
            std::write!($dst, "{}", expr).unwrap();
            for v in iter { std::write!($dst, "{}{}", $sep, v).unwrap(); }
        }
        $crate::prtln!(@ $dst, "");
    } };
    (@ $dst:expr, bytes=$v:expr) => {
        $crate::prtln!(@ $dst, std::str::from_utf8(&$v).unwrap());
    };
    (@ $dst:expr, YesNo=$v:expr) => { $crate::prtln!(@ $dst, if $v { "Yes" } else { "No" }); };
    (@ $dst:expr, YESNO=$v:expr) => { $crate::prtln!(@ $dst, if $v { "YES" } else { "NO" }); };
    (@ $dst:expr, $v:expr, no eol) => { std::write!($dst, "{}", $v).unwrap(); };
    (@ $dst:expr, $v:expr) => { std::writeln!($dst, "{}", $v).unwrap(); };
    (@ $dst:expr, $v:expr, $($t:tt)*) => { {
        std::write!($dst, "{} ", $v).unwrap();
        $crate::prtln!(@ $dst, $($t)*);
    } };
    (new $var:ident $(,)?) => { let mut $var = stdout_buf(); };
    (new $var:ident, $($t:tt)*) => {
        $crate::prtln!(new $var);
        $crate::prtln!(to $var, $($t)*);
    };
    (to $var:ident, $($t:tt)*) => { {
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
        let mut $var = $crate::parse!($iter.into_iter(), $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        #[allow(non_snake_case)]
        let $var = $crate::parse!($iter.into_iter(), $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $pat:pat in $t:tt $($r:tt)*) => {
        let $pat = $crate::parse!($iter.into_iter(), $t);
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
macro_rules! parse {
    ($iter:expr, ( $($t:tt),* )) => { ( $($crate::parse!($iter, $t)),* ) };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| $crate::parse!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, bytes) => { $iter.next().expect("no input").as_bytes() };
    ($iter:expr, [u8]) => { $iter.next().expect("no input").as_bytes().to_vec() };
    ($iter:expr, [char]) => { $iter.next().expect("no input").chars().collect::<Vec<_>>() };
    ($iter:expr, usize1) => { $crate::parse!($iter, usize) - 1 };
    (@graph $iter:expr, $n:expr, $m:expr) => { {
        let mut graph = vec![Vec::new(); $n];
        for _ in 0..$m {
            let (a, b) = $crate::parse!($iter, (usize1, usize1));
            graph[a].push(b);
            graph[b].push(a);
        }
        ($n, graph)
    } };
    ($iter:expr, graph) => { {
        let (n, m) = $crate::parse!($iter, (usize, usize));
        $crate::parse!(@graph $iter, n, m)
    } };
    ($iter:expr, tree) => { {
        let n = $crate::parse!($iter, usize);
        $crate::parse!(@graph $iter, n, n - 1)
    } };
    ($iter:expr, $t:ty) => { $iter.next().expect("no input").parse::<$t>().expect("parse error") };
    ($iter:expr) => { $iter.next().expect("no input").parse().expect("parse error") };
}

}  // mod stdio

pub mod zo {

pub trait ZeroOne: Copy + PartialEq {
    fn zero() -> Self;
    fn one() -> Self;
    fn is_zero(self) -> bool { self == Self::zero() }
}

macro_rules! impl_zo {
    ($($t:ty),*) => { $(
        impl ZeroOne for $t {
            fn zero() -> Self { 0 as $t }
            fn one() -> Self { 1 as $t }
        }
    )* };
}

impl_zo!(i32, i64, i128, isize, u32, u64, u128, usize, f32, f64);

}  // mod zo

}  // mod lib
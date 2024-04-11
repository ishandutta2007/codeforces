use std::collections::VecDeque;
use crate::lib::stdio::*;
// use lib::fp::*;
// type Int = F99;

use crate::lib::mint::*;
type Int = Mint99;

fn main() {
    prtln!(new cout);
    scan!(new cin, n: usize, m: usize, uv: [(usize1, usize1); m]);
    let mut graph = vec![Vec::new(); n];
    for (i, &(u, v)) in uv.iter().enumerate() {
        graph[u].push((v, i * 2));
        graph[v].push((u, i * 2 + 1));
    }
    let mut dists = Vec::new();
    let mut counts = Vec::new();
    let mut bfs = VecDeque::new();
    for s in 0..n {
        let mut dist = vec![std::i32::MAX; n];
        let mut count = vec![Int::ZERO; n];
        dist[s] = 0;
        count[s] += 1;
        bfs.push_back(s);
        while let Some(v) = bfs.pop_front() {
            for &(to, _) in &graph[v] {
                if dist[to] > dist[v] + 1 {
                    dist[to] = dist[v] + 1;
                    let val = count[v];
                    count[to] += val;
                    bfs.push_back(to);
                } else if dist[to] == dist[v] + 1 {
                    let val = count[v];
                    count[to] += val;
                }
            }
        }
        dists.push(dist);
        counts.push(count);
    }
    let mut ress = vec![vec![None; n]; n];
    let mut used = vec![false; m * 2];
    let mut prev = vec![!0; n];
    let mut ignore = vec![false; n];
    for i in 0..n {
        let di = &dists[i];
        let iter = (0..n).map(|j| {
            if counts[i][j] != Int::ONE {
                return Int::ZERO;
            }
            if let Some(res) = ress[j][i] {
                return res;
            }
            let dj = &dists[j];
            prev[i] = !0;
            used.iter_mut().for_each(|e| *e = false);
            let mut res = Int::ONE;
            for v in 0..n {
                for &(to, i) in &graph[v] {
                    if di[to] + 1 == di[v] {
                        prev[v] = to;
                        used[i] = true;
                    }
                }
            }
            ignore.iter_mut().for_each(|e| *e = false);
            let mut v = j;
            while v != i {
                ignore[v] = true;
                v = prev[v];
            }
            ignore[v] = true;
            for v in 0..n {
                if ignore[v] {
                    continue;
                }
                let mut cnt = 0;
                for &(to, ei) in &graph[v] {
                    if dj[to] + 1 == dj[v] && used[ei] {
                        cnt += 1;
                    }
                }
                res *= cnt;
            }
            ress[i][j] = Some(res);
            res
        });
        prtln!(to cout, iter=iter);
    }
}



pub mod lib {

pub mod mint {

pub use crate::def_mod;
pub use crate::lib::zo::ZeroOne;
use std::marker::PhantomData;
use std::{fmt, iter, ops};

pub trait Mod: Default + Clone + Copy + PartialEq + Eq {
    const M: u32;
    const PHI: u32;
}

#[macro_export]
macro_rules! def_mod {
    ($name:ident, $modulus:expr) => {
        def_mod!($name, $modulus, $modulus - 1);
    };
    ($name:ident, $modulus:expr, $phi:expr) => {
        #[derive(Default, Clone, Copy, PartialEq, Eq, Debug)]
        pub struct $name;
        impl Mod for $name {
            const M: u32 = $modulus;
            const PHI: u32 = $phi;
        }
    };
}

def_mod!(ModA, 1_000_000_007);
def_mod!(ModB, 998_244_353);
def_mod!(ModC, 1_012_924_417);
def_mod!(ModD, 924_844_033);

#[derive(Default, Clone, Copy, PartialEq, Eq)]
pub struct Mint<M: Mod> {
    pub val: u32,
    _m: PhantomData<M>,
}

pub type MintA = Mint<ModA>;
pub type MintB = Mint<ModB>;
pub type MintC = Mint<ModC>;
pub type MintD = Mint<ModD>;
pub type Mint17 = MintA;
pub type Mint99 = MintB;

impl<M: Mod> Mint<M> {
    pub const M: u32 = M::M;
    pub fn new(val: i64) -> Self { Self::from_val(val.rem_euclid(M::M as i64) as u32) }
    pub fn from_val(val: u32) -> Self { Mint { val, _m: PhantomData } }
    pub fn value(self) -> u32 { self.val }
    pub fn pow(self, mut exp: u32) -> Self {
        if self.val == 0 && exp == 0 {
            return Self::from_val(1);
        }
        let mut b = self;
        let mut res = Self::from_val(1);
        while exp != 0 {
            if exp % 2 == 1 { res *= b; }
            b *= b;
            exp >>= 1;
        }
        res
    }
    pub fn inv(self) -> Self { self.pow(M::PHI - 1) }
    pub fn modulus() -> u32 { M::M }
}

macro_rules! impl_from_int {
    ($(($t:ty: $via:ty)),* $(,)?) => { $(
        impl<M: Mod> From<$t> for Mint<M> {
            fn from(x: $t) -> Self { Self::from_val((x as $via).rem_euclid(M::M as $via) as u32) }
        }
    )* };
}
impl_from_int! {
    (i8: i32), (i16: i32), (i32: i32), (i64: i64), (isize: i64),
    (u8: u32), (u16: u32), (u32: u32), (u64: u64), (usize: u64),
}

impl<M: Mod, T: Into<Mint<M>>> ops::Add<T> for Mint<M> {
    type Output = Self;
    fn add(mut self, rhs: T) -> Self { self += rhs; self }
}
impl<M: Mod, T: Into<Mint<M>>> ops::AddAssign<T> for Mint<M> {
    fn add_assign(&mut self, rhs: T) {
        self.val += rhs.into().val;
        if self.val >= M::M { self.val -= M::M; }
    }
}
impl<M: Mod> ops::Neg for Mint<M> {
    type Output = Self;
    fn neg(self) -> Self { Mint::from_val(if self.val == 0 { 0 } else { M::M - self.val }) }
}
impl<M: Mod, T: Into<Mint<M>>> ops::Sub<T> for Mint<M> {
    type Output = Self;
    fn sub(mut self, rhs: T) -> Self { self -= rhs; self }
}
impl<M: Mod, T: Into<Mint<M>>> ops::SubAssign<T> for Mint<M> {
    fn sub_assign(&mut self, rhs: T) {
        let rhs = rhs.into();
        if self.val < rhs.val { self.val += M::M; }
        self.val -= rhs.val;
    }
}
impl<M: Mod, T: Into<Mint<M>>> ops::Mul<T> for Mint<M> {
    type Output = Self;
    fn mul(self, rhs: T) -> Self {
        let val = self.val as u64 * rhs.into().val as u64 % M::M as u64;
        Self::from_val(val as u32)
    }
}
impl<M: Mod, T: Into<Mint<M>>> ops::MulAssign<T> for Mint<M> {
    fn mul_assign(&mut self, rhs: T) { *self = *self * rhs; }
}
impl<M: Mod, T: Into<Mint<M>>> ops::Div<T> for Mint<M> {
    type Output = Self;
    fn div(mut self, rhs: T) -> Self { self /= rhs; self }
}
impl<M: Mod, T: Into<Mint<M>>> ops::DivAssign<T> for Mint<M> {
    fn div_assign(&mut self, rhs: T) { *self *= rhs.into().pow(M::PHI - 1); }
}
impl<M: Mod> iter::Sum for Mint<M> {
    fn sum<I: Iterator<Item = Self>>(iter: I) -> Self { iter.fold(Self::from_val(0), |b, x| b + x) }
}
impl<M: Mod> iter::Product for Mint<M> {
    fn product<I: Iterator<Item = Self>>(iter: I) -> Self {
        iter.fold(Self::from_val(1), |b, x| b * x)
    }
}
impl<M: Mod> fmt::Debug for Mint<M> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result { self.val.fmt(f) }
}
impl<M: Mod> fmt::Display for Mint<M> {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result { self.val.fmt(f) }
}
impl<M: Mod> ZeroOne for Mint<M> {
    const ZERO: Self = Self { val: 0, _m: PhantomData };
    const ONE: Self = Self { val: 1, _m: PhantomData };
}

}  // mod mint

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
            std::write!($dst, "{}", expr).unwrap();
            for expr in iter { std::write!($dst, "{}{}", $sep, expr).unwrap(); }
        }
        $crate::prtln!(@ $dst, "");
    } };
    (@ $dst:expr, $expr:expr) => { std::writeln!($dst, "{}", $expr).unwrap(); };
    (@ $dst:expr, $expr:expr, $($exprs:expr),*) => { {
        std::write!($dst, "{} ", $expr).unwrap();
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
    (@ $iter:expr, mut $var:ident : $t:tt $($r:tt)*) => {
        let mut $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
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
    ($iter:expr, [u8]) => { $iter.next().unwrap().as_bytes() };
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
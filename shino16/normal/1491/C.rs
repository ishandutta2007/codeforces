use crate::lib::stdio::*;
use crate::lib::ds::fenwick::*;

fn main() {
    scan!(new input, t: u32);
    prtln!(new output);
    let mut fwk = FenwickTree::new(vec![0_usize; 5005], Addition());
    for _ in 0..t {
        fwk.clear();
        scan!(from input, n: usize, s: [usize; n]);
        let mut ans = 0_u64;
        for i in 0..n {
            let count = fwk.ask_prefix(i + 1);
            let rest = (s[i] - 1).saturating_sub(count);
            ans += rest as u64;
            fwk.add(i + 2, 1);
            let j = i + s[i] + 1;
            if j < fwk.len() {
                fwk.sub(j, 1);
            }
            let d = count.saturating_sub(s[i] - 1);
            fwk.add(i + 1, d);
            fwk.sub(i + 2, d);
        }
        prtln!(to output, ans);
    }
}



pub mod lib {

pub mod alg {

// basic algebraic structures

pub trait Monoid<T: Copy> {
    fn unit(&self) -> T;
    fn op(&self, x: T, y: T) -> T;
    fn op_to(&self, y: T, x: &mut T) { *x = self.op(*x, y); }
}

pub trait Group<T: Copy>: Monoid<T> {
    fn inv(&self, x: T) -> T;
    fn op_inv_to(&self, y: T, x: &mut T) { *x = self.op(*x, self.inv(y)) }
}

pub struct MonoidImpl<T: Copy, Unit: Fn() -> T, Op: Fn(T, T) -> T>(pub Unit, pub Op);

pub struct GroupImpl<T: Copy, Unit: Fn() -> T, Op: Fn(T, T) -> T, Inv>(pub Unit, pub Op, pub Inv)
where
    Inv: Fn(T) -> T;

impl<T: Copy, Unit: Fn() -> T, Op: Fn(T, T) -> T> Monoid<T> for MonoidImpl<T, Unit, Op> {
    fn unit(&self) -> T { (self.0)() }
    fn op(&self, x: T, y: T) -> T { (self.1)(x, y) }
}

impl<T: Copy, Unit: Fn() -> T, Op: Fn(T, T) -> T, Inv> Monoid<T> for GroupImpl<T, Unit, Op, Inv>
where
    Inv: Fn(T) -> T,
{
    fn unit(&self) -> T { (self.0)() }
    fn op(&self, x: T, y: T) -> T { (self.1)(x, y) }
}

impl<T: Copy, Unit: Fn() -> T, Op: Fn(T, T) -> T, Inv> Group<T> for GroupImpl<T, Unit, Op, Inv>
where
    Inv: Fn(T) -> T,
{
    fn inv(&self, x: T) -> T { (self.2)(x) }
}

pub mod arith {

pub use super::*;
pub use crate::lib::num::*;

#[derive(Default, Clone, Copy)]
pub struct Addition();

macro_rules! impl_alg {
    ($($t:ty),*) => { $(
        impl Monoid<$t> for Addition {
            fn unit(&self) -> $t { 0 }
            fn op(&self, x: $t, y: $t) -> $t { x.wrapping_add(y) }
        }
        impl Group<$t> for Addition {
            fn inv(&self, x: $t) -> $t { x.wrapping_neg() }
        }
    )* };
}

impl_alg!(i8, i16, i32, i64, isize, u8, u16, u32, u64, usize);

}  // mod arith

}  // mod alg

pub mod ds {

pub mod fenwick {

pub use crate::lib::alg::arith::*;

#[derive(Clone)]
pub struct FenwickTree<T, M> {
    data: Vec<T>,
    alg: M,
}

impl<T: Copy, M: Monoid<T>> FenwickTree<T, M> {
    pub fn new(mut data: Vec<T>, alg: M) -> Self {
        let len = data.len();
        data.insert(0, alg.unit());
        for i in 1..=len {
            if i + lsb(i) <= len {
                data[i + lsb(i)] = alg.op(data[i + lsb(i)], data[i]);
            }
        }
        Self { data, alg }
    }
    pub fn len(&self) -> usize {
        self.data.len() - 1
    }
    pub fn clear(&mut self) {
        for e in &mut self.data {
            *e = self.alg.unit();
        }
    }
    pub fn add(&mut self, pos: usize, v: T) {
        let mut pos = pos + 1;
        while pos < self.data.len() {
            self.data[pos] = self.alg.op(self.data[pos], v);
            pos += lsb(pos);
        }
    }
    pub fn push(&mut self, v: T) {
        self.data.push(self.alg.unit());
        self.add(self.data.len() - 1, v);
    }
    pub fn ask_prefix(&self, mut r: usize) -> T {
        let mut res = self.alg.unit();
        while r != 0 {
            res = self.alg.op(self.data[r], res);
            r -= lsb(r);
        }
        res
    }
    pub fn partition_point<F: FnMut(T) -> bool>(&self, mut pred: F) -> usize {
        let mut x = 0; // pred(&self.ask_prefix(x)) == true
        let mut w = self.data.len().next_power_of_two() >> 1;
        let mut l = self.alg.unit();
        while w != 0 {
            if x + w < self.data.len() && pred(self.alg.op(l, self.data[x + w])) {
                x += w;
                l = self.alg.op(l, self.data[x + w]);
            }
            w >>= 1;
        }
        x + 1
    }
    pub fn lower_bound(&self, v: T) -> usize
    where
        T: Ord,
    {
        self.partition_point(|x| x < v)
    }
    pub fn upper_bound(&self, v: T) -> usize
    where
        T: Ord,
    {
        self.partition_point(|x| x <= v)
    }
}

impl<T: Copy, M: Group<T>> FenwickTree<T, M> {
    pub fn sub(&mut self, pos: usize, v: T) {
        self.add(pos, self.alg.inv(v));
    }
    pub fn ask(&self, l: usize, r: usize) -> T {
        self.alg.op(self.alg.inv(self.ask_prefix(l)), self.ask_prefix(r))
    }
}

fn lsb(n: usize) -> usize {
    n & (!n + 1)
}

}  // mod fenwick

}  // mod ds

pub mod num {

use crate::lib::util::trait_alias::*;
pub use crate::lib::zo::ZeroOne;
use std::fmt::*;
use std::ops::*;

trait_alias!(pub trait Num =
    ZeroOne
    + Add<Output = Self> + AddAssign
    + Sub<Output = Self> + SubAssign
    + Mul<Output = Self> + MulAssign
    + Div<Output = Self> + DivAssign
    + Debug
    + Display);

trait_alias!(pub trait INum = Num + Neg<Output = Self>);

}  // mod num

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

pub mod util {

pub mod trait_alias {

pub use crate::trait_alias;

#[macro_export]
macro_rules! trait_alias {
    (pub trait $ident:ident = $($t:tt)*) => {
        pub trait $ident: $($t)* {}
        impl<T: $($t)*> $ident for T {}
    };
}

}  // mod trait_alias

}  // mod util

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
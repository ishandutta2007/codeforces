use crate::lib::io::*;
use crate::lib::int::gcd::*;

fn main() {
	std::thread::spawn(|| {
		let mut io = IO::new();
		let (n, m) = io.scan();
		let a = io.scan_vec::<i64>(n);
		let b = io.scan_vec::<i64>(m);
		let mut g = 0;
		for (&a, &b) in a.iter().skip(1).zip(&a).skip(1) {
			g = gcd(g, (a - b).abs());
		}
		for b in b {
			io.println(gcd(a[0] + b, g));
		}
	}).join().unwrap();
}




pub mod lib {

pub mod bit {

use std::ops::*;

pub trait Bits:
	Sized
	+ BitAnd<Output = Self> + BitAndAssign
	+ BitOr<Output = Self> + BitOrAssign
	+ BitXor<Output = Self> + BitXorAssign
	+ Shl<u32, Output = Self> + ShlAssign<u32>
	+ Shr<u32, Output = Self> + ShrAssign<u32>
	+ Not<Output = Self>
{
	fn trailing_zeros(self) -> u32;
	fn lsb(self) -> Self;
	fn ilog2(self) -> u32;
	fn msb(self) -> Self;
}

macro_rules! impl_bit {
	($($t:ty), *) => { $(
		impl Bits for $t {
			fn trailing_zeros(self) -> u32 {
				<$t>::trailing_zeros(self)
			}
			fn lsb(self) -> Self {
				self & self.wrapping_neg()
			}
			fn ilog2(self) -> u32 {
				std::mem::size_of::<$t>() as u32 * 8 - self.leading_zeros() - 1
			}
			fn msb(self) -> Self {
				(1 as $t) << self.ilog2()
			}
		}
	)* };
}

impl_bit!(i32, i64, i128, isize, u32, u64, u128, usize);

}  // mod bit

pub mod bounded {

pub trait Bounded: Ord {
	const MIN: Self;
	const MAX: Self;
}

macro_rules! impl_bound {
	($($t:ident),*) => { $(
		impl Bounded for $t {
			const MIN: Self = std::$t::MIN;
			const MAX: Self = std::$t::MAX;
		}
	)* };
}

impl_bound!(i32, i64, i128, isize, u32, u64, u128, usize);

}  // mod bounded

pub mod cast {

pub trait CastTo<T> {
	fn cast_to(self) -> T;
}
pub trait CastFrom<T> {
	fn cast_from(src: T) -> Self;
}

impl<T, U: CastTo<T>> CastFrom<U> for T {
	fn cast_from(src: U) -> Self {
		U::cast_to(src)
	}
}

macro_rules! impl_prim {
	($($ts:ty),*) => {
		impl_asint!({ $($ts),* } => { $($ts),* });
		pub trait PrimCast where $(Self: CastTo<$ts>),*, $(Self: CastFrom<$ts>),* {}
		$( impl PrimCast for $ts {} )*
	}
}

macro_rules! impl_asint {
	({ $t:ty } => { $($us:ty),* }) => { $(
		impl CastTo<$us> for $t {
			fn cast_to(self) -> $us {
				self as $us
			}
		}
	)* };
	({ $t:ty, $($ts:ty),* } => { $($us:ty),* }) => {
		impl_asint!({ $t } => { $($us),* });
		impl_asint!({ $($ts),* } => { $($us),* });
	};
}

impl_prim!(i32, i64, i128, isize, u32, u64, u128, usize, f32, f64);

pub trait As: Sized {
	fn as_<T: CastFrom<Self>>(self) -> T {
		T::cast_from(self)
	}
	fn into_<T: From<Self>>(self) -> T {
		T::from(self)
	}
}

impl<T> As for T {}

}  // mod cast

pub mod int {

use crate::lib::bit::*;
pub use crate::lib::bounded::*;
use crate::lib::cast::*;
pub use crate::lib::num::*;
pub use crate::lib::zo::*;
use std::ops::*;


pub trait Int: Num + Ord + Rem<Output = Self> + RemAssign + Bounded + Bits + PrimCast {
	type Signed: IInt + CastFrom<Self> + CastTo<Self>;
	type Unsigned: UInt + CastFrom<Self> + CastTo<Self>;
	fn abs(self) -> Self::Unsigned;
	fn rem_euclid(self, rhs: Self::Unsigned) -> Self::Unsigned;
}

pub trait IInt: Int + INum {}
pub trait UInt: Int {}

macro_rules! impl_int {
	(@ $t:ident, $i:ident, $u:ident, $abs:expr) => {
		impl Int for $t {
			type Signed = $i;
			type Unsigned = $u;
			fn abs(self) -> Self::Unsigned {
				$abs(self) as $u
			}
			fn rem_euclid(self, rhs: Self::Unsigned) -> Self::Unsigned {
				<$t>::rem_euclid(self, rhs as $t) as $u
			}
		}
	};
	({ $i:ident }, { $u:ident }) => {
		impl_int!(@ $i, $i, $u, |x| <$i>::abs(x));
		impl_int!(@ $u, $i, $u, |x| x);
		impl IInt for $i {}
		impl UInt for $u {}
	};
	({ $i:ident, $($is:ident),* }, { $u:ident, $($us:ident),* }) => {
		impl_int!({ $i }, { $u });
		impl_int!({ $($is),* }, { $($us),* });
	}
}

impl_int!({ i32, i64, i128, isize }, { u32, u64, u128, usize });

pub mod gcd {

use super::*;

pub fn gcd<I: Int>(a: I, b: I) -> I {
	ugcd(a.abs(), b.abs()).as_()
}

// binary gcd
pub fn ugcd<I: UInt>(a: I, b: I) -> I {
	#[target_feature(enable = "bmi1")]
	unsafe fn ugcd_impl<I: UInt>(mut a: I, mut b: I) -> I {
		if a.is_zero() {
			return b;
		} else if b.is_zero() {
			return a;
		}
		let a_shift = a.trailing_zeros();
		a >>= a_shift;
		let b_shift = b.trailing_zeros();
		b >>= b_shift;
		while a != b {
			if a > b {
				std::mem::swap(&mut a, &mut b);
			}
			b -= a;
			b >>= b.trailing_zeros();
		}
		a << a_shift.min(b_shift)
	}
	unsafe {
		ugcd_impl(a, b)
	}
}

/// (x, y, g) where ax + by = g, x >= 0
pub fn extgcd<I: IInt>(mut a: I, mut b: I) -> (I, I, I) {
	// A = [a, x, y; b, u, v], k = [-1; a0; b0]
	// A'= [a, x, y; 0, u, v] \therefore a0*u + b0*v = 0
	let (mut x, mut y, mut u, mut v) = (I::ONE, I::ZERO, I::ZERO, I::ONE);
	while !b.is_zero() {
		let t = a / b;
		a -= t * b;
		x -= t * u;
		y -= t * v;
		std::mem::swap(&mut a, &mut b);
		std::mem::swap(&mut x, &mut u);
		std::mem::swap(&mut y, &mut v);
	}
	if x < I::ZERO {
		x += u;
		y -= v;
		debug_assert_eq!(gcd(u, v), I::ONE);
		debug_assert!(x + u >= I::ZERO);
	}
	(x, y, a)
}

}  // mod gcd

}  // mod int

pub mod io {

use std::io::{stdout, BufWriter, Read, StdoutLock, Write};
use std::marker::PhantomData;

pub type Bytes = &'static [u8];

pub struct IO {
	iter: std::str::SplitAsciiWhitespace<'static>,
	buf: BufWriter<StdoutLock<'static>>,
}
impl IO {
	pub fn new() -> Self {
		let mut input = String::new();
		std::io::stdin().read_to_string(&mut input).unwrap();
		let input = Box::leak(input.into_boxed_str());
		let out = Box::leak(Box::new(stdout()));
		IO {
			iter: input.split_ascii_whitespace(),
			buf: BufWriter::new(out.lock()),
		}
	}
	fn scan_str(&mut self) -> &'static str { self.iter.next().unwrap() }
	fn scan_raw(&mut self) -> Bytes { self.scan_str().as_bytes() }
	pub fn scan<T: Scan>(&mut self) -> T { T::scan(self) }
	pub fn scan_iter<T: Scan>(&mut self, n: usize) -> std::iter::Take<Iter<'_, T>> {
		Iter { io: self, _m: PhantomData }.take(n)
	}
	pub fn scan_vec<T: Scan>(&mut self, n: usize) -> Vec<T> {
		(0..n).map(|_| self.scan()).collect()
	}
	pub fn print<T: Print>(&mut self, x: T) { T::print(self, x); }
	pub fn println<T: Print>(&mut self, x: T) {
		self.print(x);
		self.print("\n");
	}
	pub fn iterln<T: Print, I: IntoIterator<Item = T>>(&mut self, into_iter: I, delim: &str) {
		let mut iter = into_iter.into_iter();
		if let Some(v) = iter.next() {
			self.print(v);
			for v in iter {
				self.print(delim);
				self.print(v);
			}
		}
		self.print("\n");
	}
	pub fn flush(&mut self) { self.buf.flush().unwrap(); }
}
pub struct Iter<'a, T> {
	io: &'a mut IO,
	_m: PhantomData<T>,
}
impl<T: Scan> Iterator for Iter<'_, T> {
	type Item = T;
	fn next(&mut self) -> Option<Self::Item> { Some(self.io.scan()) }
}
pub trait Scan {
	fn scan(io: &mut IO) -> Self;
}
pub trait Print {
	fn print(w: &mut IO, x: Self);
}
macro_rules! impl_parse_iint {
	($($t:ty),*) => { $(
		impl Scan for $t {
			fn scan(s: &mut IO) -> Self {
				let scan = |t: &[u8]| t.iter().fold(0, |s, &b| s * 10 + (b & 0x0F) as $t);
				let s = s.scan_raw();
				if let Some((&b'-', t)) = s.split_first() { -scan(t) } else { scan(s) }
			}
		}
	)* };
}
macro_rules! impl_parse_uint {
	($($t:ty),*) => { $(
		impl Scan for $t {
			fn scan(s: &mut IO) -> Self {
				s.scan_raw().iter().fold(0, |s, &b| s * 10 + (b & 0x0F) as $t)
			}
		}
	)* };
}
impl_parse_iint!(i32, i64, i128, isize);
impl_parse_uint!(u32, u64, u128, usize);
impl Scan for u8 {
	fn scan(s: &mut IO) -> Self {
		let bytes = s.scan_raw();
		debug_assert_eq!(bytes.len(), 1);
		bytes[0]
	}
}
impl Scan for Bytes {
	fn scan(s: &mut IO) -> Self { s.scan_raw() }
}
impl Scan for Vec<u8> {
	fn scan(s: &mut IO) -> Self { s.scan_raw().to_vec() }
}
macro_rules! impl_tuple {
	() => {};
	($t:ident $($ts:ident)*) => {
		impl<$t: Scan, $($ts: Scan),*> Scan for ($t, $($ts),*) {
			fn scan(s: &mut IO) -> Self { ($t::scan(s), $($ts::scan(s)),*) }
		}
		impl<$t: Print, $($ts: Print),*> Print for ($t, $($ts),*) {
			#[allow(non_snake_case)]
			fn print(w: &mut IO, ($t, $($ts),*): Self) {
				w.print($t);
				$( w.print(" "); w.print($ts); )*
			}
		}
		impl_tuple!($($ts)*);
	};
}
impl_tuple!(A B C D E F G);
macro_rules! impl_scan_array {
	() => {};
	($n:literal $($ns:literal)*) => {
		impl<T: Scan> Scan for [T; $n] {
			fn scan(s: &mut IO) -> Self {
				let mut scan = |_| T::scan(s);
				[scan($n), $(scan($ns)),*]
			}
		}
		// use IO::iterln to print [T; N]
		impl_scan_array!($($ns)*);
	};
}
impl_scan_array!(7 6 5 4 3 2 1);
macro_rules! impl_print_prim {
	($($t:ty),*) => { $(
		impl Print for $t {
			fn print(w: &mut IO, x: Self) {
				w.buf.write_all(format!("{:.10}", x).as_bytes()).unwrap();
			}
		}
		impl Print for &$t {
			fn print(w: &mut IO, x: Self) { w.print(*x); }
		}
	)* };
}
impl_print_prim!(i32, i64, i128, isize, u32, u64, u128, usize, f32, f64);
impl Print for u8 {
	fn print(w: &mut IO, x: Self) { w.buf.write_all(&[x]).unwrap(); }
}
impl Print for &[u8] {
	fn print(w: &mut IO, x: Self) { w.buf.write_all(x).unwrap(); }
}
impl Print for Vec<u8> {
	fn print(w: &mut IO, x: Self) { w.buf.write_all(&x).unwrap(); }
}
impl Print for &str {
	fn print(w: &mut IO, x: Self) { w.print(x.as_bytes()); }
}
#[derive(Debug, Clone, Copy, Default)]
pub struct Usize1(pub usize);
impl Scan for Usize1 {
	fn scan(io: &mut IO) -> Self {
		let n: usize = io.scan();
		Self(n - 1)
	}
}
impl Print for Usize1 {
	fn print(w: &mut IO, x: Self) { w.print(x.0 + 1) }
}

impl Scan for f64 {
    fn scan(io: &mut IO) -> Self {
        io.scan_str().parse().unwrap()
    }
}

}  // mod io

pub mod num {

pub use crate::lib::zo::ZeroOne;
use std::fmt::*;
use std::ops::*;

pub trait Num:
	ZeroOne
	+ Add<Output = Self>
	+ AddAssign
	+ Sub<Output = Self>
	+ SubAssign
	+ Mul<Output = Self>
	+ MulAssign
	+ Div<Output = Self>
	+ DivAssign
	+ Debug
	+ Display
{
	fn wrapping_add(self, rhs: Self) -> Self;
	fn wrapping_neg(self) -> Self;
}

pub trait INum: Num + Neg<Output = Self> {}

macro_rules! impl_num {
	($($t:ty),*) => { $(
		impl Num for $t {
			fn wrapping_add(self, rhs: Self) -> Self {
				self.wrapping_add(rhs)
			}
			fn wrapping_neg(self) -> Self {
				self.wrapping_neg()
			}
		}
	)* };
}

impl_num!(i32, i64, i128, isize, u32, u64, u128, usize);

impl<T: Num + Neg<Output = Self>> INum for T {}

}  // mod num

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
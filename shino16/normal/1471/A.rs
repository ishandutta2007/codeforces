use std::{u32, u64};

use crate::lib::io::*;

fn main() {
	let mut io = IO::new();
	let t: u32 = io.scan();
	for _ in 0..t {
		let (n, x): (usize, u64) = io.scan();
		let a = io.scan_vec::<u64>(n);
		let sum: u64 = a.iter().to_owned().sum();
		let min = (sum + x - 1) / x;
		let max: u64 = a.into_iter().map(|e| (e + x - 1) / x).sum();
		io.println((min, max));
	}
}




pub mod lib {

pub mod io {

use std::io::{stdout, BufWriter, Read, StdoutLock, Write};
use std::marker::PhantomData;

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
	fn scan_str(&mut self) -> &'static str {
		self.iter.next().unwrap()
	}
	fn scan_raw(&mut self) -> &'static [u8] {
		self.scan_str().as_bytes()
	}
	pub fn scan<T: Scan>(&mut self) -> T {
		T::scan(self)
	}
	pub fn scan_iter<T: Scan>(&mut self) -> Iter<'_, T> {
		Iter { io: self, _m: PhantomData }
	}
	pub fn scan_n<T: Scan>(&mut self, n: usize) -> std::iter::Take<Iter<'_, T>> {
		self.scan_iter().take(n)
	}
	pub fn scan_vec<T: Scan>(&mut self, n: usize) -> Vec<T> {
		(0..n).map(|_| self.scan()).collect()
	}
	pub fn scan_vv<T: Scan>(&mut self, h: usize, w: usize) -> Vec<Vec<T>> {
		(0..h).map(|_| self.scan_vec(w)).collect()
	}
	pub fn print<T: Print>(&mut self, x: T) {
		T::print(self, x);
	}
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
	pub fn flush(&mut self) {
		self.buf.flush().unwrap();
	}
}

pub struct Iter<'a, T> {
	io: &'a mut IO,
	_m: PhantomData<T>,
}

impl<T: Scan> Iterator for Iter<'_, T> {
	type Item = T;
	fn next(&mut self) -> Option<Self::Item> {
		Some(self.io.scan())
	}
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

#[derive(Debug, Clone, Copy, Default)]
pub struct Usize1(pub usize);
impl Scan for Usize1 {
	fn scan(io: &mut IO) -> Self {
		let n: usize = io.scan();
		Self(n - 1)
	}
}

impl Scan for u8 {
	fn scan(s: &mut IO) -> Self {
		let bytes = s.scan_raw();
		debug_assert_eq!(bytes.len(), 1);
		bytes[0]
	}
}

impl Scan for &[u8] {
	fn scan(s: &mut IO) -> Self {
		s.scan_raw()
	}
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
	fn print(w: &mut IO, x: Self) {
		w.buf.write_all(&[x]).unwrap();
	}
}

impl Print for &[u8] {
	fn print(w: &mut IO, x: Self) {
		w.buf.write_all(x).unwrap();
	}
}

impl Print for &str {
	fn print(w: &mut IO, x: Self) {
		w.print(x.as_bytes());
	}
}

}  // mod io

}  // mod lib
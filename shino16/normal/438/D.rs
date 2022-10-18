use crate::lib::ds::segtree::beats::*;
use crate::lib::io::*;

#[derive(Clone, Copy, Debug)]
struct T {
	max: u32,
	sum: u64,
	leaf: bool,
}

fn main() {
	let mut io = IO::new();
	let [n, q]: [usize; 2] = io.scan();
	let a = io
		.scan_iter::<u32>(n)
		.map(|a| T { max: a, sum: a as u64, leaf: true })
		.collect::<Vec<_>>();

	let mut st = SegmentTreeBeats::from_slice(
		&a,
		MonoidImpl(
			|| T { max: 0, sum: 0, leaf: false },
			|a, b| T { max: a.max.max(b.max), sum: a.sum + b.sum, leaf: false },
		),
		MonoidImpl(|| std::u32::MAX, |_, b| b),
		|mut t, x| {
			if t.max < x {
				Some(t)
			} else if t.leaf {
				t.max %= x;
				t.sum = t.max as u64;
				Some(t)
			} else {
				None
			}
		},
	);

	for _ in 0..q {
		let c: u32 = io.scan();
		if c == 1 {
			let ans = st.ask(io.scan::<Usize1>().0, io.scan());
			io.println(ans.sum);
		} else if c == 2 {
			st.act_over(io.scan::<Usize1>().0, io.scan(), io.scan());
		} else {
			st.exec(io.scan::<Usize1>().0, |x| {
				debug_assert_eq!(x.max as u64, x.sum);
				x.max = io.scan();
				x.sum = x.max as u64;
			});
		}
	}
}




pub mod lib {

pub mod alg {


pub trait Monoid {
	type Item: Copy;
	fn unit(&self) -> Self::Item;
	fn op(&self, x: Self::Item, y: Self::Item) -> Self::Item;
	fn op_to(&self, y: Self::Item, x: &mut Self::Item) { *x = self.op(*x, y); }
}

pub trait Group: Monoid {
	fn inv(&self, x: Self::Item) -> Self::Item;
	fn op_inv_to(&self, y: Self::Item, x: &mut Self::Item) { *x = self.op(*x, self.inv(y)) }
}

macro_rules! impl_monoid {
	($target:ty, $($params:tt : $bounds:tt),*) => {
		impl<$($params : $bounds),*> Monoid for $target {
			type Item = T;
			fn unit(&self) -> Self::Item { (self.0)() }
			fn op(&self, x: Self::Item, y: Self::Item) -> Self::Item { (self.1)(x, y) }
		}
	};
}

macro_rules! impl_group {
	($target:ty, $($params:tt : $bounds:tt),*) => {
		impl_monoid!($target, $($params : $bounds),*);
		impl<$($params : $bounds),*> Group for $target {
			fn inv(&self, x: Self::Item) -> Self::Item { (self.2)(x) }
		}
	};
}

pub struct MonoidImpl<T: Copy, Unit: Fn() -> T, Op: Fn(T, T) -> T>(pub Unit, pub Op);
pub struct GroupImpl<T, Unit, Op, Inv>(pub Unit, pub Op, pub Inv)
where
	T: Copy,
	Unit: Fn() -> T,
	Op: Fn(T, T) -> T,
	Inv: Fn(T) -> T;

// help!
impl_monoid!(MonoidImpl<T, Unit, Op>, T: Copy, Unit: (Fn() -> T), Op: (Fn(T, T) -> T));
impl_group!(GroupImpl<T, Unit, Op, Inv>,
			T: Copy, Unit: (Fn() -> T), Op: (Fn(T, T) -> T), Inv: (Fn(T) -> T));

}  // mod alg

pub mod ds {

pub mod segtree {

pub mod beats {

pub use crate::lib::alg::*;

fn trunc(x: usize) -> usize {
	x >> x.trailing_zeros()
}

#[derive(Clone)]
pub struct SegmentTreeBeats<On: Monoid, Act: Monoid, Apply>
where
	Apply: Fn(On::Item, Act::Item) -> Option<On::Item>,
{
	len: usize,
	log: u32,
	data: Vec<(On::Item, Act::Item)>,
	on_alg: On,
	act_alg: Act,
	apply: Apply,
}

impl<On: Monoid, Act: Monoid, Apply: Fn(On::Item, Act::Item) -> Option<On::Item>>
	SegmentTreeBeats<On, Act, Apply>
{
	pub fn new(len: usize, on_alg: On, act_alg: Act, apply: Apply) -> Self {
		Self {
			len,
			log: len.next_power_of_two().trailing_zeros(),
			data: vec![(on_alg.unit(), act_alg.unit()); len * 2],
			on_alg,
			act_alg,
			apply,
		}
	}
	pub fn from_slice(slice: &[On::Item], on_alg: On, act_alg: Act, apply: Apply) -> Self {
		let len = slice.len();
		let log = len.next_power_of_two().trailing_zeros();
		let iter = slice.iter().map(|&x| (x, act_alg.unit()));
		let mut data: Vec<_> = iter.clone().chain(iter).collect();
		for i in (1..len).rev() {
			data[i].0 = on_alg.op(data[i << 1].0, data[i << 1 | 1].0);
		}
		Self { len, log, data, on_alg, act_alg, apply }
	}
	pub fn len(&self) -> usize {
		self.len
	}
	fn apply(&mut self, p: usize, actor: Act::Item) -> u32 {
		self.act_alg.op_to(actor, &mut self.data[p].1);
		let mut depth = 0;
		self.data[p].0 = if let Some(d) = (self.apply)(self.data[p].0, actor) {
			d
		} else {
			depth = self.push(p);
			self.on_alg.op(self.data[p << 1].0, self.data[p << 1 | 1].0)
		};
		depth
	}
	fn push(&mut self, p: usize) -> u32 {
		let depth = self.apply(p << 1, self.data[p].1);
		self.apply(p << 1 | 1, self.data[p].1);
		self.data[p].1 = self.act_alg.unit();
		depth + 1
	}
	fn flush(&mut self, p: usize) {
		if p == 0 {
			return;
		}
		let mut s = self.log;
		while p >> s == 0 {
			s -= 1;
		}
		while s != 0 {
			s -= self.push(p >> s);
		}
	}
	fn build(&mut self, mut p: usize) {
		p >>= 1;
		while p != 0 {
			self.data[p].0 = self.on_alg.op(self.data[p << 1].0, self.data[p << 1 | 1].0);
			// debug_assert_eq!(self.data[p].1, self.act_alg.unit());
			p >>= 1;
		}
	}
	pub fn ask(&mut self, l: usize, r: usize) -> On::Item {
		self.flush(trunc(l + self.len()));
		self.flush(trunc(r + self.len()) - 1);
		let [mut resl, mut resr] = [self.on_alg.unit(); 2];
		let (mut l, mut r) = (l + self.len(), r + self.len());
		while l < r {
			if l & 1 != 0 {
				resl = self.on_alg.op(resl, self.data[l].0);
				l += 1;
			}
			if r & 1 != 0 {
				r -= 1;
				resr = self.on_alg.op(self.data[r].0, resr);
			}
			l >>= 1;
			r >>= 1;
		}
		self.on_alg.op(resl, resr)
	}
	pub fn exec<F: FnOnce(&mut On::Item)>(&mut self, pos: usize, f: F) {
		self.flush(pos + self.len());
		let p = pos + self.len();
		f(&mut self.data[p].0);
		self.build(pos + self.len());
	}
	pub fn act_over(&mut self, l: usize, r: usize, actor: Act::Item) {
		self.flush(trunc(l + self.len()));
		self.flush(trunc(r + self.len()) - 1);
		{
			let (mut l, mut r) = (l + self.len(), r + self.len());
			while l < r {
				if l & 1 != 0 {
					self.apply(l, actor);
					l += 1;
				}
				if r & 1 != 0 {
					r -= 1;
					self.apply(r, actor);
				}
				l >>= 1;
				r >>= 1;
			}
		}
		self.build(trunc(l + self.len()));
		self.build(trunc(r + self.len()) - 1);
	}
}

}  // mod beats

}  // mod segtree

}  // mod ds

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

}  // mod io

}  // mod lib
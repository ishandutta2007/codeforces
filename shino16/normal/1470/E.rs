// original: https://codeforces.com/contest/1470/submission/103523513

use crate::lib::func::rec::*;
use crate::lib::io::*;

fn main() {
	let mut io = IO::new();

	let mut combination = vec![[0_i64; 5]; 40000];
	combination[0][0] = 1;
	for i in 1..40000 {
		combination[i][0] = 1;
		for j in 1..=4 {
			combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]).min(1 << 60);
		}
	}

	let t: u64 = io.scan();
	for _ in 0..t {
		let [n, c, q]: [usize; 3] = io.scan();
		let mut p = io.scan_vec::<u64>(n as usize);
		for e in &mut p {
			*e -= 1;
		}

		let f = |n: u64, c: u64| {
			if n == 0 {
				1
			} else {
				let mut ret = 0;
				for i in 0..=c {
					ret = (ret + combination[n as usize - 1][i as usize]).min(1 << 60);
				}
				ret
			}
		};

		let h = |idx: u64, c| {
			let mut a = Vec::new();
			for i in 0..=c {
				if i + idx >= n as u64 {
					break;
				}
				a.push((i, f(n as u64 - idx - 1 - i, c - i)));
			}
			a.sort_unstable_by_key(|q| p[(idx + q.0) as usize]);
			a
		};

		let mut a = vec![[Vec::new(), Vec::new(), Vec::new(), Vec::new(), Vec::new()]; 30100];
		for i in 0..n {
			for j in 0..=c {
				a[i as usize][j as usize] = h(i as u64, j as u64);
			}
		}

		let mut v = [Vec::new(), Vec::new(), Vec::new(), Vec::new(), Vec::new()];
		for (c, v) in (0..).zip(&mut v) {
			v.clear();
			v.push(0);
			for i in 0..n {
				let mut val = *v.last().unwrap();
				for j in 1..=c {
					if i + j >= n || p[i as usize + j as usize] >= p[i as usize] {
						continue;
					}
					val += f((n - i - j - 1) as _, (c - j) as _);
				}
				v.push(val);
			}
		}
		let rev = std::cell::RefCell::new(Vec::new());
		let g = recurse(|g, (idx, c, num): (u64, u64, i64)| {
			if v[c as usize][n as usize] - v[c as usize][idx as usize] == num {
				return;
			}
			let mut ok = idx;
			let mut ng = n as u64 - 1;
			while ok != ng {
				let mid = (ok + ng) / 2;
				let mut val = v[c as usize][mid as usize] - v[c as usize][idx as usize];
				if val > num {
					ng = mid;
					continue;
				}
				for &tmp in &a[mid as usize][c as usize] {
					if tmp.0 == 0 {
						if val <= num && num < val + tmp.1 {
							ok = mid + 1;
						} else {
							ng = mid;
						}
					} else {
						val += tmp.1;
					}
				}
			}
			let mut val = v[c as usize][ok as usize] - v[c as usize][idx as usize];
			for &tmp in &a[ok as usize][c as usize] {
				if val <= num && num < val + tmp.1 {
					rev.borrow_mut().push((ok, tmp.0));
					g((ok + tmp.0 + 1, c - tmp.0, num - val));
					break;
				} else {
					val += tmp.1;
				}
			}
		});

		for _ in 0..q {
			let (mut a, mut b): (u64, u64) = io.scan();
			a -= 1;
			b -= 1;
			if f(n as _, c as _) < (b + 1) as _ {
				io.println(-1);
				continue;
			}

			g.call((0, c as _, b as _));
			let mut ans = p[a as usize];
			for tmp in rev.borrow_mut().drain(..) {
				if tmp.0 <= a && a < tmp.0 + tmp.1 + 1 {
					ans = p[(tmp.0 * 2 + tmp.1 - a) as usize];
				}
			}
			io.println(ans + 1);
		}
	}
}




pub mod lib {

pub mod func {

pub mod rec {

pub struct Recurse<F>(F);

impl<F> Recurse<F> {
	pub fn call<Arg, Ret>(&self, arg: Arg) -> Ret
	where
		F: Fn(&dyn Fn(Arg) -> Ret, Arg) -> Ret,
	{
		self.0(&|arg| self.call(arg), arg)
	}
}

pub fn recurse<Arg, Ret, F: Fn(&dyn Fn(Arg) -> Ret, Arg) -> Ret>(f: F) -> Recurse<F> {
	Recurse(f)
}

}  // mod rec

}  // mod func

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
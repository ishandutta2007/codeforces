use crate::lib::io::*;
use crate::lib::graph::{
	io::*,
	dfs::*,
	bfs::*,
};

fn main() {
	let mut io = IO::new();
	let t: u32 = io.scan();
	for _ in 0..t {
		let (g, n, _) = io.scan_graph();
		let mut state = vec![!0_u32; n];
		state[0] = 0;
		if !is_connected(&g) {
			io.println("NO");
			continue;
		}
		let mut has_black = vec![false; n];
		let mut black = vec![false; n];
		bfs(&g, 0, |v, _| {
			if !has_black[v] {
				black[v] = true;
				g.adj(v, |w| has_black[w] = true);
			}
		});
		io.println("YES");
		io.println(black.iter().map(|&b| b as u32).sum::<u32>());
		io.iterln((0..n).filter(|&v| black[v]).map(Usize1), " ");
	}
}




pub mod lib {

pub mod ds {

pub mod bitset {

pub trait BitSet {
	fn get_bit(&self, i: usize) -> bool;
	fn set_bit(&mut self, i: usize, b: bool);
	fn modify_bit(&mut self, i: usize, b: bool) -> bool {
		if self.get_bit(i) == b {
			false
		} else {
			self.set_bit(i, b);
			true
		}
	}
	fn negate(&mut self);
}

macro_rules! impl_bitset {
	($($type:ty),*) => { $(
		impl BitSet for $type {
			fn get_bit(&self, i: usize) -> bool {
				((*self >> i) & 1) != 0
			}
			fn set_bit(&mut self, i: usize, b: bool) {
				*self |= (b as $type) << i;
			}
			fn negate(&mut self) {
				*self = !*self;
			}
		}
	)* };
}

impl_bitset!(i32, i64, i128, isize, u32, u64, u128, usize);

impl BitSet for [u32] {
	fn get_bit(&self, i: usize) -> bool {
		self[i / 32].get_bit(i % 32)
	}
	fn set_bit(&mut self, i: usize, b: bool) {
		self[i / 32].set_bit(i % 32, b);
	}
	fn negate(&mut self) {
		for x in self {
			x.negate()
		}
	}
}

pub fn new_bitset(n: usize) -> Vec<u32> {
	vec![0; (n + 31) / 32]
}

}  // mod bitset

}  // mod ds

pub mod graph {


use crate::lib::zo::ZeroOne;

pub trait Graph {
	fn len(&self) -> usize;
	fn adj<F: FnMut(usize)>(&self, v: usize, f: F);
}

pub trait WGraph<W>: Graph {
	fn adj_w<F: FnMut(usize, &W)>(&self, v: usize, f: F);
}

pub trait Tree: Graph {}

pub trait WTree<W>: WGraph<W> {}

impl Graph for Vec<Vec<usize>> {
	fn len(&self) -> usize {
		self.len()
	}
	fn adj<F: FnMut(usize)>(&self, v: usize, f: F) {
		self[v].iter().copied().for_each(f);
	}
}

impl<N: ZeroOne> WGraph<N> for Vec<Vec<usize>> {
	fn adj_w<F: FnMut(usize, &N)>(&self, v: usize, mut f: F) {
		self[v].iter().for_each(|&v| f(v, &N::ONE))
	}
}

impl<W> Graph for Vec<Vec<(usize, W)>> {
	fn len(&self) -> usize {
		self.len()
	}
	fn adj<F: FnMut(usize)>(&self, v: usize, mut f: F) {
		self[v].iter().for_each(|&(v, _)| f(v))
	}
}

impl<W> WGraph<W> for Vec<Vec<(usize, W)>> {
	fn adj_w<F: FnMut(usize, &W)>(&self, v: usize, mut f: F) {
		self[v].iter().for_each(|&(v, ref e)| f(v, e));
	}
}

impl<G: Graph> Tree for G {}
impl<W, G: WGraph<W>> WTree<W> for G {}

pub mod bfs {

use std::collections::VecDeque;

pub use super::*;
use crate::lib::ds::bitset::*;

/// f: (v, par)
pub fn bfs<G: Graph, F: FnMut(usize, usize)>(g: &G, s: usize, mut f: F) {
	let mut visited = new_bitset(g.len());
	let mut togo: VecDeque<_> = vec![(s, !0)].into();
	visited.set_bit(s, true);
	while let Some((v, par)) = togo.pop_front() {
		f(v, par);
		g.adj(v, |w| {
			if visited.modify_bit(w, true) {
				togo.push_back((w, v));
			}
		})
	}
}

}  // mod bfs

pub mod dfs {

pub use super::*;
use crate::lib::ds::bitset::*;

/// f: (v, par)
pub fn dfs<G: Graph, F: FnMut(usize, usize)>(g: &G, s: usize, mut f: F) {
	let mut togo = vec![(s, !0)];
	let mut visited = new_bitset(g.len());
	visited.set_bit(s, true);
	while let Some((v, par)) = togo.pop() {
		f(v, par);
		g.adj(v, |w| {
			if visited.modify_bit(w, true) {
				togo.push((w, v));
			}
		});
	}
}

pub fn is_connected<G: Graph>(g: &G) -> bool {
	let mut cnt = 0;
	dfs(g, 0, |_, _| cnt += 1);
	cnt == g.len()
}

pub fn dfs_ord_par<G: Graph>(g: &G, s: usize) -> (Vec<(usize, usize)>, Vec<usize>) {
	let mut ord = Vec::with_capacity(g.len());
	let mut par = vec![!0; g.len()];
	dfs(g, s, |v, p| {
		ord.push((v, p));
		par[v] = p;
	});
	(ord, par)
}

}  // mod dfs

pub mod io {

pub use crate::lib::io::*;

impl IO {
	pub fn scan_tree(&mut self) -> (Vec<Vec<usize>>, usize) {
		let n = self.scan();
		let mut graph = vec![Vec::new(); n];
		for _ in 0..n - 1 {
			let (Usize1(u), Usize1(v)) = self.scan();
			graph[u].push(v);
			graph[v].push(u);
		}
		(graph, n)
	}
	pub fn scan_graph(&mut self) -> (Vec<Vec<usize>>, usize, usize) {
		let (n, m) = self.scan();
		let mut graph = vec![Vec::new(); n];
		for _ in 0..m {
			let (Usize1(u), Usize1(v)) = self.scan();
			graph[u].push(v);
			graph[v].push(u);
		}
		(graph, n, m)
	}
	pub fn scan_ditree(&mut self) -> (Vec<Vec<usize>>, usize) {
		let n = self.scan();
		let mut graph = vec![Vec::new(); n];
		for _ in 0..n - 1 {
			let (Usize1(u), Usize1(v)) = self.scan();
			graph[u].push(v);
		}
		(graph, n)
	}
	pub fn scan_digraph(&mut self) -> (Vec<Vec<usize>>, usize, usize) {
		let (n, m) = self.scan();
		let mut graph = vec![Vec::new(); n];
		for _ in 0..m {
			let (Usize1(u), Usize1(v)) = self.scan();
			graph[u].push(v);
		}
		(graph, n, m)
	}
	pub fn scan_wtree<W: Scan + Copy>(&mut self) -> (Vec<Vec<(usize, W)>>, usize) {
		let n = self.scan();
		let mut graph = vec![Vec::new(); n];
		for _ in 0..n - 1 {
			let (Usize1(u), Usize1(v)) = self.scan();
			let w: W = self.scan();
			graph[u].push((v, w));
			graph[v].push((u, w));
		}
		(graph, n)
	}
	pub fn scan_wgraph<W: Scan + Copy>(&mut self) -> (Vec<Vec<(usize, W)>>, usize, usize) {
		let (n, m) = self.scan();
		let mut graph = vec![Vec::new(); n];
		for _ in 0..m {
			let (Usize1(u), Usize1(v)) = self.scan();
			let w: W = self.scan();
			graph[u].push((v, w));
			graph[v].push((u, w));
		}
		(graph, n, m)
	}
	pub fn scan_wditree<W: Scan + Copy>(&mut self) -> (Vec<Vec<(usize, W)>>, usize) {
		let n = self.scan();
		let mut graph = vec![Vec::new(); n];
		for _ in 0..n - 1 {
			let (Usize1(u), Usize1(v)) = self.scan();
			let w: W = self.scan();
			graph[u].push((v, w));
		}
		(graph, n)
	}
	pub fn scan_wdigraph<W: Scan + Copy>(&mut self) -> (Vec<Vec<(usize, W)>>, usize, usize) {
		let (n, m) = self.scan();
		let mut graph = vec![Vec::new(); n];
		for _ in 0..m {
			let (Usize1(u), Usize1(v)) = self.scan();
			let w: W = self.scan();
			graph[u].push((v, w));
		}
		(graph, n, m)
	}
}

}  // mod io

}  // mod graph

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

#[derive(Debug, Clone, Copy, Default)]
pub struct Usize1(pub usize);
impl Scan for Usize1 {
	fn scan(io: &mut IO) -> Self {
		let n: usize = io.scan();
		Self(n - 1)
	}
}
impl Print for Usize1 {
    fn print(w: &mut IO, x: Self) {
		w.print(x.0 + 1)
    }
}

}  // mod io

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
use crate::lib::io::*;
use crate::lib::ds::uvec::*;

fn main() {
    let mut io = IO::new();
    let t: usize = io.scan();
    for _ in 0..t {
        let (h, w): (usize, usize) = io.scan();
        let a = UVec(io.scan_vec::<i64>(h*w));
        let mut b = Vec::with_capacity(h*w);
        for r in 0..h {
            for c in 0..w {
                b.push(a[r*w+c]-(r+c) as i64);
            }
        }
        b.sort_unstable();
        b.dedup();
        let mut res = std::i64::MAX;
        let mut cost = UVec(vec![0; h*w]);
        for x in b {
            cost.iter_mut().for_each(|v| *v = 1 << 60);
            cost[0] = a[0] - x;
            if cost[0] < 0 {
                continue;
            }
            for r in 0..h {
                for c in 0..w {
                    let d = cost[r*w+c];
                    let he = x + (r + c + 1) as i64;
                    if r + 1 < h && he <= a[r*w+w+c] {
                        cost[r*w+w+c] = cost[r*w+w+c].min(d+a[r*w+w+c]-he);
                    }
                    if c + 1 < w && he <= a[r*w+c+1] {
                        cost[r*w+c+1] = cost[r*w+c+1].min(d+a[r*w+c+1]-he);
                    }
                }
            }
            res = res.min(cost[h*w-1]);
        }
        io.println(res);
    }
}




pub mod lib {

pub mod ds {

pub mod uvec {

use std::ops::{Deref, DerefMut};

pub struct UVec<T>(pub Vec<T>);

impl<T> Deref for UVec<T> {
    type Target = Vec<T>;
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

impl<T> DerefMut for UVec<T> {
    fn deref_mut(&mut self) -> &mut Self::Target {
        &mut self.0
    }
}

#[cfg(not(debug_assertions))]
use std::ops::{Index, IndexMut};

#[cfg(not(debug_assertions))]
impl<T> Index<usize> for UVec<T> {
    type Output = T;
    fn index(&self, index: usize) -> &Self::Output {
        unsafe { self.0.get_unchecked(index) }
    }
}

#[cfg(not(debug_assertions))]
impl<T> IndexMut<usize> for UVec<T> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        unsafe { self.0.get_unchecked_mut(index) }
    }
}

}  // mod uvec

}  // mod ds

pub mod io {

use std::io::{stdout, BufWriter, Read, StdoutLock, Write};

pub struct IO {
    iter: std::str::SplitAsciiWhitespace<'static>,
    buf: BufWriter<StdoutLock<'static>>,
}

impl IO {
    pub fn new() -> Self {
        let mut input = String::new();
        std::io::stdin().read_to_string(&mut input).unwrap();
        let input = Box::leak(input.into_boxed_str());
        let out = Box::new(stdout());
        IO {
            iter: input.split_ascii_whitespace(),
            buf: BufWriter::new(Box::leak(out).lock()),
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
    pub fn scan_vec<T: Scan>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.scan()).collect()
    }
    pub fn scan_graph(&mut self) -> (usize, usize, Vec<Vec<usize>>) {
        let n = self.scan();
        let m = self.scan();
        let mut graph = vec![Vec::new(); n];
        for _ in 0..m {
            let u: usize = self.scan();
            let v: usize = self.scan();
            graph[u].push(v);
            graph[v].push(u);
        }
        (n, m, graph)
    }
    pub fn scan_digraph(&mut self) -> (usize, usize, Vec<Vec<usize>>) {
        let n = self.scan();
        let m = self.scan();
        let mut graph = vec![Vec::new(); n];
        for _ in 0..m {
            let u: usize = self.scan();
            let v: usize = self.scan();
            graph[u].push(v);
        }
        (n, m, graph)
    }
    pub fn scan_tree(&mut self) -> (usize, Vec<Vec<usize>>) {
        let n = self.scan();
        let mut graph = vec![Vec::new(); n];
        for _ in 0..n - 1 {
            let u: usize = self.scan();
            let v: usize = self.scan();
            graph[u].push(v);
            graph[v].push(u);
        }
        (n, graph)
    }
}

impl IO {
    pub fn print<T: Print>(&mut self, x: T) {
        T::print(self, x);
    }
    pub fn println<T: Print>(&mut self, x: T) {
        self.print(x);
        self.print("\n");
    }
    pub fn iterln<T: Print, I: Iterator<Item = T>>(&mut self, mut iter: I, delim: &str) {
        if let Some(v) = iter.next() {
            self.print(v);
            for v in iter {
                self.print(delim);
                self.println(v);
            }
        }
        self.print("\n");
    }
    pub fn flush(&mut self) {
        self.buf.flush().unwrap();
    }
}

pub trait Scan {
    fn scan(io: &mut IO) -> Self;
}

macro_rules! impl_parse_int {
    ($($t:tt),*) => {
        $(
            impl Scan for $t {
                fn scan(s: &mut IO) -> Self {
                    let mut res = 0;
                    for d in s.scan_raw() {
                        res *= 10;
                        res += (*d - b'0') as $t;
                    }
                    res
                }
            }
        )*
    };
}

impl_parse_int!(i32, i64, isize, u32, u64, usize);

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

impl<T: Scan, U: Scan> Scan for (T, U) {
    fn scan(s: &mut IO) -> Self {
        (T::scan(s), U::scan(s))
    }
}

impl<T: Scan, U: Scan, V: Scan> Scan for (T, U, V) {
    fn scan(s: &mut IO) -> Self {
        (T::scan(s), U::scan(s), V::scan(s))
    }
}

impl<T: Scan> Scan for [T; 2] {
    fn scan(s: &mut IO) -> Self {
        [s.scan(), s.scan()]
    }
}

impl<T: Scan> Scan for [T; 3] {
    fn scan(s: &mut IO) -> Self {
        [s.scan(), s.scan(), s.scan()]
    }
}

impl<T: Scan> Scan for [T; 4] {
    fn scan(s: &mut IO) -> Self {
        [s.scan(), s.scan(), s.scan(), s.scan()]
    }
}

pub trait Print {
    fn print(w: &mut IO, x: Self);
}

macro_rules! impl_print_int {
    ($($t:ty),*) => {
        $(
            impl Print for $t {
                fn print(w: &mut IO, x: Self) {
                    w.buf.write_all(x.to_string().as_bytes()).unwrap();
                }
            }
        )*
    };
}

impl_print_int!(i32, i64, isize, u32, u64, usize);

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

impl<T: Print, U: Print> Print for (T, U) {
    fn print(w: &mut IO, (x, y): Self) {
        w.print(x);
        w.print(" ");
        w.print(y);
    }
}

impl<T: Print, U: Print, V: Print> Print for (T, U, V) {
    fn print(w: &mut IO, (x, y, z): Self) {
        w.print(x);
        w.print(" ");
        w.print(y);
        w.print(" ");
        w.print(z);
    }
}

}  // mod io

}  // mod lib
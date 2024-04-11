use std::collections::HashMap;

use crate::lib::io_interactive::*;
use crate::lib::math::convex::*;

fn main() {
    let mut io = IO::new();
    let n: usize = io.scan();
    let mut memo = HashMap::new();
    let (_, i) = convex_min(1, n + 1, |i| {
        *memo.entry(i).or_insert_with(|| {
            io.println(("?", i));
            io.flush();
            io.scan::<usize>()
        })
    });
    io.println(("!", i));
}



pub mod lib {

pub mod io_interactive {

use std::io::{stdin, stdout, BufRead, BufReader, BufWriter, StdinLock, StdoutLock, Write};
use std::marker::PhantomData;

pub struct IO {
    input: Vec<u8>,
    pos: usize,
    in_buf: BufReader<StdinLock<'static>>,
    out_buf: BufWriter<StdoutLock<'static>>,
}

impl IO {
    pub fn new() -> Self {
        let inp = Box::leak(Box::new(stdin()));
        let out = Box::leak(Box::new(stdout()));
        IO {
            input: Vec::new(),
            pos: 0,
            in_buf: BufReader::new(inp.lock()),
            out_buf: BufWriter::new(out.lock()),
        }
    }
    fn scan_raw(&mut self) -> &[u8] {
        loop {
            if self.pos == self.input.len() {
                self.input.clear();
                self.in_buf.read_until(b'\n', &mut self.input).unwrap();
                self.pos = 0;
            } else if self.input[self.pos].is_ascii_whitespace() {
                self.pos += 1;
            } else {
                break;
            }
        }
        let i = self.pos;
        while self.pos != self.input.len() && !self.input[self.pos].is_ascii_whitespace() {
            self.pos += 1;
        }
        &self.input[i..self.pos]
    }
    pub fn scan<T: Scan>(&mut self) -> T {
        T::scan(self)
    }
    pub fn scan_iter<T: Scan>(&mut self, n: usize) -> std::iter::Take<Iter<'_, T>> {
        Iter { io: self, _m: PhantomData }.take(n)
    }
    pub fn scan_vec<T: Scan>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.scan()).collect()
    }
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
                self.print(v);
            }
        }
        self.print("\n");
    }
    pub fn flush(&mut self) {
        self.out_buf.flush().unwrap();
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

impl Scan for Vec<u8> {
    fn scan(s: &mut IO) -> Self {
        s.scan_raw().to_owned()
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

macro_rules! impl_print_int {
    ($($t:ty),*) => { $(
        impl Print for $t {
            fn print(w: &mut IO, x: Self) {
                w.out_buf.write_all(x.to_string().as_bytes()).unwrap();
            }
        }
        impl Print for &$t {
            fn print(w: &mut IO, x: Self) {
                w.out_buf.write_all(x.to_string().as_bytes()).unwrap();
            }
        }
    )* };
}

impl_print_int!(i32, i64, i128, isize, u32, u64, u128, usize);

impl Print for u8 {
    fn print(w: &mut IO, x: Self) {
        w.out_buf.write_all(&[x]).unwrap();
    }
}

impl Print for &[u8] {
    fn print(w: &mut IO, x: Self) {
        w.out_buf.write_all(x).unwrap();
    }
}

impl Print for &str {
    fn print(w: &mut IO, x: Self) {
        w.print(x.as_bytes());
    }
}

}  // mod io_interactive

pub mod math {

pub mod convex {

pub type Int = usize;

/// return (min f, argmin f)
pub fn convex_min<F: FnMut(Int) -> T, T: Ord>(
    mut l: Int,
    mut r: Int,
    mut f: F,
) -> (T, Int) {
    r -= 1;
    // f(r) < f(r + 1)
    while l != r {
        let m = (l + r) / 2;
        if f(m) < f(m + 1) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    (f(l), l)
}

}  // mod convex

}  // mod math

}  // mod lib
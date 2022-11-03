#![allow(unused_imports, unused_macros, unused_must_use)]
use std::{
	io::{self, Write},
	str,
};

struct Scanner<R> {
	reader: R,
	buf_str: Vec<u8>,
	buf_iter: str::SplitAsciiWhitespace<'static>,
}

impl<R: io::BufRead> Scanner<R> {
	fn new(reader: R) -> Self {
		Self {
			reader,
			buf_str: Vec::new(),
			buf_iter: "".split_ascii_whitespace(),
		}
	}
	fn next<T: str::FromStr>(&mut self) -> T {
		loop {
			if let Some(token) = self.buf_iter.next() {
				return token.parse().ok().expect("Failed parse");
			}
			self.buf_str.clear();
			self.reader.read_until(b'\n', &mut self.buf_str).expect("Failed read");
			self.buf_iter = unsafe {
				let slice = str::from_utf8_unchecked(&self.buf_str);
				std::mem::transmute(slice.split_ascii_whitespace())
			}
		}
	}
}

fn main() {
	let (stdin, stdout) = (io::stdin(), io::stdout());
	let mut cin = Scanner::new(stdin.lock());
	let mut cout = io::BufWriter::new(stdout.lock());

	let n: i64 = cin.next();
	let m: i64 = cin.next();
	let k: i64 = cin.next();
	writeln!(cout, "{}", ((n + k - 1) / k) * ((m + k - 1) / k));
}
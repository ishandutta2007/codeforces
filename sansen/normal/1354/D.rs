// ---------- begin fenwick tree ----------
#[allow(dead_code)]
mod fenwick {
    type T = i32;
    const ZERO: T = 0;
    pub struct Tree {
        a: Box<[T]>,
    }
    impl Tree {
        pub fn new(n: usize) -> Tree {
            Tree {
                a: vec![ZERO; n + 1].into_boxed_slice(),
            }
        }
        pub fn add(&mut self, mut x: usize, v: T) {
            assert!(x > 0);
            while let Some(a) = self.a.get_mut(x) {
                *a += v;
                x += x & (!x + 1);
            }
        }
        pub fn sum(&self, mut x: usize) -> T {
            assert!(x < self.a.len());
            let mut res = ZERO;
            while x > 0 {
                res += self.a[x];
                x -= x & (!x + 1);
            }
            res
        }
        pub fn search(&self, s: T) -> usize {
            debug_assert!(self.sum(self.a.len() - 1) >= s);
            let mut k = 1;
            while 2 * k < self.a.len() {
                k *= 2;
            }
            let mut x = 0;
            let mut w = ZERO;
            while k > 0 {
                self.a.get(x + k).map(|a| {
                    if w + *a < s {
                        w += *a;
                        x += k;
                    }
                });
                k >>= 1;
            }
            x + 1
        }
    }
}
// ---------- end fenwick tree ----------

use std::io::Read;
use std::str::FromStr;

struct Scanner<R> {
    reader: R,
    buf: Vec<u8>,
}

impl<R: Read> Scanner<R> {
    fn new(reader: R) -> Self {
        Scanner {
            reader: reader,
            buf: Vec::with_capacity(1024),
        }
    }
    fn next<T: FromStr>(&mut self) -> T {
        let it = self.reader
            .by_ref()
            .bytes()
            .map(|c| c.unwrap())
            .skip_while(|c| c.is_ascii_control() || c.is_ascii_whitespace())
            .take_while(|c| !c.is_ascii_control() && !c.is_ascii_whitespace());
        self.buf.clear();
        for c in it {
            self.buf.push(c);
        }
        std::str::from_utf8(&self.buf)
            .unwrap()
            .parse::<T>()
            .ok()
            .unwrap()
    }
}

fn main() {
    run();
}

fn run() {
    let stdin = std::io::stdin();
    let mut sc = Scanner::new(stdin.lock());
    let n: usize = sc.next();
    let q: usize = sc.next();
    let mut bit = fenwick::Tree::new(n);
    for _ in 0..n {
        let a: usize = sc.next();
        bit.add(a, 1);
    }
    for _ in 0..q {
        let k: i32 = sc.next();
        if k > 0 {
            bit.add(k as usize, 1);
        } else {
            let k = -k;
            let x = bit.search(k);
            bit.add(x, -1);
        }
    }
    let ans = if bit.sum(n) > 0 {
        bit.search(1)
    } else {
        0
    };
    println!("{}", ans);
}
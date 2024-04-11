// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(&T, &T) -> T> {
        size: usize,
        a: Vec<Option<T>>,
        fold: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(&T, &T) -> T> PURQ<T, F> {
        pub fn new(len: usize, fold: F) -> PURQ<T, F> {
            let size = len.next_power_of_two();
            PURQ {
                size: size,
                a: vec![None; 2 * size],
                fold: fold,
            }
        }
        pub fn update(&mut self, x: usize, v: Option<T>) {
            let mut k = self.size + x;
            self.a[k] = v;
            k >>= 1;
            while k > 0 {
                self.a[k] = self.merge(&self.a[2 * k], &self.a[2 * k + 1]);
                k >>= 1;
            }
        }
        fn merge(&self, a: &Option<T>, b: &Option<T>) -> Option<T> {
            match (a.as_ref(), b.as_ref()) {
                (Some(a), Some(b)) => Some((self.fold)(a, b)),
                (Some(a), None) => Some(a.clone()),
                (None, Some(b)) => Some(b.clone()),
                (None, None) => None,
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: Option<T>) {
            self.a[x + self.size] = v;
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.size)).rev() {
                self.a[k] = self.merge(&self.a[2 * k], &self.a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> Option<T> {
            let mut p: Option<T> = None;
            let mut q: Option<T> = None;
            let a = &self.a;
            l += self.size;
            r += self.size;
            while l < r {
                if (l & 1) == 1 {
                    p = self.merge(&p, &a[l]);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = self.merge(&a[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            self.merge(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let q: usize = sc.next();
    type T = (f64, f64, f64, f64);
    let fold = |a: &T, b: &T| -> T {
        let (x, y, z, w) = *a;
        let (p, q, r, s) = *b;
        let m = 1.0 / (1.0 - p * w);
        (x + m * y * p * z, m * y * q, m * r * z, s + m * r * w * q)
    };
    let mut seg = segment_tree::PURQ::new(n, fold);
    for i in 0..n {
        let a: u32 = sc.next();
        let b: u32 = sc.next();
        let q = (b - a) as f64 / b as f64;
        let p = a as f64 / b as f64;
        seg.update_tmp(i, Some((q, p, q, p)));
    }
    seg.update_all();
    for _ in 0..q {
        let op: u8 = sc.next();
        if op == 1 {
            let i = sc.next::<usize>() - 1;
            let a: u32 = sc.next();
            let b: u32 = sc.next();
            let q = (b - a) as f64 / b as f64;
            let p = a as f64 / b as f64;
            seg.update(i, Some((q, p, q, p)));
        } else {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let ans = seg.find(l, r).unwrap().1;
            writeln!(out, "{:.5}", ans).ok();
        }
    }
}
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T, F> {
        size: usize,
        data: Vec<T>,
        e: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T, F> PURQ<T, F>
    where
        T: Clone,
        F: Fn(&T, &T) -> T,
    {
        pub fn new(size: usize, e: T, op: F) -> PURQ<T, F> {
            let size = size.next_power_of_two();
            PURQ {
                size,
                data: vec![e.clone(); 2 * size],
                e: e,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            assert!(x < self.size);
            let mut x = x + self.size;
            let data = &mut self.data;
            data[x] = v;
            x >>= 1;
            while x > 0 {
                data[x] = (self.op)(&data[2 * x], &data[2 * x + 1]);
                x >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            assert!(x < self.size);
            self.data[x + self.size] = v;
        }
        pub fn update_all(&mut self) {
            let data = &mut self.data;
            for k in (1..self.size).rev() {
                data[k] = (self.op)(&data[2 * k], &data[2 * k + 1]);
            }
        }
        pub fn find(&self, l: usize, r: usize) -> T {
            assert!(l <= r && r <= self.size);
            if l == r {
                return self.e.clone();
            }
            let mut p = self.e.clone();
            let mut q = self.e.clone();
            let mut l = l + self.size;
            let mut r = r + self.size;
            let data = &self.data;
            while l < r {
                if l & 1 == 1 {
                    p = (self.op)(&p, &data[l]);
                    l += 1;
                }
                if r & 1 == 1 {
                    r -= 1;
                    q = (self.op)(&data[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
// sep
pub fn join<T: std::fmt::Display>(a: &[T], sep: &str) -> String {
    use std::fmt::Write;
    let mut s = String::new();
    for (i, a) in a.iter().enumerate() {
        if i > 0 {
            write!(&mut s, "{}", sep).ok();
        }
        write!(&mut s, "{}", a).ok();
    }
    s
}
// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u128, b: u128) -> u128 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

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
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let a = sc.next_vec::<u128>(n);
        let b = sc.next_vec::<u128>(m);
        let mut x = (0..n).collect::<Vec<_>>();
        let mut y = (0..m).collect::<Vec<_>>();
        let mut seg_a = a.iter().map(|a| {
            let mut seg = segment_tree::PURQ::new(m, 1, |a, b| *a / binary_gcd(*a, *b) * *b);
            for (i, b) in b.iter().enumerate() {
                seg.update_tmp(i, binary_gcd(*a, *b));
            }
            seg.update_all();
            seg
        }).collect::<Vec<_>>();
        let mut seg_b = b.iter().map(|b| {
            let mut seg = segment_tree::PURQ::new(n, 1, |a, b| *a / binary_gcd(*a, *b) * *b);
            for (i, a) in a.iter().enumerate() {
                seg.update_tmp(i, binary_gcd(*a, *b));
            }
            seg.update_all();
            seg
        }).collect::<Vec<_>>();
        loop {
            let mut update = false;
            for i in (0..x.len()).rev() {
                if seg_a[x[i]].find(0, m) != a[x[i]] {
                    for j in 0..m {
                        seg_b[j].update(x[i], 1);
                    }
                    update = true;
                    x.remove(i);
                }
            }
            for i in (0..y.len()).rev() {
                if seg_b[y[i]].find(0, n) != b[y[i]] {
                    for j in 0..n {
                        seg_a[j].update(y[i], 1);
                    }
                    update = true;
                    y.remove(i);
                }
            }
            if !update {
                break;
            }
        }
        if x.len() > 0 && y.len() > 0 {
            let a = x.into_iter().map(|x| a[x]).collect::<Vec<_>>();
            let b = y.into_iter().map(|x| b[x]).collect::<Vec<_>>();
            writeln!(out, "YES").ok();
            writeln!(out, "{} {}", a.len(), b.len()).ok();
            writeln!(out, "{}", join(&a, " ")).ok();
            writeln!(out, "{}", join(&b, " ")).ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
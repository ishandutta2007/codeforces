// ---------- begin Lazy Segment Tree ----------
pub trait TE {
    type T: Clone;
    type E: Clone;
    fn fold(l: Self::T, r: Self::T) -> Self::T;
    fn eval(x: Self::T, f: Self::E) -> Self::T;
    fn merge(g: Self::E, h: Self::E) -> Self::E;
    fn e() -> Self::T;
    fn id() -> Self::E;
}

pub struct LazySegmentTree<R: TE> {
    size: usize,
    bit: usize,
    a: Vec<(R::T, R::E)>,
}

impl <R: TE> LazySegmentTree<R> {
    pub fn new(n: usize) -> LazySegmentTree<R> {
        let mut bit = 0;
        while (1 << bit) < n {
            bit += 1;
        }
        LazySegmentTree {
            size: 1 << bit,
            bit: bit,
            a: vec![(R::e(), R::id()); 2 << bit],
        }
    }
    pub fn build_by(z: &[R::T]) -> LazySegmentTree<R> {
        let n = z.len();
        let mut bit = 0;
        while (1 << bit) < n {
            bit += 1;
        }
        let mut a = vec![(R::e(), R::id()); 2 << bit];
        for (a, z) in a[(1 << bit)..].iter_mut().zip(z.iter()) {
            a.0 = z.clone();
        }
        for i in (1..(1 << bit)).rev() {
            let l = R::eval(a[2 * i].0.clone(), a[2 * i].1.clone());
            let r = R::eval(a[2 * i + 1].0.clone(), a[2 * i + 1].1.clone());
            a[i].0 = R::fold(l, r);
        }
        LazySegmentTree {
            size: 1 << bit,
            bit : bit,
            a: a,
        }
    }
    fn eval(&self, k: usize) -> R::T {
        R::eval(self.a[k].0.clone(), self.a[k].1.clone())
    }
    fn propagate(&mut self, x: usize) {
        let x = x + self.size;
        for i in (1..(self.bit + 1)).rev() {
            let k = x >> i;
            self.a[2 * k].1 = R::merge(self.a[2 * k].1.clone(), self.a[k].1.clone());
            self.a[2 * k + 1].1 = R::merge(self.a[2 * k + 1].1.clone(), self.a[k].1.clone());
            self.a[k].1 = R::id();
            self.a[k].0 = R::fold(self.eval(2 * k), self.eval(2 * k + 1));
        }
    }
    fn save(&mut self, x: usize) {
        let x = x + self.size;
        for i in 1..(self.bit + 1) {
            let k = x >> i;
            self.a[k].0 = R::fold(self.eval(2 * k), self.eval(2 * k + 1));
        }
    }
    pub fn update(&mut self, l: usize, r: usize, op: R::E) {
        self.propagate(l);
        self.propagate(r - 1);
        let mut x = l + self.size;
        let mut y = r + self.size;
        while x < y {
            if x & 1 == 1 {
                self.a[x].1 = R::merge(self.a[x].1.clone(), op.clone());
                x += 1;
            }
            if y & 1 == 1 {
                y -= 1;
                self.a[y].1 = R::merge(self.a[y].1.clone(), op.clone());
            }
            x >>= 1;
            y >>= 1;
        }
        self.save(l);
        self.save(r - 1);
    }
    pub fn find(&mut self, l: usize, r: usize) -> R::T {
        self.propagate(l);
        self.propagate(r - 1);
        let mut x = l + self.size;
        let mut y = r + self.size;
        let mut p = R::e();
        let mut q = R::e();
        while x < y {
            if x & 1 == 1 {
                p = R::fold(p, self.eval(x));
                x += 1;
            }
            if y & 1 == 1 {
                y -= 1;
                q = R::fold(self.eval(y), q);
            }
            x >>= 1;
            y >>= 1;
        }
        R::fold(p, q)
    }
}
// ---------- end Lazy Segment Tree ----------

use std::io::Read;
use std::io::Write;
use std::cmp::*;

struct R;
impl TE for R {
    type T = (i64, i64);
    type E = i64;
    fn fold(l: Self::T, r: Self::T) -> Self::T {
        (l.0 + r.0, l.1 + r.1)
    }
    fn eval(x: Self::T, f: Self::E) -> Self::T {
        (x.0 + x.1 * f, x.1)
    }
    fn merge(g: Self::E, h: Self::E) -> Self::E {
        g + h
    }
    fn e() -> Self::T {
        (0, 0)
    }
    fn id() -> Self::E {
        0
    }
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut a = vec![];
    for _ in 0..n {
        let v: i64 = it.next().unwrap().parse().unwrap();
        a.push((v, 1));
    }
    let mut seg = LazySegmentTree::<R>::build_by(&a);
    let mut map = std::collections::BTreeMap::new();
    for i in 0..(n - 1) {
        let d: i64 = it.next().unwrap().parse().unwrap();
        map.insert(i + 1, a[i + 1].0 - a[i].0 - d);
    }
    map.insert(n, std::i64::MAX);
    let q: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..q {
        let op: char = it.next().unwrap().chars().next().unwrap();
        if op == 's' {
            let l: usize = it.next().unwrap().parse().unwrap();
            let r: usize = it.next().unwrap().parse().unwrap();
            let ans = seg.find(l - 1, r).0;
            writeln!(out, "{}", ans).ok();
        } else {
            let x = it.next().unwrap().parse::<usize>().unwrap() - 1;
            let mut d: i64 = it.next().unwrap().parse().unwrap();
            *map.entry(x).or_insert(0) += d;
            use std::ops::Bound::*;
            let mut memo = vec![];
            for (k, u) in map.range_mut((Included(&(x + 1)), Unbounded)) {
                if *u >= d {
                    *u -= d;
                    seg.update(x, *k, d);
                    break;
                }
                memo.push(*k);
                seg.update(x, *k, *u);
                d -= *u;
            }
            for k in memo {
                map.remove(&k);
            }
        }
    }
}

fn main() {
    run();
}
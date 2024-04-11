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

struct R;
impl TE for R {
    type T = usize;
    type E = usize;
    fn fold(l: Self::T, r: Self::T) -> Self::T {
        std::cmp::max(l, r)
    }
    fn eval(x: Self::T, f: Self::E) -> Self::T {
        x + f
    }
    fn merge(g: Self::E, h: Self::E) -> Self::E {
        g + h
    }
    fn e() -> Self::T {
        0
    }
    fn id() -> Self::E {
        0
    }
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut a: Vec<usize> = it.map(|s| s.parse().unwrap()).collect();
    a.append(&mut a.clone());
    let mut s = 0;
    while a[s] != 1 {
        s += 1;
    }
    let mut seg = LazySegmentTree::<R>::build_by(&vec![0; 2 * n]);
    let mut stack = vec![(1, s)];
    let mut right = vec![0; n];
    for i in (s + 1)..(s + n) {
        let v = a[i];
        while let Some(&(x, _)) = stack.last() {
            if v <= x {
                stack.pop();
            } else {
                break;
            }
        }
        let (_, y) = *stack.last().unwrap();
        seg.update(i, i + 1, stack.len());
        if y + 1 < i {
            seg.update(y + 1, i, 1);
        }
        stack.push((v, i));
        right[i - s] = seg.find(0, 2 * n);
    }
    let mut seg = LazySegmentTree::<R>::build_by(&vec![0; 2 * n]);
    let mut stack = vec![(1, n + s)];
    let mut left = vec![0; n];
    for i in ((s + 1)..(s + n)).rev() {
        let v = a[i];
        while let Some(&(x, _)) = stack.last() {
            if v <= x {
                stack.pop();
            } else {
                break;
            }
        }
        let (_, y) = *stack.last().unwrap();
        seg.update(i, i + 1, stack.len());
        if i + 1 < y {
            seg.update(i + 1, y, 1);
        }
        stack.push((v, i));
        left[n + s - i] = seg.find(0, 2 * n);
    }
    let mut ans = (1_000_000, 0);
    for i in 0..n {
        let d = std::cmp::max(left[i], right[n - 1 - i]);
        ans = std::cmp::min(ans, (d, (s + n - i) % n));
    }
    println!("{} {}", ans.0 + 1, ans.1);
}

fn main() {
    run();
}
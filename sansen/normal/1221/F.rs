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
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

struct R;
impl TE for R {
    type T = (i64, i64);
    type E = i64;
    fn fold(l: Self::T, r: Self::T) -> Self::T {
        if l.0 >= r.0 {l} else {r}
    }
    fn eval(x: Self::T, f: Self::E) -> Self::T {
        (x.0 + f, x.1)
    }
    fn merge(g: Self::E, h: Self::E) -> Self::E {
        g + h
    }
    fn e() -> Self::T {
        (-1_000_000_000_000_000, 2_000_000_000)
    }
    fn id() -> Self::E {
        0
    }
}

fn run() {
    input! {
        n: usize,
        p: [(i64, i64, i64); n],
    }
    let mut p = p;
    for p in &mut p {
        if p.0 < p.1 {
            *p = (p.1, p.0, p.2);
        }
    }
    let mut z = Vec::with_capacity(2 * n);
    for &(x, y, _) in &p {
        z.push(x);
        z.push(y);
    }
    z.sort();
    z.dedup();
    let m = z.len();
    let mut ini = Vec::with_capacity(m);
    for i in 0..m {
        ini.push((-z[i], z[i]));
    }
    let mut s = LazySegmentTree::<R>::build_by(&ini);
    let mut g = vec![vec![]; m];
    for (x, y, c) in p {
        let r = z.binary_search(&x).unwrap() as usize;
        let l = z.binary_search(&y).unwrap() as usize;
        g[l].push((r, c));
        s.update(r, m, c);
    }
    let mut ans = (0, 2_000_000_000, 2_000_000_000);
    for l in 0..m {
        let (v, r) = s.find(l, m);
        let v = v + z[l];
        if v > ans.0 {
            ans = (v, z[l], r);
        }
        for &(r, c) in &g[l] {
            s.update(r, m, -c);
        }
    }
    println!("{}\n{1} {1} {2} {2}", ans.0, ans.1, ans.2);
}

fn main() {
    run();
}
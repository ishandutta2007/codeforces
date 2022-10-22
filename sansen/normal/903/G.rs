// ---------- begin Lazy Segment Tree ----------
pub trait TE {
    type T: Clone;
    type E: Clone;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T;
    fn eval(x: &Self::T, f: &Self::E) -> Self::T;
    fn merge(g: &Self::E, h: &Self::E) -> Self::E;
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
        let size = n.next_power_of_two();
        let bit = size.trailing_zeros() as usize;
        LazySegmentTree {
            size: size,
            bit: bit,
            a: vec![(R::e(), R::id()); 2 * size],
        }
    }
    pub fn build_by(z: &[R::T]) -> LazySegmentTree<R> {
        let mut seg = LazySegmentTree::<R>::new(z.len());
        for (a, z) in seg.a[seg.size..].iter_mut().zip(z.iter()) {
            a.0 = z.clone();
        }
        let a = &mut seg.a;
        for i in (1..seg.size).rev() {
            a[i].0 = R::fold(&a[2 * i].0, &a[2 * i + 1].0);
        }
        seg
    }
    fn apply(&mut self, x: usize, op: &R::E) {
        let node = &mut self.a[x];
        node.0 = R::eval(&node.0, op);
        node.1 = R::merge(&node.1, op);
    }
    fn propagate(&mut self, x: usize) {
        let mut op = R::id();
        std::mem::swap(&mut op, &mut self.a[x].1);
        self.apply(2 * x, &op);
        self.apply(2 * x + 1, &op);
    }
    fn propagate_range(&mut self, l: usize, r: usize) {
        let x = l + self.size;
        let y = r + self.size;
        let mut k = self.bit;
        while (x >> k) == (y >> k) {
            self.propagate(x >> k);
            k -= 1;
        }
        for i in ((x.trailing_zeros() as usize + 1)..=k).rev() {
            self.propagate(x >> i);
        }
        for i in ((y.trailing_zeros() as usize + 1)..=k).rev() {
            self.propagate(y >> i);
        }
    }
    fn save_range(&mut self, l: usize, r: usize) {
        let mut x = l + self.size;
        let mut y = r + self.size;
        let mut p = (x & 1) == 1;
        let mut q = (y & 1) == 1;
        x >>= 1;
        y >>= 1;
        while 0 < x && x < y {
            if p {
                self.a[x].0 = R::fold(&self.a[2 * x].0, &self.a[2 * x + 1].0);
            }
            if q {
                self.a[y].0 = R::fold(&self.a[2 * y].0, &self.a[2 * y + 1].0);
            }
            p |= (x & 1) == 1;
            q |= (y & 1) == 1;
            x >>= 1;
            y >>= 1;
        }
        while 0 < x {
            self.a[x].0 = R::fold(&self.a[2 * x].0, &self.a[2 * x + 1].0);
            x >>= 1;
        }
    }
    pub fn update(&mut self, l: usize, r: usize, op: R::E) {
        self.propagate_range(l, r);
        let mut x = l + self.size;
        let mut y = r + self.size;
        while x < y {
            if x & 1 == 1 {
                self.apply(x, &op);
                x += 1;
            }
            if y & 1 == 1 {
                y -= 1;
                self.apply(y, &op);
            }
            x >>= 1;
            y >>= 1;
        }
        self.save_range(l, r);
    }
    pub fn find(&mut self, l: usize, r: usize) -> R::T {
        self.propagate_range(l, r);
        let mut x = l + self.size;
        let mut y = r + self.size;
        let mut p = R::e();
        let mut q = R::e();
        while x < y {
            if x & 1 == 1 {
                p = R::fold(&p, &self.a[x].0);
                x += 1;
            }
            if y & 1 == 1 {
                y -= 1;
                q = R::fold(&self.a[y].0, &q);
            }
            x >>= 1;
            y >>= 1;
        }
        R::fold(&p, &q)
    }
}
// ---------- end Lazy Segment Tree ----------
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(T, T) -> T> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(T, T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(a[2 * k].clone(), a[2 * k + 1].clone());
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.n)).rev() {
                self.a[k] = (self.op)(self.a[2 * k].clone(), self.a[2 * k + 1].clone());
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(p, self.a[l].clone());
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(self.a[r].clone(), q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(p, q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
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

use std::io::Write;

struct RMQandRAQ;
impl TE for RMQandRAQ {
    type T = i64;
    type E = i64;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        std::cmp::min(*l, *r)
    }
    fn eval(x: &Self::T, f: &Self::E) -> Self::T {
        *x + *f
    }
    fn merge(g: &Self::E, h: &Self::E) -> Self::E {
        *g + *h
    }
    fn e() -> Self::T {
        std::i64::MAX / 10
    }
    fn id() -> Self::E {
        0
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        q: usize,
        p: [(i64, i64); n - 1],
        e: [(usize1, usize1, i64); m],
        ask: [(usize1, i64); q],
    }
    let mut b = vec![];
    for p in p.iter() {
        b.push(p.1);
    }
    b.push(RMQandRAQ::e());
    let mut seg = LazySegmentTree::<RMQandRAQ>::build_by(&b);
    let mut g = vec![vec![]; n];
    for (a, b, c) in e {
        g[a].push((b, c));
    }
    let mut dp = vec![0; n];
    for (i, g) in g.into_iter().enumerate() {
        for (b, c) in g.into_iter() {
            let flow = std::cmp::min(c, seg.find(b, n));
            dp[i] += flow;
            seg.update(b, n, -flow);
        }
    }
    let inf = RMQandRAQ::e();
    let mut seg = segment_tree::PURQ::new(n, (inf, 0), |(c, v), (d, u)| {
        if c <= u {
            (0, v + c)
        } else {
            (std::cmp::min(c - u, d), v + u)
        }
    });
    for i in 0..(n - 1) {
        seg.update_tmp(i, (p[i].0, dp[i]));
    }
    seg.update_tmp(n - 1, (inf, dp[n - 1]));
    seg.update_all();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", seg.find(0, n).1).ok();
    for (v, w) in ask {
        seg.update(v, (w, dp[v]));
        writeln!(out, "{}", seg.find(0, n).1).ok();
    }
}

fn main() {
    run();
}
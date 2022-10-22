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

impl<R: TE> LazySegmentTree<R> {
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
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------

use std::io::Write;

struct R;
impl TE for R {
    type T = (i32, usize);
    type E = i32;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        if l.0 == r.0 {
            (l.0, l.1 + r.1)
        } else {
            std::cmp::min(*l, *r)
        }
    }
    fn eval(x: &Self::T, f: &Self::E) -> Self::T {
        (x.0 + *f, x.1)
    }
    fn merge(g: &Self::E, h: &Self::E) -> Self::E {
        *g + *h
    }
    fn e() -> Self::T {
        (std::i32::MAX / 10, 0)
    }
    fn id() -> Self::E {
        0
    }
}

fn run() {
    input! {
        t: usize,
        ask: [(usize, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, mut s) in ask {
        if s[0] == b'D' {
            for s in s.iter_mut() {
                *s ^= b'R' ^ b'D';
            }
        }
        let mut x = 0;
        let mut y = 0;
        for c in s.iter() {
            if *c == b'R' {
                y += 1;
            } else {
                x += 1;
            }
        }
        let (h, w) = (x, y);
        let mut ans = n;
        if let Some(d) = s.iter().position(|c| *c == b'D') {
            let mut x = 0;
            let mut y = 0;
            let mut query = vec![];
            for (i, c) in s.iter().enumerate() {
                if *c == b'R' {
                    y += 1;
                } else {
                    x += 1;
                }
                if i < d {
                    query.push((x, 1, y, y + n - w));
                    query.push((x + 1, -1, y, y + n - w));
                } else {
                    query.push((x, 1, y, y + n - w));
                    query.push((x + n - h, -1, y, y + n - w));
                }
            }
            let mut h = vec![];
            let mut w = vec![];
            for p in query.iter() {
                h.push(p.0);
                w.push(p.2);
                w.push(p.3);
            }
            h.sort();
            h.dedup();
            w.sort();
            w.dedup();
            query.sort();
            let ini = w.windows(2).map(|w| (0, w[1] - w[0])).collect::<Vec<_>>();
            let mut seg = LazySegmentTree::<R>::build_by(&ini);
            let mut x = 0;
            let mut sub = 0;
            for h in h.windows(2) {
                while x < query.len() && query[x].0 == h[0] {
                    let (_, v, l, r) = query[x];
                    let l = w.binary_search(&l).unwrap();
                    let r = w.binary_search(&r).unwrap();
                    seg.update(l, r, v);
                    x += 1;
                }
                let p = seg.find(0, ini.len());
                if p.0 == 0 {
                    sub += p.1 * (h[1] - h[0]);
                }
            }
            ans = (n - 1) * n - sub + 1;
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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
    // max, sum, tri sum, len
    type T = (u64, u64, u64, u64);
    type E = u64;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        (l.0.max(r.0), l.1 + r.1, l.2 + l.1 * r.3 + r.2, l.3 + r.3)
    }
    fn eval(x: &Self::T, f: &Self::E) -> Self::T {
        (x.0 + *f, x.1 + *f * x.3, x.2 + *f * x.3 * (x.3 + 1) / 2, x.3)
    }
    fn merge(g: &Self::E, h: &Self::E) -> Self::E {
        *g + *h
    }
    fn e() -> Self::T {
        (0, 0, 0, 0)
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
        a: [u64; n],
        b: [u64; m],
        ask: [(u8, usize, u64); q],
    }
    let db = b.windows(2).map(|b| {
        let d = b[1] - b[0];
        (d, d, d, 1)
    }).collect::<Vec<_>>();
    let mut a = a;
    let mut b = b;
    let mut sb = b[0];
    let mut seg = LazySegmentTree::<R>::build_by(&db);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (op, k, d) in ask {
        if op == 1 {
            for (i, a) in a.iter_mut().rev().enumerate().take(k) {
                *a += d * (k - i) as u64;
            }
        } else {
            seg.update((m - 1).saturating_sub(k), m - 1, d);
            if k == m {
                sb += d;
            }
        }
        let mut ans = (sb + a[0]) * (n + m - 1) as u64;
        let mut s = 0;
        for (i, a) in a.windows(2).enumerate() {
            let d = a[1] - a[0];
            let mut pos = 1;
            while pos < seg.size {
                seg.propagate(pos);
                let p = seg.a[2 * pos].0;
                if p.0 <= d {
                    pos = 2 * pos + 1;
                } else {
                    pos = 2 * pos;
                }
            }
            if (seg.a[pos].0).0 <= d {
                pos += 1;
            }
            pos -= seg.size;
            pos.chmax(s);
            pos.chmin(m - 1);
            if s < pos {
                let (_, sum, tri, _) = seg.find(s, pos);
                ans += tri + sum * (m - 1 - pos + n - 1 - i) as u64;
                s = pos;
            }
            ans += d * (m - 1 - s + n - 1 - i) as u64;
        }
        if s < m - 1 {
            ans += seg.find(s, m - 1).2;
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
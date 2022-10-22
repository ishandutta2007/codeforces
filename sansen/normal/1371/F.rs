// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        if *self > x {
            *self = x;
            true
        } else {
            false
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        if *self < x {
            *self = x;
            true
        } else {
            false
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

//

// flip
// 
// >>><<<  <<< 
// >>><<<  >>> 
// max
// ver

struct R;
impl TE for R {
    // 0: left, 1: right
    // 0:  1: 
    type T = Option<[(u32, [(u32, u32); 2], u32); 2]>;
    type E = usize;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        if l.is_none() {
            return r.clone();
        }
        if r.is_none() {
            return l.clone();
        }
        let l = l.as_ref().unwrap();
        let r = r.as_ref().unwrap();
        let mut ans = [(0, [(0, 0); 2], 0); 2];
        for (ans, (l, r)) in ans.iter_mut().zip(l.iter().zip(r.iter())) {
            ans.0.chmax(l.0);
            ans.0.chmax(r.0);
            ans.0.chmax(l.1[1].0 + r.1[0].1);
            ans.0.chmax(l.1[1].1 + r.1[0].0);
            ans.0.chmax(l.1[1].1 + r.1[0].1);
            ans.2 = l.2 + r.2;
            ans.1[0] = l.1[0];
            if l.1[0].0 == l.2 {
                ans.1[0].0.chmax(l.2 + r.1[0].1);
            }
            if l.1[0].1 == l.2 {
                ans.1[0].1.chmax(l.2 + r.1[0].1);
            }
            if l.1[1].1 == l.2 {
                ans.1[0].0.chmax(l.2 + r.1[0].0);
            }
            ans.1[1] = r.1[1];
            if r.1[1].0 == r.2 {
                ans.1[1].0.chmax(r.2 + l.1[1].1);
            }
            if r.1[1].1 == r.2 {
                ans.1[1].1.chmax(r.2 + l.1[1].1);
            }
            if r.1[0].1 == r.2 {
                ans.1[1].0.chmax(r.2 + l.1[1].0);
            }
        }
        Some(ans)
    }
    fn eval(x: &Self::T, f: &Self::E) -> Self::T {
        x.as_ref().map(|x| {
            [x[*f], x[*f ^ 1]]
        })
    }
    fn merge(g: &Self::E, h: &Self::E) -> Self::E {
        *g ^ *h
    }
    fn e() -> Self::T {
        None
//        [(0, [(0, 0); 2], 0); 2]
    }
    fn id() -> Self::E {
        0
    }
}

use std::io::Write;

fn run() {
    input! {
        _n: usize,
        q: usize,
        s: bytes,
        ask: [(usize1, usize); q],
    }
    let mut a = vec![];
    for s in s {
        let mut v = [(0, [(0, 0); 2], 0); 2];
        let k = (s == b'>') as usize;
        v[0].0 = 1;
        v[0].1[k].1 = 1;
        v[0].1[k ^ 1].0 = 1;
        v[0].2 = 1;
        v[1].0 = 1;
        v[1].1[k ^ 1].1 = 1;
        v[1].1[k].0 = 1;
        v[1].2 = 1;
        a.push(Some(v));
    }
    let mut seg = LazySegmentTree::<R>::build_by(&a);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r) in ask {
        seg.update(l, r, 1);
        let ans = seg.find(l, r).unwrap()[0].0;
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
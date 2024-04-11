use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        q: usize,
        p: [usize; n],
        ask: [(usize1, usize); q],
    }
    let mut event = vec![];
    for (i, &(l, r)) in ask.iter().enumerate() {
        event.push((l, 0, i));
        event.push((r, 0, i));
    }
    let area = beautiful_area(&p);
    for (i, &(_, _, d, u)) in area.iter().enumerate() {
        event.push((d, 1, i));
        event.push((u, 2, i));
    }
    event.sort_by_key(|p| p.0);
    let mut seg = LazySegmentTree::build((0..n).map(|_| (0, 0, 1)), n, R);
    let mut ans = vec![0; q];
    for (h, op, k) in event {
        if op == 0 {
            let (l, r) = ask[k];
            let (a, b, _) = seg.find(l, r);
            let v = a * (h as i64) + b;
            ans[k] += if h == l { -v } else { v };
        } else {
            let (l, r, d, u) = area[k];
            if op == 1 {
                seg.update(l, r + 1, (1, -(d as i64)));
            } else {
                seg.update(l, r + 1, (-1, (d + u - d + 1) as i64));
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

struct R;
impl TE for R {
    // a, b, len
    type T = (i64, i64, i64);
    type E = (i64, i64);
    fn fold(&self, l: &Self::T, r: &Self::T) -> Self::T {
        (l.0 + r.0, l.1 + r.1, l.2 + r.2)
    }
    fn eval(&self, x: &Self::T, f: &Self::E) -> Self::T {
        (x.0 + f.0 * x.2, x.1 + f.1 * x.2, x.2)
    }
    fn merge(&self, g: &Self::E, h: &Self::E) -> Self::E {
        (g.0 + h.0, g.1 + h.1)
    }
    fn e(&self) -> Self::T {
        (0, 0, 0)
    }
    fn id(&self) -> Self::E {
        (0, 0)
    }
}

// l, r, d, u
// 
fn beautiful_area(p: &[usize]) -> Vec<(usize, usize, usize, usize)> {
    let n = p.len();
    let mut ip = vec![0; n + 1];
    let mut seg = segment_tree::PURQ::new(n, (0, 0), |a, b| std::cmp::max(*a, *b));
    for (i, p) in p.iter().enumerate() {
        seg.update_tmp(i, (*p, i));
        ip[*p] = i;
    }
    seg.update_all();
    let mut dfs = vec![(0, n)];
    let mut area = vec![];
    while let Some((l, r)) = dfs.pop() {
        if l >= r {
            continue;
        }
        let (max, pos) = seg.find(l, r);
        dfs.push((l, pos));
        dfs.push((pos + 1, r));
        let mut memo = vec![];
        for i in (1..).take_while(|d| d * d < max) {
            if max % i != 0 {
                continue;
            }
            let x = ip[i];
            let y = ip[max / i];
            if !(l <= x && x < r && l <= y && y < r) {
                continue;
            }
            memo.push((pos.min(x).min(y), pos.max(x).max(y)));
        }
        memo.sort_by_key(|p| (p.1, !p.0));
        memo.dedup_by(|a, b| a.0 <= b.0);
        let mut last = l;
        for (x, y) in memo {
            area.push((last, x, y, r - 1));
            last = x + 1;
        }
    }
    area
}

fn main() {
    run();
}

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
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
// ---------- begin Lazy Segment Tree ----------
pub trait TE {
    type T: Clone;
    type E: Clone;
    fn fold(&self, l: &Self::T, r: &Self::T) -> Self::T;
    fn eval(&self, x: &Self::T, f: &Self::E) -> Self::T;
    fn merge(&self, g: &Self::E, h: &Self::E) -> Self::E;
    fn e(&self) -> Self::T;
    fn id(&self) -> Self::E;
}

pub struct LazySegmentTree<R: TE> {
    n: usize,
    size: usize,
    bit: u32,
    op: R,
    data: Vec<(R::T, R::E)>,
}

impl<R: TE> LazySegmentTree<R> {
    pub fn new(n: usize, op: R) -> Self {
        assert!(n > 0);
        let size = n.next_power_of_two();
        let bit = size.trailing_zeros();
        let data = vec![(op.e(), op.id()); 2 * size];
        Self {
            n,
            size,
            bit,
            op,
            data,
        }
    }
    pub fn build<I>(init: I, n: usize, op: R) -> Self
    where
        I: Iterator<Item = R::T>,
    {
        let mut seg = Self::new(n, op);
        for (data, ini) in seg.data[seg.size..].iter_mut().zip(init) {
            data.0 = ini;
        }
        for i in (1..seg.size).rev() {
            seg.pull(i);
        }
        seg
    }
    pub fn update(&mut self, l: usize, r: usize, f: R::E) {
        assert!(l <= r && r <= self.n);
        if l == r {
            return;
        }
        self.push_range(l, r);
        let mut s = l + self.size;
        let mut t = r + self.size;
        while s < t {
            if s & 1 == 1 {
                self.apply(s, &f);
                s += 1;
            }
            if t & 1 == 1 {
                t -= 1;
                self.apply(t, &f);
            }
            s >>= 1;
            t >>= 1;
        }
        let l = l + self.size;
        let r = r + self.size;
        for k in 1..=self.bit {
            if (l >> k) << k != l {
                self.pull(l >> k);
            }
            if (r >> k) << k != r {
                self.pull((r - 1) >> k);
            }
        }
    }
    pub fn find(&mut self, l: usize, r: usize) -> R::T {
        assert!(l <= r && r <= self.n);
        if l == r {
            return self.op.e();
        }
        self.push_range(l, r);
        let mut l = l + self.size;
        let mut r = r + self.size;
        let mut p = self.op.e();
        let mut q = self.op.e();
        while l < r {
            if l & 1 == 1 {
                p = self.op.fold(&p, &self.data[l].0);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                q = self.op.fold(&self.data[r].0, &q);
            }
            l >>= 1;
            r >>= 1;
        }
        self.op.fold(&p, &q)
    }
    pub fn set_at(&mut self, x: usize, v: R::T) {
        assert!(x < self.n);
        let x = x + self.size;
        for k in (1..=self.bit).rev() {
            self.push(x >> k);
        }
        self.data[x].0 = v;
        for k in 1..=self.bit {
            self.pull(x >> k);
        }
    }
    fn push_range(&mut self, l: usize, r: usize) {
        let l = l + self.size;
        let r = r + self.size;
        for k in (1..=self.bit).rev() {
            if (l >> k) << k != l {
                self.push(l >> k);
            }
            if (r >> k) << k != r {
                self.push((r - 1) >> k);
            }
        }
    }
    fn apply(&mut self, x: usize, f: &R::E) {
        self.data[x].0 = self.op.eval(&self.data[x].0, f);
        self.data[x].1 = self.op.merge(&self.data[x].1, f);
    }
    fn push(&mut self, x: usize) {
        let f = std::mem::replace(&mut self.data[x].1, self.op.id());
        self.apply(2 * x, &f);
        self.apply(2 * x + 1, &f);
    }
    fn pull(&mut self, x: usize) {
        self.data[x].0 = self.op.fold(&self.data[2 * x].0, &self.data[2 * x + 1].0);
    }
}
// ---------- end Lazy Segment Tree ----------
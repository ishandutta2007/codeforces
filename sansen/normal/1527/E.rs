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
    pub fn build(z: &[R::T]) -> LazySegmentTree<R> {
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
    fn propagate_at(&mut self, x: usize) {
        let op = std::mem::replace(&mut self.a[x].1, R::id());
        self.apply(2 * x, &op);
        self.apply(2 * x + 1, &op);
    }
    fn save_at(&mut self, x: usize) {
        self.a[x].0 = R::fold(&self.a[2 * x].0, &self.a[2 * x + 1].0);
    }
    fn propagate(&mut self, l: usize, r: usize) {
        let l = l + self.size;
        let r = r + self.size;
        for i in (1..=self.bit).rev() {
            if (l >> i) << i != l {
                self.propagate_at(l >> i);
            }
            if (r >> i) << i != r {
                self.propagate_at((r - 1) >> i);
            }
        }
    }
    fn save(&mut self, l: usize, r: usize) {
        let l = l + self.size;
        let r = r + self.size;
        for i in 1..=self.bit {
            if (l >> i) << i != l {
                self.save_at(l >> i);
            }
            if (r >> i) << i != r {
                self.save_at((r - 1) >> i);
            }
        }
    }
    pub fn set_at(&mut self, x: usize, v: R::T) {
        assert!(x < self.size);
        let y = x + self.size;
        for i in (1..=self.bit).rev() {
            self.propagate_at(y >> i);
        }
        self.a[y].0 = v;
        for i in 1..=self.bit {
            self.save_at(y >> i);
        }
    }
    pub fn update(&mut self, l: usize, r: usize, op: R::E) {
        assert!(l <= r && r <= self.size);
        if l == r {
            return;
        }
        self.propagate(l, r);
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
        self.save(l, r);
    }
    pub fn find(&mut self, l: usize, r: usize) -> R::T {
        assert!(l <= r && r <= self.size);
        if l == r {
            return R::e();
        }
        self.propagate(l, r);
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

const INF: u32 = 1_000_000_000;

struct R;
impl TE for R {
    type T = u32;
    type E = u32;
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
        INF
    }
    fn id() -> Self::E {
        0
    }
}

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [usize1; n],
    }
    let mut last = vec![None; n];
    let mut cost = vec![None; n];
    for (i, &a) in a.iter().enumerate().rev() {
        if let Some(x) = last[a] {
            cost[i] = Some((x, (x - i) as u32));
        }
        last[a] = Some(i);
    }
    let size = (n + 1).next_power_of_two();
    let mut dp = vec![INF; size];
    dp[n] = 0;
    for _ in 0..k {
        let mut next = vec![INF; size];
        let mut seg = LazySegmentTree::<R>::build(&dp);
        for i in (0..n).rev() {
            if let Some((x, c)) = cost[i] {
                seg.update(x + 1, size, c);
            }
            next[i] = seg.find(i + 1, size);
        }
        dp = next;
    }
    println!("{}", dp[0]);
}

fn main() {
    run();
}
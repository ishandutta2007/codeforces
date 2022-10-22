// https://twitter.com/SSRS_cp/status/1449976191813709824
//
// capacity toll DSU
// 
// capasity 
// v 
// capacity x_v
// toll y_v
// x_v  (enjoyment[v], y_v, y_v) 
// |a, b| 
// if a.0 == b.0 {
//     (a.0, a.1.min(b.1), a.2.max(b.2))
// } else {
//     max(a, b)
// }
//  (e, l, r) 
// enjoyment e
// l = l.min(pos(x)), r = r.max(pos(x)) 
// toll  l,r max 

// ---------- begin super slice ----------
pub trait SuperSlice {
    type Item;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn lower_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn lower_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn upper_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn upper_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
}

impl<T> SuperSlice for [T] {
    type Item = T;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.lower_bound_by(|p| p.cmp(key))
    }
    fn lower_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Greater))
            .unwrap_err()
    }
    fn lower_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.lower_bound_by(|p| f(p).cmp(key))
    }
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.upper_bound_by(|p| p.cmp(key))
    }
    fn upper_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Less))
            .unwrap_err()
    }
    fn upper_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.upper_bound_by(|p| f(p).cmp(key))
    }
}
// ---------- end super slice ----------
//---------- begin union_find ----------
// undo uniteRE
// snap unite 
pub struct DSU {
    parent: Vec<u32>,
    size: Vec<u32>,
    stack: Vec<Option<(u32, u32)>>,
}

impl DSU {
    pub fn new(n: usize) -> DSU {
        assert!(n < std::u32::MAX as usize);
        let mut res = DSU {
            parent: vec![0; n],
            size: vec![1; n],
            stack: vec![],
        };
        res.init();
        res
    }
    pub fn init(&mut self) {
        self.stack.clear();
        for (i, (parent, size)) in self.parent.iter_mut().zip(self.size.iter_mut()).enumerate() {
            *parent = i as u32;
            *size = 1;
        }
    }
    pub fn root(&self, mut x: usize) -> usize {
        assert!(x < self.parent.len());
        while self.parent[x] != x as u32 {
            x = self.parent[x] as usize;
        }
        x
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            self.stack.push(None);
            return None;
        }
        if (self.size[x], x) < (self.size[y], y) {
            std::mem::swap(&mut x, &mut y);
        }
        self.size[x] += self.size[y];
        self.parent[y] = x as u32;
        self.stack.push(Some((x as u32, y as u32)));
        Some((x, y))
    }
    pub fn parent(&self, x: usize) -> Option<usize> {
        assert!(x < self.parent.len());
        let p = self.parent[x];
        if p != x as u32 {
            Some(p as usize)
        } else {
            None
        }
    }
    pub fn sum<F>(&self, mut x: usize, mut f: F) -> usize
    where
        F: FnMut(usize),
    {
        while let Some(p) = self.parent(x) {
            f(x);
            x = p;
        }
        x
    }
    pub fn lca<F, C>(&self, mut x: usize, mut y: usize, mut f: F, mut cond: C) -> usize
    where
        F: FnMut(usize),
        C: FnMut(usize, usize) -> bool,
    {
        while x != y {
            if cond(x, y) {
                f(x);
                x = self.parent(x).unwrap();
            } else {
                f(y);
                y = self.parent(y).unwrap();
            }
        }
        x
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.parent.len());
        let r = self.root(x);
        self.size[r] as usize
    }
    pub fn undo(&mut self) -> Option<(usize, usize)> {
        self.stack.pop().unwrap().map(|(x, y)| {
            let x = x as usize;
            let y = y as usize;
            self.size[x] -= self.size[y];
            self.parent[y] = y as u32;
            (x, y)
        })
    }
    pub fn snap(&mut self) {
        self.stack.clear();
    }
    pub fn rollback(&mut self) {
        while !self.stack.is_empty() {
            self.undo();
        }
    }
}
//---------- end union_find ----------
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

fn run() {
    input! {
        n: usize,
        q: usize,
        a: [u32; n],
        e: [(usize1, usize1, u32, u32); n - 1],
        ask: [(u32, usize1); q],
    }
    let inf = 10u32.pow(9) + 1;
    let mut e = e;

    // capacity, (capacity, )
    let mut dp = vec![(0, 0, vec![(inf, 1)]); n];
    let mut dsu = DSU::new(n);
    e.sort_by_key(|e| e.2);
    for &(a, b, c, _) in e.iter().rev() {
        let (a, b) = dsu.unite(a, b).unwrap();
        dsu.undo();
        dp[b].0 = dsu.size(a);
        dp[b].1 = c;
        dsu.unite(a, b);
        dp[a].2.push((c, dsu.size(a)));
    }
    let left = (0..n)
        .map(|k| {
            let mut pos = 0;
            dsu.sum(k, |v| pos += dp[v].0);
            pos
        })
        .collect::<Vec<_>>();
    let (dp_capacity, dsu_capacity) = (dp, dsu);


    // toll
    let mut dp = vec![(0, inf); n];
    let mut dsu = DSU::new(n);
    e.sort_by_key(|e| e.3);
    for &(a, b, _, t) in e.iter() {
        let (a, b) = dsu.unite(a, b).unwrap();
        dsu.undo();
        dp[b] = (dsu.size(a), t);
        dsu.unite(a, b);
    }
    let toll_pos = (0..n)
        .map(|k| {
            let mut pos = 0;
            dsu.sum(k, |v| pos += dp[v].0);
            pos
        })
        .collect::<Vec<_>>();
    let mut inv_toll_pos = vec![0; n];
    for (i, toll_pos) in toll_pos.iter().enumerate() {
        inv_toll_pos[*toll_pos] = i;
    }
    let inv_toll_pos = inv_toll_pos;
    let (dp_toll, dsu_toll) = (dp, dsu);

    // 
    let mut seg = segment_tree::PURQ::new(n, (0, 0, 0), |a, b| {
        if a.0 == b.0 {
            (a.0, a.1.min(b.1), a.2.max(b.2))
        } else {
            std::cmp::max(*a, *b)
        }
    });
    for (v, a) in a.iter().enumerate() {
        let x = left[v];
        let pos = toll_pos[v];
        seg.update_tmp(x, (*a, pos, pos));
    }
    seg.update_all();
    let seg = seg;

    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (v, x) in ask {
        let mut root = x;
        while dp_capacity[root].1 >= v {
            root = dsu_capacity.parent(root).unwrap();
        }
        let history = &dp_capacity[root].2;
        let width = history[history.upper_bound_by_key(&!v, |p| !p.0) - 1].1;
        let (enjoyment, mut l, mut r) = seg.find(left[root], left[root] + width);
        l = l.min(toll_pos[x]);
        r = r.max(toll_pos[x]);
        let mut path_max = 0;
        dsu_toll.lca(
            inv_toll_pos[l],
            inv_toll_pos[r],
            |v| path_max = dp_toll[v].1,
            |a, b| dp_toll[a].1 <= dp_toll[b].1,
        );
        writeln!(out, "{} {}", enjoyment, path_max).ok();
    }
}

fn main() {
    run();
}
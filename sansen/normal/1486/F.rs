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
// ---------- begin Heavy-Light decomposition ----------
pub struct HLD {
    size: usize,
    edge: Vec<(usize, usize)>,
    child: Vec<Vec<usize>>,
    path_root: Vec<usize>,
    parent: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
    inverse: Vec<usize>,
}

impl HLD {
    pub fn new(size: usize) -> Self {
        assert!(size <= 10usize.pow(8));
        HLD {
            size: size,
            edge: Vec::with_capacity(size - 1),
            child: Vec::new(),
            path_root: Vec::new(),
            parent: Vec::new(),
            left: Vec::new(),
            right: Vec::new(),
            inverse: Vec::new(),
        }
    }
    pub fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a != b && a < self.size && b < self.size);
        self.edge.push((a, b));
    }
    pub fn build(&mut self, root: usize) {
        assert!(self.edge.len() + 1 == self.size);
        let size = self.size;
        let mut cnt = vec![0; size];
        for &(a, b) in self.edge.iter() {
            cnt[a] += 1;
            cnt[b] += 1;
        }
        let mut child = cnt
            .into_iter()
            .map(|c| Vec::with_capacity(c))
            .collect::<Vec<_>>();
        for &(a, b) in self.edge.iter() {
            child[a].push(b);
            child[b].push(a);
        }
        let mut parent = vec![size; size];
        let mut q = Vec::with_capacity(size);
        q.push(root);
        parent[root] = root;
        for i in 0..size {
            let v = q[i];
            for u in child[v].clone() {
                assert!(parent[u] == size);
                parent[u] = v;
                let k = child[u].iter().position(|e| *e == v).unwrap();
                child[u].remove(k);
                q.push(u);
            }
        }
        let mut sum = vec![1; size];
        for &v in q.iter().rev() {
            let child = &mut child[v];
            if !child.is_empty() {
                let mut max = (0, 0);
                for (i, &u) in child.iter().enumerate() {
                    sum[v] += sum[u];
                    max = std::cmp::max(max, (sum[u], i));
                }
                child.swap(0, max.1);
            }
        }
        let mut path_root = (0..size).collect::<Vec<_>>();
        let mut left = vec![0; size];
        let mut right = vec![0; size];
        let mut dfs = vec![(root, false)];
        let mut id = 0;
        while let Some((v, end)) = dfs.pop() {
            if end {
                right[v] = id;
                continue;
            }
            left[v] = id;
            id += 1;
            dfs.push((v, true));
            let child = &child[v];
            if !child.is_empty() {
                for &u in child.iter().skip(1) {
                    path_root[u] = u;
                    dfs.push((u, false));
                }
                let u = child[0];
                path_root[u] = path_root[v];
                dfs.push((u, false));
            }
        }
        let mut inverse = vec![0; size];
        for (i, l) in left.iter().enumerate() {
            inverse[*l] = i;
        }
        self.child = child;
        self.parent = parent;
        self.left = left;
        self.right = right;
        self.path_root = path_root;
        self.inverse = inverse;
    }
    pub fn lca(&self, mut a: usize, mut b: usize) -> usize {
        assert!(a < self.size && b < self.size);
        let path = &self.path_root;
        let parent = &self.parent;
        let index = &self.left;
        while path[a] != path[b] {
            if index[a] > index[b] {
                a = parent[path[a]];
            } else {
                b = parent[path[b]];
            }
        }
        (index[a], a).min((index[b], b)).1
    }
    pub fn path(
        &self,
        src: usize,
        dst: usize,
        up: &mut Vec<(usize, usize)>,
        down: &mut Vec<(usize, usize)>,
    ) {
        assert!(src < self.size && dst < self.size);
        up.clear();
        down.clear();
        let path = &self.path_root;
        let parent = &self.parent;
        let index = &self.left;
        let mut x = src;
        let mut y = dst;
        while path[x] != path[y] {
            if index[x] > index[y] {
                let p = path[x];
                assert!(p == path[p]);
                up.push((index[p], index[x] + 1));
                x = parent[p];
            } else {
                let p = path[y];
                assert!(p == path[p]);
                down.push((index[p], index[y] + 1));
                y = parent[p];
            }
        }
        if index[x] <= index[y] {
            down.push((index[x], index[y] + 1));
        } else {
            up.push((index[y], index[x] + 1));
        }
        down.reverse();
    }
    pub fn sub_tree(&self, v: usize) -> (usize, usize) {
        assert!(v < self.size);
        (self.left[v], self.right[v])
    }
    pub fn parent(&self, v: usize) -> Option<usize> {
        assert!(v < self.size);
        let p = self.parent[v];
        if p == v {
            None
        } else {
            Some(p)
        }
    }
    pub fn vertex(&self, x: usize) -> usize {
        assert!(x < self.size);
        self.inverse[x]
    }
    pub fn next(&self, p: usize, x: usize) -> usize {
        let (a, b) = self.sub_tree(p);
        let (c, d) = self.sub_tree(x);
        assert!(p != x && a <= c && d <= b);
        let mut x = x;
        let mut pre = x;
        while self.path_root[p] != self.path_root[x] {
            pre = self.path_root[x];
            x = self.parent[pre];
        }
        if x == p {
            pre
        } else {
            self.vertex(a + 1)
        }
    }
}
// ---------- end Heavy-Light decomposition ----------
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

// lca 
// 
// 
// 
// 1
// lca
// ^  | 
// 
// lca
// 
// lca

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
        m: usize,
        ask: [(usize1, usize1); m],
    }
    let mut hld = HLD::new(n);
    for (a, b) in e {
        hld.add_edge(a, b);
    }
    let root = 0;
    hld.build(root);
    let hld = hld;
    let mut query = vec![vec![]; n];
    for (a, b) in ask {
        let lca = hld.lca(a, b);
        query[lca].push((a, b));
    }
    let mut up = vec![];
    let mut down = vec![];
    let mut ord = (0..n)
        .map(|k| {
            hld.path(root, k, &mut up, &mut down);
            let depth = up.iter().chain(down.iter()).fold(0, |s, a| s + a.1 - a.0);
            (depth, k)
        })
        .collect::<Vec<_>>();
    ord.sort();
    let mut seg = segment_tree::PURQ::new(n, 0i64, |a, b| *a + *b);
    let mut cnt = vec![0; n + 1];
    let mut ans = 0i64;
    for (_, v) in ord.into_iter().rev() {
        let query = std::mem::take(&mut query[v]);
        let mut ask = vec![];
        for (a, b) in query {
            hld.path(a, b, &mut up, &mut down);
            for &(l, r) in up.iter().chain(down.iter()) {
                ans += seg.find(l, r);
            }
            if a == b {
                ask.push((n, n));
            } else if a == v {
                let c = hld.next(a, b);
                ask.push((c, n));
            } else if b == v {
                let c = hld.next(b, a);
                ask.push((c, n));
            } else {
                let c = hld.next(v, a);
                let d = hld.next(v, b);
                ask.push((c.min(d), c.max(d)));
            }
        }
        let mut map = std::collections::BTreeMap::new();
        for (i, &(c, d)) in ask.iter().enumerate() {
            if c == n {
                ans += i as i64;
            } else if d == n {
                ans += i as i64 - cnt[c];
                cnt[c] += 1;
            } else {
                ans += i as i64 - cnt[c] - cnt[d] + map.get(&(c, d)).cloned().unwrap_or(0);
                cnt[c] += 1;
                cnt[d] += 1;
                *map.entry((c, d)).or_insert(0) += 1;
            }
        }
        let x = hld.sub_tree(v).0;
        for (c, d) in ask {
            cnt[c] = 0;
            cnt[d] = 0;
            let v = seg.find(x, x + 1);
            seg.update(x, v + 1);
            if c == n {
            } else if d == n {
                let x = hld.sub_tree(c).0;
                let v = seg.find(x, x + 1);
                seg.update(x, v - 1);
            } else {
                for &c in [c, d].iter() {
                    let x = hld.sub_tree(c).0;
                    let v = seg.find(x, x + 1);
                    seg.update(x, v - 1);
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
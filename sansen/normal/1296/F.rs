// ---------- begin Heavy-Light decomposition ----------
struct HLD {
    graph: Vec<Vec<usize>>,
    path_root: Vec<usize>,
    path_parent: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
}

impl HLD {
    fn new(n: usize) -> Self {
        HLD {
            graph: vec![vec![]; n],
            path_root: vec![],
            path_parent: vec![],
            left: vec![],
            right: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        self.graph[a].push(b);
        self.graph[b].push(a);
    }
    fn build(&mut self, root: usize) {
        let mut q = vec![];
        let mut stack = vec![(root, root)];
        let graph = &mut self.graph;
        while let Some((v, p)) = stack.pop() {
            q.push(v);
            for i in 0..graph[v].len() {
                if graph[v][i] == p {
                    graph[v].swap_remove(i);
                    break;
                }
            }
            for &u in &graph[v] {
                stack.push((u, v));
            }
        }
        let n = graph.len();
        let mut size = vec![1; n];
        for &v in q.iter().rev() {
            for i in 0..graph[v].len() {
                let u = graph[v][i];
                size[v] += size[u];
                if size[u] > size[graph[v][0]] {
                    graph[v].swap(0, i);
                }
            }
        }
        let mut path_root = vec![root; n];
        let mut path_parent = vec![root; n];
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let mut stack = vec![(root, 0)];
        let mut k = 0;
        while let Some((v, op)) = stack.pop() {
            if op == 1 {
                right[v] = k;
                continue;
            }
            left[v] = k;
            k += 1;
            stack.push((v, 1));
            for i in 1..graph[v].len() {
                let u = graph[v][i];
                path_root[u] = u;
                path_parent[u] = v;
                stack.push((u, 0));
            }
            if graph[v].len() > 0 {
                let u = graph[v][0];
                path_root[u] = path_root[v];
                path_parent[u] = path_parent[v];
                stack.push((u, 0));
            }
        }
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.left = left;
        self.right = right;
    }
    fn sub_tree(&self, v: usize) -> (usize, usize) {
        (self.left[v], self.right[v])
    }
    fn path(&self, v: usize, u: usize) -> Vec<(usize, usize)> {
        let path = &self.path_root;
        let parent = &self.path_parent;
        let index = &self.left;
        let mut x = v;
        let mut y = u;
        let mut ans = vec![];
        while path[x] != path[y] {
            if index[x] < index[y] {
                let p = path[y];
                ans.push((index[p], index[y] + 1));
                y = parent[y];
            } else {
                let p = path[x];
                ans.push((index[p], index[x] + 1));
                x = parent[x];
            }
        }
        ans.push((std::cmp::min(index[x], index[y]), std::cmp::max(index[x], index[y]) + 1));
        ans
    }
}
// ---------- end Heavy-Light decomposition ----------
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
    type T = u32;
    type E = u32;
    fn fold(l: Self::T, r: Self::T) -> Self::T {
        std::cmp::min(l, r)
    }
    fn eval(x: Self::T, f: Self::E) -> Self::T {
        if f == 0 {
            x
        } else {
            f
        }
    }
    fn merge(g: Self::E, h: Self::E) -> Self::E {
        if h == 0 {
            g
        } else {
            h
        }
    }
    fn e() -> Self::T {
        1_000_000
    }
    fn id() -> Self::E {
        0
    }
}

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
        m: usize,
        p: [(usize1, usize1, u32); m],
    }
    let mut hld = HLD::new(n);
    for &(a, b) in e.iter() {
        hld.add_edge(a, b);
    }
    hld.build(0);
    let mut seg = LazySegmentTree::<R>::new(n);
    let mut p = p;
    p.sort_by_key(|p| p.2);
    for &(a, b, c) in p.iter() {
        let mut path = hld.path(a, b);
        let (l, r) = path.pop().unwrap();
        if l + 1 < r {
            seg.update(l + 1, r, c);
        }
        for (l, r) in path {
            seg.update(l, r, c);
        }
    }
    for &(a, b, c) in p.iter() {
        let mut ok = false;
        let mut path = hld.path(a, b);
        let (l, r) = path.pop().unwrap();
        if l + 1 < r {
            ok |= seg.find(l + 1, r) == c;
        }
        for (l, r) in path {
            ok |= seg.find(l, r) == c;
        }
        if !ok {
            println!("-1");
            return;
        }
    }
    let mut out = String::new();
    for &(a, b) in e.iter() {
        let (p, _) = hld.sub_tree(a);
        let (r, _) = hld.sub_tree(b);
        if p < r {
            out.push_str(&format!("{} ", seg.find(r, r + 1)));
        } else {
            out.push_str(&format!("{} ", seg.find(p, p + 1)));
        }
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
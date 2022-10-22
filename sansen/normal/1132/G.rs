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
            if let Some(k) = graph[v].iter().position(|u| *u == p) {
                graph[v].swap_remove(k);
            }
            for &u in graph[v].iter() {
                stack.push((u, v));
            }
        }
        let n = graph.len();
        let mut size = vec![1; n];
        for &v in q.iter().rev() {
            let child = &mut graph[v];
            if child.is_empty() {
                continue;
            }
            let mut max = (0, 0);
            for (i, &u) in child.iter().enumerate() {
                size[v] += size[u];
                max = std::cmp::max(max, (size[u], i));
            }
            child.swap(0, max.1);
        }
        let mut path_root = vec![root; n];
        let mut path_parent = vec![root; n];
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let mut stack = vec![(root, false)];
        let mut k = 0;
        while let Some((v, end)) = stack.pop() {
            if end {
                right[v] = k;
                continue;
            }
            left[v] = k;
            k += 1;
            stack.push((v, true));
            let child = &graph[v];
            if child.is_empty() {
                continue;
            }
            for &u in child.iter().skip(1) {
                path_root[u] = u;
                path_parent[u] = v;
                stack.push((u, false));
            }
            let u = child[0];
            path_root[u] = path_root[v];
            path_parent[u] = path_parent[v];
            stack.push((u, false));
        }
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.left = left;
        self.right = right;
    }
    #[allow(dead_code)]
    fn sub_tree(&self, v: usize) -> (usize, usize) {
        (self.left[v], self.right[v])
    }
    #[allow(dead_code)]
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

//

use std::cmp::*;

struct R;
impl TE for R {
    type T = i32;
    type E = i32;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        max(*l, *r)
    }
    fn eval(x: &Self::T, f: &Self::E) -> Self::T {
        *x + *f
    }
    fn merge(g: &Self::E, h: &Self::E) -> Self::E {
        *g + *h
    }
    fn e() -> Self::T {
        -1_000_000
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
    let mut a = a;
    a.push(n);
    let mut hld = HLD::new(n + 1);
    let mut h = std::collections::BinaryHeap::<Reverse<(usize, usize)>>::new();
    for (i, &a) in a.iter().enumerate() {
        while let Some(Reverse((v, k))) = h.pop() {
            if v < a {
                hld.add_edge(i, k);
            } else {
                h.push(Reverse((v, k)));
                break;
            }
        }
        h.push(Reverse((a, i)));
    }
    hld.build(n);
    let mut seg = LazySegmentTree::<R>::build_by(&vec![0; n + 1]);
    for i in 0..(k - 1) {
        let (l, r) = hld.sub_tree(i);
        seg.update(l, r, 1);
    }
    let mut ans = String::new();
    for i in 0..(n - k + 1) {
        let (l, r) = hld.sub_tree(i + k - 1);
        seg.update(l, r, 1);
        let v = seg.find(0, n + 1);
        ans.push_str(&format!("{} ", v));
        let (l, r) = hld.sub_tree(i);
        seg.update(l, r, -1);
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}
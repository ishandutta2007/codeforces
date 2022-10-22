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
    fn propagate_at(&mut self, x: usize) {
        let mut op = R::id();
        std::mem::swap(&mut op, &mut self.a[x].1);
        self.apply(2 * x, &op);
        self.apply(2 * x + 1, &op);
    }
    fn save_at(&mut self, x: usize) {
        self.a[x].0 = R::eval(&R::fold(&self.a[2 * x].0, &self.a[2 * x + 1].0), &self.a[x].1);
    }
    fn propagate(&mut self, x: usize) {
        let x = self.size + x;
        for i in (1..=self.bit).rev() {
            self.propagate_at(x >> i);
        }
    }
    fn save(&mut self, x: usize) {
        let mut x = (self.size + x) >> 1;
        while x > 0 {
            self.save_at(x);
            x >>= 1;
        }
    }
    pub fn set_at(&mut self, x: usize, val: R::T) {
        let y = x + self.size;
        for i in (1..=self.bit).rev() {
            self.propagate_at(y >> i);
        }
        self.a[y].0 = R::eval(&val, &self.a[y].1);
        let mut y = y >> 1;
        while y > 0 {
            self.save_at(y);
            y >>= 1;
        }
    }
    pub fn update(&mut self, l: usize, r: usize, op: R::E) {
        assert!(l < r && r <= self.size);
        self.propagate(l);
        self.propagate(r - 1);
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
        self.save(l);
        self.save(r - 1);
    }
    pub fn find(&mut self, l: usize, r: usize) -> R::T {
        assert!(l < r && r <= self.size);
        self.propagate(l);
        self.propagate(r - 1);
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
// ---------- begin Heavy-Light decomposition ----------
struct HLD {
    size: usize,
    root: usize,
    edge: Vec<(usize, usize)>,
    child: Vec<Vec<usize>>,
    parent: Vec<usize>,
    path_root: Vec<usize>,
    path_parent: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
}

#[allow(dead_code)]
impl HLD {
    fn new(size: usize) -> Self {
        HLD {
            size: size,
            root: size,
            edge: Vec::with_capacity(size - 1),
            child: vec![],
            parent: vec![],
            path_root: vec![],
            path_parent: vec![],
            left: vec![],
            right: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b));
    }
    fn build(&mut self, root: usize) {
        assert!(root < self.size);
        self.root = root;
        let n = self.size;
        let mut deg = vec![0; n];
        for &(a, b) in self.edge.iter() {
            deg[a] += 1;
            deg[b] += 1;
        }
        let mut graph = deg.into_iter().map(|d| Vec::with_capacity(d)).collect::<Vec<_>>();
        for &(a, b) in self.edge.iter() {
            graph[a].push(b);
            graph[b].push(a);
        }
        let mut parent = vec![root; n];
        let mut q = Vec::with_capacity(n);
        q.push(root);
        for i in 0..n {
            let v = q[i];
            let child = &mut graph[v];
            if let Some(k) = child.iter().position(|u| *u == parent[v]) {
                child.swap_remove(k);
            }
            for &u in child.iter() {
                parent[u] = v;
                q.push(u);
            }
        }
        assert!(q.len() == n);
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
        self.child = graph;
        self.parent = parent;
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.left = left;
        self.right = right;
    }
    fn sub_tree(&self, v: usize) -> (usize, usize) {
        (self.left[v], self.right[v])
    }
    // u -> vpath
    fn path(&self, v: usize, u: usize, up: &mut Vec<(usize, usize)>, down: &mut Vec<(usize, usize)>) {
        up.clear();
        down.clear();
        let path = &self.path_root;
        let parent = &self.path_parent;
        let index = &self.left;
        let mut x = v;
        let mut y = u;
        while path[x] != path[y] {
            if index[x] < index[y] {
                let p = path[y];
                down.push((index[p], index[y] + 1));
                y = parent[y];
            } else {
                let p = path[x];
                up.push((index[p], index[x] + 1));
                x = parent[x];
            }
        }
        if index[x] < index[y] {
            down.push((index[x], index[y] + 1));
        } else {
            up.push((index[y], index[x] + 1));
        }
        down.reverse();
    }
}
// ---------- end Heavy-Light decomposition ----------
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

struct R;
impl TE for R {
    type T = (u64, usize, usize);
    type E = u64;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        std::cmp::min(*l, *r)
    }
    fn eval(x: &Self::T, f: &Self::E) -> Self::T {
        (x.0 + *f, x.1, x.2)
    }
    fn merge(g: &Self::E, h: &Self::E) -> Self::E {
        *g + *h
    }
    fn e() -> Self::T {
        (std::u64::MAX / 2, 100_000, 100_000)
    }
    fn id() -> Self::E {
        0
    }
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let q: usize = sc.next();
    let mut hld = HLD::new(n);
    for _ in 1..n {
        let a = sc.next::<usize>() - 1;
        let b = sc.next::<usize>() - 1;
        hld.add_edge(a, b);
    }
    hld.build(0);
    let mut set = vec![std::collections::BTreeSet::new(); n];
    let mut c = vec![0usize; m];
    for (i, c) in c.iter_mut().enumerate() {
        *c = sc.next();
        *c -= 1;
        set[*c].insert(i);
    }
    let mut seg = LazySegmentTree::<R>::new(n);
    for (i, set) in set.iter_mut().enumerate() {
        if let Some(&k) = set.iter().next() {
            set.remove(&k);
            let x = hld.sub_tree(i).0;
            seg.set_at(x, (k as u64, i, k));
        }
    }
    let mut up = vec![];
    let mut down = vec![];
    for _ in 0..q {
        let op: u8 = sc.next();
        if op == 1 {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            let k = sc.next::<usize>();
            let mut ans = vec![];
            hld.path(a, b, &mut up, &mut down);
            for _ in 0..k {
                let mut res = R::e();
                for &(l, r) in up.iter().chain(down.iter()) {
                    res = R::fold(&res, &seg.find(l, r));
                }
                if res.2 >= m {
                    break;
                }
                ans.push(res.2);
                let c = res.1;
                let set = &mut set[c];
                if let Some(&v) = set.iter().next() {
                    set.remove(&v);
                    let x = hld.sub_tree(c).0;
                    seg.set_at(x, (v as u64, c, v));
                } else {
                    let x = hld.sub_tree(c).0;
                    seg.set_at(x, R::e());
                }
            }
            let mut s = String::new();
            s.push_str(&format!("{}", ans.len()));
            for a in ans {
                s.push_str(&format!(" {}", a + 1));
            }
            writeln!(out, "{}", s).ok();
        } else {
            let a = sc.next::<usize>() - 1;
            let w: u64 = sc.next();
            let (l, r) = hld.sub_tree(a);
            seg.update(l, r, w);
        }
    }
}
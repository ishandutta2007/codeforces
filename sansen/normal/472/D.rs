//---------- begin union_find ----------
pub struct DSU {
    p: Vec<i32>,
}
impl DSU {
    pub fn new(n: usize) -> DSU {
        assert!(n < std::i32::MAX as usize);
        DSU { p: vec![-1; n] }
    }
    pub fn init(&mut self) {
        self.p.iter_mut().for_each(|p| *p = -1);
    }
    pub fn root(&self, mut x: usize) -> usize {
        assert!(x < self.p.len());
        while self.p[x] >= 0 {
            x = self.p[x] as usize;
        }
        x
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.p.len() && y < self.p.len());
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.p.len() && y < self.p.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            return None;
        }
        if self.p[x] > self.p[y] {
            std::mem::swap(&mut x, &mut y);
        }
        self.p[x] += self.p[y];
        self.p[y] = x as i32;
        Some((x, y))
    }
    pub fn parent(&self, x: usize) -> Option<usize> {
        assert!(x < self.p.len());
        let p = self.p[x];
        if p >= 0 {
            Some(p as usize)
        } else {
            None
        }
    }
    pub fn sum<F>(&self, mut x: usize, mut f: F) -> usize
    where F: FnMut(usize),
    {
        while let Some(p) = self.parent(x) {
            f(x);
            x = p;
        }
        x
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.p.len());
        let r = self.root(x);
        (-self.p[r]) as usize
    }
}
//---------- end union_find ----------
// ---------- begin Lowest Common Ancestor ----------
struct LCA {
    graph: Vec<Vec<usize>>,
    parent: Vec<usize>,
    path_root: Vec<usize>,
    path_parent: Vec<usize>,
    index: Vec<usize>
}

impl LCA {
    fn new(n: usize) -> Self {
        LCA {
            graph: vec![vec![]; n],
            parent: vec![],
            path_root: vec![],
            path_parent: vec![],
            index: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a != b && a < self.graph.len() && b < self.graph.len());
        self.graph[a].push(b);
        self.graph[b].push(a);
    }
    fn build(&mut self, root: usize) {
        let n = self.graph.len();
        assert!(root < n);
        let mut parent = vec![root; n];
        let mut q = vec![root];
        let graph = &mut self.graph;
        for i in 0..n {
            let v = q[i];
            let p = parent[v];
            let child = &mut graph[v];
            if let Some(k) = child.iter().position(|u| *u == p) {
                child.swap_remove(k);
            }
            for &u in child.iter() {
                parent[u] = v;
                q.push(u);
            }
        }
        let mut size = vec![1; n];
        for &v in q.iter().rev() {
            if graph[v].is_empty() {
                continue;
            }
            let mut max = (0, 0);
            for (i, &u) in graph[v].iter().enumerate() {
                size[v] += size[u];
                if size[u] > max.0 {
                    max = (size[u], i);
                }
            }
            graph[v].swap(0, max.1);
        }
        let mut path_root = vec![root; n];
        let mut path_parent = vec![root; n];
        let mut index = vec![n; n];
        let mut stack = vec![root];
        let mut k = 0;
        while let Some(v) = stack.pop() {
            index[v] = k;
            k += 1;
            if graph[v].is_empty() {
                continue;
            }
            for &u in graph[v].iter().skip(1) {
                path_root[u] = u;
                path_parent[u] = v;
                stack.push(u);
            }
            let u = graph[v][0];
            path_root[u] = path_root[v];
            path_parent[u] = path_parent[v];
            stack.push(u);
        }
        self.parent = parent;
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.index = index;
    }
    fn query(&self, mut a: usize, mut b: usize) -> usize {
        let path = &self.path_root;
        let parent = &self.path_parent;
        let index = &self.index;
        while path[a] != path[b] {
            if index[a] < index[b] {
                b = parent[b];
            } else {
                a = parent[a];
            }
        }
        if index[a] < index[b] {a} else {b}
    }
    fn parent(&self, v: usize) -> Option<usize> {
        let p = self.parent[v];
        if p == v {
            None
        } else {
            Some(p)
        }
    }
}
// ---------- end Lowest Common Ancestor ----------
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

fn dfs(v: usize, p: usize, depth: &mut [u64], g: &[Vec<(usize, u64)>]) {
    for &(u, d) in g[v].iter() {
        if u != p {
            depth[u] = depth[v] + d;
            dfs(u, v, depth, g);
        }
    }
}

fn run() {
    input! {
        n: usize,
        d: [[u64; n]; n],
    }
    let mut p = vec![];
    for (i, d) in d.iter().enumerate() {
        for (j, d) in d.iter().enumerate().skip(i + 1) {
            if *d == 0 {
                println!("NO");
                return;
            }
            p.push((*d, i, j));
        }
    }
    p.sort();
    let mut lca = LCA::new(n);
    let mut g = vec![vec![]; n];
    let mut dsu = DSU::new(n);
    for (d, a, b) in p {
        if dsu.unite(a, b).is_some() {
            lca.add_edge(a, b);
            g[a].push((b, d));
            g[b].push((a, d));
        }
    }
    lca.build(0);
    let mut depth = vec![0; n];
    dfs(0, n, &mut depth, &g);
    for (i, d) in d.iter().enumerate() {
        for (j, d) in d.iter().enumerate() {
            let v = depth[i] + depth[j] - 2 * depth[lca.query(i, j)];
            if v != *d {
                println!("NO");
                return;
            }
        }
    }
    println!("YES");
}

fn main() {
    run();
}
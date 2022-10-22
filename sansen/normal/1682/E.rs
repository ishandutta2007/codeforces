use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        m: usize,
        p: [usize; n],
        e: [(usize, usize); m],
    }
    let mut p = p;
    p.insert(0, 0);
    let mut ip = vec![0; n + 1];
    for (i, p) in p.iter().enumerate() {
        ip[*p] = i;
    }
    let (p, ip) = (p, ip);
    let mut dsu = QuickFind::new(n + 1);
    let mut hld = HLD::new(n + 1);
    let mut map = Map::new();
    for (i, &(a, b)) in e.iter().enumerate() {
        assert!(dsu.unite(a, b).is_some());
        hld.add_edge(a, b);
        map.insert((a, b), i);
        map.insert((b, a), i);
    }
    for i in 1..=n {
        if i == dsu.root(i) {
            hld.add_edge(i, 0);
        }
    }
    hld.build(0);
    let mut ans = vec![];
    let mut deg = vec![0; n + 1];
    let mut child = vec![vec![]; n + 1];
    for i in 1..=n {
        if i != dsu.root(i) || dsu.size(i) == 1 {
            continue;
        }
        let v = Vec::from(dsu.enumerate(i));
        let mut edge = vec![];
        for &v in v.iter() {
            let mut pos = ip[v];
            let mut p = m;
            while pos != v {
                let u = hld.next(pos, v);
                let k = map[&(pos, u)];
                edge.push(k);
                if p != m {
                    deg[k] += 1;
                    child[p].push(k);
                }
                p = k;
                pos = u;
            }
        }
        edge.sort();
        edge.dedup();
        let mut topo = vec![];
        for &k in edge.iter() {
            if deg[k] == 0 {
                topo.push(k);
            }
        }
        for i in 0..edge.len() {
            let k = topo[i];
            for &u in child[k].iter() {
                deg[u] -= 1;
                if deg[u] == 0 {
                    topo.push(u);
                }
            }
        }
        ans.append(&mut topo);
    }
    let mut p = p;
    for k in ans.iter() {
        let (a, b) = e[*k];
        p.swap(a, b);
    }
    assert!(p.windows(2).all(|p| p[0] < p[1]));
    use util::*;
    println!("{}", ans.iter().map(|a| *a + 1).join(" "));
}

fn main() {
    run();
}

mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
}
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
                child[u].retain(|e| *e != v);
                q.push(u);
            }
        }
        let mut sum = vec![1; size];
        for &v in q.iter().rev() {
            let child = &mut child[v];
            if !child.is_empty() {
                let (pos, _) = child.iter().enumerate().max_by_key(|p| sum[*p.1]).unwrap();
                child.swap(0, pos);
                sum[v] = 1 + child.iter().fold(0, |s, a| s + sum[*a]);
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
                for &u in child[1..].iter() {
                    path_root[u] = u;
                    dfs.push((u, false));
                }
                let u = child[0];
                path_root[u] = path_root[v];
                dfs.push((u, false));
            }
        }
        let mut inverse = vec![size; size];
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
                std::mem::swap(&mut a, &mut b);
            }
            b = parent[path[b]];
        }
        std::cmp::min((index[a], a), (index[b], b)).1
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
    // s -> t 2
    pub fn next(&self, s: usize, t: usize) -> usize {
        assert!(s < self.size && t < self.size && s != t);
        let (a, b) = self.sub_tree(s);
        let (c, d) = self.sub_tree(t);
        if !(a <= c && d <= b) {
            return self.parent[s];
        }
        let mut pos = t;
        let mut pre = t;
        while self.path_root[s] != self.path_root[pos] {
            pre = self.path_root[pos];
            pos = self.parent[pre];
        }
        if s == pos {
            pre
        } else {
            self.child[s][0]
        }
    }
    pub fn vertex(&self, x: usize) -> usize {
        assert!(x < self.size);
        self.inverse[x]
    }
}
// ---------- end Heavy-Light decomposition ----------
// ---------- begin quick find ----------
pub struct QuickFind {
    size: usize,
    id: Vec<usize>,
    list: Vec<Vec<usize>>,
}

impl QuickFind {
    pub fn new(size: usize) -> Self {
        let id = (0..size).collect::<Vec<_>>();
        let list = (0..size).map(|x| vec![x]).collect::<Vec<_>>();
        QuickFind { size, id, list }
    }
    pub fn root(&self, x: usize) -> usize {
        assert!(x < self.size);
        self.id[x]
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.size);
        assert!(y < self.size);
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.size);
        assert!(y < self.size);
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            return None;
        }
        if (self.list[x].len(), x) < (self.list[y].len(), y) {
            std::mem::swap(&mut x, &mut y);
        }
        let mut z = std::mem::take(&mut self.list[y]);
        z.iter().for_each(|y| self.id[*y] = x);
        self.list[x].append(&mut z);
        Some((x, y))
    }
    pub fn enumerate(&self, x: usize) -> &[usize] {
        assert!(x < self.size);
        &self.list[self.root(x)]
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.size);
        self.enumerate(x).len()
    }
}
// ---------- end quick find ----------
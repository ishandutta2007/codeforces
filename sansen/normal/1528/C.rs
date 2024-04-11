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
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

use std::collections::*;

type Set<T> = BTreeSet<T>;

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a = vec![vec![]; n];
        for i in 1..n {
            let p = sc.next::<usize>() - 1;
            a[p].push(i);
        }
        let mut hld = HLD::new(n);
        for i in 1..n {
            let b = sc.next::<usize>() - 1;
            hld.add_edge(b, i);
        }
        hld.build(0);
        let range = (0..n).map(|v| hld.sub_tree(v)).collect::<Vec<_>>();
        let mut ans = 0;
        dfs(0, &a, &range, &mut Set::new(), &mut ans);
        writeln!(out, "{}", ans).ok();
    }
}

fn dfs(v: usize, g: &[Vec<usize>], range: &[(usize, usize)], set: &mut Set<(usize, usize)>, ans: &mut usize) {
    let (l, r) = range[v];
    let mut cond = true;
    if let Some(&p) = set.range((l, 0)..).next() {
        if p.1 <= r {
            cond = false;
        }
    }
    let mut del = None;
    if let Some(&p) = set.range(..(l, r)).next_back() {
        if p.0 <= l && r <= p.1 {
            del = Some(p);
            set.remove(&p);
        }
    }
    if cond {
        set.insert((l, r));
    }
    *ans = set.len().max(*ans);
    for &u in g[v].iter() {
        dfs(u, g, range, set, ans);
    }
    set.remove(&(l, r));
    if let Some(p) = del {
        set.insert(p);
    }
}
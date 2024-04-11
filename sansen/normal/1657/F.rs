// ---------- begin 2-SAT ----------
struct StaticGraph {
    elist: Vec<u32>,
    starts: Vec<u32>,
}

impl StaticGraph {
    fn new<I>(size: usize, edge: I) -> Self
    where
        I: Iterator<Item = (usize, usize)> + Clone,
    {
        let mut starts = vec![0u32; size + 1];
        for (a, b) in edge.clone() {
            assert!(a < size && b < size);
            starts[a + 1] += 1;
        }
        for i in 1..=size {
            starts[i] += starts[i - 1];
        }
        let mut elist = vec![0; starts[size] as usize];
        let mut pos = starts.clone();
        for (a, b) in edge {
            let po = &mut pos[a];
            elist[*po as usize] = b as u32;
            *po += 1;
        }
        Self { elist, starts }
    }
    fn neighbor(&self, v: usize) -> impl Iterator<Item = usize> + '_ {
        let s = self.starts[v] as usize;
        let t = self.starts[v + 1] as usize;
        self.elist[s..t].iter().map(|u| *u as usize)
    }
}

pub fn strongly_connected_components<G, I>(size: usize, graph: G) -> (usize, Vec<usize>)
where
    G: Fn(usize) -> I,
    I: Iterator<Item = usize>,
{
    let mut ord = vec![0; size];
    let mut res = vec![0; size];
    let mut vertex = vec![];
    let mut dfs = vec![];
    let mut id = 0;
    for s in 0..size {
        if ord[s] > 0 {
            continue;
        }
        vertex.push(s);
        ord[s] = vertex.len();
        dfs.push((s, graph(s)));
        while let Some((v, mut it)) = dfs.pop() {
            (|| {
                while let Some(u) = it.next() {
                    if ord[u] == 0 {
                        vertex.push(u);
                        ord[u] = vertex.len();
                        dfs.push((v, it));
                        dfs.push((u, graph(u)));
                        return;
                    }
                }
                let low = ord[v].min(graph(v).map(|u| ord[u]).min().unwrap_or(ord[v]));
                if low < ord[v] {
                    ord[v] = low;
                    return;
                }
                while let Some(u) = vertex.pop() {
                    ord[u] = !0;
                    res[u] = id;
                    if u == v {
                        break;
                    }
                }
                id += 1;
            })();
        }
    }
    res.iter_mut().for_each(|p| *p = id - 1 - *p);
    (id, res)
}

pub struct SAT2 {
    size: usize,
    clause: Vec<(usize, usize)>,
}

impl SAT2 {
    pub fn new(size: usize) -> Self {
        SAT2 {
            size: size,
            clause: vec![],
        }
    }
    pub fn either(&mut self, a: usize, b: usize) {
        assert!(a.min(!a) < self.size && b.min(!b) < self.size);
        self.clause.push((a, b));
    }
    pub fn add_variable(&mut self) -> usize {
        let v = self.size;
        self.size += 1;
        v
    }
    pub fn at_most_one<V>(&mut self, mut list: V)
    where
        V: Iterator<Item = usize> + Clone,
    {
        let size = list.clone().count();
        if size <= 1 {
            return;
        }
        let mut cur = !list.next().unwrap();
        for v in list.clone().skip(1) {
            let next = self.add_variable();
            self.either(cur, !v);
            self.either(cur, next);
            self.either(!v, next);
            cur = !next;
        }
        self.either(cur, !list.next().unwrap());
    }
    pub fn solve(&self) -> Option<Vec<bool>> {
        let size = self.size;
        let g = StaticGraph::new(
            2 * size,
            self.clause.iter().flat_map(|&(a, b)| {
                let (x, ix) = if a >= size {
                    (!a + size, !a)
                } else {
                    (a, a + size)
                };
                let (y, iy) = if b >= size {
                    (!b + size, !b)
                } else {
                    (b, b + size)
                };
                assert!(x.max(ix).max(y).max(iy) < 2 * size);
                [(ix, y), (iy, x)]
            }),
        );
        let (_, id) = strongly_connected_components(2 * size, |v| g.neighbor(v));
        let mut ans = Vec::with_capacity(size);
        for (a, b) in id.iter().zip(id[size..].iter()) {
            if *a == *b {
                return None;
            } else {
                ans.push(*a > *b);
            }
        }
        Some(ans)
    }
}
// ---------- end 2-SAT ----------
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
        e: [(usize1, usize1); n - 1],
        cond: [(usize1, usize1, bytes); q],
    }
    let mut hld = HLD::new(n);
    for &(a, b) in e.iter() {
        hld.add_edge(a, b);
    }
    let root = 0;
    hld.build(root);
    let find = |map: &[Vec<(u8, usize)>], v: usize, c: u8| -> Option<usize> {
        map[v].iter().find(|p| p.0 == c).map(|p| p.1)
    };
    let mut sat = SAT2::new(q);
    let mut map = vec![vec![]; n];
    for (i, (x, y, s)) in cond.iter().cloned().enumerate() {
        for (j, &(src, dst)) in [(x, y), (y, x)].iter().enumerate() {
            if find(&map, src, s[0]).is_none() {
                map[src].push((s[0], sat.add_variable()));
            }
            let p = if j > 0 { !i } else { i };
            sat.either(!p, find(&map, src, s[0]).unwrap());
            let mut pos = src;
            for &s in s[1..].iter() {
                pos = hld.next(pos, dst);
                if find(&map, pos, s).is_none() {
                    map[pos].push((s, sat.add_variable()));
                }
                sat.either(!p, find(&map, pos, s).unwrap());
            }
        }
    }
    for map in map.iter() {
        sat.at_most_one(map.iter().map(|p| p.1));
    }
    if let Some(ans) = sat.solve() {
        println!("YES");
        let mut s = vec![b'a'; n];
        for (i, map) in map.into_iter().enumerate() {
            for a in map.iter() {
                let v = a.1;
                if ans[v] {
                    s[i] = a.0;
                }
            }
        }
        let s = s.into_iter().map(|s| s as char).collect::<String>();
        println!("{}", s);
    } else {
        println!("NO");
    }
}

fn main() {
    run();
}
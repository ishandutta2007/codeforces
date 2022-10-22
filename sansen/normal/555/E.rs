// ---------- begin Heavy-Light decomposition ----------
struct HLD {
    size: usize,
    edge: Vec<(usize, usize)>,
    child: Vec<Vec<usize>>,
    path_root: Vec<usize>,
    parent: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
}

impl HLD {
    fn new(size: usize) -> Self {
        assert!(size <= 10usize.pow(8));
        HLD {
            size: size,
            edge: Vec::with_capacity(size - 1),
            child: Vec::new(),
            path_root: Vec::new(),
            parent: Vec::new(),
            left: Vec::new(),
            right: Vec::new(),
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a != b && a < self.size && b < self.size);
        self.edge.push((a, b));
    }
    fn build(&mut self, root: usize) {
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
            for j in 0..child[v].len() {
                let u = child[v][j];
                assert!(parent[u] == size);
                parent[u] = v;
                let k = child[u].iter().position(|e| *e == v).unwrap();
                child[u].remove(k);
                q.push(u);
            }
        }
        let mut sum = vec![1; size];
        for i in (0..size).rev() {
            let v = q[i];
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
        self.child = child;
        self.parent = parent;
        self.left = left;
        self.right = right;
        self.path_root = path_root;
    }
    #[allow(dead_code)]
    fn lca(&self, mut a: usize, mut b: usize) -> usize {
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
        std::cmp::min((index[a], a), (index[b], b)).1
    }
    #[allow(dead_code)]
    fn path(
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
        if index[x] + 1 <= index[y] {
            down.push((index[x] + 1, index[y] + 1));
        } else if index[y] + 1 <= index[x] {
            up.push((index[y] + 1, index[x] + 1));
        }
        down.reverse();
    }
    #[allow(dead_code)]
    fn sub_tree(&self, v: usize) -> (usize, usize) {
        assert!(v < self.size);
        (self.left[v], self.right[v])
    }
    #[allow(dead_code)]
    fn parent(&self, v: usize) -> Option<usize> {
        assert!(v < self.size);
        let p = self.parent[v];
        if p == v {
            None
        } else {
            Some(p)
        }
    }
}
// ---------- end Heavy-Light decomposition ----------
// ---------- begin SegmentTree Range update Point query ----------
mod segment_tree {
    pub struct RUPQ<T, F> {
        n: usize,
        b: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    impl<T: Copy, F: Fn(T, T) -> T> RUPQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> RUPQ<T, F> {
            let mut k = 0;
            while (1 << k) < n {
                k += 1;
            }
            RUPQ {
                n: 1 << k,
                b: k,
                a: vec![id; 2 << k],
                id: id,
                op: op,
            }
        }
        fn down(&mut self, x: usize) {
            let k = x + self.n;
            let a = &mut self.a;
            for i in (1..(self.b + 1)).rev() {
                let y = k >> i;
                a[2 * y] = (self.op)(a[2 * y], a[y]);
                a[2 * y + 1] = (self.op)(a[2 * y + 1], a[y]);
                a[y] = self.id;
            }
        }
        pub fn update(&mut self, mut l: usize, mut r: usize, v: T) {
            self.down(l);
            self.down(r - 1);
            l += self.n;
            r += self.n;
            let a = &mut self.a;
            while l < r {
                if (l & 1) == 1 {
                    a[l] = (self.op)(a[l], v);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    a[r] = (self.op)(a[r], v);
                }
                l >>= 1;
                r >>= 1;
            }
        }
        pub fn find(&mut self, mut x: usize) -> T {
            x += self.n;
            let mut y = self.a[x];
            x >>= 1;
            while x > 0 {
                y = (self.op)(y, self.a[x]);
                x >>= 1;
            }
            y
        }
    }
}
// ---------- end SegmentTree Range update Point query ----------
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

fn dfs(v: usize, p: usize, ord: &mut [usize], low: &mut [usize], id: &mut usize, g: &[Vec<(usize, usize)>], bridge: &mut Vec<usize>) {
    ord[v] = *id;
    low[v] = *id;
    *id += 1;
    for &(u, q) in g[v].iter() {
        if q == p {
            continue;
        }
        if ord[u] > *id {
            dfs(u, q, ord, low, id, g, bridge);
            low[v] = low[v].min(low[u]);
            if ord[v] < low[u] {
                bridge.push(q);
            }
        } else {
            low[v] = low[v].min(ord[u]);
        }
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        q: usize,
        e: [(usize1, usize1); m],
        ask: [(usize1, usize1); q],
    }
    let mut dsu = DSU::new(n);
    let mut e = e;
    for &(a, b) in e.iter() {
        dsu.unite(a, b);
    }
    if ask.iter().any(|p| !dsu.same(p.0, p.1)) {
        println!("No");
        return;
    }
    for i in 1..n {
        if dsu.unite(i - 1, i).is_some() {
            e.push((i - 1, i));
        }
    }
    let mut g = vec![vec![]; n];
    for (i, &(a, b)) in e.iter().enumerate() {
        g[a].push((b, i));
        g[b].push((a, i));
    }
    let mut ord = vec![n; n];
    let mut low = vec![n; n];
    let mut id = 0;
    let mut bridge = vec![];
    dfs(0, e.len(), &mut ord, &mut low, &mut id, &g, &mut bridge);
    bridge.sort();
    bridge.dedup();
    dsu.init();
    for (i, &(a, b)) in e.iter().enumerate() {
        if bridge.binary_search(&i).is_err() {
            dsu.unite(a, b);
        }
    }
    let mut index = vec![n; n];
    let mut v = 0;
    for i in 0..n {
        let r = dsu.root(i);
        if index[r] == n {
            index[r] = v;
            v += 1;
        }
    }
    let n = v;
    let mut ask = ask.into_iter().filter(|p| !dsu.same(p.0, p.1)).collect::<Vec<_>>();
    for p in ask.iter_mut().chain(e.iter_mut()) {
        p.0 = index[dsu.root(p.0)];
        p.1 = index[dsu.root(p.1)];
    }
    let mut hld = HLD::new(n);
    for b in bridge.iter() {
        let (a, b) = e[*b];
        hld.add_edge(a, b);
    }
    hld.build(0);
    let mut up = vec![];
    let mut down = vec![];
    let mut seg = segment_tree::RUPQ::new(n, 3, |a, b| a & b);
    for &(a, b) in ask.iter() {
        hld.path(a, b, &mut up, &mut down);
        for &(l, r) in up.iter() {
            seg.update(l, r, 1);
        }
        for &(l, r) in down.iter() {
            seg.update(l, r, 2);
        }
    }
    let mut ok = true;
    for i in 0..n {
        ok &= seg.find(i) != 0;
    }
    if ok {
        println!("Yes");
    } else {
        println!("No");
    }

}

fn main() {
    run();
}
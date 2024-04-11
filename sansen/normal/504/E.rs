// ---------- begin sparse table ----------
pub struct SparseTable<T, F> {
    table: Vec<Vec<T>>,
    size: usize,
    op: F,
}

impl<T, F> SparseTable<T, F>
where
    F: Fn(&T, &T) -> T
{
    pub fn new(mut a: Vec<T>, op: F) -> Self {
        assert!(a.len() > 0);
        let size = a.len();
        let mut table = vec![];
        let mut w = 1;
        while w + 1 <= a.len() {
            let next = a.windows(w + 1).map(|a| op(&a[0], &a[w])).collect::<Vec<_>>();
            table.push(a);
            a = next;
            w <<= 1;
        }
        table.push(a);
        SparseTable {
            table: table,
            size: size,
            op: op,
        }
    }
    pub fn find(&self, l: usize, r: usize) -> T {
        assert!(l < r && r <= self.size);
        let k = (r - l + 1).next_power_of_two().trailing_zeros() as usize - 1;
        let table = &self.table[k];
        (self.op)(&table[l], &table[r - (1 << k)])
    }
}
// ---------- end sparse table ----------
// ---------- begin Suffix Array ----------
//  https://ei1333.github.io/luzhiled/snippets/string/suffix-array.html
// 
fn suffix_array<T: Ord>(s: &[T]) -> Vec<usize> {
    let n = s.len();
    let mut z = s.iter().collect::<Vec<_>>();
    z.sort();
    z.dedup();
    let mut c = Vec::with_capacity(n);
    for s in s.iter() {
        c.push(z.binary_search(&s).unwrap());
    }
    let mut sa: Vec<usize> = (0..n).collect();
    sa.sort_by(|a, b| c[*a].cmp(&c[*b]).then(b.cmp(a)));
    let mut classes = vec![0; n];
    let mut cnt = vec![0; n];
    let mut len = 1;
    let mut id = 0;
    while id < n && len < n {
        id = 1;
        let mut prev = sa[0];
        classes[prev] = id - 1;
        cnt[0] = 0;
        for (i, &sa) in sa.iter().enumerate().skip(1) {
            if c[sa] == c[prev] && prev < n - len && c[prev + len / 2] == c[sa + len / 2] {
                classes[sa] = id - 1;
            } else {
                id += 1;
                classes[sa] = id - 1;
                cnt[id - 1] = i;
            }
            prev = sa;
        }
        c.copy_from_slice(&sa);
        for c in c.iter() {
            if *c >= len {
                let k = *c - len;
                let po = &mut cnt[classes[k]];
                sa[*po] = k;
                *po += 1;
            }
        }
        std::mem::swap(&mut classes, &mut c);
        len <<= 1;
    }
    sa
}
// ---------- end Suffix Array ----------
// ---------- begin lcp array ----------
fn lcp_array<T: Ord>(s: &[T], sa: &[usize]) -> Vec<usize> {
    let mut isa = vec![0; s.len()];
    for (i, sa) in sa.iter().enumerate() {
        isa[*sa] = i;
    }
    let mut lcp = vec![0; s.len()];
    let mut h = 0;
    for i in 0..sa.len() {
        if isa[i] + 1 < sa.len() {
            let j = sa[isa[i] + 1];
            while i.max(j) + h < sa.len() && s[i + h] == s[j + h] {
                h += 1;
            }
            lcp[isa[i] + 1] = h;
            if h > 0 {
                h -= 1;
            }
        }
    }
    lcp
}
// ---------- end lcp array ----------
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
        s: bytes,
        e: [(usize1, usize1); n - 1],
        q: usize,
        ask: [(usize1, usize1, usize1, usize1); q],
    }
    let mut hld = HLD::new(n);
    for (a, b) in e {
        hld.add_edge(a, b);
    }
    let root = 0;
    hld.build(root);
    let mut a = vec![b'.'; 2 * n];
    for (i, c) in s.iter().enumerate() {
        let x = hld.sub_tree(i).0;
        a[x] = *c;
        a[2 * n - 1 - x] = *c;
    }
    let mut up = vec![];
    let mut down = vec![];
    let mut path = |s: usize, t: usize, res: &mut Vec<(usize, usize)>| {
        hld.path(s, t, &mut up, &mut down);
        res.clear();
        for (l, r) in up.drain(..) {
            res.push((2 * n - r, 2 * n - l));
        }
        for (l, r) in down.drain(..) {
            res.push((l, r));
        }
    };
    let sa = suffix_array(&a);
    let mut isa = vec![0; a.len()];
    for (i, a) in sa.iter().enumerate() {
        isa[*a] = i;
    }
    let lcp = lcp_array(&a, &sa);
    let table = SparseTable::new(lcp, |a, b| std::cmp::min(*a, *b));
    let find = |x: usize, y: usize| -> usize {
        let x = isa[x];
        let y = isa[y];
        if x == y {
            a.len()
        } else {
            table.find(x.min(y) + 1, x.max(y) + 1)
        }
    };
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut p = vec![];
    let mut q = vec![];
    for (a, b, c, d) in ask {
        path(a, b, &mut p);
        path(c, d, &mut q);
        let mut ans = 0;
        let mut x = (0, 0);
        let mut y = (0, 0);
        while x.0 < p.len() && y.0 < q.len() {
            let (a, b) = p[x.0];
            let (c, d) = q[y.0];
            let len = (b - a - x.1).min(d - c - y.1);
            let res = find(a + x.1, c + y.1).min(len);
            ans += res;
            if res < len {
                break;
            }
            x.1 += res;
            y.1 += res;
            if a + x.1 >= b {
                x = (x.0 + 1, 0);
            }
            if c + y.1 >= d {
                y = (y.0 + 1, 0);
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
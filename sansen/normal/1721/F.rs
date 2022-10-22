use std::io::Write;

fn run() {
    let (l, r, m, q) = {
        let a = read();
        (a[0], a[1], a[2], a[3])
    };
    let mut graph = BipartitieMatching::new(l, r);
    let mut edge = vec![];
    for i in 1..=m {
        let (x, y) = {
            let a = read();
            (a[0], a[1])
        };
        edge.push((x, y, i));
        graph.add_edge(x - 1, y - 1);
    }
    edge.sort();
    let max_match = graph.solve();
    let mut g = vec![vec![]; l + r + 1];
    for &(a, b, _) in edge.iter() {
        g[a].push(l + b);
    }
    let mut pair = vec![None; l + r + 1];
    let mut sum = 0;
    for &(a, b) in max_match.iter() {
        let a = a + 1;
        let b = b + 1;
        g[l + b].push(a);
        let k = edge.binary_search_by_key(&(a, b), |e| (e.0, e.1)).unwrap();
        let k = edge[k].2;
        sum += k;
        pair[a] = Some(k);
        pair[l + b] = Some(k);
    }
    let (len, id) = strongly_connected_components(l + r + 1, |v| g[v].iter().cloned());
    let mut op = vec![0; len];
    let mut vertex = vec![vec![vec![]; 2]; len];
    for i in 1..=l {
        if pair[i].is_none() {
            op[id[i]] |= 1;
        }
        vertex[id[i]][0].push(i);
    }
    for i in 1..=r {
        if pair[l + i].is_none() {
            op[id[l + i]] |= 2;
        }
        vertex[id[l + i]][1].push(l + i);
    }
    let mut z = vec![vec![]; len];
    for i in 0..id.len() {
        z[id[i]].push(i);
    }
    let mut push = op.clone();
    for (i, z) in z.iter().enumerate() {
        let val = push[i];
        for &v in z.iter() {
            for &u in g[v].iter() {
                push[id[u]] |= val;
            }
        }
    }
    let mut pull = op.clone();
    for (i, z) in z.iter().enumerate().rev() {
        for &v in z.iter() {
            for &u in g[v].iter() {
                pull[i] |= pull[id[u]];
            }
        }
    }
    let mut pos = 0;
    for _ in 0..q {
        let ask = read()[0];
        if ask == 1 {
            while vertex[pos][0].len() == 0 || vertex[pos][1].len() == 0 {
                pos += 1;
            }
            let del = if pull[pos] & 2 == 2 {
                let v = vertex[pos][0].pop().unwrap();
                sum -= pair[v].unwrap();
                v as i32
            } else {
                let v = vertex[pos][1].pop().unwrap();
                sum -= pair[v].unwrap();
                -((v - l) as i32)
            };
            println!("1\n{}\n{}", del, sum);
        } else {
            let mut elem = vec![false; l + r + 1];
            for v in vertex.iter().flatten().flatten() {
                elem[*v] = true;
            }
            let mut ans = vec![];
            for &(a, b) in max_match.iter() {
                let a = a + 1;
                let b = b + 1;
                if elem[a] && elem[l + b] {
                    let k = edge.binary_search_by_key(&(a, b), |e| (e.0, e.1)).unwrap();
                    ans.push(edge[k].2);
                }
            }
            println!("{}", ans.len());
            use util::*;
            println!("{}", ans.iter().join(" "));
        }
    }
}

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim()
        .split_whitespace()
        .flat_map(|s| s.parse())
        .collect::<Vec<_>>()
}

fn main() {
    run();
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
// ---------- begin max flow (Dinic) ----------
mod maxflow {
    pub trait MaxFlowCapacity:
        Copy + Ord + std::ops::Add<Output = Self> + std::ops::Sub<Output = Self>
    {
        fn zero() -> Self;
        fn inf() -> Self;
    }

    macro_rules! impl_primitive_integer_capacity {
        ($x:ty, $y:expr) => {
            impl MaxFlowCapacity for $x {
                fn zero() -> Self {
                    0
                }
                fn inf() -> Self {
                    $y
                }
            }
        };
    }

    impl_primitive_integer_capacity!(u32, std::u32::MAX);
    impl_primitive_integer_capacity!(u64, std::u64::MAX);
    impl_primitive_integer_capacity!(i32, std::i32::MAX);
    impl_primitive_integer_capacity!(i64, std::i64::MAX);

    #[derive(Clone)]
    struct Edge<Cap> {
        to_: u32,
        inv_: u32,
        cap_: Cap,
    }

    impl<Cap> Edge<Cap> {
        fn new(to: usize, inv: usize, cap: Cap) -> Self {
            Edge {
                to_: to as u32,
                inv_: inv as u32,
                cap_: cap,
            }
        }
        fn to(&self) -> usize {
            self.to_ as usize
        }
        fn inv(&self) -> usize {
            self.inv_ as usize
        }
    }

    impl<Cap: MaxFlowCapacity> Edge<Cap> {
        fn add(&mut self, cap: Cap) {
            self.cap_ = self.cap_ + cap;
        }
        fn sub(&mut self, cap: Cap) {
            self.cap_ = self.cap_ - cap;
        }
        fn cap(&self) -> Cap {
            self.cap_
        }
    }

    pub struct Graph<Cap> {
        graph: Vec<Vec<Edge<Cap>>>,
    }

    #[allow(dead_code)]
    pub struct EdgeIndex {
        src: usize,
        dst: usize,
        x: usize,
        y: usize,
    }

    impl<Cap: MaxFlowCapacity> Graph<Cap> {
        pub fn new(size: usize) -> Self {
            Self {
                graph: vec![vec![]; size],
            }
        }
        pub fn add_edge(&mut self, src: usize, dst: usize, cap: Cap) -> EdgeIndex {
            assert!(src.max(dst) < self.graph.len());
            assert!(cap >= Cap::zero());
            assert!(src != dst);
            let x = self.graph[src].len();
            let y = self.graph[dst].len();
            self.graph[src].push(Edge::new(dst, y, cap));
            self.graph[dst].push(Edge::new(src, x, Cap::zero()));
            EdgeIndex { src, dst, x, y }
        }
        // src, dst, used, intial_capacity
        #[allow(dead_code)]
        pub fn get_edge(&self, e: &EdgeIndex) -> (usize, usize, Cap, Cap) {
            let max = self.graph[e.src][e.x].cap() + self.graph[e.dst][e.y].cap();
            let used = self.graph[e.dst][e.y].cap();
            (e.src, e.dst, used, max)
        }
        pub fn flow(&mut self, src: usize, dst: usize) -> Cap {
            let size = self.graph.len();
            assert!(src.max(dst) < size);
            assert!(src != dst);
            let mut queue = std::collections::VecDeque::new();
            let mut level = vec![0; size];
            let mut it = vec![0; size];
            let mut ans = Cap::zero();
            loop {
                (|| {
                    level.clear();
                    level.resize(size, 0);
                    level[src] = 1;
                    queue.clear();
                    queue.push_back(src);
                    while let Some(v) = queue.pop_front() {
                        let d = level[v] + 1;
                        for e in self.graph[v].iter() {
                            let u = e.to();
                            if e.cap() > Cap::zero() && level[u] == 0 {
                                level[u] = d;
                                if u == dst {
                                    return;
                                }
                                queue.push_back(u);
                            }
                        }
                    }
                })();
                if level[dst] == 0 {
                    break;
                }
                it.clear();
                it.resize(size, 0);
                loop {
                    let f = self.dfs(dst, src, Cap::inf(), &mut it, &level);
                    if f == Cap::zero() {
                        break;
                    }
                    ans = ans + f;
                }
            }
            ans
        }
        fn dfs(&mut self, v: usize, src: usize, cap: Cap, it: &mut [usize], level: &[u32]) -> Cap {
            if v == src {
                return cap;
            }
            while let Some((u, inv)) = self.graph[v].get(it[v]).map(|p| (p.to(), p.inv())) {
                if level[u] + 1 == level[v] && self.graph[u][inv].cap() > Cap::zero() {
                    let cap = cap.min(self.graph[u][inv].cap());
                    let c = self.dfs(u, src, cap, it, level);
                    if c > Cap::zero() {
                        self.graph[v][it[v]].add(c);
                        self.graph[u][inv].sub(c);
                        return c;
                    }
                }
                it[v] += 1;
            }
            Cap::zero()
        }
    }
}
// ---------- end max flow (Dinic) ----------
// ---------- begin scc ----------
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
                let low = graph(v).map(|u| ord[u]).min().unwrap_or(ord[v]);
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
// ---------- end scc ----------

struct BipartitieMatching {
    graph: Vec<Vec<usize>>,
    left: usize,
    right: usize,
}

impl BipartitieMatching {
    fn new(left: usize, right: usize) -> Self {
        assert!(left > 0 && right > 0);
        BipartitieMatching {
            graph: vec![vec![]; left],
            left: left,
            right: right,
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a < self.left && b < self.right);
        self.graph[a].push(b);
    }
    fn bfs(&self, used: &[bool], assign: &[Option<usize>], depth: &mut [u32]) {
        let mut que = std::collections::VecDeque::new();
        for (v, (&used, depth)) in used.iter().zip(depth.iter_mut()).enumerate() {
            if !used {
                *depth = 0;
                que.push_back(v);
            }
        }
        while let Some(v) = que.pop_front() {
            let d = depth[v] + 1;
            for &u in self.graph[v].iter() {
                if let Some(k) = assign[u] {
                    if depth[k] > d {
                        depth[k] = d;
                        que.push_back(k);
                    }
                }
            }
        }
    }
    fn dfs(
        &self,
        v: usize,
        it: &mut [usize],
        used: &mut [bool],
        assign: &mut [Option<usize>],
        depth: &[u32],
    ) -> bool {
        let d = depth[v] + 1;
        for (k, &u) in self.graph[v].iter().enumerate().skip(it[v]) {
            let ok = assign[u].map_or(true, |k| {
                assert!(used[k]);
                depth[k] == d && self.dfs(k, it, used, assign, depth)
            });
            if ok {
                assign[u] = Some(v);
                used[v] = true;
                return true;
            }
            it[v] = k + 1;
        }
        false
    }
    fn solve(&self) -> Vec<(usize, usize)> {
        let mut used = vec![false; self.left];
        let mut assign = vec![None; self.right];
        let mut depth = Vec::with_capacity(self.left);
        let mut it = Vec::with_capacity(self.left);
        loop {
            depth.clear();
            depth.resize(self.left, std::u32::MAX / 2);
            self.bfs(&used, &assign, &mut depth);
            it.clear();
            it.resize(self.left, 0);
            let mut update = false;
            for v in 0..self.left {
                if !used[v] {
                    update |= self.dfs(v, &mut it, &mut used, &mut assign, &depth);
                }
            }
            if !update {
                break;
            }
        }
        let mut ans = vec![];
        for (r, a) in assign.into_iter().enumerate() {
            if let Some(l) = a {
                ans.push((l, r));
            }
        }
        ans
    }
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
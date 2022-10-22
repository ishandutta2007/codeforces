// N, M <=  10000
//
// s_i = 1 a_i = b_i 
// (u, v) b[u] += 1, b[v] -= 1 or 
// 
//
// 
//
// (u, v)  (v, u), (u, v) 
//
// ??
//
// 1(?)
// 
// 
// 1
// +- 
// 
// ...
// d_i
// |a_i| < d_i parity
// 
//
// 0
// 1
// s_i = 1  |a_i| < d_i parity  or s_i = 0
// 
// 
// 
// 
// 1s0
// 
// 1
// 2
// 
//
// 
// parity
//
// s=0 
// 
// 
// 0->v-> 
// -->v 
// +v-> 
// ok
//
// 
// 0dfs -> 1dfs 

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        m: usize,
        s: [i32; n],
        a: [i32; n],
        e: [(usize1, usize1); m],
    }
    let mut deg = vec![0; n];
    for e in e.iter() {
        deg[e.0] += 1;
        deg[e.1] += 1;
    }
    if s.iter()
        .zip(a.iter())
        .zip(deg.iter())
        .any(|((s, a), d)| *s == 1 && (a.abs() > *d || a.abs() & 1 != *d & 1))
    {
        println!("NO");
        return;
    }
    let mut g = maxflow::Graph::new(n + 4);
    let src = n;
    let dst = src + 1;
    let super_src = src + 2;
    let super_dst = src + 3;
    let mut info = vec![];
    for &(a, b) in e.iter() {
        info.push(g.add_edge_bi(a, b, 1i32));
    }
    for (i, ((&s, &a), &d)) in s.iter().zip(a.iter()).zip(deg.iter()).enumerate() {
        if s == 1 {
            if a < 0 {
                let a = a.abs();
                g.add_edge(super_src, i, a);
                g.add_edge(src, super_dst, a);
            } else if a > 0 {
                g.add_edge(super_src, dst, a);
                g.add_edge(i, super_dst, a);
            }
        } else if d > 0 {
            g.add_edge(src, i, d);
            g.add_edge(i, dst, d);
        }
    }
    g.flow(super_src, super_dst);
    g.flow(super_src, dst);
    g.flow(src, super_dst);
    let mut deg = vec![0; n];
    let mut ans = vec![(0, 0); m];
    let mut graph = vec![vec![]; n];
    for (i, e) in info.iter().enumerate() {
        let (a, b, st, ts) = g.get_edge(e);
        if st == 0 {
            deg[a] -= 1;
            deg[b] += 1;
            ans[i] = (a, b);
        } else if ts == 0 {
            deg[a] += 1;
            deg[b] -= 1;
            ans[i] = (b, a);
        } else {
            graph[a].push((b, i));
            graph[b].push((a, i));
        }
    }
    for (deg, s) in deg.iter_mut().zip(s.iter()) {
        *deg *= *s;
    }
    if deg != a {
        println!("NO");
        return;
    }
    let mut g = graph;
    let mut used = vec![false; m];
    for p in 0..2 {
        for (i, s) in s.iter().enumerate() {
            if *s == p {
                while g[i].len() > 0 {
                    dfs(i, &mut g, &mut used, &mut ans);
                }
            }
        }
    }
    println!("YES");
    for (a, b) in ans {
        println!("{} {}", a + 1, b + 1);
    }
}

fn dfs(v: usize, g: &mut [Vec<(usize, usize)>], used: &mut [bool], ans: &mut [(usize, usize)]) {
    while let Some((u, k)) = g[v].pop() {
        if !used[k] {
            ans[k] = (v, u);
            used[k] = true;
            dfs(u, g, used, ans);
            break;
        }
    }
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
        pub fn add_edge_bi(&mut self, src: usize, dst: usize, cap: Cap) -> EdgeIndex {
            assert!(src.max(dst) < self.graph.len());
            assert!(cap >= Cap::zero());
            assert!(src != dst);
            let x = self.graph[src].len();
            let y = self.graph[dst].len();
            self.graph[src].push(Edge::new(dst, y, cap));
            self.graph[dst].push(Edge::new(src, x, cap));
            EdgeIndex { src, dst, x, y }
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
            let st = self.graph[e.src][e.x].cap();
            let ts = self.graph[e.dst][e.y].cap();
            (e.src, e.dst, st, ts)
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
    where
        F: FnMut(usize),
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
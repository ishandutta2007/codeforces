fn main() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        c: i32,
        d: i32,
        a: [usize1; k],
        e: [(usize1, usize1); m],
    }
    let h = n + k;
    let mut g = Graph::new(n * h + 2);
    let src = n * h;
    let dst = src + 1;
    for a in a {
        g.add_edge(src, a, 1, 0);
    }
    for i in 0..h {
        g.add_edge(i * n, dst, k as i32, i as i32 * c);
    }
    for i in 1..h {
        for v in 0..n {
            g.add_edge((i - 1) * n + v, i * n + v, k as i32, 0);
        }
        for (a, b) in e.iter().flat_map(|&(a, b)| [(a, b), (b, a)]) {
            for j in 0..(k as i32) {
                g.add_edge((i - 1) * n + a, i * n + b, 1, (2 * j + 1) * d);
            }
        }
    }
    let ans = g.slope(src, dst, k as i32).last().unwrap().1;
    println!("{}", ans);
}

use std::ops::*;

pub trait MinCostFlowValue:
    Copy + Add<Output = Self> + Sub<Output = Self> + Mul<Output = Self> + Neg<Output = Self> + Ord
{
    fn zero() -> Self;
    fn inf() -> Self;
}

impl MinCostFlowValue for i32 {
    fn zero() -> Self {
        0
    }
    fn inf() -> Self {
        std::i32::MAX
    }
}

#[derive(Clone)]
struct Edge<T> {
    to: u32,
    inv: u32,
    cap: T,
    cost: T,
}

impl<T> Edge<T>
where
    T: MinCostFlowValue,
{
    fn new(to: usize, inv: usize, cap: T, cost: T) -> Self {
        Edge {
            to: to as u32,
            inv: inv as u32,
            cap,
            cost,
        }
    }
    fn to(&self) -> usize {
        self.to as usize
    }
    fn inv(&self) -> usize {
        self.inv as usize
    }
    fn cap(&self) -> T {
        self.cap
    }
    fn cost(&self) -> T {
        self.cost
    }
    fn add(&mut self, cap: T) {
        self.cap = self.cap + cap;
    }
    fn sub(&mut self, cap: T) {
        self.cap = self.cap - cap;
    }
}

pub struct Graph<T> {
    size: usize,
    edges: Vec<(usize, usize, T, T)>,
}

impl<T: MinCostFlowValue> Graph<T> {
    pub fn new(size: usize) -> Self {
        Graph {
            size: size,
            edges: vec![],
        }
    }
    pub fn add_edge(&mut self, src: usize, dst: usize, cap: T, cost: T) {
        assert!(src.max(dst) < self.size && src != dst);
        assert!(T::zero() <= cap && T::zero() <= cost);
        self.edges.push((src, dst, cap, cost));
    }
    pub fn slope(&mut self, src: usize, dst: usize, cap: T) -> Vec<(T, T)> {
        assert!(src.max(dst) < self.size && src != dst);
        assert!(T::zero() <= cap);
        let mut deg = vec![0; self.size];
        for e in self.edges.iter() {
            deg[e.0] += 1;
            deg[e.1] += 1;
        }
        let mut graph = deg
            .into_iter()
            .map(|d| Vec::with_capacity(d))
            .collect::<Vec<_>>();
        for &(src, dst, cap, cost) in self.edges.iter() {
            let x = graph[src].len();
            let y = graph[dst].len();
            graph[src].push(Edge::new(dst, y, cap, cost));
            graph[dst].push(Edge::new(src, x, T::zero(), -cost));
        }
        let mut heap = std::collections::BinaryHeap::new();
        let mut dist = vec![(T::zero(), T::zero()); self.size];
        let mut parent = vec![(0, 0); self.size];
        let mut visited = vec![false; self.size];
        let mut flow = T::zero();
        let mut cost = T::zero();
        let mut ans = vec![];
        while flow < cap {
            dist.iter_mut().for_each(|p| p.1 = T::inf());
            visited.iter_mut().for_each(|v| *v = false);
            heap.clear();
            dist[src].1 = T::zero();
            heap.clear();
            heap.push(std::cmp::Reverse((dist[src].1, src)));
            while let Some(std::cmp::Reverse((_, v))) = heap.pop() {
                if visited[v] {
                    continue;
                }
                visited[v] = true;
                let (a, b) = dist[v];
                for (k, e) in graph[v]
                    .iter()
                    .enumerate()
                    .filter(|(_, e)| e.cap() > T::zero())
                {
                    let (u, w) = (e.to(), e.cost());
                    let cost = w - dist[u].0 + a;
                    if dist[u].1 - b > cost {
                        let d = b + cost;
                        dist[u].1 = d;
                        parent[u] = (v, k);
                        heap.push(std::cmp::Reverse((d, u)));
                    }
                }
            }
            if !visited[dst] {
                break;
            }
            for v in 0..self.size {
                if !visited[v] {
                    continue;
                }
                dist[v].0 = dist[v].0 - dist[dst].1 + dist[v].1;
            }
            let mut sub = cap;
            let mut pos = dst;
            while pos != src {
                let (pre, k) = parent[pos];
                sub = std::cmp::min(sub, graph[pre][k].cap());
                pos = pre;
            }
            let mut pos = dst;
            while pos != src {
                let (pre, k) = parent[pos];
                let inv = graph[pre][k].inv();
                graph[pre][k].sub(sub);
                graph[pos][inv].add(sub);
                pos = pre;
            }
            flow = flow + sub;
            cost = cost + -dist[src].0 * sub;
            ans.push((flow, cost));
        }
        ans
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
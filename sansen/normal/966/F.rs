// ---------- begin max flow (Dinic) ----------
mod maxflow {
    pub trait MaxFlowCapacity:
        Copy + PartialOrd + std::ops::Add<Output = Self> + std::ops::Sub<Output = Self>
    {
        fn zero() -> Self;
        fn inf() -> Self;
    }

    macro_rules! impl_capacity {
        ($x:ty, $z: expr, $y:expr) => {
            impl MaxFlowCapacity for $x {
                fn zero() -> Self {
                    $z
                }
                fn inf() -> Self {
                    $y
                }
            }
        };
    }

    impl_capacity!(u32, 0, std::u32::MAX);
    impl_capacity!(u64, 0, std::u64::MAX);
    impl_capacity!(i32, 0, std::i32::MAX);
    impl_capacity!(i64, 0, std::i64::MAX);

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
            let mut queue = vec![src; size];
            let mut level = vec![0; size];
            let mut it = vec![0; size];
            let mut ans = Cap::zero();
            loop {
                (|| {
                    level.clear();
                    level.resize(size, 0);
                    level[src] = 1;
                    let mut front = 0;
                    let mut back = 1;
                    while front < back {
                        let v = queue[front];
                        front += 1;
                        let d = level[v] + 1;
                        for e in self.graph[v].iter() {
                            let u = e.to();
                            if e.cap() > Cap::zero() && level[u] == 0 {
                                level[u] = d;
                                if u == dst {
                                    return;
                                }
                                queue[back] = u;
                                back += 1;
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
                    let p = self.graph[u][inv].cap();
                    let cap = if cap < p { cap } else { p };
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
        m: usize,
        e: [(usize1, usize1, i64, i64, i64, i64); m],
    }
    let div = 10000000;
    let p = 10000;
    let eval = |m: i64| -> i64 {
        assert!(0 <= m && m <= div);
        let mut graph = maxflow::Graph::new(n + 2);
        let src = n;
        let dst = n + 1;
        let mut need = 0;
        for &(s, t, a, b, c, d) in e.iter() {
            let l = a * m + b * div;
            let r = c * m + d * div;
            assert!(l <= r && r <= div * p, "{} {} {} {} {} {}", s, t, a, b, c, d);
            need += l;
            if s != t {
                graph.add_edge(s, t, r - l);
            }
            graph.add_edge(src, t, l);
            graph.add_edge(s, dst, l);
        }
        need - graph.flow(src, dst)
    };
    let mut l = 0;
    let mut r = div;
    while r - l >= 3 {
        let ll = (l + l + r) / 3;
        let rr = (l + r + r) / 3;
        if eval(ll) >= eval(rr) {
            l = ll;
        } else {
            r = rr;
        }
    }
    let m = (l..=r).max_by_key(|p| eval(*p)).unwrap();
    let mut ans = 0;
    for &(mut ok, mut ng, sign) in [(m, -1, -1), (m, div + 1, 1)].iter() {
        while (ok - ng).abs() > 1 {
            let mid = (ok + ng) / 2;
            if eval(mid) == 0 {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans += sign * ok;
    }
    println!("{}", ans as f64 / div as f64);
}

fn main() {
    run();
}
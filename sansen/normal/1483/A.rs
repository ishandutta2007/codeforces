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
    impl_primitive_integer_capacity!(usize, std::usize::MAX);
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

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let mut g = maxflow::Graph::new(n + m + 2);
        let src = n + m;
        let dst = src + 1;
        let mut edge = vec![];
        for i in 0..m {
            let k: usize = sc.next();
            for _ in 0..k {
                let a = sc.next::<usize>() - 1;
                edge.push(g.add_edge(a, n + i, 1));
            }
            g.add_edge(n + i, dst, 1);
        }
        let up = (m + 1) / 2;
        for i in 0..n {
            g.add_edge(src, i, up);
        }
        if g.flow(src, dst) < m {
            writeln!(out, "NO").ok();
        } else {
            writeln!(out, "YES").ok();
            let mut ans = vec![0; m];
            for e in edge.iter() {
                let (s, t, u, _) = g.get_edge(e);
                if u == 1 {
                    ans[t - n] = s + 1;
                }
            }
            for (i, a) in ans.iter().enumerate() {
                if i > 0 {
                    write!(out, " ").ok();
                }
                write!(out, "{}", *a).ok();
            }
            writeln!(out).ok();
        }
    }
}
// ---------- begin Rerooting ----------
pub trait RerootingOperator {
    type Value: Clone;
    type Edge: Clone;
    fn init(&mut self, v: usize) -> Self::Value;
    fn merge(&mut self, p: &Self::Value, c: &Self::Value, e: &Self::Edge) -> Self::Value;
}

pub struct Rerooting<R: RerootingOperator> {
    manager: R,
    size: usize,
    edge: Vec<(usize, usize, R::Edge, R::Edge)>,
}

impl<R: RerootingOperator> Rerooting<R> {
    pub fn new(size: usize, manager: R) -> Self {
        Rerooting {
            manager: manager,
            size: size,
            edge: vec![],
        }
    }
    #[allow(dead_code)]
    pub fn add_edge(&mut self, a: usize, b: usize, cost: R::Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.add_edge_bi(a, b, cost.clone(), cost);
    }
    #[allow(dead_code)]
    pub fn add_edge_bi(&mut self, a: usize, b: usize, ab: R::Edge, ba: R::Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b, ab, ba));
    }
    pub fn solve(&mut self) -> Vec<R::Value> {
        let size = self.size;
        let mut graph = vec![vec![]; size];
        for e in self.edge.iter() {
            graph[e.0].push((e.1, e.2.clone()));
            graph[e.1].push((e.0, e.3.clone()));
        }
        let root = 0;
        let mut topo = vec![];
        let mut parent = vec![root; size];
        let mut stack = vec![root];
        let mut parent_edge: Vec<Option<R::Edge>> = (0..size).map(|_| None).collect();
        while let Some(v) = stack.pop() {
            topo.push(v);
            if let Some(k) = graph[v].iter().position(|e| e.0 == parent[v]) {
                let (_, c) = graph[v].remove(k);
                parent_edge[v] = Some(c);
            }
            for e in graph[v].iter() {
                parent[e.0] = v;
                stack.push(e.0);
            }
        }
        assert!(topo.len() == size);
        let manager = &mut self.manager;
        let mut down: Vec<_> = (0..size).map(|v| manager.init(v)).collect();
        for &v in topo.iter().rev() {
            for e in graph[v].iter() {
                down[v] = manager.merge(&down[v], &down[e.0], &e.1);
            }
        }
        let mut up: Vec<_> = (0..size).map(|v| manager.init(v)).collect();
        let mut stack = vec![];
        for &v in topo.iter() {
            if let Some(e) = parent_edge[v].take() {
                let ini = manager.init(v);
                up[v] = manager.merge(&ini, &up[v], &e);
            }
            if !graph[v].is_empty() {
                stack.push((graph[v].as_slice(), up[v].clone()));
                while let Some((g, val)) = stack.pop() {
                    if g.len() == 1 {
                        up[g[0].0] = val;
                    } else {
                        let m = g.len() / 2;
                        let (a, b) = g.split_at(m);
                        for a in [(a, b), (b, a)].iter() {
                            let mut p = val.clone();
                            for a in a.0.iter() {
                                p = manager.merge(&p, &down[a.0], &a.1);
                            }
                            stack.push((a.1, p));
                        }
                    }
                }
            }
            for e in graph[v].iter() {
                up[v] = manager.merge(&up[v], &down[e.0], &e.1);
            }
        }
        up
    }
}
// ---------- end Rerooting ----------
// ---------- begin Scanner(require delimiter) ----------
mod scanner {
    pub struct Scanner<R> {
        reader: R,
        buf: Vec<u8>,
    }
    #[allow(dead_code)]
    impl<R: std::io::BufRead> Scanner<R> {
        pub fn new(reader: R) -> Self {
            Scanner {
                reader: reader,
                buf: Vec::with_capacity(1024),
            }
        }
        fn read(&mut self, del: u8) {
            self.buf.clear();
            self.reader.read_until(del, &mut self.buf).ok();
            assert!(self.buf.pop().unwrap() == del);
        }
        pub fn next<T: std::str::FromStr>(&mut self, del: u8) -> T {
            self.read(del);
            std::str::from_utf8(&self.buf)
                .unwrap()
                .trim()
                .parse::<T>()
                .ok()
                .unwrap()
        }
        pub fn next_bytes(&mut self, del: u8) -> Vec<u8> {
            self.read(del);
            std::str::from_utf8(&self.buf)
                .unwrap()
                .trim()
                .bytes()
                .collect()
        }
    }
}
// ---------- end scanner(require delimiter) ----------

fn main() {
    let stdin = std::io::stdin();
    let mut sc = scanner::Scanner::new(stdin.lock());
    run(&mut sc);
}

struct Solver;
impl RerootingOperator for Solver {
    type Value = [(u64, u64); 2];
    type Edge = ();
    fn init(&mut self, _v: usize) -> Self::Value {
        [(1, 0), (0, 0)]
    }
    fn merge(&mut self, p: &Self::Value, c: &Self::Value, _e: &Self::Edge) -> Self::Value {
        let mut res = *p;
        res[0].0 += c[1].0;
        res[0].1 += c[1].1;
        res[1].0 += c[0].0;
        res[1].1 += c[0].1 + c[0].0;
        res
    }
}

fn run<R: std::io::BufRead>(sc: &mut scanner::Scanner<R>) {
    let n = sc.next::<usize>(b'\n');
    let mut solver = Rerooting::new(n, Solver);
    for _ in 1..n {
        let a = sc.next::<usize>(b' ') - 1;
        let b = sc.next::<usize>(b'\n') - 1;
        solver.add_edge(a, b, ());
    }
    let ans = solver.solve().into_iter().map(|p| p[0].1 + p[1].1).sum::<u64>() / 2;
    println!("{}", ans);
}
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
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

struct R {
    k: usize,
}
impl RerootingOperator for R {
    type Value = (usize, usize, bool);// (, )
    type Edge = ();
    fn init(&mut self, _v: usize) -> Self::Value {
        (0, 0, true)
    }
    fn merge(&mut self, p: &Self::Value, c: &Self::Value, _e: &Self::Edge) -> Self::Value {
        let k = self.k;
        let mut ans = *p;
        ans.0 += c.0;
        ans.2 &= c.2 && c.1 == 0;
        if c.2 && c.1 == 0 {
            ans.1 += 1;
            if ans.1 == k {
                ans.1 = 0;
                ans.0 += 1;
            }
        }
        ans
    }
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let k: usize = sc.next();
        let mut solver = Rerooting::new(n, R{k: k,});
        for _ in 1..n {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            solver.add_edge(a, b, ());
        }
        let ans = solver.solve().into_iter().map(|p| p.0).max().unwrap();
        writeln!(out, "{}", ans).ok();
    }
}
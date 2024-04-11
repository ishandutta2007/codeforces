// ---------- begin Rerooting ----------
struct Rerooting<Edge, Value, Func, Init> {
    size: usize,
    graph: Vec<Vec<(usize, Edge)>>,
    init: Init,
    merge: Func,
    phantom: std::marker::PhantomData<Value>,
}

impl<Edge, Value, Func, Init> Rerooting<Edge, Value, Func, Init>
where
    Edge: Clone,
    Value: Clone,
    Func: Fn(&Value, &Value, &Edge) -> Value,
    Init: Fn(usize) -> Value,
{
    fn new(size: usize, init: Init, func: Func) -> Self {
        Rerooting {
            size: size,
            graph: vec![vec![]; size],
            init: init,
            merge: func,
            phantom: std::marker::PhantomData,
        }
    }
    fn add_edge(&mut self, a: usize, b: usize, cost: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.graph[a].push((b, cost.clone()));
        self.graph[b].push((a, cost));
    }
    fn solve(&self) -> Vec<Value> {
        let mut graph = self.graph.clone();
        let root = 0;
        let mut topo = Vec::with_capacity(self.size);
        let mut stack = vec![(root, root)];
        while let Some((v, p)) = stack.pop() {
            topo.push(v);
            if let Some(k) = graph[v].iter().position(|e| e.0 == p) {
                graph[v].remove(k);
            }
            for e in graph[v].iter() {
                stack.push((e.0, v));
            }
        }
        assert!(topo.len() == self.size);
        let mut down: Vec<Value> = (0..self.size).map(|k| (self.init)(k)).collect();
        for &v in topo.iter().rev() {
            for e in graph[v].iter() {
                down[v] = (self.merge)(&down[v], &down[e.0], &e.1);
            }
        }
        let mut up: Vec<Value> = (0..self.size).map(|k| (self.init)(k)).collect();
        let mut ans = up.clone();
        for &v in topo.iter() {
            ans[v] = up[v].clone();
            for e in graph[v].iter() {
                ans[v] = (self.merge)(&ans[v], &down[e.0], &e.1);
            }
            if graph[v].is_empty() {
                continue;
            }
            let mut stack = vec![(graph[v].as_slice(), up[v].clone())];
            while let Some((g, val)) = stack.pop() {
                if g.len() == 1 {
                    up[g[0].0] = (self.merge)(&(self.init)(g[0].0), &val, &g[0].1);
                } else {
                    let m = g.len() / 2;
                    let (a, b) = g.split_at(m);
                    let mut p = val.clone();
                    for e in a.iter() {
                        p = (self.merge)(&p, &down[e.0], &e.1);
                    }
                    let mut q = val;
                    for e in b.iter() {
                        q = (self.merge)(&q, &down[e.0], &e.1);
                    }
                    stack.push((b, p));
                    stack.push((a, q));
                }
            }
        }
        ans
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

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    for _ in 0..q {
        type Value = (u32, u32, u32);// top2, 
        type Edge = ();
        let init = |_v| (0, 0, 0);
        let merge = |a: &Value, b: &Value, _c: &Edge| -> Value {
            let v = if b.0 > 0 {b.0 + b.2 - 1 + 1} else {1};
            if v > a.0 {
                (v, a.0, a.2 + 1)
            } else if v > a.1 {
                (a.0, v, a.2 + 1)
            } else {
                (a.0, a.1, a.2 + 1)
            }
        };
        let n: usize = sc.next();
        let mut solver = Rerooting::new(n, init, merge);
        for _ in 1..n {
            let a: usize = sc.next();
            let b: usize = sc.next();
            solver.add_edge(a - 1, b - 1, ());
        }
        let res = solver.solve();
        let ans = res.into_iter().map(|p| p.0 + p.1 + p.2 - std::cmp::min(2, p.2) + 1).max().unwrap();
        writeln!(out, "{}", ans).ok();
    }
}
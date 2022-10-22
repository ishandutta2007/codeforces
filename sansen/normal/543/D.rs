struct Rerooting<Edge, Value, Func, Init> {
    size: usize,
    edge: Vec<(usize, usize, Edge)>,
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
            edge: vec![],
            init: init,
            merge: func,
            phantom: std::marker::PhantomData,
        }
    }
    fn add_edge(&mut self, a: usize, b: usize, cost: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b, cost));
    }
    fn solve(&self) -> Vec<Value> {
        let mut graph = vec![vec![]; self.size];
        for e in self.edge.iter() {
            let a = e.0;
            let b = e.1;
            graph[a].push((b, e.2.clone()));
            graph[b].push((a, e.2.clone()));
        }
        let root = 0;
        let mut topo = vec![];
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

use std::io::Read;
use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    const MOD: u64 = 1_000_000_007;
    type Value = u64;
    type Edge = ();
    let init = |_| -> Value {
        1
    };
    let merge = |a: &Value, b: &Value, _c: &Edge| -> Value {
        *a * (1 + *b) % MOD
    };
    let mut solver = Rerooting::new(n, init, merge);
    for i in 1..n {
        let x = it.next().unwrap().parse::<usize>().unwrap() - 1;
        solver.add_edge(x, i, ());
    }
    let ans = solver.solve();
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    writeln!(out, "{}", s).ok();
}

fn main() {
    run();
}
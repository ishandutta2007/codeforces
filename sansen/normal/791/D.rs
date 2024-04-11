struct Rerooting<Edge, Value, Init, Lift, Merge> {
    size: usize,
    edge: Vec<(usize, usize)>,
    cost: Vec<Edge>,
    init: Init,
    lift: Lift,
    merge: Merge,
    phantom: std::marker::PhantomData<Value>,
}

impl<Edge, Value, Init, Lift, Merge> Rerooting<Edge, Value, Init, Lift, Merge>
where
    Value: Clone,
    Init: Fn(usize) -> Value,
    Lift: Fn(&Value, &Edge) -> Value,
    Merge: Fn(&Value, &Value) -> Value,
{
    fn new(size: usize, init: Init, lift: Lift, merge: Merge) -> Self {
        Rerooting {
            size: size,
            edge: vec![],
            cost: vec![],
            init: init,
            lift: lift,
            merge: merge,
            phantom: std::marker::PhantomData,
        }
    }
    fn add_edge(&mut self, a: usize, b: usize, cost: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b));
        self.cost.push(cost);
    }
    fn solve(&self) -> Vec<Value> {
        let mut graph = vec![vec![]; self.size];
        for (k, &(s, t)) in self.edge.iter().enumerate() {
            graph[s].push((t, k));
            graph[t].push((s, k));
        }
        let root = 0;
        let mut topo = vec![];
        let mut stack = vec![(root, root)];
        while let Some((v, p)) = stack.pop() {
            topo.push(v);
            if let Some(k) = graph[v].iter().position(|e| e.0 == p) {
                graph[v].remove(k);
            }
            for &(u, _) in graph[v].iter() {
                stack.push((u, v));
            }
        }
        assert!(topo.len() == self.size);
        let mut down: Vec<Value> = (0..self.size).map(|k| (self.init)(k)).collect();
        for &v in topo.iter().rev() {
            for &(u, k) in graph[v].iter() {
                down[v] = (self.merge)(&down[v], &(self.lift)(&down[u], &self.cost[k]));
            }
        }
        let mut up: Vec<Value> = (0..self.size).map(|k| (self.init)(k)).collect();
        let mut ans = up.clone();
        for &v in topo.iter() {
            let mut stack = vec![up[v].clone()];
            for &(u, k) in graph[v].iter() {
                let lift = (self.lift)(&down[u], &self.cost[k]);
                let val = (self.merge)(stack.last().unwrap(), &lift);
                stack.push(val);
            }
            ans[v] = stack.pop().unwrap();
            let len = graph[v].len();
            if len == 0 {
                continue;
            }
            let (u, k) = *graph[v].last().unwrap();
            up[u] = (self.merge)(&up[u], &(self.lift)(stack.last().unwrap(), &self.cost[k]));
            let mut right = (self.lift)(&down[u], &self.cost[k]);
            for &(u, k) in graph[v][..(len - 1)].iter().rev() {
                stack.pop();
                let val = (self.merge)(stack.last().unwrap(), &right);
                up[u] = (self.merge)(&up[u], &(self.lift)(&val, &self.cost[k]));
                right = (self.merge)(&(self.lift)(&down[u], &self.cost[k]), &right);
            }
        }
        ans
    }
}

use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let k: usize = it.next().unwrap().parse().unwrap();
    type Value = (u64, Vec<u64>);
    type Edge = ();
    let init = |_v: usize| -> Value {
        let mut a = vec![0; k];
        a[0] = 1;
        (0, a)
    };
    let lift = |a: &Value, _e: &Edge| -> Value {
        let c = a.0 + a.1[0];
        let mut b = a.1.clone();
        b.rotate_left(1);
        (c, b)
    };
    let merge = |a: &Value, b: &Value| -> Value {
        let mut c = a.1.clone();
        for (c, b) in c.iter_mut().zip(b.1.iter()) {
            *c += *b;
        }
        (a.0 + b.0, c)
    };
    let mut solver = Rerooting::new(n, init, lift, merge);
    for _ in 1..n {
        let x = it.next().unwrap().parse::<usize>().unwrap() - 1;
        let y = it.next().unwrap().parse::<usize>().unwrap() - 1;
        solver.add_edge(x, y, ());
    }
    let res = solver.solve();
    let ans = res.into_iter().fold(0, |s, a| s + a.0) / 2;
    println!("{}", ans);
}

fn main() {
    run();
}
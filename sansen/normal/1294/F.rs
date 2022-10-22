// ---------- begin Rerooting ----------
struct Rerooting<Edge, Value, Func, Init> {
    size: usize,
    edge: Vec<(usize, usize, Edge, Edge)>,
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
    #[allow(dead_code)]
    fn add_edge(&mut self, a: usize, b: usize, cost: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b, cost.clone(), cost));
    }
    #[allow(dead_code)]
    fn add_edge_bi(&mut self, a: usize, b: usize, x: Edge, y: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b, x, y));
    }
    fn solve(&self) -> Vec<Value> {
        let mut graph = vec![vec![]; self.size];
        for e in self.edge.iter() {
            graph[e.0].push((e.1, e.2.clone()));
            graph[e.1].push((e.0, e.3.clone()));
        }
        let root = 0;
        let mut topo = Vec::with_capacity(self.size);
        let mut parent = vec![root; self.size];
        let mut parent_edge: Vec<Option<Edge>> = (0..self.size).map(|_| None).collect();
        let mut stack = vec![root];
        while let Some(v) = stack.pop() {
            topo.push(v);
            if let Some(k) = graph[v].iter().position(|e| e.0 == parent[v]) {
                let x = graph[v].remove(k);
                parent_edge[v] = Some(x.1);
            }
            for e in graph[v].iter() {
                parent[e.0] = v;
                stack.push(e.0);
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
            if let Some(e) = parent_edge[v].take() {
                up[v] = (self.merge)(&ans[v], &up[v], &e);
            }
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
                    up[g[0].0] = val;
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
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    type Value = [(usize, usize); 3];
    type Edge = ();
    let init = |v: usize| -> Value {
        let mut a = [(0, n); 3];
        a[0] = (0, v);
        a
    };
    let merge = |a: &Value, b: &Value, _c: &Edge| -> Value {
        let (d, v) = b[0];
        let d = d + 1;
        let mut res = a.clone();
        if d > a[0].0 {
            res[2] = res[1];
            res[1] = res[0];
            res[0] = (d, v);
        } else if d > a[1].0 {
            res[2] = res[1];
            res[1] = (d, v);
        } else if d > a[2].0 {
            res[2] = (d, v);
        }
        res
    };
    let mut solver = Rerooting::new(n, init, merge);
    for (a, b) in e {
        solver.add_edge(a, b, ());
    }
    let ans = solver.solve();
    let mut max = (0, 0);
    for i in 0..n {
        let mut s = 0;
        for j in 0..3 {
            if ans[i][j].1 == n {
                s = 0;
                break;
            }
            s += ans[i][j].0;
        }
        if s > max.0 {
            max = (s, i);
        }
    }
    let a = ans[max.1][0].1;
    let b = ans[max.1][1].1;
    let mut c = ans[max.1][2].1;
    if c == n {
        c = 0;
        while c == a || c == b {
            c += 1;
        }
    }
    println!("{}\n{} {} {}", max.0, a + 1, b + 1, c + 1);
}

fn main() {
    run();
}
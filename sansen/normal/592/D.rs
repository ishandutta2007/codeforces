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
        assert!(size > 0 && size < 10usize.pow(8));
        Rerooting {
            manager: manager,
            size: size,
            edge: vec![],
        }
    }
    pub fn add_edge(&mut self, a: usize, b: usize, cost: R::Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.add_edge_bi(a, b, cost.clone(), cost);
    }
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
        let mut topo = vec![root];
        let mut parent = vec![root; size];
        let mut parent_edge: Vec<Option<R::Edge>> = (0..size).map(|_| None).collect();
        for i in 0..size {
            let v = topo[i];
            let child = std::mem::take(&mut graph[v]);
            for e in child.iter() {
                let k = graph[e.0].iter().position(|e| e.0 == v).unwrap();
                let c = graph[e.0].remove(k).1;
                parent_edge[e.0] = Some(c);
                parent[e.0] = v;
                topo.push(e.0);
            }
            graph[v] = child;
        }
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

struct State {
    attack: Vec<bool>,
}

impl RerootingOperator for State {
    type Value = (u64, u64, bool);// 
    type Edge = ();
    fn init(&mut self, v: usize) -> Self::Value {
        (0, 0, self.attack[v])
    }
    fn merge(&mut self, p: &Self::Value, c: &Self::Value, e: &Self::Edge) -> Self::Value {
        if c.2 {
            (p.0 + 2 + c.0, (p.0 + 1 + c.1).min(2 + c.0 + p.1), true)
        } else {
            *p
        }
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); n - 1],
        v: [usize1; m],
    }
    let mut state = State {
        attack: vec![false; n],
    };
    for v in v {
        state.attack[v] = true;
    }
    let mut solver = Rerooting::new(n, state);
    for (a, b) in e {
        solver.add_edge(a, b, ());
    }
    let dp = solver.solve();
    let mut ans = (10u64.pow(18), n);
    for (i, dp) in dp.iter().enumerate() {
        let val = (dp.1, i + 1);
        ans = ans.min(val);
    }
    println!("{}\n{}", ans.1, ans.0);
}

fn main() {
    run();
}
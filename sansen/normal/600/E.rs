// ---------- begin DSU on Tree ----------
pub trait DSUOperator {
    type Value;
    type Query: Clone;
    type Answer;
    fn init(&mut self);
    fn insert(&mut self, v: &Self::Value);
    fn delete(&mut self, v: &Self::Value);
    fn answer(&mut self, q: &Self::Query) -> Self::Answer;
}

pub struct DSUonTree<State: DSUOperator> {
    state: State,
    array: Vec<State::Value>,
    edge: Vec<(usize, usize)>,
    query: Vec<Vec<(State::Query, usize)>>,
    id: usize,
}

impl<State: DSUOperator> DSUonTree<State> {
    pub fn new(state: State, array: Vec<State::Value>) -> Self {
        let n = array.len();
        DSUonTree {
            state: state,
            array: array,
            edge: vec![],
            query: vec![vec![]; n],
            id: 0,
        }
    }
    pub fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a < self.array.len() && b < self.array.len() && a != b);
        self.edge.push((a, b));
    }
    pub fn add_query(&mut self, v: usize, op: State::Query) {
        self.query[v].push((op, self.id));
        self.id += 1;
    }
    pub fn solve(&mut self, root: usize, answer: &mut [State::Answer]) {
        assert!(answer.len() >= self.query.len());
        let n = self.array.len();
        let mut graph = vec![vec![]; n];
        for &(a, b) in self.edge.iter() {
            graph[a].push(b);
            graph[b].push(a);
        }
        let mut topo = vec![];
        let mut stack = vec![(root, root)];
        while let Some((v, p)) = stack.pop() {
            topo.push(v);
            let child = &mut graph[v];
            if let Some(k) = child.iter().position(|u| *u == p) {
                child.remove(k);
            }
            for &u in child.iter() {
                stack.push((u, v));
            }
        }
        assert!(topo.len() == n);
        let mut size = vec![1; n];
        for &v in topo.iter().rev() {
            let child = &mut graph[v];
            let mut max = (0, 0);
            for (k, &u) in child.iter().enumerate() {
                size[v] += size[u];
                max = std::cmp::max(max, (size[u], k));
            }
            if max.1 < child.len() {
                child.swap(0, max.1);
            }
        }
        let graph = graph;
        let state = &mut self.state;
        state.init();
        enum Operation {
            INSERT(usize),
            DELETE(usize),
            EVAL(usize),
            CALL(usize, bool),
        }
        let mut dfs = vec![Operation::CALL(root, false)];
        while let Some(op) = dfs.pop() {
            match op {
                Operation::INSERT(v) => {
                    state.insert(&self.array[v]);
                    for &u in graph[v].iter() {
                        dfs.push(Operation::INSERT(u));
                    }
                },
                Operation::DELETE(v) => {
                    state.delete(&self.array[v]);
                    for &u in graph[v].iter() {
                        dfs.push(Operation::DELETE(u));
                    }
                },
                Operation::EVAL(v) => {
                    state.insert(&self.array[v]);
                    for p in self.query[v].iter() {
                        answer[p.1] = state.answer(&p.0);
                    }
                },
                Operation::CALL(v, save) => {
                    if !save {
                        dfs.push(Operation::DELETE(v));
                    }
                    dfs.push(Operation::EVAL(v));
                    let child = &graph[v];
                    if child.is_empty() {
                        continue;
                    }
                    for &u in child.iter().skip(1) {
                        dfs.push(Operation::INSERT(u));
                    }
                    dfs.push(Operation::CALL(child[0], true));
                    for &u in child.iter().skip(1) {
                        dfs.push(Operation::CALL(u, false));
                    }
                },
            }
        }
    }
}
// ---------- end DSU on Tree ----------
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

struct State {
    cnt: Vec<usize>,
    max: usize,
    sum: u64,
}

impl State {
    fn new(n: usize) -> Self {
        State {
            cnt: vec![0; n + 1],
            max: 0,
            sum: 0,
        }
    }
}

impl DSUOperator for State {
    type Value = usize;
    type Query = ();
    type Answer = u64;
    fn init(&mut self) {
        for c in self.cnt.iter_mut() {
            *c = 0;
        }
        self.max = 0;
        self.sum = 0;
    }
    fn insert(&mut self, v: &Self::Value) {
        let c = &mut self.cnt[*v];
        *c += 1;
        if *c > self.max {
            self.max = *c;
            self.sum = *v as u64;
        } else if *c == self.max {
            self.sum += *v as u64;
        }
    }
    fn delete(&mut self, v: &Self::Value) {
        self.cnt[*v] -= 1;
        self.sum = 0;
        self.max = 0;
    }
    fn answer(&mut self, _q: &Self::Query) -> Self::Answer {
        self.sum
    }
}

fn run() {
    input! {
        n: usize,
        c: [usize; n],
        e: [(usize1, usize1); n - 1],
    }
    let mut dsu = DSUonTree::new(State::new(n), c);
    for (a, b) in e {
        dsu.add_edge(a, b);
    }
    for i in 0..n {
        dsu.add_query(i, ());
    }
    let mut ans = vec![0; n];
    dsu.solve(0, &mut ans);
    let mut out = String::new();
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
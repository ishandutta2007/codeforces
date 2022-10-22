// ---------- begin SCC ----------
struct SCCInternalGraph {
    start: Vec<usize>,
    elist: Vec<usize>,
}

impl SCCInternalGraph {
    fn build(size: usize, edge: &[(usize, usize)]) -> Self {
        let mut start = vec![0; size + 1];
        edge.iter().for_each(|&(s, _)| start[s + 1] += 1);
        for i in 1..=size {
            start[i] += start[i - 1];
        }
        let mut index = start.clone();
        let mut elist = vec![0; edge.len()];
        for &(s, t) in edge.iter() {
            let po = &mut index[s];
            elist[*po] = t;
            *po += 1;
        }
        SCCInternalGraph { start, elist }
    }
    fn neighbor(&self, v: usize) -> &[usize] {
        assert!(v + 1 < self.start.len());
        &self.elist[self.start[v]..self.start[v + 1]]
    }
}

struct SCC {
    size: usize,
    edge: Vec<(usize, usize)>,
}

impl SCC {
    fn new(size: usize) -> Self {
        SCC { size, edge: vec![] }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a < self.size);
        assert!(b < self.size);
        self.edge.push((a, b));
    }
    fn build(&self) -> (usize, Vec<usize>) {
        let graph = SCCInternalGraph::build(self.size, &self.edge);
        let size = self.size;
        let mut ord = vec![size; size];
        let mut assigned = vec![false; size];
        let mut stack_s = vec![];
        let mut stack_p = vec![];
        let mut call = vec![];
        let mut now_ord = 0;
        let mut res = vec![0; size];
        let mut id = 0;
        enum Operation {
            Call(usize),
            Iter(usize, usize),
            Eval(usize),
        }
        for i in 0..size {
            if ord[i] != size {
                continue;
            }
            call.push(Operation::Call(i));
            while let Some(op) = call.pop() {
                match op {
                    Operation::Call(v) => {
                        ord[v] = now_ord;
                        now_ord += 1;
                        stack_s.push(v);
                        stack_p.push(v);
                        call.push(Operation::Eval(v));
                        call.push(Operation::Iter(v, 0));
                    },
                    Operation::Iter(v, k) => {
                        let g = graph.neighbor(v);
                        for i in k..g.len() {
                            let u = g[i];
                            if ord[u] == size {
                                call.push(Operation::Iter(v, i + 1));
                                call.push(Operation::Call(u));
                                break;
                            } else if !assigned[u] {
                                while ord[*stack_p.last().unwrap()] > ord[u] {
                                    stack_p.pop();
                                }
                            }
                        }
                    },
                    Operation::Eval(v) => {
                        if *stack_p.last().unwrap() == v {
                            while let Some(u) = stack_s.pop() {
                                res[u] = id;
                                assigned[u] = true;
                                if u == v {
                                    break;
                                }
                            }
                            stack_p.pop();
                            id += 1;
                        }
                    },
                }
            }
        }
        res.iter_mut().for_each(|v| *v = id - 1 - *v);
        (id, res)
    }
}
// ---------- end SCC ----------
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
        s: [bytes; n],
    }
    let cond = |b: bool| {
        if !b {
            println!("Impossible");
            std::process::exit(0);
        }
    };
    let w = 26;
    let mut scc = SCC::new(w);
    for s in s.windows(2) {
        let a = &s[0];
        let b = &s[1];
        if let Some(k) = a.iter().zip(b.iter()).position(|p| *p.0 != *p.1) {
            let a = (a[k] - b'a') as usize;
            let b = (b[k] - b'a') as usize;
            scc.add_edge(a, b);
        } else {
            cond(a.len() <= b.len());
        }
    }
    let (len, id) = scc.build();
    cond(len == w);
    let mut ans = vec![b'0'; w];
    for (i, id) in id.iter().enumerate() {
        ans[*id] = b'a' + i as u8;
    }
    for a in ans {
        print!("{}", a as char);
    }
    println!();
}

fn main() {
    run();
}
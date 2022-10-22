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

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let s: Vec<char> = sc.next_chars();
        let mut scc = SCC::new(n);
        for (i, c) in s.iter().enumerate() {
            if *c != '<' {
                scc.add_edge(i, (i + 1) % n);
            }
            if *c != '>' {
                scc.add_edge((i + 1) % n, i);
            }
        }
        let (len, id) = scc.build();
        let mut cnt = vec![0; len];
        for id in id.iter() {
            cnt[*id] += 1;
        }
        let mut ans = 0;
        for id in id {
            if cnt[id] > 1 {
                ans += 1;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
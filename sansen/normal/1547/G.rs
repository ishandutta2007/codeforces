// ---------- begin SCC ----------
pub struct SCC {
    size: usize,
    edge: Vec<(u32, u32)>,
}

impl SCC {
    pub fn new(size: usize) -> Self {
        assert!(size <= 10usize.pow(8));
        SCC { size, edge: vec![] }
    }
    pub fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a < self.size && b < self.size);
        self.edge.push((a as u32, b as u32));
    }
    pub fn build(&self) -> (usize, Vec<usize>) {
        let size = self.size;
        let mut start = vec![0u32; size + 1];
        self.edge.iter().for_each(|e| start[e.0 as usize + 1] += 1);
        for i in 1..=size {
            start[i] += start[i - 1];
        }
        let mut buf = vec![0; self.edge.len()];
        for &(a, b) in self.edge.iter() {
            let po = &mut start[a as usize];
            buf[*po as usize] = b;
            *po += 1;
        }
        let mut s = 0usize;
        let mut neighbor = start.into_iter().take(size).map(|t| {
            let t = t as usize;
            let it = buf[s..t].iter().map(|p| *p as usize);
            s = t;
            it
        }).collect::<Vec<_>>();
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
            Iter(usize),
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
                        call.push(Operation::Iter(v));
                    },
                    Operation::Iter(v) => {
                        let it = &mut neighbor[v];
                        while let Some(u) = it.next() {
                            if ord[u] == size {
                                call.push(Operation::Iter(v));
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
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let mut e = vec![(0, 0); m];
        let mut scc = SCC::new(n);
        for e in e.iter_mut() {
            e.0 = sc.next::<usize>() - 1;
            e.1 = sc.next::<usize>() - 1;
            scc.add_edge(e.0, e.1);
        }
        let (len, id) = scc.build();
        let mut has_loop = vec![false; len];
        let mut g = vec![vec![]; len];
        for &(a, b) in e.iter() {
            let a = id[a];
            let b = id[b];
            if a == b {
                has_loop[a] = true;
            } else {
                g[a].push(b);
            }
        }
        #[derive(Clone, Copy, Eq, PartialEq)]
        enum State {
            No,
            One,
            Finite,
            Infinite,
        }
        let mut dp = vec![State::No; len];
        dp[id[0]] = State::One;
        for i in 0..len {
            if dp[i] == State::No {
                continue;
            }
            if has_loop[i] {
                dp[i] = State::Infinite;
            }
            let src = dp[i];
            for &u in g[i].iter() {
                match (src, dp[u]) {
                    (State::Infinite, _) => dp[u] = State::Infinite,
                    (_, State::Infinite) => (),
                    (State::Finite, _) => dp[u] = State::Finite,
                    (_, State::Finite) => dp[u] = State::Finite,
                    (State::One, State::One) => dp[u] = State::Finite,
                    (s, _) => dp[u] = s,
                };
            }
        }
        let mut s = String::new();
        for i in 0..n {
            let v = match dp[id[i]] {
                State::No => 0,
                State::One => 1,
                State::Finite => 2,
                State::Infinite => -1,
            };
            s.push_str(&format!("{} ", v));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
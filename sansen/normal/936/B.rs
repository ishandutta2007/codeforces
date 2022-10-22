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
    let n: usize = sc.next();
    sc.next::<usize>();
    let mut edge = vec![];
    let mut g = vec![vec![]; n];
    let mut h = vec![vec![]; n];
    for i in 0..n {
        let c = sc.next::<usize>();
        for _ in 0..c {
            let x = sc.next::<usize>() - 1;
            edge.push((i, x));
            g[i].push(x);
            h[x].push(i);
        }
    }
    let src = sc.next::<usize>() - 1;
    let mut dp = vec![[(false, n); 2]; n];
    for i in 0..n {
        if g[i].len() > 0 {
            continue;
        }
        dp[i][1].0 = true;
        let mut dfs = vec![(i, 1)];
        while let Some((v, d)) = dfs.pop() {
            let d = d ^ 1;
            for &u in h[v].iter() {
                if !dp[u][d].0 {
                    dp[u][d] = (true, v);
                    dfs.push((u, d));
                }
            }
        }
    }
    if dp[src][0].0 {
        let mut pos = (src, 0);
        let mut ans = String::new();
        while g[pos.0].len() > 0 {
            ans.push_str(&format!("{} ", pos.0 + 1));
            pos = (dp[pos.0][pos.1].1, pos.1 ^ 1);
        }
        ans.push_str(&format!("{} ", pos.0 + 1));
        ans.pop();
        writeln!(out, "Win").ok();
        writeln!(out, "{}", ans).ok();
        return;
    }
    let mut scc = SCC::new(n);
    for &(a, b) in &edge {
        scc.add_edge(a, b);
    }
    let (len, id) = scc.build();
    let mut cnt = vec![0; len];
    id.iter().for_each(|x| cnt[*x] += 1);
    let mut next = vec![vec![]; len];
    for &(a, b) in &edge {
        let a = id[a];
        let b = id[b];
        if a != b {
            next[a].push(b);
        }
    }
    let mut draw = vec![false; len];
    for (i, g) in next.iter().enumerate().rev() {
        if cnt[i] > 1 {
            draw[i] = true;
        }
        for &u in g.iter() {
            draw[i] |= draw[u];
        }
    }
    if draw[id[src]] {
        writeln!(out, "Draw").ok();
    } else {
        writeln!(out, "Lose").ok();
    }
}
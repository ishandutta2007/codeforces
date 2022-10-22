// ---------- begin Tree DP ----------
struct TreeDP<Edge> {
    size: usize,
    edge: Vec<(usize, usize)>,
    cost: Vec<Edge>,
}

impl<Edge>  TreeDP<Edge> {
    fn new(size: usize) -> Self {
        TreeDP {
            size: size,
            edge: vec![],
            cost: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize, c: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b));
        self.cost.push(c);
    }
    fn solve<Init, Merge, Value>(&self, root: usize, init: Init, merge: Merge) -> Value
    where Init: Fn(usize) -> Value, 
          Merge: Fn(Value, Value, &Edge) -> Value,
    {
        let size = self.size;
        let mut graph = vec![vec![]; size];
        for (i, e) in self.edge.iter().enumerate() {
            graph[e.0].push((e.1, i));
            graph[e.1].push((e.0, i));
        }
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
        assert!(topo.len() == size);
        let mut dp: Vec<Option<Value>> = (0..size).map(|_| None).collect();
        for &v in topo.iter().rev() {
            let mut now = init(v);
            for &(u, k) in graph[v].iter() {
                let b = dp[u].take().unwrap();
                now = merge(now, b, &self.cost[k]);
            }
            dp[v] = Some(now);
        }
        dp[root].take().unwrap()
    }
}
// ---------- end Tree DP ----------
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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let mut cnt = vec![0i64; n];
        for v in cnt.iter_mut() {
            *v -= sc.next::<i64>();
        }
        for v in cnt.iter_mut() {
            *v += sc.next::<i64>();
        }
        let mut solver = TreeDP::new(n);
        for _ in 1..n {
            let a: usize = sc.next();
            let b: usize = sc.next();
            solver.add_edge(a - 1, b - 1, ());
        }
        type Value = Vec<(u32, i64)>;
        type Edge = ();
        let init = |v: usize| vec![(0, cnt[v])];
        let merge = |a: Value, b: Value, _e: &Edge| -> Value {
            let mut next = vec![(0, std::i64::MIN); a.len() + b.len()];
            for (i, a) in a.iter().enumerate() {
                for (j, b) in b.iter().enumerate() {
                    next[i + j] = std::cmp::max(next[i + j], (a.0 + b.0, a.1 + b.1));
                    if b.1 > 0 {
                        next[i + j + 1] = std::cmp::max(next[i + j + 1], (a.0 + b.0 + 1, a.1));
                    } else {
                        next[i + j + 1] = std::cmp::max(next[i + j + 1], (a.0 + b.0, a.1));
                    }
                }
            }
            next
        };
        let (x, y) = solver.solve(0, init, merge)[m - 1];
        let ans = x + if y > 0 {1} else {0};
        writeln!(out, "{}", ans).ok();
    }
}
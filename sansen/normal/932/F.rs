// 
// N
//  O(log N)
// : O((log N)^2)
// ---------- begin incremental convex hull trick (min) ----------
// reference: https://yukicoder.me/wiki/decomposable_searching_problem
// verify: https://old.yosupo.jp/submission/35150
#[derive(Clone)]
struct ConvexHullTrick {
    line: Vec<(i64, i64)>,
}

impl ConvexHullTrick {
    fn new(mut line: Vec<(i64, i64)>) -> Self {
        assert!(line.len() > 0);
        line.sort();
        line.dedup_by(|a, b| a.0 == b.0);
        let mut stack: Vec<(i64, i64)> = vec![];
        for (a, b) in line {
            while stack.len() >= 2 {
                let len = stack.len();
                let (c, d) = stack[len - 1];
                let (e, f) = stack[len - 2];
                let x = (d - b).div_euclid(a - c);
                let y = (f - d).div_euclid(c - e);
                if x >= y {
                    stack.pop();
                } else {
                    break;
                }
            }
            stack.push((a, b));
        }
        ConvexHullTrick { line: stack }
    }
    fn find(&self, x: i64) -> i64 {
        let mut l = 0;
        let mut r = self.line.len() - 1;
        let line = &self.line;
        let func = |k: usize| -> i64 {
            let (a, b) = line[k];
            a * x + b
        };
        while r - l >= 3 {
            let ll = (2 * l + r) / 3;
            let rr = (l + 2 * r) / 3;
            if func(ll) <= func(rr) {
                r = rr;
            } else {
                l = ll;
            }
        }
        line[l..=r].iter().map(|p| p.0 * x + p.1).min().unwrap()
    }
}

#[derive(Clone, Default)]
pub struct IncrementalCHT {
    size: usize,
    cht: Vec<(ConvexHullTrick, usize)>,
}

impl IncrementalCHT {
    pub fn new() -> Self {
        IncrementalCHT { 
            size: 0,
            cht: vec![]
        }
    }
    pub fn add_line(&mut self, a: i64, b: i64) {
        self.size += 1;
        let mut line = vec![(a, b)];
        let mut p = 0;
        while self.cht.last().map_or(false, |q| q.1 == p) {
            p += 1;
            line.append(&mut self.cht.pop().unwrap().0.line);
        }
        let cht = ConvexHullTrick::new(line);
        self.cht.push((cht, p));
    }
    pub fn find(&self, x: i64) -> i64 {
        self.cht.iter().map(|p| p.0.find(x)).min().unwrap()
    }
    pub fn append(&mut self, other: &mut Self) {
        if self.size < other.size {
            std::mem::swap(self, other);
        }
        for (mut cht, _) in other.cht.drain(..) {
            for (a, b) in cht.line.drain(..) {
                self.add_line(a, b);
            }
        }
        other.size = 0;
    }
}
// ---------- end incremental convex hull trick (min) ----------
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
        a: [i64; n],
        b: [i64; n],
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut topo = vec![0];
    for i in 0..n {
        let v = topo[i];
        for u in g[v].clone() {
            let x = g[u].iter().position(|p| *p == v).unwrap();
            g[u].remove(x);
            topo.push(u);
        }
    }
    let mut dp = vec![0; n];
    let mut cht = vec![IncrementalCHT::new(); n];
    for &v in topo.iter().rev() {
        if g[v].is_empty() {
            cht[v].add_line(b[v], 0);
            continue;
        }
        let mut m = IncrementalCHT::new();
        for &u in g[v].iter() {
            m.append(&mut cht[u]);
        }
        dp[v] = m.find(a[v]);
        m.add_line(b[v], dp[v]);
        cht[v] = m;
    }
    let mut s = String::new();
    for dp in dp {
        s.push_str(&format!("{} ", dp));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
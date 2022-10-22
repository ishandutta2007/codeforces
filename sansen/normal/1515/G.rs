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
        let mut neighbor = start
            .into_iter()
            .take(size)
            .map(|t| {
                let t = t as usize;
                let it = buf[s..t].iter().map(|p| *p as usize);
                s = t;
                it
            })
            .collect::<Vec<_>>();
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
                    }
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
                    }
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
                    }
                }
            }
        }
        res.iter_mut().for_each(|v| *v = id - 1 - *v);
        (id, res)
    }
}
// ---------- end SCC ----------
// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u64, b: u64) -> u64 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
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

use std::io::Write;

fn dfs(
    v: usize,
    g: &[Vec<(usize, u64)>],
    ord: &mut [usize],
    id: &mut usize,
    depth: &mut [u64],
    ans: &mut Option<u64>,
) {
    ord[v] = *id;
    *id += 1;
    for &(u, w) in g[v].iter() {
        if ord[u] >= *id {
            depth[u] = depth[v] + w;
            dfs(u, g, ord, id, depth, ans);
        } else {
            let a = depth[v] + w;
            let b = depth[u];
            let d = a.max(b) - a.min(b);
            if d != 0 {
            if let Some(g) = ans.as_mut() {
                *g = binary_gcd(*g, d);
            } else {
                *ans = Some(d)
            }
            }
        }
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1, u64); m],
        q: usize,
        ask: [(usize1, u64, u64); q],
    }
    let mut scc = SCC::new(n);
    for &(a, b, _) in e.iter() {
        scc.add_edge(a, b);
    }
    let (len, id) = scc.build();
    let mut g = vec![vec![]; n];
    for (a, b, l) in e {
        if id[a] == id[b] {
            g[a].push((b, l));
        }
    }
    let mut root = vec![n; len];
    for i in 0..n {
        root[id[i]] = i;
    }
    let mut ans = vec![None; len];
    let mut depth = vec![0; n];
    let mut ord = vec![n; n];
    let mut val = 0;
    for i in 0..len {
        dfs(root[i], &g, &mut ord, &mut val, &mut depth, &mut ans[i]);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (v, s, t) in ask {
        let r = id[v];
        let mut v = "NO";
        if let Some(d) = ans[r] {
            let a = binary_gcd(t, d);
            if (t - s) % a == 0 {
                v = "YES";
            }
        }
        if s == 0 {
            v = "YES";
        }
        writeln!(out, "{}", v).ok();
    }
}

fn main() {
    run();
}
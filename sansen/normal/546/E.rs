type F = i32;
pub const INF: F = 10000;
const ZERO: F = 0;
fn non_zero(f: F) -> bool {
    f > ZERO
}
fn min(a: F, b: F) -> F {
    if a < b {
        a
    } else {
        b
    }
}
pub struct Graph {
    n: usize,
    depth: Vec<usize>,
    it: Vec<usize>,
    g: Vec<Vec<(usize, F, usize)>>,
}
impl Graph {
    pub fn new(n: usize) -> Graph {
        Graph {
            n: n,
            depth: vec![n + 1; n],
            it: vec![0; n],
            g: vec![vec![]; n],
        }
    }
    pub fn add_edge(&mut self, s: usize, t: usize, f: F) -> usize {
        let x = self.g[s].len();
        let y = self.g[t].len();
        self.g[s].push((t, f, y));
        self.g[t].push((s, ZERO, x));
        x
    }
    fn bfs(&mut self, src: usize, dst: usize) {
        let g = &self.g;
        let n = self.n;
        let dp = &mut self.depth;
        dp.clear();
        dp.resize(n, n + 1);
        dp[src] = 0;
        let mut q = std::collections::VecDeque::new();
        q.push_back(src);
        'outer: while let Some(v) = q.pop_front() {
            for &(u, f, _) in g[v].iter() {
                if dp[u] > dp[v] + 1 && non_zero(f) {
                    dp[u] = dp[v] + 1;
                    if u == dst {
                        break 'outer;
                    }
                    q.push_back(u);
                }
            }
        }
    }
    fn dfs(&mut self, v: usize, src: usize, f: F) -> F {
        if v == src {
            return f;
        }
        while self.it[v] < self.g[v].len() {
            let (u, _, inv) = self.g[v][self.it[v]];
            if self.depth[u] < self.depth[v] && non_zero(self.g[u][inv].1) {
                let capa = min(f, self.g[u][inv].1);
                let c = self.dfs(u, src, capa);
                if non_zero(c) {
                    self.g[v][self.it[v]].1 += c;
                    self.g[u][inv].1 -= c;
                    return c;
                }
            }
            self.it[v] += 1;
        }
        ZERO
    }
    pub fn flow(&mut self, src: usize, dst: usize) -> F {
        let mut ans = ZERO;
        loop {
            self.bfs(src, dst);
            if self.depth[dst] > self.n {
                break;
            }
            self.it.clear();
            self.it.resize(self.n, 0);
            loop {
                let f = self.dfs(dst, src, INF);
                if non_zero(f) {
                    ans += f;
                } else {
                    break;
                }
            }
        }
        ans
    }
}

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
        m: usize,
        a: [i32; n],
        b: [i32; n],
        e: [(usize1, usize1); m],
    }
    let mut g = Graph::new(2 * n + 2);
    let src = 2 * n + 1;
    let dst = src - 1;
    for (i, (a, b)) in a.iter().zip(b.iter()).enumerate() {
        g.add_edge(src, i, *a);
        g.add_edge(i + n, dst, *b);
        g.add_edge(i, i + n, INF);
    }
    let mut index = vec![];
    for &(a, b) in e.iter() {
        index.push(g.add_edge(a, b + n, INF));
        index.push(g.add_edge(b, a + n, INF));
    }
    let s = a.iter().sum::<i32>();
    let t = b.iter().sum::<i32>();
    if s != t || g.flow(src, dst) != s {
        println!("NO");
        return;
    }
    let mut f = vec![vec![0; n]; n];
    for (k, &(s, t)) in index.chunks(2).zip(e.iter()) {
        for &(k, s, t) in [(k[0], s, t), (k[1], t, s)].iter() {
            let v = INF - g.g[s][k].1;
            f[s][t] = v;
        }
    }
    for (i, (a, f)) in a.iter().zip(f.iter_mut()).enumerate() {
        let s = f.iter().sum::<i32>();
        f[i] = *a - s;
    }
    println!("YES");
    for f in f {
        for (i, f) in f.iter().enumerate() {
            if i > 0 {
                print!(" ");
            }
            print!("{}", *f);
        }
        println!();
    }
}

fn main() {
    run();
}
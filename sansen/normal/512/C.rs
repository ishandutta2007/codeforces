    type F = i32;
    pub const INF: F = 600;
    const ZERO: F = 0;
    fn non_zero(f: F) -> bool {
        f > ZERO
    }
    fn min(a: F, b: F) -> F {
        if a < b {a} else {b}
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
            let dp  = &mut self.depth;
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

// A <= 10^4
// a >= 2, 4
// a >= 2 ...
// 4
// N <= 200
// 
// 2
// 
// 2
// 
// 
// 
// 
// 
//
// 
// 
//
// 
// ...
//
// 2

fn is_prime(a: u32) -> bool {
    (2..).take_while(|p| p * p <= a).all(|p| a % p != 0)
}

fn dfs(v: usize, used: &mut [bool], res: &mut Vec<usize>, g: &[Vec<usize>]) {
    used[v] = true;
    for &u in g[v].iter() {
        if !used[u] {
            dfs(u, used, res, g);
        }
    }
    res.push(v);
}

fn run() {
    input! {
        n: usize,
        a: [u32; n],
    }
    let cond = |b: bool| {
        if !b {
            println!("Impossible");
            std::process::exit(0);
        }
    };
    cond(n % 2 == 0);
    let mut g = Graph::new(n + 2);
    let src = n + 1;
    let dst = src - 1;
    let mut edge = vec![];
    for (i, x) in a.iter().enumerate() {
        if x & 1 == 0 {
            g.add_edge(src, i, 2);
        } else {
            g.add_edge(i, dst, 2);
        }
        for (j, y) in a.iter().enumerate().take(i) {
            let s = if *x & 1 == 0 {i} else {j};
            let t = i + j - s;
            if is_prime(*x + *y) {
                edge.push((s, t, g.add_edge(s, t, 1)));
            }
        }
    }
    cond(g.flow(src, dst) == (n / 2 * 2) as i32);
    let mut tour = vec![vec![]; n];
    for &(s, t, k) in edge.iter() {
        if g.g[s][k].1 == 0 {
            tour[s].push(t);
            tour[t].push(s);
        }
    }
    let mut ans = vec![];
    let mut used = vec![false; n];
    for i in 0..n {
        if !used[i] {
            let mut res = vec![];
            dfs(i, &mut used, &mut res, &tour);
            ans.push(res);
        }
    }
    println!("{}", ans.len());
    for a in ans {
        print!("{}", a.len());
        for a in a {
            print!(" {}", a + 1);
        }
        println!();
    }
}

fn main() {
    run();
}
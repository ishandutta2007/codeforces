mod max_flow {
    use std;
    type F = i32;
    pub const INF: F = 1000;
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
        pub fn add_edge(&mut self, s: usize, t: usize, f: F) {
            let x = self.g[s].len();
            let y = self.g[t].len();
            self.g[s].push((t, f, y));
            self.g[t].push((s, ZERO, x));
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
}

fn diff(a: usize, b: usize) -> usize {
    std::cmp::max(a, b) - std::cmp::min(a, b)
}

#[allow(dead_code)]
fn test() {
    let n = 25;
    for h in 1..=n {
        print!("{:>2}: ", h);
        for w in 1..=n {
            let mut g = max_flow::Graph::new(h * w + 2);
            let src = h * w + 1;
            let dst = src - 1;
            for i in 0..h {
                for j in 0..w {
                    if (i + j) & 1 == 0 {
                        g.add_edge(src, i * w + j, 1);
                        for k in 0..h {
                            for l in 0..w {
                                if diff(i, k) + diff(j, l) == 3 {
                                    g.add_edge(i * w + j, k * w + l, 1);
                                }
                            }
                        }
                    } else {
                        g.add_edge(i * w + j, dst, 1);
                    }
                }
            }
            let ans = g.flow(src, dst) * 2;
            let c = if ans as usize == h * w { ' ' } else { '!' };
            print!("{:>4}{}", ans, c);
        }
        println!();
    }
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let mut h: usize = it.next().unwrap().parse().unwrap();
    let mut w: usize = it.next().unwrap().parse().unwrap();
    if h > w {
        std::mem::swap(&mut h, &mut w);
    }
    if h * w <= 100 {
        let mut g = max_flow::Graph::new(h * w + 2);
        let src = h * w + 1;
        let dst = src - 1;
        for i in 0..h {
            for j in 0..w {
                if (i + j) & 1 == 0 {
                    g.add_edge(src, i * w + j, 1);
                    for k in 0..h {
                        for l in 0..w {
                            if diff(i, k) + diff(j, l) == 3 {
                                g.add_edge(i * w + j, k * w + l, 1);
                            }
                        }
                    }
                } else {
                    g.add_edge(i * w + j, dst, 1);
                }
            }
        }
        let ans = g.flow(src, dst) * 2;
        println!("{}", ans);
    } else if h == 1 {
        let mut ans = w / 6 * 6;
        if w % 6 >= 4 {
            ans += 2;
        }
        if w % 6 >= 5 {
            ans += 2;
        }
        println!("{}", ans);
    } else if h % 2 == 1 && w % 2 == 1 {
        let ans = h as u64 * w as u64 - 1;
        println!("{}", ans);
    } else {
        let ans = h as u64 * w as u64;
        println!("{}", ans);
    }
}

fn main() {
//    test();
    run();
}
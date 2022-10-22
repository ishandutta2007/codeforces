// ---------- begin Centroid Decomposition ----------
struct CentroidDecomposition {
    graph: Vec<Vec<usize>>,
    next: Vec<(usize, usize)>,
}

#[allow(dead_code)]
impl CentroidDecomposition {
    fn new(n: usize) -> Self {
        CentroidDecomposition {
            graph: vec![vec![]; n],
            next: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        self.graph[a].push(b);
        self.graph[b].push(a);
    }
    fn build(&mut self) {
        let graph = &self.graph;
        let next = &mut self.next;
        let n = graph.len();
        next.clear();
        next.resize(n, (n, n));
        assert!(
            graph.iter().fold(0, |s, a| s + a.len()) == 2 * n - 2,
            "graph is not tree"
        );
        let mut dfs = vec![(0, 0, n)];
        let mut used = vec![false; n];
        let mut size = vec![0; n];
        let mut stack = vec![];
        let mut q = vec![];
        while let Some((v, rank, g)) = dfs.pop() {
            size[v] = 0;
            stack.push((v, v));
            q.clear();
            while let Some((v, p)) = stack.pop() {
                q.push(v);
                for &u in graph[v].iter() {
                    size[u] = 0;
                    if u != p && !used[u] {
                        stack.push((u, v));
                    }
                }
            }
            for &v in q.iter().rev() {
                size[v] = 1;
                for &u in graph[v].iter() {
                    size[v] += size[u];
                }
            }
            let mut parent = v;
            let mut r = v;
            loop {
                let mut max = (0, 0);
                for &u in graph[r].iter() {
                    if u != parent && !used[u] {
                        max = std::cmp::max(max, (size[u], u));
                    }
                }
                if 2 * max.0 <= size[v] {
                    break;
                }
                parent = r;
                r = max.1;
            }
            used[r] = true;
            next[r] = (rank, g);
            for &v in graph[r].iter() {
                if !used[v] {
                    dfs.push((v, rank + 1, r));
                }
            }
        }
    }
    fn belong(&self, v: usize) -> Vec<usize> {
        let mut ans = vec![];
        let mut v = v;
        while v < self.graph.len() {
            ans.push(v);
            v = self.next[v].1;
        }
        ans
    }
    fn rank(&self, v: usize) -> usize {
        self.next[v].0
    }
}
// ---------- end Centroid Decomposition ----------
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

//

use std::io::Write;

fn run() {
    input! {
        n: usize,
        a: [i64; n],
        b: [(usize1, usize1, i64, i64); n - 1],
        q: usize,
        p: [(usize1, usize1); q],
    }
    let mut graph = vec![vec![]; 2 * n];
    for (i, a) in a.iter().enumerate() {
        graph[2 * i].push((2 * i + 1, *a));
        graph[2 * i + 1].push((2 * i, *a));
    }
    for &(x, y, z, w) in b.iter() {
        graph[2 * x].push((2 * y, z));
        graph[2 * y].push((2 * x, z));
        graph[2 * x + 1].push((2 * y + 1, w));
        graph[2 * y + 1].push((2 * x + 1, w));
    }
    let mut cent = CentroidDecomposition::new(n);
    for &(x, y, _, _) in b.iter() {
        cent.add_edge(x, y);
    }
    cent.build();
    let mut memo = vec![];
    for k in 0.. {
        let mut dp = vec![vec![1_000_000_000_000 * 300_000i64; 2 * n]; 2];
        let mut update = false;
        for i in 0..n {
            if cent.rank(i) != k {
                continue;
            }
            update = true;
            for (r, dp) in dp.iter_mut().enumerate() {
                dp[2 * i + r] = 0;
                let mut h = std::collections::BinaryHeap::new();
                h.push((0, 2 * i + r));
                while let Some((d, v)) = h.pop() {
                    let d = -d;
                    if d > dp[v] {
                        continue;
                    }
                    for &(u, w) in graph[v].iter() {
                        let d = d + w;
                        if cent.rank(u / 2) >= k && dp[u] > d {
                            dp[u] = d;
                            h.push((-d, u));
                        }
                    }
                }
            }
        }
        if !update {
            break;
        }
        memo.push(dp);
    }
    let dp = memo;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (u, v) in p {
        let mut p = u / 2;
        let mut q = v / 2;
        while p != q {
            if cent.rank(p) > cent.rank(q) {
                p = cent.next[p].1;
            } else {
                q = cent.next[q].1;
            }
        }
        let mut ans = std::i64::MAX;
        while p < n {
            let i = cent.rank(p);
            p = cent.next[p].1;
            ans = std::cmp::min(ans, dp[i][0][u] + dp[i][0][v]);
            ans = std::cmp::min(ans, dp[i][1][u] + dp[i][1][v]);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
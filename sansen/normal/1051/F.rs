// ---------- begin Lowest Common Ancestor ----------
struct LCA {
    graph: Vec<Vec<usize>>,
    path_root: Vec<usize>,
    path_parent: Vec<usize>,
    index: Vec<usize>
}

impl LCA {
    fn new(n: usize) -> Self {
        LCA {
            graph: vec![vec![]; n],
            path_root: vec![],
            path_parent: vec![],
            index: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        self.graph[a].push(b);
        self.graph[b].push(a);
    }
    fn build(&mut self, root: usize) {
        let mut q = vec![];
        let mut stack = vec![(root, root)];
        let graph = &mut self.graph;
        while let Some((v, p)) = stack.pop() {
            q.push(v);
            for i in 0..graph[v].len() {
                if graph[v][i] == p {
                    graph[v].swap_remove(i);
                    break;
                }
            }
            for &u in &graph[v] {
                stack.push((u, v));
            }
        }
        assert!(q.len() == graph.len());
        let n = graph.len();
        let mut size = vec![1; n];
        for &v in q.iter().rev() {
            for i in 0..graph[v].len() {
                let u = graph[v][i];
                size[v] += size[u];
                if size[u] > size[graph[v][0]] {
                    graph[v].swap(0, i);
                }
            }
        }
        let mut path_root = vec![root; n];
        let mut path_parent = vec![root; n];
        let mut index = vec![n; n];
        let mut stack = vec![root];
        let mut k = 0;
        while let Some(v) = stack.pop() {
            index[v] = k;
            k += 1;
            for i in 1..graph[v].len() {
                let u = graph[v][i];
                path_root[u] = u;
                path_parent[u] = v;
                stack.push(u);
            }
            if graph[v].len() > 0 {
                let u = graph[v][0];
                path_root[u] = path_root[v];
                path_parent[u] = path_parent[v];
                stack.push(u);
            }
        }
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.index = index;
    }
    fn query(&self, mut a: usize, mut b: usize) -> usize {
        let path = &self.path_root;
        let parent = &self.path_parent;
        let index = &self.index;
        while path[a] != path[b] {
            if index[a] < index[b] {
                b = parent[b];
            } else {
                a = parent[a];
            }
        }
        if index[a] < index[b] {a} else {b}
    }
}
// ---------- end Lowest Common Ancestor ----------
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
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1, i64); m],
        query: usize,
        ask: [(usize1, usize1); query],
    }
    let mut g = vec![vec![]; n];
    for (a, b, d) in e {
        g[a].push((b, d));
        g[b].push((a, d));
    }
    let root = 0;
    let mut lca = LCA::new(n);
    let mut parent = vec![n; n];
    parent[root] = root;
    let mut distance = vec![0; n];
    let mut stack = vec![root];
    let mut q = vec![];
    let mut b = vec![];
    while let Some(v) = stack.pop() {
        q.push(v);
        for &(u, d) in g[v].iter() {
            if parent[u] == n {
                parent[u] = v;
                distance[u] = d;
                lca.add_edge(u, v);
                stack.push(u);
            } else if u != parent[v] {
                b.push(u);
                b.push(v);
            }
        }
    }
    lca.build(root);
    for &v in q[1..].iter() {
        let p = parent[v];
        distance[v] += distance[p];
    }
    b.sort();
    b.dedup();
    let mut memo = vec![];
    for &src in b.iter() {
        let mut dp = vec![std::i64::MAX; n];
        dp[src] = 0;
        let mut h = std::collections::BinaryHeap::new();
        h.push((-dp[src], src));
        while let Some((d, v)) = h.pop() {
            let d = -d;
            if d > dp[v] {
                continue;
            }
            for &(u, c) in g[v].iter() {
                let d = d + c;
                if d < dp[u] {
                    dp[u] = d;
                    h.push((-d, u));
                }
            }
        }
        memo.push(dp);
    }
    for (a, b) in ask {
        let p = lca.query(a, b);
        let mut ans = distance[a] + distance[b] - 2 * distance[p];
        for dp in memo.iter() {
            ans = std::cmp::min(ans, dp[a] + dp[b]);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
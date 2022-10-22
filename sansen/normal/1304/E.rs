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
        e: [(usize1, usize1); n - 1],
        q: usize,
        ask: [(usize1, usize1, usize1, usize1, usize); q],
    }
    let mut lca = LCA::new(n);
    for (a, b) in e {
        lca.add_edge(a, b);
    }
    let root = 0;
    lca.build(root);
    let mut depth = vec![0; n];
    let mut stack = vec![root];
    while let Some(v) = stack.pop() {
        for &u in lca.graph[v].iter() {
            depth[u] = depth[v] + 1;
            stack.push(u);
        }
    }
    let distance = |a: usize, b: usize| -> usize {
        depth[a] + depth[b] - 2 * depth[lca.query(a, b)]
    };
    for (x, y, a, b, k) in ask {
        let valid = |d: usize| -> bool {
            d <= k && (k - d) % 2 == 0
        };
        let mut ok = false;
        ok |= valid(distance(a, b));
        ok |= valid(distance(a, x) + distance(y, b) + 1);
        ok |= valid(distance(a, y) + distance(x, b) + 1);
        let ans = if ok {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
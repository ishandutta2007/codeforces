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
            if let Some(k) = graph[v].iter().position(|u| *u == p) {
                graph[v].swap_remove(k);
            }
            for &u in graph[v].iter() {
                stack.push((u, v));
            }
        }
        let n = graph.len();
        let mut size = vec![1; n];
        for &v in q.iter().rev() {
            if graph[v].is_empty() {
                continue;
            }
            let mut max = (0, 0);
            for (i, &u) in graph[v].iter().enumerate() {
                size[v] += size[u];
                if size[u] > max.0 {
                    max = (size[u], i);
                }
            }
            graph[v].swap(0, max.1);
        }
        let mut path_root = vec![root; n];
        let mut path_parent = vec![root; n];
        let mut index = vec![n; n];
        let mut stack = vec![root];
        let mut k = 0;
        while let Some(v) = stack.pop() {
            index[v] = k;
            k += 1;
            if graph[v].is_empty() {
                continue;
            }
            for &u in graph[v].iter().skip(1) {
                path_root[u] = u;
                path_parent[u] = v;
                stack.push(u);
            }
            let u = graph[v][0];
            path_root[u] = path_root[v];
            path_parent[u] = path_parent[v];
            stack.push(u);
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

//

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for &(a, b) in e.iter() {
        g[a].push(b);
        g[b].push(a);
    }
    let root = 0;
    let mut used = vec![false; n];
    let mut parent = vec![root; n];
    let mut stack = vec![root];
    used[root] = true;
    let mut lca = LCA::new(n);
    let mut back = vec![];
    let mut q = vec![];
    while let Some(v) = stack.pop() {
        q.push(v);
        for &u in g[v].iter() {
            if u == parent[v] {
                continue;
            }
            if !used[u] {
                used[u] = true;
                parent[u] = v;
                lca.add_edge(u, v);
                stack.push(u);
            } else {
                back.push((u, v));
            }
        }
    }
    lca.build(root);
    if let Some((u, v)) = back.pop() {
        let p = lca.query(u, v);
        let mut ans = std::collections::VecDeque::new();
        let mut x = u;
        while x != p {
            ans.push_front(x);
            x = parent[x];
        }
        ans.push_front(x);
        let mut x = v;
        while x != p {
            ans.push_back(x);
            x = parent[x];
        }
        let mut s = String::new();
        if ans.len() > k {
            s.push_str(&format!("1\n"));
            for a in ans.iter().step_by(2).take((k + 1) / 2) {
                s.push_str(&format!("{} ", *a + 1));
            }
        } else {
            s.push_str(&format!("2\n{}\n", ans.len()));
            for a in ans {
                s.push_str(&format!("{} ", a + 1));
            }
        }
        s.pop();
        println!("{}", s);
    } else {
        let mut s = String::new();
        s.push_str(&format!("1\n"));
        let mut used = vec![false; n];
        let mut cnt = (k + 1) / 2;
        for &v in q.iter().rev() {
            if !used[v] && cnt > 0 {
                used[v] = true;
                used[parent[v]] = true;
                cnt -= 1;
                s.push_str(&format!("{} ", v + 1));
            }
        }
        s.pop();
        println!("{}", s);
    }
}

fn main() {
    run();
}
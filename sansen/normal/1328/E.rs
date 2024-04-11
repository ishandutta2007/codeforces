// ---------- begin Heavy-Light decomposition ----------
struct HLD {
    graph: Vec<Vec<usize>>,
    path_root: Vec<usize>,
    path_parent: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
    parent: Vec<usize>,
}

impl HLD {
    fn new(n: usize) -> Self {
        HLD {
            graph: vec![vec![]; n],
            path_root: vec![],
            path_parent: vec![],
            left: vec![],
            right: vec![],
            parent: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        self.graph[a].push(b);
        self.graph[b].push(a);
    }
    fn build(&mut self, root: usize) {
        let mut q = vec![];
        let mut stack = vec![(root, root)];
        self.parent.resize(self.graph.len(), root);
        let graph = &mut self.graph;
        while let Some((v, p)) = stack.pop() {
            q.push(v);
            self.parent[v] = p;
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
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let mut stack = vec![(root, 0)];
        let mut k = 0;
        while let Some((v, op)) = stack.pop() {
            if op == 1 {
                right[v] = k;
                continue;
            }
            left[v] = k;
            k += 1;
            stack.push((v, 1));
            for i in 1..graph[v].len() {
                let u = graph[v][i];
                path_root[u] = u;
                path_parent[u] = v;
                stack.push((u, 0));
            }
            if graph[v].len() > 0 {
                let u = graph[v][0];
                path_root[u] = path_root[v];
                path_parent[u] = path_parent[v];
                stack.push((u, 0));
            }
        }
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.left = left;
        self.right = right;
    }
    fn sub_tree(&self, v: usize) -> (usize, usize) {
        (self.left[v], self.right[v])
    }
    fn path(&self, v: usize, u: usize) -> Vec<(usize, usize)> {
        let path = &self.path_root;
        let parent = &self.path_parent;
        let index = &self.left;
        let mut x = v;
        let mut y = u;
        let mut ans = vec![];
        while path[x] != path[y] {
            if index[x] < index[y] {
                let p = path[y];
                ans.push((index[p], index[y] + 1));
                y = parent[y];
            } else {
                let p = path[x];
                ans.push((index[p], index[x] + 1));
                x = parent[x];
            }
        }
        ans.push((std::cmp::min(index[x], index[y]), std::cmp::max(index[x], index[y]) + 1));
        ans
    }
    fn parent(&self, x: usize) -> usize {
        self.parent[x]
    }
}
// ---------- end Heavy-Light decomposition ----------
//---------- begin scanner ----------
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
//---------- end scanner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let mut hld = HLD::new(n);
    for _ in 1..n {
        let a: usize = sc.next();
        let b: usize = sc.next();
        hld.add_edge(a - 1, b - 1);
    }
    hld.build(0);
    let mut depth = vec![0; n];
    for i in 0..n {
        let path = hld.path(0, i);
        depth[i] = path.into_iter().fold(0, |s, a| s + a.1 - a.0);
    }
    for _ in 0..m {
        let k: usize = sc.next();
        let mut set = std::collections::BTreeSet::new();
        for _ in 0..k {
            let v: usize = sc.next();
            let u = hld.parent(v - 1);
            set.insert(u);
        }
        let mut p: Vec<(usize, usize)> = set.into_iter().map(|v| (depth[v], v)).collect();
        p.sort();
        let valid = p.windows(2).all(|a| {
            let (l, r) = hld.sub_tree(a[0].1);
            let (x, y) = hld.sub_tree(a[1].1);
            l <= x && y <= r
        });
        if valid {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
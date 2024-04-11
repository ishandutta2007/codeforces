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

use std::io::Read;

#[derive(Clone, Copy)]
struct Line(i64, i64);

impl Line {
    fn eval(&self, x: i64) -> i64 {
        self.0 * x + self.1
    }
}

type Link = Option<Box<Node>>;

struct Node {
    line: Line,
    left: Link,
    right: Link,
}

fn insert(node: &mut Link, l: i64, r: i64, line: Line) {
    if node.is_none() {
        *node = Some(Box::new(Node {
            line: line,
            left: None,
            right: None,
        }));
        return;
    }
    let node = node.as_mut().unwrap();
    let (x, y) = if node.line.eval(l) >= line.eval(l) {
        (node.line, line)
    } else {
        (line, node.line)
    };
    let m = (l + r) / 2;
    if x.eval(r) >= y.eval(r) {
        node.line = x;
    } else if x.eval(m) >=y.eval(m) {
        node.line = x;
        insert(&mut node.right, m, r, y);
    } else {
        node.line = y;
        insert(&mut node.left, l, m, x);
    }
}

fn eval(node: &Link, l: i64, r: i64, x: i64) -> i64 {
    if node.is_none() {
        return 0;
    }
    assert!(l <= x && x < r);
    let node = node.as_ref().unwrap();
    let m = (l + r) / 2;
    let v = if x < m {
        eval(&node.left, l, m, x)
    } else {
        eval(&node.right, m, r, x)
    };
    std::cmp::max(v, node.line.eval(x))
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut cent = CentroidDecomposition::new(n);
    for _ in 1..n {
        let a: usize = it.next().unwrap().parse().unwrap();
        let b: usize = it.next().unwrap().parse().unwrap();
        cent.add_edge(a - 1, b - 1);
    }
    cent.build();
    let a: Vec<i64> = it.map(|s| s.parse().unwrap()).collect();
    let mut ans = 0;
    for g in 0..n {
        let r = cent.rank(g);
        let mut cht = None;
        let range = (0i64, (n / (2 << r)) as i64 + 1);
        for &u in cent.graph[g].iter() {
            if cent.rank(u) <= r {
                continue;
            }
            let mut memo = vec![];
            let mut stack = vec![(u, g, 1, a[u], a[u])];
            while let Some((v, p, d, sum, psum)) = stack.pop() {
                ans = std::cmp::max(eval(&cht, range.0, range.1, d) + psum, ans);
                memo.push((sum + a[g], (d + 1) * sum - psum + a[g] + sum));
                for &u in cent.graph[v].iter() {
                    if u != p && cent.rank(u) > r {
                        stack.push((u, v, d + 1, sum + a[u], psum + sum + a[u]));
                    }
                }
            }
            for (a, b) in memo {
                insert(&mut cht, range.0, range.1, Line(a, b));
            }
        }
        let mut cht = None;
        let range = (0i64, (n / (2 << r)) as i64 + 1);
        for &u in cent.graph[g].iter().rev() {
            if cent.rank(u) <= r {
                continue;
            }
            let mut memo = vec![];
            let mut stack = vec![(u, g, 1, a[u], a[u])];
            while let Some((v, p, d, sum, psum)) = stack.pop() {
                ans = std::cmp::max(eval(&cht, range.0, range.1, d) + psum, ans);
                memo.push((sum + a[g], (d + 1) * sum - psum + a[g] + sum));
                for &u in cent.graph[v].iter() {
                    if u != p && cent.rank(u) > r {
                        stack.push((u, v, d + 1, sum + a[u], psum + sum + a[u]));
                    }
                }
            }
            for (a, b) in memo {
                insert(&mut cht, range.0, range.1, Line(a, b));
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
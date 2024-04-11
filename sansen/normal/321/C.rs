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
 
fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut centroid = CentroidDecomposition::new(n);
    for _ in 1..n {
        let a: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
        let b: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
        centroid.add_edge(a, b);
    }
    centroid.build();
    let c = centroid;
    let mut ans = String::new();
    for i in 0..n {
        let v = ('A' as u8 + c.rank(i) as u8) as char;
        ans.push(v);
        ans.push(' ');
    }
    ans.pop();
    println!("{}", ans);
}
 
fn main() {
    run();
}
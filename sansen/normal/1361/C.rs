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

struct Graph {
    size: usize,
    edge: Vec<(usize, usize)>,
}

impl Graph {
    fn new(size: usize) -> Self {
        Graph {
            size: size,
            edge: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a < self.size && b < self.size);
        self.edge.push((a, b));
    }
    // 
    fn solve(&self) -> Option<Vec<(usize, usize, usize)>> {
        let size = self.size;
        let edge = &self.edge;
        let mut deg = vec![0; size];
        for &(a, b) in edge.iter() {
            deg[a] += 1;
            deg[b] += 1;
        }
        if deg.iter().filter(|d| *d % 2 == 1).count() > 2 {
            return None;
        }
        if edge.is_empty() {
            return Some(vec![]);
        }
        let mut graph: Vec<Vec<(usize, usize)>> = deg.iter().map(|d| Vec::with_capacity(*d)).collect();
        for (i, &(a, b)) in edge.iter().enumerate() {
            graph[a].push((b, i));
            graph[b].push((a, i));
        }
        let start = if let Some(k) = graph.iter().position(|g| g.len() & 1 == 1) {
            k
        } else {
            graph.iter().position(|g| !g.is_empty()).unwrap()
        };
        let mut used = vec![false; edge.len()];
        enum Operation {
            ADD(usize, usize, usize),
            DFS(usize),
        }
        let mut ans = Vec::with_capacity(edge.len());
        let mut stack = vec![Operation::DFS(start)];
        while let Some(op) = stack.pop() {
            match op {
                Operation::ADD(k, s, t) => {
                    ans.push((k, s, t));
                },
                Operation::DFS(v) => {
                    while let Some((u, k)) = graph[v].pop() {
                        if !used[k] {
                            used[k] = true;
                            stack.push(Operation::DFS(v));
                            stack.push(Operation::ADD(k, v, u));
                            stack.push(Operation::DFS(u));
                            break;
                        }
                    }
                },
            }
        }
        if ans.len() < edge.len() {
            None
        } else {
            ans.reverse();
            assert!(ans.windows(2).all(|a| a[0].2 == a[1].1));
            Some(ans)
        }
    }
}

fn run() {
    input! {
        n: usize,
        p: [(usize, usize); n],
    }
    for bit in (0usize..=20).rev() {
        let mask = (1 << bit) - 1;
        let mut cnt = vec![0; mask + 1];
        for &(a, b) in p.iter() {
            cnt[a & mask] += 1;
            cnt[b & mask] += 1;
        }
        if cnt.iter().any(|c| *c & 1 == 1) {
            continue;
        }
        let mut g = Graph::new(mask + 1);
        for &(a, b) in p.iter() {
            g.add_edge(a & mask, b & mask);
        }
        if let Some(ans) = g.solve() {
            let mut out = String::new();
            out.push_str(&format!("{}\n", bit));
            for (k, s, _) in ans {
                let x = p[k].0;
                let (a, b) = if s == x & mask {
                    (2 * k + 1, 2 * k + 2)
                } else {
                    (2 * k + 2, 2 * k + 1)
                };
                out.push_str(&format!("{} {} ", a, b));
            }
            out.pop();
            println!("{}", out);
            return;
        }
    }
}

fn main() {
    run();
}
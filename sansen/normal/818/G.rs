const INF: i64 = 3000 + 1;

struct Graph {
    size: usize,
    edge: Vec<(usize, usize, i64, i64)>,
}

impl Graph {
    fn new(size: usize) -> Self {
        Graph {
            size: size,
            edge: vec![],
        }
    }
    fn add_edge(&mut self, src: usize, dst: usize, capa: i64, cost: i64) {
        assert!(src < self.size && dst < self.size && src != dst);
        self.edge.push((src, dst, capa, cost));
    }
    fn solve(&self, src: usize, dst: usize, flow: i64) -> Option<i64> {
        if src == dst {
            return Some(0);
        }
        let size = self.size;
        let edge = &self.edge;
        let mut deg = vec![0; size];
        for &(a, b, _, _) in edge.iter() {
            deg[a] += 1;
            deg[b] += 1;
        }
        let mut graph: Vec<_> = deg.into_iter().map(|d| Vec::with_capacity(d)).collect();
        for &(a, b, capa, cost) in edge.iter() {
            let x = graph[a].len();
            let y = graph[b].len();
            graph[a].push((b, capa, cost, y));
            graph[b].push((a, 0, -cost, x));
        }
        let mut ans = 0;
        let mut dp = Vec::with_capacity(size);
        let mut elem = Vec::with_capacity(size);
        let mut que = std::collections::VecDeque::new();
        for _ in 0..flow {
            dp.clear();
            dp.resize(size, (INF, src, 0));// 
            dp[src] = (0, src, 0);
            elem.clear();
            elem.resize(size, false);
            elem[src] = true;
            que.push_back(src);
            while let Some(v) = que.pop_front() {
                elem[v] = false;
                let (c, _, _) = dp[v];
                for (i, &(u, capa, cost, _)) in graph[v].iter().enumerate() {
                    if capa == 0 {
                        continue;
                    }
                    let c = c + cost;
                    if c < dp[u].0 {
                        dp[u] = (c, v, i);
                        if !elem[u] {
                            elem[u] = true;
                            que.push_back(u);
                        }
                    }
                }
            }
            if dp[dst].0 == INF {
                return None;
            }
            ans += dp[dst].0;
            let mut pos = dst;
            while pos != src {
                let (_, parent, k) = dp[pos];
                let inv = graph[parent][k].3;
                graph[parent][k].1 -= 1;
                graph[pos][inv].1 += 1;
                pos = parent;
            }
        }
        Some(ans)
    }
}

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

// 2N+2 O(N^2) 
// 
// ij (> i) 
// 
// 2
// 

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut edge = vec![];
    let src = 2 * n;
    let dst = 2 * n + 1;
    for i in 0..n {
        edge.push((i, n + i, 1, -1));
        edge.push((src, i, 4, 0));
        edge.push((n + i, dst, 4, 0));
    }
    let mut diff = vec![None; 100000 + 2];
    let mut modulo = vec![None; 7];
    let mut id = dst + 1;
    for (i, &a) in a.iter().enumerate().rev() {
        for &k in [a - 1, a + 1].iter() {
            if let Some(v) = diff[k] {
                edge.push((i + n, v, 4, 0));
            }
        }
        if let Some(v) = modulo[a % 7] {
            edge.push((i + n, v, 4, 0));
            edge.push((id, i, 4, 0));
            edge.push((id, v, 4, 0));
            modulo[a % 7] = Some(id);
            id += 1;
        } else {
            modulo[a % 7] = Some(i);
        }
        if let Some(v) = diff[a] {
            edge.push((i + n, v, 4, 0));
            edge.push((id, i, 4, 0));
            edge.push((id, v, 4, 0));
            diff[a] = Some(id);
            id += 1;
        } else {
            diff[a] = Some(i);
        }
    }
    let mut g = Graph::new(id);
    for (a, b, capa, cost) in edge {
        g.add_edge(a, b, capa, cost);
    }
    let ans = -g.solve(src, dst, 4).unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
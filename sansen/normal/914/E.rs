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
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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
// ---------- end input macro ----------

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
        s: bytes,
    }
    let s = s
        .into_iter()
        .map(|s| (s - b'a') as usize)
        .collect::<Vec<_>>();
    let mut cent = CentroidDecomposition::new(n);
    for (a, b) in e {
        cent.add_edge(a, b);
    }
    cent.build();
    let len = 20;
    let mut dp = vec![0usize; n];
    let mut imos = vec![0u64; n];
    let mut cnt = vec![0u64; 1 << len];
    let mut ans = vec![1u64; n];
    for root in 0..n {
//        println!("root: {}", root);
        dp[root] = 0;
        let rank = cent.rank(root);
        let mut child = vec![];
        for &u in cent.graph[root].iter() {
            if cent.rank(u) <= rank {
                continue;
            }
            let mut topo = vec![];
            let mut dfs = vec![(u, root)];
            while let Some((v, p)) = dfs.pop() {
                topo.push((v, p));
                dp[v] = dp[p] ^ (1 << s[v]);
                cnt[dp[v]] += 1;
                for &u in cent.graph[v].iter() {
                    if u != p && cent.rank(u) > rank {
                        dfs.push((u, v));
                    }
                }
            }
//            println!("child: {:?}", topo);
            child.push(topo);
        }
        let mut sum = 0;
        for topo in child.iter() {
            topo.iter().for_each(|v| cnt[dp[v.0]] -= 1);
            for &(v, _) in topo.iter() {
                let bit = dp[v] ^ (1 << s[root]);
                if bit.count_ones() <= 1 {
                    imos[v] += 1;
                }
                imos[v] += cnt[bit];
                sum += cnt[bit];
                for i in 0..len {
                    let w = cnt[bit ^ (1 << i)];
                    imos[v] += w;
                    sum += w;
                }
            }
            topo.iter().for_each(|v| cnt[dp[v.0]] += 1);
        }
        assert!(sum % 2 == 0, "ERROR: root {}, sum: {}", root, sum);
        for &(v, p) in child.iter().flatten().rev() {
            imos[p] += imos[v];
            ans[v] += imos[v];
            imos[v] = 0;
            cnt[dp[v]] = 0;
        }
        ans[root] += imos[root] - sum / 2;
        imos[root] = 0;
    }
    let a = ans.iter().map(|a| a.to_string()).collect::<Vec<_>>().join(" ");
    println!("{}", a);
}

fn main() {
    run();
}
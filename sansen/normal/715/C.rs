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

use std::collections::*;

fn mod_pow(r: u64, mut n: u64, m: u64) -> u64 {
    let mut t = 1 % m;
    let mut s = r % m;
    while n > 0 {
        if n & 1 == 1 {
            t = t * s % m;
        }
        s = s * s % m;
        n >>= 1;
    }
    t
}

fn inverse(a: u64, m: u64) -> u64 {
    let mut phi = m;
    let mut x = m;
    for k in 2.. {
        if k * k > x {
            break;
        }
        if x % k == 0 {
            while x % k == 0 {
                x /= k;
            }
            phi -= phi / k;
        }
    }
    if x > 1 {
        phi -= phi / x;
    }
    mod_pow(a, phi - 1, m)
}

fn run() {
    input! {
        n: usize,
        m: u64,
        e: [(usize, usize, u64); n - 1],
    }
    let mut cent = CentroidDecomposition::new(n);
    let mut g = vec![vec![]; n];
    for &(a, b, d) in e.iter(){
        cent.add_edge(a, b);
        g[a].push((b, d % m));
        g[b].push((a, d % m));
    }
    cent.build();
    let rad = 10 % m;
    let inv = inverse(rad, m);
    assert!(m == 1 || rad * inv % m == 1);
    let mut down = vec![vec![]; n];
    let mut up = vec![vec![]; n];
    let mut ans = 0u64;
    for i in 0..n {
        let r = cent.rank(i);
        let mut all = vec![];
        for &(u, w) in g[i].iter() {
            if cent.rank(u) <= r {
                continue;
            }
            let down = &mut down[u];
            let up = &mut up[u];
            down.clear();
            up.clear();
            let mut stack = vec![(u, i, w, w, 0)];
            while let Some((v, p, a, b, d)) = stack.pop() {
                down.push((a, d));
                up.push((b, d));
                all.push((b, d));
                for &(u, w) in g[v].iter() {
                    if u == p || cent.rank(u) <= r {
                        continue;
                    }
                    stack.push((u, v, (rad * a + w) % m, (inv * b + w) % m, d + 1));
                }
            }
        }
        let mut map = BTreeMap::new();
        for (b, d) in all {
            *map.entry(b * mod_pow(rad, d, m) % m).or_insert(0) += 1;
        }
        for &(u, _) in g[i].iter() {
            if cent.rank(u) <= r {
                continue;
            }
            let mut sub = BTreeMap::new();
            for &(b, d) in up[u].iter() {
                if b == 0 {
                    ans += 1;
                }
                *sub.entry(b * mod_pow(rad, d, m) % m).or_insert(0) += 1;
            }
            for &(a, d) in down[u].iter() {
                if a == 0 {
                    ans += 1;
                }
                let a = a * mod_pow(inv, d + 1, m) % m;
                let key = (m - a) % m;
                let mut x = map.get(&key).cloned().unwrap_or(0);
                x -= sub.get(&key).cloned().unwrap_or(0);
                ans += x;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
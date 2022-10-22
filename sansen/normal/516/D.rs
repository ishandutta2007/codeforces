//---------- begin union_find ----------
pub struct DSU {
    p: Vec<i32>,
}
impl DSU {
    pub fn new(n: usize) -> DSU {
        DSU { p: vec![-1; n] }
    }
    pub fn init(&mut self) {
        self.p.iter_mut().for_each(|p| *p = -1);
    }
    pub fn root(&mut self, x: usize) -> usize {
        assert!(x < self.p.len());
        if self.p[x] < 0 {
            x
        } else {
            let r = self.root(self.p[x] as usize);
            self.p[x] = r as i32;
            r
        }
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.p.len());
        assert!(y < self.p.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            return None;
        }
        if self.p[x] > self.p[y] {
            std::mem::swap(&mut x, &mut y);
        }
        self.p[x] += self.p[y];
        self.p[y] = x as i32;
        Some((x, y))
    }
}
//---------- end union_find ----------
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

// dfs
// -L
// setlog

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1, u64); n - 1],
        q: usize,
        ask: [u64; q],
    }
    let mut g = vec![vec![]; n];
    for &(a, b, c) in e.iter() {
        g[a].push((b, c));
        g[b].push((a, c));
    }
    let dfs = |v: usize| -> Vec<u64> {
        let mut dp = vec![0; n];
        let mut stack = vec![(v, v)];
        while let Some((v, p)) = stack.pop() {
            let d = dp[v];
            for &(u, c) in g[v].iter() {
                if u != p {
                    dp[u] = c + d;
                    stack.push((u, v));
                }
            }
        }
        dp
    };
    let mut memo = vec![0; n];
    let mut root = 0;
    for _ in 0..3 {
        let dp = dfs(root);
        let mut max = (0, n);
        for (i, (memo, dp)) in memo.iter_mut().zip(dp.iter()).enumerate() {
            *memo = std::cmp::max(*memo, *dp);
            max = std::cmp::max(max, (*dp, i));
        }
        root = max.1;
    }
    let mut ord = memo.iter().cloned().enumerate().collect::<Vec<_>>();
    ord.sort_by_key(|p| p.1);
    let root = ord[0].0;
    let mut g = vec![vec![]; n];
    for (a, b, _) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut topo = vec![root];
    for i in 0..n {
        let v = topo[i];
        let child = std::mem::take(&mut g[v]);
        for &u in child.iter() {
            let k = g[u].iter().position(|p| *p == v).unwrap();
            g[u].remove(k);
            topo.push(u);
        }
        g[v] = child;
    }
    for sup in ask {
        let mut ans = 0;
        let mut dsu = DSU::new(n);
        let mut dp = vec![0; n];
        let mut p = n - 1;
        for &(v, d) in ord.iter().rev() {
            while ord[p].1 > d + sup {
                dp[dsu.root(ord[p].0)] -= 1;
                p -= 1;
            }
            for &u in g[v].iter() {
                let (a, b) = dsu.unite(v, u).unwrap();
                dp[a] += dp[b];
            }
            let r = dsu.root(v);
            dp[r] += 1;
            ans = std::cmp::max(ans, dp[r]);
        }
        println!("{}", ans);
    }
}

fn main() {
    run();
}
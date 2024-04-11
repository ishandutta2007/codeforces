// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 
// 
// M=1
// 
//
// M=2
// 
// 1
// 2
// 
// 2?
// ?
// 
//  O(NM) 
// 
// 
//
// s
// 
// 
// 
// DP?
// v  k v dis(s, v) + dp[rem - k][v]
// s v
// x vk
//
// s 
// 

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1, u32); n - 1],
        src: usize1,
        m: usize,
        x: [usize1; m],
    }
    let inf = std::u32::MAX / 2;
    let mut deg = vec![0; n];
    let mut g = vec![vec![inf; n]; n];
    for i in 0..n {
        g[i][i] = 0;
    }
    let mut graph = vec![vec![]; n];
    for (a, b, w) in e {
        deg[a] += 1;
        deg[b] += 1;
        g[a][b] = w;
        g[b][a] = w;
        graph[a].push(b);
        graph[b].push(a);
    }
    for k in 0..n {
        for i in 0..n {
            for j in 0..n {
                let c = g[i][k] + g[k][j];
                g[i][j].chmin(c);
            }
        }
    }
    let deg = deg;
    let cost = g;
    let graph = graph;
    let mut dp = vec![vec![0; n]; m + 1];
    dp[0] = vec![0; n];
    for rem in 1..=m {
        for v in 0..n {
            if deg[v] > 1 {
                continue;
            }
            let mut leaf = vec![];
            for i in 0..n {
                if i != v && deg[i] == 1 {
                    leaf.push((i, 0));
                }
            }
            let mut val = (0, n);
            for _ in 0..rem {
                val = (0, n);
                for (i, &(u, k)) in leaf.iter().enumerate() {
                    let c = (cost[v][u] + dp[rem - k - 1][u], i);
                    val.chmax(c);
                }
                leaf[val.1].1 += 1;
            }
            dp[rem][v] = val.0;
        }
    }
    let mut cnt = vec![0; n];
    for x in x.iter() {
        cnt[*x] += 1;
    }
    let mut ans = inf;
    for &v in graph[src].iter() {
        let mut c = 0;
        let mut dfs = vec![(v, src)];
        let mut leaf = vec![];
        while let Some((v, p)) = dfs.pop() {
            c += cnt[v];
            if graph[v].len() == 1 {
                leaf.push((v, 0));
            }
            for &u in graph[v].iter() {
                if u != p {
                    dfs.push((u, v));
                }
            }
        }
        if c == 0 {
            continue;
        }
        let rem = c;
        let mut val = (0, n);
        for _ in 0..rem {
            val = (0, n);
            for (i, &(u, k)) in leaf.iter().enumerate() {
                let c = (cost[src][u] + dp[m - k - 1][u], i);
                val.chmax(c);
            }
            leaf[val.1].1 += 1;
        }
        ans.chmin(val.0);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
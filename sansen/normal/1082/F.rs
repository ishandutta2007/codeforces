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

// dp[][speed dial ][speeddial]

struct Tree {
    child: Vec<Vec<usize>>,
    weight: Vec<i64>,
}

impl Tree {
    fn dfs(&self, v: usize) -> Vec<[i64; 11]> {
        let len = self.weight.len();
        let mut dp = vec![[0i64; 11]; len];
        for &u in self.child[v].iter() {
            let res = self.dfs(u);
            let mut next = vec![[std::i64::MAX / 2; 11]; len];
            for ((next, dp), res) in next.iter_mut().zip(&dp).zip(&res[1..]) {
                for (i, dp) in dp.iter().enumerate() {
                    for (next, res) in next[i..].iter_mut().zip(res) {
                        next.chmin(*dp + *res);
                    }
                }
            }
            dp = next;
        }
        for (i, dp) in dp.iter_mut().enumerate() {
            let add = i as i64 * self.weight[v];
            dp.iter_mut().for_each(|dp| *dp += add);
        }
        let zero = dp[0];
        for dp in dp[1..].iter_mut() {
            for (dp, zero) in dp[1..].iter_mut().zip(&zero) {
                dp.chmin(*zero);
            }
        }
        dp
    }
}

fn run() {
    input! {
        n: usize,
        k: usize,
        s: [(bytes, i64); n],
    }
    let mut child: Vec<Vec<(usize, u8)>> = vec![vec![]];
    let mut weight = vec![0];
    for (s, m) in s {
        let mut pos = 0;
        for s in s.into_iter() {
            if child[pos].iter().find(|c| c.1 == s).is_none() {
                let node = child.len();
                child[pos].push((node, s));
                child.push(vec![]);
                weight.push(0);
            }
            pos = child[pos].iter().find(|c| c.1 == s).unwrap().0;
        }
        weight[pos] += m;
    }
    let tree = Tree {
        child: child
            .into_iter()
            .map(|c| c.into_iter().map(|c| c.0).collect())
            .collect(),
        weight: weight,
    };
    let ans = *tree.dfs(0)[0][..=k].iter().min().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
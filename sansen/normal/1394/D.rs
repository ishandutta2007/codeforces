// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
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

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        t: [i64; n],
        h: [u32; n],
        e: [(usize1, usize1); n - 1],
    }
    for root in 0..1 {
        let mut g = vec![vec![]; n];
        for &(a, b) in e.iter() {
            g[a].push(b);
            g[b].push(a);
        }
        let mut topo = vec![(root, root)];
        for i in 0..n {
            let (v, p) = topo[i];
            let g = &mut g[v];
            if let Some(k) = g.iter().position(|u| *u == p) {
                g.remove(k);
            }
            for &u in g.iter() {
                topo.push((u, v));
            }
        }
        let inf = std::i64::MAX / 10;
        // 0: 
        // 1: 
        let mut dp = vec![(inf, inf); n];
        for &(v, _) in topo.iter().rev().take(n - 1) {
            let child = &g[v];
            let mut sum = 0;
            let mut a = vec![];
            let mut b = 0;
            let mut c = 0;
            for &u in child.iter() {
                if h[v] == h[u] {
                    sum += dp[u].0;
                    a.push(dp[u].1 - dp[u].0);
                } else if h[v] > h[u] {
                    sum += dp[u].0;
                    b += 1;
                } else {
                    sum += dp[u].1;
                    c += 1;
                }
            }
            a.sort();
            let mut val = (inf, inf);
            b += a.len();
            if b == c {
                val.0 = sum + t[v] * (c as i64 + 1);
                val.1 = sum + t[v] * (c as i64 + 1);
            } else if b > c {
                val.0 = sum + t[v] * b as i64;
                val.1 = sum + t[v] * (b as i64 + 1);
            } else {
                val.0 = sum + t[v] * (c as i64 + 1);
                val.1 = sum + t[v] * c as i64;
            }
            for a in a {
                sum += a;
                b -= 1;
                c += 1;
                if b == c {
                    val.0.chmin(sum + t[v] * (c as i64 + 1));
                    val.1.chmin(sum + t[v] * (c as i64 + 1));
                } else if b > c {
                    val.0.chmin(sum + t[v] * b as i64);
                    val.1.chmin(sum + t[v] * (b as i64 + 1));
                } else {
                    val.0.chmin(sum + t[v] * (c as i64 + 1));
                    val.1.chmin(sum + t[v] * c as i64);
                }
            }
            dp[v] = val;
        }
        let mut ans = inf;
        let v = root;
        let child = &g[v];
        let mut sum = 0;
        let mut a = vec![];
        let mut b = 0;
        let mut c = 0;
        for &u in child.iter() {
            if h[v] == h[u] {
                sum += dp[u].0;
                a.push(dp[u].1 - dp[u].0);
            } else if h[v] > h[u] {
                sum += dp[u].0;
                b += 1;
            } else {
                sum += dp[u].1;
                c += 1;
            }
        }
        a.sort();
        b += a.len();
        if b == c {
            ans.chmin(sum + t[v] * c as i64);
        } else if b > c {
            ans.chmin(sum + t[v] * b as i64);
        } else {
            ans.chmin(sum + t[v] * c as i64);
        }
        for a in a {
            sum += a;
            b -= 1;
            c += 1;
            if b == c {
                ans.chmin(sum + t[v] * c as i64);
            } else if b > c {
                ans.chmin(sum + t[v] * b as i64);
            } else {
                ans.chmin(sum + t[v] * c as i64);
            }
        }
        println!("{}", ans);
    }
}

fn main() {
    run();
}
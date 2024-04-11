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

use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// k=20
// xx(x+1)/2 
// 
//
// N^2k DP
// 
// 
// monotone ?
// 
// 
//
// 
// 
// DP
// 
// k
// 
// 
// CHT?
// 
// 
//
// 
// 
// 
// Mo

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [usize1; n],
    }
    let inf = 10i64.pow(11);
    let mut cost = 0i64;
    let mut cnt = vec![0; n];
    let mut x = 0;
    let mut y = 0;
    let mut add = |x: usize, v: i64| {
        let cnt = &mut cnt[a[x]];
        let mut res = v * *cnt;
        *cnt += v;
        if v < 0 {
            res += 1;
        }
        res
    };
    let mut find = |l: usize, r: usize| -> i64 {
        if l >= r {
            return inf;
        }
        assert!(l < r && r <= n);
        while x > l {
            x -= 1;
            cost += add(x, 1);
        }
        while y < r {
            cost += add(y, 1);
            y += 1;
        }
        while x < l {
            cost += add(x, -1);
            x += 1;
        }
        while y > r {
            y -= 1;
            cost += add(y, -1);
        }
        cost
    };
    let mut dp = vec![inf; n + 1];
    dp[0] = 0;
    for i in 1..=n {
        dp[i] = find(0, i);
    }
    for i in 1..k {
        let mut next = dp.clone();
        let mut dfs = vec![(i, n + 1, i, n + 1)];
        while let Some((l, r, u, d)) = dfs.pop() {
            if u >= d {
                continue;
            }
            let m = (u + d) / 2;
            let mut val = (inf, 0);
            for i in l..r {
                val.chmin((find(i, m) + dp[i], i));
            }
            next[m] = val.0;
            dfs.push((l, val.1 + 1, u, m));
            dfs.push((val.1, r, m + 1, d));
        }
        dp = next;
    }
    println!("{}", dp[n]);
}

fn main() {
    run();
}
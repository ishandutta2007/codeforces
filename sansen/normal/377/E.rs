fn dfs(l: usize, r: usize, dp: &mut [(i64, i64)], p: &[(i64, i64)]) {
    if l + 1 >= r {
        return;
    }
    const INF: i64 = 1_000_000_000_000_000_000;
    let mid = (l + r) / 2;
    dfs(l, mid, dp, p);
    let mut call = vec![(l, mid, mid, r)];
    while let Some((a, b, c, d)) = call.pop() {
        if c >= d {
            continue;
        }
        let m = (c + d) / 2;
        let cost = p[m].1;
        let mut val = (INF, 0);
        let mut pos = a;
        for x in a..b {
            let q = (cost - dp[x].1 + p[x].0 - 1) / p[x].0;
            let (time, rem) = (dp[x].0 + q, dp[x].1 + q * p[x].0 - cost);
            if val.0 > time {
                val = (time, rem);
                pos = x;
            } else if val.0 == time && val.1 < rem {
                val = (time, rem);
                pos = x;
            }
        }
        if val.0 < dp[m].0 || (dp[m].0 == val.0 && dp[m].1 < val.1) {
            dp[m] = val;
        }
        call.push((a, pos + 1, c, m));
        call.push((pos, b, m + 1, d));
    }
    dfs(mid, r, dp, p);
}
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


fn run() {
    input! {
        n: usize,
        s: i64,
        p: [(i64, i64); n],
    }
    let mut p = p.into_iter().filter(|p| p.1 < s).collect::<Vec<_>>();
    p.push((1, s));
    p.sort_by_key(|p| p.1);
    for i in 1..p.len() {
        p[i].0 = p[i - 1].0.max(p[i].0);
    }
    let n = p.len();
    let inf = s + 1;
    // dp[i]: i
    let mut dp = vec![(inf, 0); n];
    dp[0] = (0, 0);
    dfs(0, n, &mut dp, &p);
    println!("{:?}", dp[n - 1].0);
}

fn main() {
    run();
}
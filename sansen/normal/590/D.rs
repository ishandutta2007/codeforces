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
        k: usize,
        s: usize,
        a: [i64; n],
    }
    let s = s.min(n * (n - 1) / 2);
    let inf = std::i64::MAX / 10;
    // dp[x][y]: xyswap = 
    let mut dp = vec![vec![inf; s + 1]; k + 1];
    let mut next = vec![vec![inf; s + 1]; k + 1];
    dp[0][0] = 0;
    for (i, &a) in a.iter().enumerate() {
        for (a, b) in next.iter_mut().zip(&dp) {
            a.clone_from_slice(b);
        }
        for (x, (next, dp)) in next[1..].iter_mut().zip(dp.iter()).enumerate() {
            let cost = i - x;
            if cost > s {
                continue;
            }
            for (next, dp) in next[cost..].iter_mut().zip(dp) {
                next.chmin(*dp + a);
            }
        }
        std::mem::swap(&mut dp, &mut next);
    }
    let ans = dp[k].iter().min().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
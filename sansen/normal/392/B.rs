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

// 

fn run() {
    input! {
        cost: [[u64; 3]; 3],
        n: usize,
    }
    let inf = std::u64::MAX / 10;
    let mut dp = vec![vec![vec![inf; 3]; 3]; n + 1];
    dp[0] = vec![vec![0; 3]; 3];
    for i in 1..=n {
        for k in 0..3 {
            for x in 0..3 {
                for y in 0..3 {
                    dp[i - 1][x][y] = dp[i - 1][x][y].min(dp[i - 1][x][k] + dp[i - 1][k][y]);
                }
            }
        }
        for s in 0..3 {
            for t in 0..3 {
                if s == t {
                    dp[i][s][t] = 0;
                    continue;
                }
                let m = s ^ t ^ 0 ^ 1 ^ 2;
                let mut val = inf;
                val.chmin(dp[i - 1][s][m] + cost[s][t] + dp[i - 1][m][t]);
                val.chmin(dp[i - 1][s][t] + cost[s][m] + dp[i - 1][t][s] + cost[m][t] + dp[i - 1][s][t]);
                dp[i][s][t] = val;
            }
        }
    }
    println!("{}", dp[n][0][2]);
}

fn main() {
    run();
}
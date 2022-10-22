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
        m: usize,
        e: [(usize1, usize1); m],
    }
    let mut rail = vec![vec![false; n]; n];
    for (a, b) in e {
        rail[a][b] = true;
        rail[b][a] = true;
    }
    let inf = n * n * 2;
    let mut dp = vec![vec![vec![inf; n]; n]; 2];
    dp[0][0][0] = 0;
    let mut q = std::collections::VecDeque::new();
    q.push_back((0, 0, 0));
    while let Some((p, x, y)) = q.pop_front() {
        let d = dp[p][x][y] + 1;
        if p == 0 {
            let a = &rail[x];
            for i in 0..n {
                if a[i] && dp[p ^ 1][i][y].chmin(d) {
                    q.push_back((p ^ 1, i, y));
                }
            }
            if x == n - 1 && dp[p ^ 1][x][y].chmin(d) {
                q.push_back((p ^ 1, x, y));
            }
        } else {
            let a = &rail[y];
            for i in 0..n {
                if i != y && !a[i] && (x == n - 1 || i != x) && dp[p ^ 1][x][i].chmin(d) {
                    q.push_back((p ^ 1, x, i));
                }
            }
            if y == n - 1 && dp[p ^ 1][x][y].chmin(d) {
                q.push_back((p ^ 1, x, y));
            }
        }
    }
    if dp[0][n - 1][n - 1] < inf {
        println!("{}", dp[0][n - 1][n - 1] / 2);
    } else {
        println!("-1");
    }
}

fn main() {
    run();
}
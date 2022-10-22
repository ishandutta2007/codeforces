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

fn run() {
    input! {
        h: usize,
        w: usize,
        k: usize,
        a: [[i64; w - 1]; h],
        b: [[i64; w]; h - 1],
    }
    let mut ans = vec![vec![-1; w]; h];
    if k % 2 == 0 {
        let mut dp = vec![vec![0; w]; h];
        for _ in 0..(k / 2) {
            let mut next = vec![vec![0; w]; h];
            for x in 0..h {
                for y in 0..w {
                    let mut val = std::i64::MAX;
                    if x > 0 {
                        val.chmin(dp[x - 1][y] + 2 * b[x - 1][y]);
                    }
                    if x + 1 < h {
                        val.chmin(dp[x + 1][y] + 2 * b[x][y]);
                    }
                    if y > 0 {
                        val.chmin(dp[x][y - 1] + 2 * a[x][y - 1]);
                    }
                    if y + 1 < w {
                        val.chmin(dp[x][y + 1] + 2 * a[x][y]);
                    }
                    next[x][y] = val;
                }
            }
            dp = next;
        }
        ans = dp;
    }
    let mut s = String::new();
    for a in ans {
        for a in a {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        s.push('\n');
    }
    print!("{}", s);
}

fn main() {
    run();
}
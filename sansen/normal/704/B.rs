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
        s: usize1,
        e: usize1,
        x: [i64; n],
        a: [i64; n],
        b: [i64; n],
        c: [i64; n],
        d: [i64; n],
    }
    let inf = 10i64.pow(18);
    let mut dp = vec![inf, d[0] + b[0] - 2 * x[0]];
    let mut left = 0;
    let mut right = 0;
    if s == 0 {
        left = 1;
        dp[1] -= b[0] - x[0];
    } else if e == 0 {
        right = 1;
        dp[1] -= d[0] - x[0];
    }
    for (i, ((((&x, a), b), c), d)) in x.iter().zip(a).zip(b).zip(c).zip(d).enumerate().skip(1) {
        let mut next = vec![inf; dp.len() + 1];
        if i == s {
            for (j, &v) in dp.iter().enumerate().skip(1) {
                next[j + 1].chmin(v - x + d);
                next[j].chmin(v + x + c);
            }
            left = 1;
        } else if i == e {
            for (j, &v) in dp.iter().enumerate().skip(1) {
                next[j].chmin(v + x + a);
                next[j + 1].chmin(v - x + b);
            }
            right = 1;
        } else {
            for (j, &v) in dp.iter().enumerate().skip(1) {
                if j > left && j > right {
                    next[j - 1].chmin(v + 2 * x + a + c);
                }
                if j > right {
                    next[j].chmin(v + a + d);
                }
                if j > left {
                    next[j].chmin(v + c + b);
                }
                if j > left || j > right {
                    next[j + 1].chmin(v - 2 * x + d + b);
                }
            }
        }
        dp = next;
    }
    let ans = dp[1];
    println!("{}", ans);
}

fn main() {
    run();
}
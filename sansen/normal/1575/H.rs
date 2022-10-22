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
        a: bytes,
        b: bytes,
    }
    let mut trans = vec![[0; 2]; m + 1];
    for (i, trans) in trans.iter_mut().enumerate() {
        for (j, t) in trans.iter_mut().enumerate() {
            let mut s = Vec::from(&b[..i]);
            s.push(b'0' + (j as u8));
            while !b.starts_with(&s) {
                s.remove(0);
            }
            *t = s.len();
        }
    }
    let inf = 1000;
    let mut dp = vec![vec![inf; m + 1]; n - m + 2];
    dp[0][0] = 0;
    for a in a {
        let p = (a - b'0') as usize;
        let mut next = vec![vec![inf; m + 1]; n - m + 2];
        for (i, dp) in dp.iter().enumerate() {
            for (trans, dp) in trans.iter().zip(dp) {
                if *dp >= inf {
                    continue;
                }
                for (j, t) in trans.iter().enumerate() {
                    let cost = *dp + (j ^ p);
                    if *t == m {
                        next[i + 1][*t].chmin(cost);
                    } else {
                        next[i][*t].chmin(cost);
                    }
                }
            }
        }
        dp = next;
    }
    let mut s = String::new();
    for a in dp {
        let v = a.into_iter().min().unwrap();
        if v >= inf {
            s.push_str(&format!("-1 "));
        } else {
            s.push_str(&format!("{} ", v));
        }
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
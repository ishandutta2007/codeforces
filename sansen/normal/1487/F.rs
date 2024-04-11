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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;

// dp?
// +-carry
// 1
// MLE
// 
//
//

const INF: i32 = 100000;

fn run() {
    input!(s: bytes);
    let m = 200;
    let geta = m / 9 + 1;
    let mut dp = vec![vec![vec![INF; m + 1]; m + 1]; 2 * geta + 1];
    dp[geta] = vec![vec![0; m + 1]; m + 1];
    for &s in s.iter().rev() {
        let s = (s - b'0') as i32;
        let mut next = vec![vec![vec![INF; m + 1]; m + 1]; 2 * geta + 1];
        for (carry, dp) in dp.iter().enumerate() {
            for (add, dp) in dp.iter().enumerate() {
                for (sub, dp) in dp.iter().enumerate() {
                    if *dp == INF {
                        continue;
                    }
                    let carry = carry as i32 - geta as i32;
                    let d = add as i32 - sub as i32 + carry;
                    if d.rem_euclid(10) != s {
                        continue;
                    }
                    let carry = (d.div_euclid(10) + geta as i32) as usize;
                    next[carry][add][sub].chmin(*dp + (add + sub) as i32);
                }
            }
        }
        dp = next;
        for dp in dp.iter_mut() {
            for i in (0..m).rev() {
                for j in (0..m).rev() {
                    dp[i][j] = dp[i][j].min(dp[i + 1][j]).min(dp[i][j + 1]);
                }
            }
        }
    }
    let mut ans = INF;
    for (carry, dp) in dp.iter().enumerate() {
        for (add, dp) in dp.iter().enumerate() {
            for (sub, dp) in dp.iter().enumerate() {
                let carry = carry as i32 - geta as i32;
                let add = add as i32;
                let sub = sub as i32;
                let mut v = *dp;
                if carry == 0 {
                } else if carry > 0 && sub >= carry {
                    v += carry;
                } else if carry < 0 && add >= -carry {
                    v += -carry;
                } else {
                    v += INF;
                }
                ans.chmin(v);
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
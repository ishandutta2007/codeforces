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

//

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        s: chars,
    }
    let s: Vec<usize> = s.into_iter().map(|c| {
        match c {
            'V' => 0,
            'K' => 1,
            _ => 2,
        }
    }).collect();
    let mut cnt = [0; 3];
    for k in s.iter() {
        cnt[*k] += 1;
    }
    let inf = n * (n + 1) / 2 + 1;
    // [V][V][K][]
    let mut dp = vec![vec![vec![vec![inf; cnt[2] + 1]; cnt[1] + 1]; cnt[0] + 1]; 2];
    dp[0][0][0][0] = 0;
    for v in 0..=cnt[0] {
        for k in 0..=cnt[1] {
            for a in 0..=cnt[2] {
                let x = dp[0][v][k][a];
                let y = dp[1][v][k][a];
                let z = [v, k, a];
                let count = |p: usize| -> usize {
                    let mut val = [0; 3];
                    let mut ans = 0;
                    for &q in s.iter() {
                        val[q] += 1;
                        if q == p && val[q] > z[p] {
                            break;
                        }
                        if val[q] > z[q] {
                            ans += 1;
                        }
                    }
                    ans
                };
                if v + 1 <= cnt[0] {
                    let val = min(x, y) + count(0);
                    dp[1][v + 1][k][a].chmin(val);
                }
                if k + 1 <= cnt[1] {
                    let val = x + count(1);
                    dp[0][v][k + 1][a].chmin(val);
                }
                if a + 1 <= cnt[2] {
                    let val = min(x, y) + count(2);
                    dp[0][v][k][a + 1].chmin(val);
                }
            }
        }
    }
    let (v, k, a) = (cnt[0], cnt[1], cnt[2]);
    let ans = min(dp[0][v][k][a], dp[1][v][k][a]);
    println!("{}", ans);
}

fn main() {
    run();
}
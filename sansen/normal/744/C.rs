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

// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        if *self > x {
            *self = x;
            true
        } else {
            false
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        if *self < x {
            *self = x;
            true
        } else {
            false
        }
    }
}
// ---------- end chmin, chmax ----------

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        p: [(chars, [i32; 2]); n],
    }
    let mut p = p
        .into_iter()
        .map(|p| ((p.0[0] == 'B') as usize, [p.1[0], p.1[1]]))
        .collect::<Vec<_>>();
    let mut need = [0; 2];
    for p in p.iter_mut() {
        let n = n as i32;
        for (need, v) in need.iter_mut().zip(p.1.iter_mut()) {
            *need += max(0, *v - n + 1);
            v.chmin(n - 1);
        }
    }
    let mut sum = vec![[0i32; 2]];
    for &(x, _) in p.iter() {
        for i in 0..sum.len() {
            let mut a = sum[i];
            a[x] += 1;
            sum.push(a);
        }
    }
    let inf = std::i32::MAX / 2;
    let sup = (n - 1) * (n - 1);
    let mut dp = vec![vec![vec![inf; 1 << n]; sup + 1]; 2];
    let abs = (need[1] - need[0]).abs() as usize;
    dp[(need[0] >= need[1]) as usize][min(sup, abs)][0] = 0;
    for bit in 0..(1 << n) {
        let sum = sum[bit];
        for rem in 0..=sup {
            for i in 0..2 {
                let v = dp[i][rem][bit];
                if v == inf {
                    continue;
                }
                for (j, &(_, p)) in p.iter().enumerate() {
                    let k = bit | (1 << j);
                    if k == bit {
                        continue;
                    }
                    let p = [max(0, p[0] - sum[0]), max(0, p[1] - sum[1])];
                    if rem as i32 + p[i ^ 1] >= p[i] {
                        let x = rem as i32 + p[i ^ 1] - p[i];
                        let v = v + p[i ^ 1];
                        dp[i][min(x as usize, sup)][k].chmin(v);
                    } else {
                        let x = p[i] - rem as i32 - p[i ^ 1];
                        let v = v + p[i] - rem as i32;
                        dp[i ^ 1][min(x as usize, sup)][k].chmin(v);
                    }
                }
            }
        }
    }
    let add = need.iter().copied().max().unwrap() + n as i32;
    let ans = add + dp.into_iter().flatten().map(|dp| dp[(1 << n) - 1]).min().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
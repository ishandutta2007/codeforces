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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use std::io::Write;
use std::cmp::min;

fn run() {
    input! {
        t: usize,
        ask: [(usize, usize, chars); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (_n, k, s) in ask {
        let s = s.into_iter().map(|c| c.to_digit(10).unwrap() as usize).collect::<Vec<_>>();
        let mut dp = vec![[0usize; 3]; k];
        for s in s.chunks(k) {
            let len = s.len();
            let sum: usize = s.iter().sum();
            for (dp, c) in dp.iter_mut().zip(s.iter()) {
                dp[2] = min(dp[2], min(dp[1], dp[0])) + sum;
                dp[1] = min(dp[1], dp[0]) + if *c == 1 {sum - 1} else {sum + 1};
                dp[0] = dp[0] + sum;
            }
            if len < k {
                for dp in dp[len..].iter_mut() {
                    for v in dp.iter_mut() {
                        *v += sum;
                    }
                }
            }
        }
        let ans = dp.into_iter().map(|dp| *dp.iter().min().unwrap()).min().unwrap();
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
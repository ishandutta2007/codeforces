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

// N = 
// N-1
// 
// 
// 
// 

use std::io::Write;

fn chmin<T: Ord>(x: &mut T, a: T) {
    if *x > a {
        *x = a;
    }
}

fn run() {
    input! {
        t: usize,
        ask: [(usize, chars, chars); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, s, t) in ask {
        let s: Vec<usize> = s.into_iter().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
        let t: Vec<usize> = t.into_iter().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
        let mut sum = vec![[0; 26]; n + 1];
        for (i, &c) in s.iter().enumerate().rev() {
            sum[i] = sum[i + 1];
            sum[i][c] += 1;
        }
        let sum_s = sum;
        let mut sum = vec![[0; 26]; n + 1];
        for (i, &c) in t.iter().enumerate().rev() {
            sum[i] = sum[i + 1];
            sum[i][c] += 1;
        }
        let sum_t = sum;
        let mut dp = vec![vec![n; n + 1]; n + 1];
        dp[n][n] = 0;
        for i in (0..=n).rev() {
            for j in (0..=n).rev() {
                let v = dp[i][j];
                if v == n {
                    continue;
                }
                if i > 0 {
                    chmin(&mut dp[i - 1][j], v + 1);
                }
                if j > 0 {
                    let k = t[j - 1];
                    if sum_s[i][k] > sum_t[j][k] {
                        chmin(&mut dp[i][j - 1], v);
                    }
                    if i > 0 && s[i - 1] == k {
                        chmin(&mut dp[i - 1][j - 1], v);
                    }
                }
            }
        }
        let ans = dp[0][0];
        if ans == n {
            writeln!(out, "-1").ok();
        } else {
            writeln!(out, "{}", ans).ok();
        }
    }
}

fn main() {
    run();
}
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
        k: usize,
        s: bytes,
        t: bytes,
    }
    let mut dp = vec![vec![0; m + 1]; n + 1];
    for _ in 0..k {
        let mut next = vec![vec![(0, 0); m + 1]; n + 1];
        for (i, s) in s.iter().enumerate().rev() {
            for (j, t) in t.iter().enumerate().rev() {
                if *s == *t {
                    next[i][j].0 = next[i + 1][j + 1].0 + 1;
                }
                next[i][j].0 = dp[i][j].max(next[i][j].0);
                next[i][j].1 = next[i][j].0.max(next[i + 1][j].1).max(next[i][j + 1].1);
            }
        }
        for (dp, next) in dp.iter_mut().zip(next.iter()) {
            for (dp, next) in dp.iter_mut().zip(next.iter()) {
                *dp = next.1;
            }
        }
    }
    let ans = dp[0][0];
    println!("{}", ans);
}

fn main() {
    run();
}
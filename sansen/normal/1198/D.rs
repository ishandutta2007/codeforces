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

fn run() {
    input! {
        n: usize,
        s: [chars; n],
    }
    let mut cnt = vec![vec![0; n + 1]; n + 1];
    for i in 0..n {
        for j in 0..n {
            if s[i][j] == '#' {
                cnt[i][j] = 1;
            }
        }
    }
    for i in (0..n).rev() {
        for j in (0..n).rev() {
            cnt[i][j] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1] + cnt[i][j];
        }
    }
    let mut dp = vec![vec![vec![]; n + 1]; n + 1];
    for h in 1..(n + 1) {
        for w in 1..(n + 1) {
            dp[h][w] = vec![vec![0; n + 1 - w]; n + 1 - h];
            for i in 0..(n + 1 - h) {
                for j in 0..(n + 1 - w) {
                    let c = cnt[i][j] - cnt[i + h][j] - cnt[i][j + w] + cnt[i + h][j + w];
                    if c == 0 {
                        continue;
                    }
                    let mut ans = std::cmp::max(h, w);
                    for k in 1..h {
                        ans = std::cmp::min(ans, dp[k][w][i][j] + dp[h - k][w][i + k][j]);
                    }
                    for k in 1..w {
                        ans = std::cmp::min(ans, dp[h][k][i][j] + dp[h][w - k][i][j + k]);
                    }
                    dp[h][w][i][j] = ans;
                }
            }
        }
    }
    let ans = dp[n][n][0][0];
    println!("{}", ans);
}

fn main() {
    run();
}
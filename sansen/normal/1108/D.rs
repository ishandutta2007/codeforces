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

use std::cmp::min;

fn run() {
    input! {
        n: usize,
        s: chars,
    }
    let c: Vec<char> = "RGB".chars().collect();
    let mut dp = vec![vec![n; n + 1]; 3];
    for j in 0..3 {
        dp[j][n] = 0;
    }
    for i in (0..n).rev() {
        for j in 0..3 {
            dp[j][i] = min(dp[(j + 1) % 3][i + 1], dp[(j + 2) % 3][i + 1]);
            if s[i] != c[j] {
                dp[j][i] += 1;
            }
        }
    }
    let mut k = 0;
    for i in 1..3 {
        if dp[k][0] > dp[i][0] {
            k = i;
        }
    }
    println!("{}", dp[k][0]);
    let mut ans = String::new();
    for i in 0..n {
        ans.push(c[k]);
        if s[i] != c[k] {
            for j in 0..3 {
                if j != k && dp[j][i + 1] + 1 == dp[k][i] {
                    k = j;
                    break;
                }
            }
        } else {
            for j in 0..3 {
                if j != k && dp[j][i + 1] == dp[k][i] {
                    k = j;
                    break;
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
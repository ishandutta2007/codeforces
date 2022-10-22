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

use std::cmp::max;

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let m = 21;
    let mut dp = vec![(0, 0); 1 << m];
    for (i, &a) in a.iter().enumerate() {
        dp[a] = (i + 1, dp[a].0);
    }
    for j in 0..m {
        for i in 0..(1 << m) {
            if (i >> j) & 1 == 1 {
                let (a, b) = dp[i];
                let (c, d) = dp[i ^ (1 << j)];
                dp[i ^ (1 << j)] = if a >= c {
                    (a, max(b, c))
                } else {
                    (c, max(a, d))
                };
            }
        }
    }
    let mut ans = 0;
    for (i, &a) in a.iter().enumerate().rev().skip(2).rev() {
        let mut bit = 0;
        for j in (0..m).rev() {
            if (a >> j) & 1 == 1 {
                continue;
            }
            if dp[bit | (1 << j)].1 > i + 1 {
                bit |= 1 << j;
            }
        }
        ans = max(ans, a | bit);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
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
        s: chars,
    }
    let n = s.len();
    let f = 20;
    let mut a = vec![0; n];
    for (a, s) in a.iter_mut().zip(s.iter()) {
        let k = *s as usize - 'a' as usize;
        *a = k;
    }
    let mut dp = vec![0; 1 << f];
    for i in 0..n {
        let mut bit = 0;
        for j in i..n {
            if (bit >> a[j]) & 1 == 1 {
                break;
            }
            bit |= 1 << a[j];
            dp[bit] = j - i + 1;
        }
    }
    for i in 1..(1 << f) {
        for j in 0..26 {
            if (i >> j) & 1 == 1 {
                dp[i] = max(dp[i], dp[i ^ (1 << j)]);
            }
        }
    }
    let mut ans = 0;
    for i in 1..(1 << f) {
        ans = max(ans, dp[i] + dp[((1 << f) - 1) ^ i]);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
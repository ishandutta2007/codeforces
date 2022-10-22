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
        a: [usize1; n],
    }
    let m = 20;
    let mut cnt = vec![0; m];
    let mut back = vec![vec![0; m]; m];
    for &a in a.iter().rev() {
        for i in 0..m {
            if i == a {
                continue;
            }
            back[a][i] += cnt[i];
        }
        cnt[a] += 1;
    }
    let mut dp = vec![1_000_000_000_000_000_000u64; 1 << m];
    dp[0] = 0;
    for i in 1..(1 << m) {
        for k in 0..m {
            if (i >> k) & 1 == 0 {
                continue;
            }
            let mut s = dp[i ^ (1 << k)];
            for j in 0..m {
                if (i >> j) & 1 == 1 {
                    s += back[k][j];
                }
            }
            dp[i] = std::cmp::min(dp[i], s);
        }
    }
    println!("{}", dp[(1 << m) - 1]);
}

fn main() {
    run();
}
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


// M = max a
// m = min a
// 
// m
// g
// g <= m 
// g <= k 
// g > k 
// 

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [usize; n],
    }
    let max = *a.iter().max().unwrap();
    let min = *a.iter().min().unwrap();
    let mut dp = vec![0usize; max + 2];
    for &a in a.iter() {
        let l = a.saturating_sub(k).max(1);
        dp[l] += 1;
        dp[a + 1] -= 1;
    }
    for i in 1..=max {
        dp[i] += dp[i - 1];
    }
    let mut ans = 0;
    for g in 1..=min {
        if g <= k {
            ans = g;
        } else {
            let mut cnt = 0;
            for i in 1..=(max / g) {
                cnt += dp[i * g];
            }
            if cnt == n {
                ans = g;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
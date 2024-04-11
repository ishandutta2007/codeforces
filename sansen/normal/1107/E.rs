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
        s: chars,
        a: [u64; n],
    }
    let mut a = a;
    a.insert(0, 0);
    for i in 2..=n {
        for j in 1..i {
            a[i] = std::cmp::max(a[i], a[j] + a[i - j]);
        }
    }
    let a = a;
    let mut dp = vec![vec![vec![0u64; n + 1]; n]; n];
    for l in 0..n {
        for r in 0..n {
            for k in 0..n {
                if l > r {
                    dp[l][r][k] = 0;
                } else if l == r {
                    dp[l][r][k] = a[k + 1];
                }
            }
        }
    }
    for len in 2..=n {
        for l in 0..=(n - len) {
            let r = l + len - 1;
            let f = s[l];
            for k in 0..n {
                let mut val = a[k + 1] + dp[l + 1][r][0];
                for i in (l + 1)..=r {
                    if f == s[i] {
                        val = std::cmp::max(val, dp[l + 1][i - 1][0] + dp[i][r][k + 1]);
                    }
                }
                dp[l][r][k] = val;
            }
        }
    }
    let ans = dp[0][n - 1][0];
    println!("{}", ans);
}

fn main() {
    run();
}
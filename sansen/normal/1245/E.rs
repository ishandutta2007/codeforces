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
    let m = 10;
    input! {
        h: [[usize; m]; m],
    }
    let mut a = vec![m * m; m * m];
    for i in 1..m {
        for j in 0..m {
            let h = h[i][j];
            if h == 0 {
                continue;
            }
            let s = if i % 2 == 0 {
                i * m + j
            } else {
                i * m + m - 1 - j
            };
            let t = if (i - h) % 2 == 0 {
                (i - h) * m + j
            } else {
                (i - h) * m + m - 1 - j
            };
            a[s] = t;
        }
    }
    let mut dp = vec![0f64; m * m];
    let p = 1f64 / 6f64;
    for i in 1..(m * m) {
        let mut sum = 1f64;
        let mut q = 0f64;
        for j in 1..=6 {
            if j > i {
                q += p;
                continue;
            }
            let mut v = dp[i - j];
            if a[i - j] < m * m {
                v = v.min(dp[a[i - j]]);
            }
            sum += p * v;
        }
        dp[i] = sum / (1.0 - q);
    }
    println!("{:.7}", dp[m * m - 1]);
}

fn main() {
    run();
}
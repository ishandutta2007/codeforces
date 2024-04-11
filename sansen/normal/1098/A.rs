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
        p: [usize1; n - 1],
        s: [i64; n],
    }
    let cond = |b: bool| {
        if !b {
            println!("-1");
            std::process::exit(0);
        }
    };
    let mut child = vec![vec![]; n];
    for (i, p) in p.iter().enumerate() {
        child[*p].push(i + 1);
    }
    let inf = std::i64::MAX / 10;
    let mut dp = vec![inf; n];
    for i in (0..n).rev() {
        if s[i] >= 0 {
            dp[i] = s[i];
        }
        for &u in child[i].iter() {
            dp[i] = std::cmp::min(dp[i], dp[u]);
        }
    }
    let mut a = vec![0; n];
    let mut sum = vec![0; n];
    for i in 0..n {
        if s[i] >= 0 {
            a[i] = s[i] - sum[i];
        } else if dp[i] != inf {
            a[i] = dp[i] - sum[i];
        }
        sum[i] += a[i];
        cond(dp[i] == inf || sum[i] <= dp[i]);
        for &u in child[i].iter() {
            sum[u] = sum[i];
        }
    }
    let ans = a.iter().sum::<i64>();
    println!("{}", ans);
}

fn main() {
    run();
}
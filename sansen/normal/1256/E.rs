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
        a: [u32; n],
    }
    let mut b = vec![];
    for (i, a) in a.iter().enumerate() {
        b.push((*a, i));
    }
    b.sort();
    let a = b;
    let inf = 1_000_000_000 + 1;
    let mut dp = vec![inf; n + 5];
    dp[n] = 0;
    for i in (0..(n - 2)).rev() {
        for j in (i + 2)..min(n, i + 5) {
            let v = dp[j + 1] + a[j].0 - a[i].0;
            dp[i] = min(dp[i], v);
        }
    }
    let mut ans = vec![0; n];
    let mut cnt = 0;
    let mut i = 0;
    while i < n {
        for j in (i + 2).. {
            let v = dp[j + 1] + a[j].0 - a[i].0;
            if v == dp[i] {
                cnt += 1;
                for k in i..=j {
                    ans[a[k].1] = cnt;
                }
                i = j + 1;
                break;
            }
        }
    }
    let mut out = String::new();
    out.push_str(&format!("{} {}\n", dp[0], cnt));
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
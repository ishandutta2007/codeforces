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
        m: usize,
        p: [(usize, usize); n],
    }
//    let mut p = p;
//    p.sort();
    let inf = std::usize::MAX / 3;
    let mut dp = vec![inf; m + 1];
    dp[0] = 0;
    for &(x, s) in p.iter().cycle().take(n * n) {
        let mut next = dp.clone();
        for i in 1..=x {
            if x - i <= s {
                let y = min(x + s, m);
                next[y] = min(next[y], dp[i - 1]);
            } else {
                let cost = (x - i) - s;
                let y = min(m, x + s + cost);
                next[y] = min(next[y], dp[i - 1] + cost);
            }
        }
        for i in x..=m {
            if i - x <= s {
                let y = if x > s {x - s} else {1};
                let z = min(x + s, m);
                next[z] = min(next[z], dp[y - 1]);
            } else {
                let cost = i - x - s;
                let y = if 2 * x > i {2 * x - i} else {1};
                next[i] = min(next[i], dp[y - 1] + cost);
            }
        }
        for i in (1..=m).rev() {
            next[i - 1] = std::cmp::min(next[i - 1], next[i]);
        }
        dp = next;
    }
    println!("{}", dp[m]);
}

fn main() {
    run();
}
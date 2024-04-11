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

use std::cmp::{max, min};

fn run() {
    input! {
        n: usize,
        m: usize,
        x: [i64; m],
    }
    let mut imos = vec![0; n + 2];
    for i in 1..m {
        let a = min(x[i], x[i - 1]);
        let b = max(x[i], x[i - 1]);
        if a == b {
            continue;
        }
        let x = a as usize;
        let y = b as usize;
        imos[1] += b - a;
        imos[x] -= b - a;
        imos[x] += b - 1;
        imos[x + 1] -= b - 1;
        imos[x + 1] += b - a - 1;
        imos[y] -= b - a - 1;
        imos[y] += a;
        imos[y + 1] -= a;
        imos[y + 1] += b - a;
    }
    for i in 2..=n {
        imos[i] += imos[i - 1];
    }
    let mut ans = String::new();
    for i in 1..=n {
        ans.push_str(&format!("{} ", imos[i]));
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}
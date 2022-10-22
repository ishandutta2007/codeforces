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

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        a: [u64; n],
    }
    let mut h = std::collections::BinaryHeap::new();
    for (i, &a) in a.iter().enumerate() {
        h.push(Reverse((a, i)));
    }
    let mut ans = vec![];
    while let Some(Reverse((a, x))) = h.pop() {
        if let Some(Reverse((b, y))) = h.pop() {
            if a == b {
                h.push(Reverse((2 * a, y)));
            } else {
                ans.push((a, x));
                h.push(Reverse((b, y)));
            }
        } else {
            ans.push((a, x));
        }
    }
    ans.sort_by_key(|p| p.1);
    let mut s = String::new();
    s.push_str(&format!("{}\n", ans.len()));
    for a in ans {
        s.push_str(&format!("{} ", a.0));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
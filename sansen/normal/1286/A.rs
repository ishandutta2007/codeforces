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
use std::collections::BTreeMap;

fn run() {
    input! {
        n: usize,
        p: [usize; n],
    }
    let mut cnt = [0; 2];
    for p in p.iter() {
        if *p == 0 {
            continue;
        }
        cnt[*p % 2] += 1;
    }
    let even = n / 2 - cnt[0];
    let odd = (n + 1) / 2 - cnt[1];
    let inf = n;
    let mut dp = BTreeMap::<(usize, usize, usize), usize>::new();
    dp.insert((0, even, odd), 0);
    dp.insert((1, even, odd), 0);
    for p in p.iter().rev() {
        let mut next = BTreeMap::<(usize, usize, usize), usize>::new();
        for ((b, x, y), v) in dp {
            if *p == 0 {
                if x > 0 {
                    let po = next.entry((0, x - 1, y)).or_insert(inf);
                    *po = min(*po, v + (b ^ 0));
                }
                if y > 0 {
                    let po = next.entry((1, x, y - 1)).or_insert(inf);
                    *po = min(*po, v + (b ^ 1));
                }
            } else {
                let po = next.entry((*p % 2, x, y)).or_insert(inf);
                *po = min(*po, v + (b ^ (*p & 1)));
            }
        }
        dp = next;
    }
    let mut ans = inf;
    for (_, v) in dp {
        ans = min(ans, v);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
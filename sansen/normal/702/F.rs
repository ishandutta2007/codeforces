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

use std::collections::*;

type Set<T> = BTreeSet<T>;

// https://codeforces.com/blog/entry/46324?#comment-810437
// 

fn run() {
    input! {
        n: usize,
        p: [(i32, i32); n],
        q: usize,
        b: [i32; q],
    }
    let w = 31;
    let pos = |b: i32| -> usize {
        assert!(b > 0);
        (b as u32).next_power_of_two().trailing_zeros() as usize
    };
    let mut set = vec![Set::new(); w];
    for (k, b) in b.into_iter().enumerate() {
        let b = b + 1;
        let x = pos(b);
        set[x].insert((b, k, 0));
    }
    // cnt, cost
    let mut dp = vec![(0u32, 0); w];
    let mut p = p;
    p.sort_by_key(|p| (-p.1, p.0));
    for (c, _) in p {
        let x = pos(c + 1);
        let d = set[x].range((c - dp[x].1 + 1, 0, 0)..).cloned().collect::<Vec<_>>();
        for (b, k, s) in d {
            set[x].remove(&(b, k, s));
            let b = b + dp[x].1 - c;
            let s = s + dp[x].0 + 1;
            let x = pos(b);
            set[x].insert((b - dp[x].1, k, s - dp[x].0));
        }
        for i in (x + 1)..w {
            while let Some(&p) = set[i].iter().next() {
                if pos(p.0 + dp[i].1 - c) == i {
                    break;
                }
                set[i].remove(&p);
                let (b, k, s) = p;
                let b = b + dp[i].1 - c;
                let s = s + dp[i].0 + 1;
                let x = pos(b);
                set[x].insert((b - dp[x].1, k, s - dp[x].0));
            }
            dp[i].0 += 1;
            dp[i].1 -= c;
        }
    }
    let mut ans = vec![0; q];
    for (&(q, c), set) in dp.iter().zip(set) {
        for (b, k, s) in set {
            assert!(b + c > 0);
            ans[k] = s + q;
        }
    }
    let s = ans.iter().map(|a| a.to_string()).collect::<Vec<_>>().join(" ");
    println!("{}", s);
}

fn main() {
    run();
}
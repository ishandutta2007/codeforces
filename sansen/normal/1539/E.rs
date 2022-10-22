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

use std::io::Write;
use std::collections::*;

type Set<T> = BTreeSet<T>;

// x, y k
// remove

fn run() {
    input! {
        n: usize,
        m: i32,
        ask: [(i32, i32, i32, i32, i32); n],
    }
    let mut memo = vec![[None; 2]; n + 1];
    let mut left = Set::new();
    let mut right = Set::new();
    // 
    left.insert((0, 0));
    right.insert((0, 0));
    let mut ask = ask;
    ask.insert(0, (0, 0, m, 0, m));
    for (i, &(k, a, b, c, d)) in ask.iter().enumerate().skip(1) {
        let mut left_del = vec![];
        left_del.extend(left.range(..(a, 0)).cloned());
        left_del.extend(left.range((b + 1, 0)..).cloned());
        for p in left_del {
            left.remove(&p);
        }
        let mut right_del = vec![];
        right_del.extend(right.range(..(c, 0)).cloned());
        right_del.extend(right.range((d + 1, 0)..).cloned());
        for p in right_del {
            right.remove(&p);
        }
        if a <= k && k <= b && right.len() > 0 {
            let v = *right.iter().next().unwrap();
            memo[i][0] = Some(v.1);
        } else {
            right.clear();
        }
        if c <= k && k <= d && left.len() > 0 {
            let v = *left.iter().next().unwrap();
            memo[i][1] = Some(v.1);
        } else {
            left.clear();
        }
        if memo[i][0].is_some() {
            left.insert((k, i));
        }
        if memo[i][1].is_some() {
            right.insert((k, i));
        }
    }
    let dp = memo;
    if dp[n][0].is_none() && dp[n][1].is_none() {
        println!("No");
        return;
    }
    let mut pos = if let Some(k) = dp[n][0] {
        (0, k, n)
    } else {
        let k = dp[n][1].unwrap();
        (1, k, n)
    };
    let mut ans = vec![];
    while pos.2 > 0 {
        ans.push(pos.0);
        pos.2 -= 1;
        if pos.2 > 0 && pos.2 == pos.1 {
            pos.0 ^= 1;
            pos.1 = dp[pos.2][pos.0].unwrap();
        }
    }
    println!("Yes");
    ans.reverse();
//    println!("{:?}", &ans);
    let mut x = 0;
    let mut y = 0;
    for (i, v) in ans.iter().enumerate() {
        let (k, a, b, c, d) = ask[i + 1];
        if *v == 0 {
            x = k;
        } else {
            y = k;
        }
        assert!(a <= x && x <= b);
        assert!(c <= y && y <= d);
    }
    let a = ans.iter().map(|a| a.to_string()).collect::<Vec<_>>().join(" ");
    println!("{}", a);
}

fn main() {
    run();
}
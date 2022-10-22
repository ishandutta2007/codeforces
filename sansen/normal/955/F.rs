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

fn chmax<T: PartialOrd>(x: &mut T, a: T) -> bool {
    if *x < a {
        *x = a;
        true
    } else {
        false
    }
}

// F(k, u, m) = udepth m k-ary heap bool
// F(k, u, m) = true F(k - 1, u, m) true
// depth mk
// k-ary heap k>1 log N

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut q = vec![];
    let mut stack = vec![(0, 0)];
    while let Some((v, p)) = stack.pop() {
        q.push(v);
        if let Some(k) = g[v].iter().position(|u| *u == p) {
            g[v].remove(k);
        }
        for &u in g[v].iter() {
            stack.push((u, v));
        }
    }
    let mut ans = 0u64;
    // k = 1
    let mut dp = vec![1; n];
    for &v in q.iter().rev() {
        let mut val = 1;
        for &u in g[v].iter() {
            chmax(&mut val, dp[u] + 1);
        }
        ans += val;
        dp[v] = val;
    }
    // k >= 2
    //memo[v] (d, k): vdk-ary heapk
    let mut memo: Vec<Option<Vec<(usize, usize)>>> = vec![None; n];
    //dp[v] (d, k): vdk-ary heapk
    let mut dp: Vec<Option<Vec<(usize, usize)>>> = vec![None; n];
    for &v in q.iter().rev() {
        let g = &g[v];
        let mut x = vec![vec![]; 2];
        let mut b = vec![];
        for &u in g.iter() {
            let a = memo[u].take().unwrap();
            x[1].push(a[0].1);
            for a in a.windows(2) {
                let (p, q) = a[0];
                let (r, s) = a[1];
                assert!(p + 1 == r && q >= s);
                if x.len() <= r {
                    x.push(vec![]);
                }
                x[r].push(s);
            }
            b.append(&mut dp[u].take().unwrap());
        }
        let x: Vec<usize> = x.into_iter().map(|mut x| {
            x.sort();
            let mut i = 0;
            for k in 1.. {
                while i < x.len() && x[i] < k {
                    i += 1;
                }
                if x.len() - i < k {
                    return k - 1;
                }
            }
            unreachable!();
        }).collect();
        let mut a = vec![(1, n)];
        for (i, x) in x.into_iter().enumerate().skip(1).filter(|x| x.1 > 1) {
            a.push((i + 1, x));
        }
        b.extend_from_slice(&a);
        b.sort();
        b.dedup_by(|a, b| {
            if a.0 == b.0 {
                b.1 = a.1;
                true
            } else {
                false
            }
        });
        let mut add = 0;
        let mut prev = 1;
        for &(d, k) in b.iter().rev() {
            if k > prev {
                add += d as u64 * (k - prev) as u64;
                prev = k;
            }
        }
        ans += add;
        memo[v] = Some(a);
        dp[v] = Some(b);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
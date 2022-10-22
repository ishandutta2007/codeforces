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

//

use std::io::Write;
use std::cmp::*;

fn run() {
    input! {
        n: usize,
        m: usize,
        l: u64,
        s: usize,
        t: usize,
        e: [(usize, usize, u64); m],
    }
    let mut g = vec![vec![]; n];
    for (k, &(a, b, w)) in e.iter().enumerate() {
        g[a].push((b, w, k));
        g[b].push((a, w, k));
    }
    let mut dp = vec![vec![(std::u64::MAX, m); n]; n];
    dp[0][s] = (0, m);
    let mut h = std::collections::BinaryHeap::new();
    h.push(Reverse((0, 0, s)));
    while let Some(Reverse((d, k, v))) = h.pop() {
        for &(u, w, i) in g[v].iter() {
            let (d, k) = if w == 0 {
                (d + 1, k + 1)
            } else {
                (d + w, k)
            };
            if k < n && d < dp[k][u].0 {
                dp[k][u] = (d, i);
                h.push(Reverse((d, k, u)));
            }
        }
    }
    if dp[0][t].0 < l {
        println!("NO");
        return;
    }
    let mut assign = vec![l + 1; m];
    let mut ok = dp[0][t].0 == l;
    for i in 1..n {
        if dp[i][t].0 > l || ok {
            continue;
        }
        ok = true;
        let mut val = l - dp[i][t].0 + 1;
        let mut pos = (i, t);
        while pos.1 != s {
            let (_, p) = dp[pos.0][pos.1];
            if e[p].2 == 0 {
                pos.0 -= 1;
                assign[p] = val;
                val = 1;
            }
            pos.1 = e[p].0 ^ e[p].1 ^ pos.1;
        }
    }
    if !ok {
        println!("NO");
        return;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "YES").ok();
    for (w, &(a, b, c)) in assign.iter().zip(e.iter()) {
        if c == 0 {
            writeln!(out, "{} {} {}", a, b, w).ok();
        } else {
            writeln!(out, "{} {} {}", a, b, c).ok();
        }
    }
}

fn main() {
    run();
}
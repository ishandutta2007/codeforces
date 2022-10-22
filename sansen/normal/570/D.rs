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

use std::collections::VecDeque;
use std::io::Write;

fn run() {
    input! {
        n: usize,
        m: usize,
        p: [usize1; n - 1],
        s: chars,
        ask: [(usize1, usize1); m],
    }
    let s: Vec<usize> = s.into_iter().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
    let mut child = vec![vec![]; n];
    let mut depth = vec![0; n];
    for (i, &p) in p.iter().enumerate() {
        child[p].push(i + 1);
        depth[i + 1] = depth[p] + 1;
    }
    let mut query = vec![vec![]; n];
    for (i, (v, h)) in ask.into_iter().enumerate() {
        query[v].push((h, i));
    }
    let mut ans = vec![true; m];
    let mut dp: Vec<Option<VecDeque<usize>>> = vec![None; n];
    for (v, c) in child.iter_mut().enumerate().rev() {
        c.sort_by_cached_key(|u| dp[*u].as_ref().unwrap().len());
        let mut deq = if let Some(u) = c.pop() {
            dp[u].take().unwrap()
        } else {
            VecDeque::new()
        };
        for &u in c.iter() {
            let p = dp[u].take().unwrap();
            for (x, y) in deq.iter_mut().zip(p.iter()) {
                *x ^= *y;
            }
        }
        deq.push_front(1 << s[v]);
        for &(h, k) in query[v].iter() {
            ans[k] = deq
                .get(h - depth[v])
                .map_or(true, |u| u.count_ones() <= 1);
        }
        dp[v] = Some(deq);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        if a {
            writeln!(out, "Yes").ok();
        } else {
            writeln!(out, "No").ok();
        }
    }
}

fn main() {
    run();
}
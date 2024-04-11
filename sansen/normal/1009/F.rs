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
use std::collections::*;

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
    let mut topo = vec![(0, 0)];
    for i in 0..n {
        let (v, p) = topo[i];
        let g = &mut g[v];
        if let Some(k) = g.iter().position(|u| *u == p) {
            g.remove(k);
        }
        for &u in g.iter() {
            topo.push((u, v));
        }
    }
    type Deque = VecDeque<usize>;
    type DP = ((usize, usize), Deque);
    let mut ans = vec![0; n];
    let mut dp: Vec<DP> = vec![DP::default(); n];
    for &(v, _) in topo.iter().rev() {
        if g[v].is_empty() {
            ans[v] = 0;
            let mut d = VecDeque::new();
            d.push_back(1);
            dp[v] = ((1, !0), d);
            continue;
        }
        let mut child = vec![];
        for &u in g[v].iter() {
            let mut p = DP::default();
            std::mem::swap(&mut p, &mut dp[u]);
            child.push(p);
        }
        let mut max = 0;
        for (i, c) in child.iter().enumerate() {
            if child[max].1.len() < c.1.len() {
                max = i;
            }
        }
        let (mut val, mut deq) = child.swap_remove(max);
        val.1 = !(!val.1 + 1);
        for (_, d) in child.into_iter() {
            for (i, (deq, d)) in deq.iter_mut().zip(d.iter()).enumerate() {
                let i = i + 1;
                *deq += d;
                val = std::cmp::max(val, (*deq, !i));
            }
        }
        deq.push_front(1);
        val = std::cmp::max(val, (1, !0));
        ans[v] = !val.1;
        dp[v] = (val, deq);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
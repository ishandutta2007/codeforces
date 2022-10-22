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

fn run() {
    input! {
        n: usize,
        k: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut q = vec![];
    let mut stack = vec![(0, 0)];
    let mut depth = vec![1i64; n];
    while let Some((v, p)) = stack.pop() {
        q.push(v);
        let g = &mut g[v];
        if let Some(k) = g.iter().position(|u| *u == p) {
            g.remove(k);
        }
        let d = depth[v] + 1;
        for &u in g.iter() {
            depth[u] = d;
            stack.push((u, v));
        }
    }
    let mut size = vec![1i64; n];
    for &v in q.iter().rev() {
        for &u in g[v].iter() {
            size[v] += size[u];
        }
    }
    let mut a = vec![];
    for (s, d) in size.iter().zip(depth.iter()) {
        a.push(*d - *s);
    }
    a.sort();
    let mut ans = 0;
    for a in a.iter().rev().take(k) {
        ans += *a;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
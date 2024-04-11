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
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut stack = vec![(0, 0)];
    let mut depth = vec![0; n];
    while let Some((v, p)) = stack.pop() {
        for &u in g[v].iter() {
            if u != p {
                depth[u] = depth[v] + 1;
                stack.push((u, v));
            }
        }
    }
    let mut deg = vec![0usize; n];
    for i in 0..n {
        if g[i].len() > 1 {
            continue;
        }
        let p = g[i][0];
        deg[p] += 1;
    }
    let mut free = n - 1;
    for d in deg {
        if d > 1 {
            free -= d - 1;
        }
    }
    let mut elem = vec![false; 2];
    for i in 0..n {
        if g[i].len() == 1 {
            elem[depth[i] & 1] = true;
        }
    }
    let min = if elem[1] && elem[0] {3} else {1};
    println!("{} {}", min, free);
}

fn main() {
    run();
}
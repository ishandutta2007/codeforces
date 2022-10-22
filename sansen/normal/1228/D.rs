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

use std::cmp::{max, min};

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
    }
    let mut e = e;
    for e in &mut e {
        *e = (min(e.0, e.1), max(e.0, e.1));
    }
    e.sort();
    let mut g = vec![vec![]; n];
    for &(a, b) in &e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut id = vec![1; n];
    for &u in &g[0] {
        id[u] = 0;
    }
    let cnt = id.iter().filter(|p| **p == 1).count();
    for v in 0..n {
        if id[v] == 0 {
            continue;
        }
        if g[v].len() != n - cnt {
            println!("-1");
            return;
        }
        for &u in &g[v] {
            if id[u] == 1 {
                println!("-1");
                return;
            }
        }
    }
    let mut r = 0;
    while r < n && id[r] == 1 {
        r += 1;
    }
    if r >= n {
        println!("-1");
        return;
    }
    id[r] = 2;
    let mut stack = vec![];
    stack.push(r);
    while let Some(v) = stack.pop() {
        let x = id[v];
        let y = 2 + 3 - x;
        for &u in &g[v] {
            if id[u] == x {
                println!("-1");
                return;
            }
            if id[u] == 0 {
                id[u] = y;
                stack.push(u);
            }
        }
    }
    if !id.contains(&3) {
        println!("-1");
        return;
    }
    let mut a = vec![vec![]; 4];
    for v in 0..n {
        a[id[v]].push(v);
    }
    for &x in &a[1] {
        for &y in &a[2] {
            let z = (min(x, y), max(x, y));
            if let Err(_) = e.binary_search(&z) {
                println!("-1");
                return;
            }
        }
    }
    for &x in &a[2] {
        for &y in &a[3] {
            let z = (min(x, y), max(x, y));
            if let Err(_) = e.binary_search(&z) {
                println!("-1");
                return;
            }
        }
    }
    for &x in &a[3] {
        for &y in &a[1] {
            let z = (min(x, y), max(x, y));
            if let Err(_) = e.binary_search(&z) {
                println!("-1");
                return;
            }
        }
    }
    let mut ans = String::new();
    for i in 0..n {
        ans.push_str(&format!("{} ", id[i]));
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}
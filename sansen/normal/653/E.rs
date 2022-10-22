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

use std::cmp::*;
use std::collections::*;

fn impossible() {
    println!("impossible");
    std::process::exit(0);
}

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        e: [(usize1, usize1); m],
    }
    let normal = |a: usize, b: usize| -> (usize, usize) {
        (min(a, b), max(a, b))
    };
    let mut set = BTreeSet::new();
    for (a, b) in e {
        set.insert(normal(a, b));
    }
    let mut unvisited = (1..n).collect::<BTreeSet<usize>>();
    let mut a = vec![];
    while let Some(&v) = unvisited.iter().next() {
        unvisited.remove(&v);
        let mut q = vec![v];
        for i in 0.. {
            if i >= q.len() {
                break;
            }
            let v = q[i];
            let mut save = vec![];
            for &u in unvisited.iter() {
                if !set.contains(&normal(v, u)) {
                    save.push(u);
                }
            }
            for u in save.iter() {
                unvisited.remove(u);
            }
            q.append(&mut save);
        }
        a.push(q);
    }
    if a.len() > k {
        impossible();
    }
    let mut deg = 0;
    for q in a {
        let mut ok = false;
        for v in q {
            if !set.contains(&normal(0, v)) {
                ok = true;
                deg += 1;
            }
        }
        if !ok {
            impossible();
        }
    }
    if deg < k {
        impossible();
    }
    println!("possible");
}

fn main() {
    run();
}
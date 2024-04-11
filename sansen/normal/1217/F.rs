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

use std::ops::Bound::*;

fn run() {
    input! {
        n: usize,
        m: usize,
        ask: [(usize, usize1, usize1); m],
    }
    let mut out = String::new();
    let batch = 2000;
    let mut edge = std::collections::BTreeSet::new();
    let mut last = 0;
    let mut reachable = Vec::with_capacity(n);
    for ask in ask.chunks(batch) {
        let mut graph = edge.clone();
        let mut elem = vec![false; n];
        for &(_, x, y) in ask.iter() {
            for &(x, y) in [(x, y), ((x + 1) % n, (y + 1) % n)].iter() {
                elem[x] = true;
                elem[y] = true;
                graph.remove(&(x, y));
                graph.remove(&(y, x));
            }
        }
        let mut compress = vec![n; n];
        let mut id = 0;
        for v in 0..n {
            if compress[v] < id || !elem[v] {
                continue;
            }
            compress[v] = id;
            let mut stack = vec![v];
            while let Some(v) = stack.pop() {
                for &(_, u) in graph.range((Included(&(v, 0)), Excluded(&(v + 1, 0)))) {
                    if compress[u] == n {
                        compress[u] = id;
                        stack.push(u);
                    }
                }
            }
            id += 1;
        }
        graph.clear();
        for &(x, y) in edge.iter() {
            if compress[x] != compress[y] {
                graph.insert((compress[x], compress[y]));
            }
        }
        for &(op, x, y) in ask.iter() {
            let (x, y) = ((x + last) % n, (y + last) % n);
            let (p, q) = (compress[x], compress[y]);
            if op == 1 {
                if edge.contains(&(x, y)) {
                    edge.remove(&(x, y));
                    edge.remove(&(y, x));
                    graph.remove(&(p, q));
                    graph.remove(&(q, p));
                } else {
                    edge.insert((x, y));
                    edge.insert((y, x));
                    graph.insert((p, q));
                    graph.insert((q, p));
                }
            } else {
                reachable.clear();
                reachable.resize(id, false);
                reachable[p] = true;
                let mut stack = vec![p];
                while let Some(v) = stack.pop() {
                    for &(_, u) in graph.range((Included(&(v, 0)), Excluded(&(v + 1, 0)))) {
                        if !reachable[u] {
                            reachable[u] = true;
                            stack.push(u);
                        }
                    }
                }
                if reachable[q] {
                    last = 1;
                    out.push('1');
                } else {
                    last = 0;
                    out.push('0');
                }
            }
        }
    }
    println!("{}", out);
}

fn main() {
    run();
}
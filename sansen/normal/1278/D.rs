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
        p: [(usize, usize); n],
    }
    let mut event = vec![(false, 0, 0); 2 * n + 1];
    for (i, (l, r)) in p.into_iter().enumerate() {
        event[l] = (true, l, i);
        event[r] = (false, l, i);
    }
    let mut set = std::collections::BTreeSet::new();
    let mut edge = vec![];
    for i in 1..=(2 * n) {
        let (op, l, k) = event[i];
        if op {
            set.insert((l, k));
        } else {
            set.remove(&(l, k));
            for &(p, u) in set.iter().rev() {
                if p < l {
                    break;
                } else {
                    edge.push((k, u));
                }
            }
            if edge.len() >= n {
                println!("NO");
                return;
            }
        }
    }
    if edge.len() != n - 1 {
        println!("NO");
        return;
    }
    let mut g = vec![vec![]; n];
    for (a, b) in edge {
        g[a].push(b);
        g[b].push(a);
    }
    let mut stack = vec![0];
    let mut visited = vec![false; n];
    visited[0] = true;
    while let Some(v) = stack.pop() {
        for &u in g[v].iter() {
            if !visited[u] {
                visited[u] = true;
                stack.push(u);
            }
        }
    }
    if visited.into_iter().all(|p| p) {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    run();
}
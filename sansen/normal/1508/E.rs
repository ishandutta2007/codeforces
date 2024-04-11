// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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
// ---------- end input macro ----------

// dfs 
// 
// 
// ...
// 
//
// dfsswap
// 
// -> dfs
// A
// 

use std::collections::*;

type Deque<T> = VecDeque<T>;

fn cond(b: bool) {
    if !b {
        println!("NO");
        std::process::exit(0);
    }
}

// 0: pop_front 
// 1: pop_back
// 2: pop_back->pop_front 
fn dfs(v: usize, a: &[usize], ord: &[usize], res: &mut [usize], g: &[Vec<usize>], deq: &mut Deque<usize>) -> (usize, u64) {
    deq.push_back(ord[v]);
    let mut state = 0;
    let mut cnt = 0;
    for &u in g[v].iter() {
        if state == 0 {
            let (a, b) = dfs(u, a, ord, res, g, deq);
            cnt += b;
            state = a;
        } else {
            let mut q = vec![u];
            while let Some(v) = q.pop() {
                res[v] = ord[v];
                q.extend(g[v].iter().cloned());
            }
        }
    }
    if state == 0 {
        if *deq.front().unwrap() == a[v] {
            cnt += deq.len() as u64 - 1;
            res[v] = deq.pop_front().unwrap();
            (0, cnt)
        } else {
            cond(deq.pop_back().unwrap() == a[v]);
            res[v] = a[v];
            (1, cnt)
        }
    } else if state == 1 {
        if *deq.back().unwrap() == a[v] {
            res[v] = deq.pop_back().unwrap();
            (1, cnt)
        } else {
            cnt += deq.len() as u64 - 1;
            cond(deq.pop_front().unwrap() == a[v]);
            res[v] = a[v];
            (2, cnt)
        }
    } else {
        cond(deq.pop_back().unwrap() == a[v]);
        res[v] = a[v];
        (2, cnt)
    }
}

fn run() {
    input! {
        n: usize,
        a: [usize; n],
        e: [(usize, usize); n - 1],
    }
    let mut a = a;
    a.insert(0, 0);
    let a = a;
    let mut g = vec![vec![]; n + 1];
    for &(a, b) in e.iter() {
        g[a].push(b);
    }
    let mut topo = vec![1];
    for i in 0..n {
        let v = topo[i];
        topo.extend_from_slice(&g[v]);
    }
    let mut min = a.clone();
    for &v in topo.iter().rev() {
        g[v].sort_by_key(|u| min[*u]);
        for &u in g[v].iter() {
            min[v] = min[v].min(min[u]);
        }
    }
    let mut ord = vec![0; n + 1];
    let mut q = vec![1];
    let mut id = 1;
    while let Some(v) = q.pop() {
        ord[v] = id;
        id += 1;
        q.extend(g[v].iter().rev().cloned());
    }
    let ord = ord;
    let cnt = if ord[1] == a[1] {
        cond(ord == a);
        0
    } else {
        let mut res = vec![0; n + 1];
        let (_, y) = dfs(1, &a, &ord, &mut res, &g, &mut Deque::new());
        cond(res == a);
        y
    };
    let mut s = String::new();
    s.push_str("YES\n");
    s.push_str(&format!("{}\n", cnt));
    for ord in ord[1..].iter() {
        s.push_str(&format!("{} ", *ord));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
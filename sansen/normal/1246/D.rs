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
        p: [usize; n - 1],
    }
    let mut child = vec![vec![]; n];
    for (i, &p) in p.iter().enumerate() {
        child[p].push(i + 1);
    }
    let mut height = vec![0; n];
    for v in (0..n).rev() {
        if child[v].len() == 0 {
            continue;
        }
        child[v].sort_by_cached_key(|u| height[*u]);
        child[v].reverse();
        height[v] = height[child[v][0]] + 1;
    }
    let mut q = vec![];
    let mut stack = vec![0];
    while let Some(v) = stack.pop() {
        q.push(v);
        for &u in &child[v] {
            stack.push(u);
        }
    }
    let mut depth = vec![0; n];
    for v in 0..n {
        for &u in &child[v] {
            depth[u] = depth[v] + 1;
        }
    }
    let mut op = vec![];
    let mut now = 0;
    for &v in &q {
        while now > depth[v] {
            op.push(v);
            now -= 1;
        }
        assert!(now == depth[v]);
        now += 1;
    }
    let mut out = String::new();
    for &v in &q {
        out.push_str(&format!("{} ", v));
    }
    out.pop();
    out.push_str(&format!("\n{}\n", op.len()));
    for &v in &op {
        out.push_str(&format!("{} ", v));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        s: [i64; n],
        m: usize,
        e: [(usize1, usize1); m],
    }
    if s.iter().fold(0, |s, a| s + *a) != 0 {
        println!("Impossible");
        return;
    }
    let mut g = vec![vec![]; n];
    for (i, (a, b)) in e.into_iter().enumerate() {
        g[a].push((b, i, 1));
        g[b].push((a, i, -1));
    }
    let mut q = vec![];
    let mut parent = vec![(n, 0, 0); n];
    parent[0].0 = 0;
    let mut stack = vec![0];
    while let Some(v) = stack.pop() {
        q.push(v);
        for &(u, k, s) in g[v].iter() {
            if parent[u].0 == n {
                parent[u] = (v, k, s);
                stack.push(u);
            }
        }
    }
    assert!(q.len() == n);
    let mut sum = vec![0; n];
    let mut ans = vec![0; m];
    for &v in q.iter().rev() {
        if v == 0 {
            assert!(sum[v] == s[v]);
        } else {
            let d = s[v] - sum[v];
            let (p, k, s) = parent[v];
            sum[p] -= d;
            sum[v] += d;
            ans[k] = s * d;
        }
    }
    writeln!(out, "Possible").ok();
    for s in ans {
        writeln!(out, "{}", s).ok();
    }
}

fn main() {
    run();
}
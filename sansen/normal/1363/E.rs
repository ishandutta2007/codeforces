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
        p: [(u64, usize, usize); n],
        e: [(usize1, usize1); n - 1],
    }
    if p.iter().fold(0, |s, p| s + p.1) != p.iter().fold(0, |s, p| s + p.2) {
        println!("-1");
        return;
    }
    let mut p = p;
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut q = vec![];
    let mut stack = vec![(0, 0)];
    while let Some((v, pa)) = stack.pop() {
        q.push(v);
        let g = &mut g[v];
        if let Some(k) = g.iter().position(|u| *u == pa) {
            g.remove(k);
        }
        let a = p[v].0;
        for &u in g.iter() {
            stack.push((u, v));
            p[u].0 = std::cmp::min(a, p[u].0);
        }
    }
    let mut ans = 0u64;
    let mut cnt = vec![[0; 2]; n];
    for &v in q.iter().rev() {
        let (a, b, c) = p[v];
        if b != c {
            cnt[v][c] += 1;
        }
        for &u in g[v].iter() {
            cnt[v][0] += cnt[u][0];
            cnt[v][1] += cnt[u][1];
        }
        let k = std::cmp::min(cnt[v][0], cnt[v][1]);
        ans += 2 * k * a;
        cnt[v][0] -= k;
        cnt[v][1] -= k;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
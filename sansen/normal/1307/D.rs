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

fn bfs(src: usize, g: &[Vec<usize>]) -> Vec<i32> {
    let n = g.len();
    let mut dp = vec![20000000; n];
    dp[src] = 0;
    let mut q = std::collections::VecDeque::new();
    q.push_back(src);
    while let Some(v) = q.pop_front() {
        for &u in g[v].iter() {
            if dp[u] > dp[v] + 1 {
                dp[u] = dp[v] + 1;
                q.push_back(u);
            }
        }
    }
    dp
}

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        a: [usize1; k],
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let dp1 = bfs(0, &g);
    let dp2 = bfs(n - 1, &g);
    let mut p = vec![];
    for &a in a.iter() {
        p.push((dp1[a] - dp2[a], dp1[a], dp2[a]));
    }
    p.sort();
    let mut ans = 0;
    let mut max = -1000000;
    for (_, b, c) in p {
        ans = std::cmp::max(ans, max + c + 1);
        max = std::cmp::max(max, b);
    }
    ans = std::cmp::min(ans, dp1[n - 1]);
    println!("{}", ans);
}

fn main() {
    run();
}
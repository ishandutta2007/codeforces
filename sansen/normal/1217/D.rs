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

fn dfs(v: usize, g: &Vec<Vec<usize>>, dp: &mut [u8]) -> bool {
    dp[v] = 1;
    for &u in &g[v] {
        if dp[u] == 1 || (dp[u] == 0 && dfs(u, g, dp)) {
            return true;
        }
    }
    dp[v] = 2;
    false
}

fn has_loop(g: &Vec<Vec<usize>>) -> bool {
    let n = g.len();
    let mut dp = vec![0; n];
    for i in 0..n {
        if dp[i] != 0 {
            continue;
        }
        if dfs(i, g, &mut dp) {
            return true;
        }
    }
    false
}

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for &(s, t) in &e {
        g[s].push(t);
    }
    if !has_loop(&g) {
        let mut ans = String::new();
        ans.push_str("1\n");
        ans.push_str(&"1 ".repeat(m));
        ans.pop();
        println!("{}", ans);
        return;
    }
    let mut ans = String::new();
    ans.push_str("2\n");
    for (a, b) in e {
        if a < b {
            ans.push_str("1 ");
        } else {
            ans.push_str("2 ");
        }
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}
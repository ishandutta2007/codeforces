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
        p: [(i64, i64); n],
        c: [i64; n],
        k: [i64; n],
    }
    let mut dp = c;
    dp.push(0);
    let mut parent = vec![n; n];
    let mut used = vec![false; n];
    let mut sum = 0;
    for _ in 0..n {
        let mut v = used.iter().position(|p| !*p).unwrap();
        for u in v..n {
            if !used[u] && dp[u] < dp[v] {
                v = u;
            }
        }
        sum += dp[v];
        used[v] = true;
        for u in 0..n {
            let d = (p[v].0 - p[u].0).abs() + (p[v].1 - p[u].1).abs();
            let w = d * (k[v] + k[u]);
            if !used[u] && dp[u] > w {
                dp[u] = w;
                parent[u] = v;
            }
        }
    }
    let mut a = vec![];
    let mut b = vec![];
    for v in 0..n {
        if parent[v] == n {
            a.push(v + 1);
        } else {
            b.push((parent[v] + 1, v + 1));
        }
    }
    let mut out = String::new();
    out.push_str(&format!("{}\n", sum));
    out.push_str(&format!("{}\n", a.len()));
    for a in a {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    out.push_str(&format!("\n{}\n", b.len()));
    for (x, y) in b {
        out.push_str(&format!("{} {}\n", x, y));
    }
    print!("{}", out);
}

fn main() {
    run();
}
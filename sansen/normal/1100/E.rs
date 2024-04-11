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

fn is_valid(m: i32, g: &Vec<Vec<(usize, i32)>>) -> bool {
    let n = g.len();
    let mut dp = vec![0; n];
    for v in 0..n {
        if dp[v] == 2 {
            continue;
        }
        dp[v] = 0;
        let mut s = vec![v; 1];
        while let Some(v) = s.pop() {
            if dp[v] == 1 {
                dp[v] = 2;
                continue;
            }
            dp[v] = 1;
            s.push(v);
            for &(u, c)in g[v].iter() {
                if c < m {
                    continue;
                }
                if dp[u] == 0 {
                    s.push(u);
                } else if dp[u] == 1 {
                    return false;
                }
            }
        }
    }
    true
}

use std::io::Write;

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1, i32); m],
    }
    let mut g = vec![vec![]; n];
    for &(s, t, c) in e.iter() {
        g[s].push((t, c));
    }
    if is_valid(0, &g) {
        println!("0 0");
        return;
    }
    let mut l = 0;
    let mut r = 1_000_000_000 + 1;
    while r - l > 1 {
        let m = (l + r) / 2;
        if is_valid(m, &g) {
            r = m;
        } else {
            l = m;
        }
    }
    let mut g = vec![vec![]; n];
    let mut d = vec![0; n];
    let mut detect = vec![];
    for (i, &(s, t, c)) in e.iter().enumerate() {
        if c >= r {
            g[s].push(t);
            d[t] += 1;
        } else {
            detect.push((s, t, i));
        }
    }
    let mut dp = vec![0; n];
    let mut depth = 1;
    let mut q = std::collections::VecDeque::new();
    for v in 0..n {
        if d[v] > 0 {
            continue;
        }
        dp[v] = depth;
        depth += 1;
        q.push_back(v);
    }
    while let Some(v) = q.pop_front() {
        for &u in g[v].iter() {
            d[u] -= 1;
            if d[u] == 0 {
                dp[u] = depth;
                depth += 1;
                q.push_back(u);
            }
        }
    }
    let mut ans = vec![];
    for (s, t, k) in detect {
        if dp[s] > dp[t] || (dp[s] == dp[t] && s > t){
            ans.push(k + 1);
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{} {}", l, ans.len()).unwrap();
    for (i, &v) in ans.iter().enumerate() {
        if i > 0 {
            write!(out, " ").unwrap();
        }
        write!(out, "{}", v).unwrap();
    }
    writeln!(out, "").unwrap();
}

fn main() {
    run();
}
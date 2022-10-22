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

fn no() {
    println!("NO");
    std::process::exit(0);
}

fn dfs(v: usize, k: u8, g: &[Vec<(usize, u8)>], ans: &mut [u8]) -> bool {
    if let Some(x) = g[v].iter().position(|p| p.1 == k) {
        let u = g[v][x].0;
        if ans[u] < 2 {
            return false;
        }
        ans[v] = k;
        ans[u] = k;
        if x ^ 1 < g[v].len() {
            let z = g[v][x ^ 1].0;
            if ans[z] == 2 && !dfs(z, k ^ 1, g, ans) {
                ans[v] = 2;
                ans[u] = 2;
                return false;
            }
        }
        if let Some(y) = g[u].iter().position(|p| p.0 != v) {
            let z = g[u][y].0;
            if ans[z] == 2 && !dfs(z, k ^ 1, g, ans) {
                ans[v] = 2;
                ans[u] = 2;
                return false;
            }
        }
        true
    } else if let Some(k) = g[v].iter().position(|p| p.0 == v) {
        ans[v] = g[v][k].1;
        true
    } else {
        false
    }
}

fn run() {
    input! {
        n: usize,
        a: i32,
        b: i32,
        p: [i32; n],
    }
    let mut p = p.iter().cloned().enumerate().collect::<Vec<_>>();
    p.sort_by_key(|p| p.1);
    let mut g = vec![vec![]; n];
    for i in 0..n {
        let v = p[i].1;
        if let Ok(k) = p.binary_search_by_key(&(a - v), |p| p.1) {
            g[i].push((k, 0));
        }
        if let Ok(k) = p.binary_search_by_key(&(b - v), |p| p.1) {
            g[i].push((k, 1));
        }
        if g[i].is_empty() {
            no();
        }
    }
    let mut ans = vec![2; n];
    let mut used = vec![false; n];
    let mut q = std::collections::VecDeque::new();
    for i in 0..n {
        if g[i].len() == 1 {
            let (u, y) = g[i][0];
            q.push_back(i);
            q.push_back(u);
            used[i] = true;
            used[u] = true;
            ans[i] = y;
            ans[u] = y;
        }
    }
    while let Some(v) = q.pop_front() {
        for &(u, _) in g[v].iter() {
            if used[u] {
                continue;
            }
            if let Some(k) = g[u].iter().position(|e| e.0 != v && !used[e.0]) {
                let (x, y) = g[u][k];
                used[u] = true;
                used[x] = true;
                ans[u] = y;
                ans[x] = y;
                q.push_back(u);
                q.push_back(x);
            } else {
                no();
            }
        }
    }
    for i in 0..n {
        if ans[i] == 2 {
            for k in 0..2 {
                if dfs(i, k, &g, &mut ans) {
                    break;
                }
            }
            if ans[i] == 2 {
                no();
            }
        }
    }
    let mut s = vec![0; n];
    for i in 0..n {
        s[p[i].0] = ans[i];
    }
    let mut out = String::new();
    println!("YES");
    for a in s {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
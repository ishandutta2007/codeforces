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
        k: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (i, &(a, b)) in e.iter().enumerate() {
        g[a].push((b, i));
        g[b].push((a, i));
    }
    let mut cnt = vec![0; n + 1];
    for g in &g {
        cnt[g.len()] += 1;
    }
    for i in (1..n).rev() {
        cnt[i] += cnt[i + 1];
    }
    let mut r = 1;
    while cnt[r + 1] > k {
        r += 1;
    }
    let mut color = vec![0; n - 1];
    let mut stack = vec![];
    for i in 0..n {
        if g[i].len() > 1 {
            continue;
        }
        let (t, k) = g[i][0];
        color[k] = 1;
        stack.push((t, i, 1));
        break;
    }
    while let Some((v, p, c)) = stack.pop() {
        if g[v].len() > r {
            for &(u, k) in &g[v] {
                if u == p {
                    continue;
                }
                color[k] = c;
                stack.push((u, v, c));
            }
        } else {
            let mut t = 1;
            for &(u, k) in &g[v] {
                if u == p {
                    continue;
                }
                if t == c {
                    t += 1;
                }
                color[k] = t;
                stack.push((u, v, t));
                t += 1;
            }
        }
    }
    let mut bad = 0;
    for v in 0..n {
        if g[v].len() > r {
            bad += 1;
            let c = color[g[v][0].1];
            for &(_, k) in &g[v] {
                assert!(c == color[k]);
            }
        } else {
            let mut set = std::collections::HashSet::<usize>::new();
            for &(_, k) in &g[v] {
                let c = color[k];
                assert!(set.insert(c));
            }
        }
    }
    assert!(bad <= k);
    let mut ans = String::new();
    ans.push_str(&format!("{}\n", r));
    for c in color {
        ans.push_str(&format!("{} ", c));
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}
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
        c: [i64; n],
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut stack = vec![(0, 0)];
    let mut q = vec![];
    while let Some((v, p)) = stack.pop() {
        q.push(v);
        for i in 0..g[v].len() {
            if g[v][i] == p {
                g[v].remove(i);
                break;
            }
        }
        for &u in g[v].iter() {
            stack.push((u, v));
        }
    }
    let mut dp0 = vec![0; n];
    let mut dp1 = vec![0; n];
    for &v in q.iter().rev() {
        if g[v].len() == 0 {
            dp0[v] = c[v];
            dp1[v] = 0;
            continue;
        }
        let mut sum = 0;
        let mut diff = 0;
        for &u in g[v].iter() {
            sum += dp0[u];
            diff = std::cmp::max(diff, dp0[u] - dp1[u]);
        }
        dp0[v] = std::cmp::min(sum, sum - diff + c[v]);
        dp1[v] = sum - diff;
        assert!(dp0[v] >= dp1[v]);
    }
    let mut a = vec![];
    let mut stack = vec![(0, 0)];
    let mut set = std::collections::BTreeSet::new();
    while let Some((v, op)) = stack.pop() {
        if set.contains(&(v, op)) {
            continue;
        }
        set.insert((v, op));
        let mut sum = 0;
        let mut diff = 0;
        let mut cnt = 0;
        for &u in g[v].iter() {
            sum += dp0[u];
            let d = dp0[u] - dp1[u];
            if d > diff {
                diff = d;
                cnt = 1;
            } else if diff == d {
                cnt += 1;
            }
        }
        if op == 0 && dp0[v] == sum {
            for &u in g[v].iter() {
                stack.push((u, 0));
            }
        }
        if op == 0 && dp0[v] == sum - diff + c[v] {
            a.push(v);
            for &u in g[v].iter() {
                if dp0[u] - dp1[u] == diff {
                    stack.push((u, 1));
                    if cnt > 1 {
                        stack.push((u, 0));
                    }
                } else {
                    stack.push((u, 0));
                }
            }
        }
        if op == 1 {
            for &u in g[v].iter() {
                if dp0[u] - dp1[u] == diff {
                    stack.push((u, 1));
                    if cnt > 1 {
                        stack.push((u, 0));
                    }
                } else {
                    stack.push((u, 0));
                }
            }
        }
    }
    a.sort();
    a.dedup();
    let mut out = String::new();
    out.push_str(&format!("{} {}\n", dp0[0], a.len()));
    for a in a {
        out.push_str(&(a + 1).to_string());
        out.push(' ');
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
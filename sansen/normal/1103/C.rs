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

fn dfs(v: usize, p: usize, parent: &mut [usize], depth: &mut [usize], g: &[Vec<usize>]) {
    for &u in g[v].iter() {
        if u == p {
            continue;
        }
        if depth[u] == g.len() {
            depth[u] = depth[v] + 1;
            parent[u] = v;
            dfs(u, v, parent, depth, g);
        }
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut parent = vec![0; n];
    let mut depth = vec![n; n];
    depth[0] = 0;
    dfs(0, 0, &mut parent, &mut depth, &g);
    let path = (n + k - 1) / k;
    if let Some(v) = depth.iter().position(|d| *d >= path - 1) {
        let mut ans = vec![];
        let mut pos = v;
        while pos > 0 {
            ans.push(pos);
            pos = parent[pos];
        }
        ans.push(0);
        println!("PATH\n{}", ans.len());
        let mut s = String::new();
        for a in ans {
            s.push_str(&format!("{} ", a + 1));
        }
        s.pop();
        println!("{}", s);
        return;
    }
    let mut leaf = vec![true; n];
    parent.iter().for_each(|p| leaf[*p] = false);
    let mut cycle = vec![];
    for v in 0..n {
        if !leaf[v] {
            continue;
        }
        let mut b = vec![];
        for &u in g[v].iter() {
            if depth[u] != depth[v] - 1 {
                b.push(u);
            }
        }
        b.sort_by_key(|b| depth[*b]);
        let mut res = vec![];
        for &b in b.iter() {
            if (depth[v] - depth[b] + 1) % 3 != 0 {
                let mut p = v;
                while p != b {
                    res.push(p);
                    p = parent[p];
                }
                res.push(p);
                break;
            }
        }
        if res.is_empty() {
            res.push(v);
            let mut p = b[1];
            while p != b[0] {
                res.push(p);
                p = parent[p];
            }
            res.push(p);
        }
        assert!(res.len() % 3 != 0 && !res.is_empty());
        cycle.push(res);
    }
    println!("CYCLES");
    cycle.truncate(k);
    let mut s = String::new();
    for c in cycle {
        s.push_str(&format!("{}\n", c.len()));
        for c in c {
            s.push_str(&format!("{} ", c + 1));
        }
        s.pop();
        s.push('\n');
    }
    print!("{}", s);
}

fn main() {
    run();
}
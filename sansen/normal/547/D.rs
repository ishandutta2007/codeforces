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

fn dfs(
    v: usize,
    g: &[Vec<(usize, usize)>],
    it: &mut [usize],
    used: &mut [bool],
    ans: &mut Vec<usize>,
    deg: &mut [usize],
) {
    while it[v] < g[v].len() {
        let (u, k) = g[v][it[v]];
        it[v] += 1;
        if !used[k] {
            used[k] = true;
            dfs(u, g, it, used, ans, deg);
            ans.push(k);
            deg[v] -= 1;
            deg[u] -= 1;
            return;
        }
    }
}

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n],
    }
    let m = e.iter().map(|e| std::cmp::max(e.0, e.1) + 1).max().unwrap();
    let mut g = vec![vec![]; 2 * m];
    let mut deg = vec![0; 2 * m];
    for (i, &(a, b)) in e.iter().enumerate() {
        g[a].push((b + m, i));
        g[b + m].push((a, i));
        deg[a] += 1;
        deg[b + m] += 1;
    }
    let mut it = vec![0; 2 * m];
    let mut used = vec![false; n];
    let mut red = vec![false; n];
    for i in 0..(2 * m) {
        if deg[i] & 1 == 1 {
            let mut ans = vec![];
            dfs(i, &g, &mut it, &mut used, &mut ans, &mut deg);
            let mut val = true;
            for a in ans {
                red[a] = val;
                val ^= true;
            }
        }
    }
    let mut it = vec![0; 2 * m];
    for i in 0..(2 * m) {
        let mut ans = vec![];
        dfs(i, &g, &mut it, &mut used, &mut ans, &mut deg);
        let mut val = true;
        for a in ans {
            red[a] = val;
            val ^= true;
        }
    }
    let mut s = String::new();
    for red in red {
        if red {
            s.push('r');
        } else {
            s.push('b');
        }
    }
    println!("{}", s);
}

fn main() {
    run();
}
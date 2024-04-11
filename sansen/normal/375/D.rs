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

fn dfs(v: usize, save: bool, cnt: &mut [usize], dp: &mut [usize], ans: &mut [usize], c: &[usize], ask: &[Vec<(usize, usize)>], g: &[Vec<usize>]) {
    for &u in g[v].iter().skip(1) {
        dfs(u, false, cnt, dp, ans, c, ask, g);
    }
    if g[v].len() > 0 {
        dfs(g[v][0], true, cnt, dp, ans, c, ask, g);
    }
    for &u in g[v].iter().skip(1) {
        let mut stack = vec![u];
        while let Some(v) = stack.pop() {
            cnt[c[v]] += 1;
            dp[cnt[c[v]]] += 1;
            stack.extend_from_slice(&g[v]);
        }
    }
    cnt[c[v]] += 1;
    dp[cnt[c[v]]] += 1;
    for &(k, x) in ask[v].iter() {
        ans[x] = dp[k];
    }
    if !save {
        let mut stack = vec![v];
        while let Some(v) = stack.pop() {
            dp[cnt[c[v]]] -= 1;
            cnt[c[v]] -= 1;
            stack.extend_from_slice(&g[v]);
        }
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        c: [usize1; n],
        e: [(usize1, usize1); n - 1],
        ask: [(usize1, usize); m],
    }
    let mut query = vec![vec![]; n];
    for (i, &(v, k)) in ask.iter().enumerate() {
        query[v].push((k, i));
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut topo = vec![0];
    for i in 0..n {
        let v = topo[i];
        for u in g[v].clone() {
            let x = g[u].iter().position(|p| *p == v).unwrap();
            g[u].remove(x);
            topo.push(u);
        }
    }
    let mut size = vec![1usize; n];
    for &v in topo.iter().rev() {
        for &u in g[v].iter() {
            size[v] += size[u];
        }
        g[v].sort_by_cached_key(|u| !size[*u]);
    }
    let mut ans = vec![0; m];
    let mut cnt = vec![0; 100000];
    let mut dp = vec![0; 100000 + 1];
    dfs(0, false, &mut cnt, &mut dp, &mut ans, &c, &query, &g);
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for ans in ans {
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
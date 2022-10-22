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

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1, i64); n - 1],
        q: usize,
        ask: [(usize1, i64); q],
    }
    let mut g = vec![vec![]; n];
    for &(a, b, _) in e.iter() {
        g[a].push(b);
        g[b].push(a);
    }
    let mut parent = vec![n; n];
    let mut topo = vec![0];
    for i in 0..n {
        let v = topo[i];
        for u in g[v].clone() {
            let x = g[u].iter().position(|p| *p == v).unwrap();
            g[u].remove(x);
            parent[u] = v;
            topo.push(u);
        }
    }
    let mut size = vec![1; n];
    for &v in topo.iter().rev() {
        for &u in g[v].iter() {
            size[v] += size[u];
        }
    }
    let way = |n: i64| n * (n - 1) * (n - 2);
    let mut sum = 0.0;
    for &(a, b, c) in e.iter() {
        let x = if parent[a] == b {
            size[a]
        } else {
            size[b]
        };
        let n = n as i64;
        sum += 2.0 * c as f64 * (way(n) - way(x) - way(n - x)) as f64;
    }
    let mut e = e;
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (r, w) in ask {
        let (a, b, c) = e[r];
        e[r].2 = w;
        let x = if parent[a] == b {
            size[a]
        } else {
            size[b]
        };
        let n = n as i64;
        sum += 2.0 * (w - c) as f64 * (way(n) - way(x) - way(n - x)) as f64;
        let ans = sum / way(n) as f64;
        writeln!(out, "{:.7}", ans).ok();
    }
}

fn main() {
    run();
}
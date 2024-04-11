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

use std::io::Write;

fn dfs(v: usize, g: &mut [Vec<(usize, usize)>], used: &mut [bool], res: &mut Vec<(usize, usize)>) {
    while let Some((u, k)) = g[v].pop() {
        if used[k] {
            continue;
        }
        used[k] = true;
        dfs(u, g, used, res);
        res.push((v + 1, u + 1));
    }
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for (i, &(x, y)) in e.iter().enumerate() {
        g[x].push((y, i));
        g[y].push((x, i));
    }
    let mut odd = vec![];
    for (i, g) in g.iter().enumerate() {
        if g.len() & 1 == 1 {
            odd.push(i);
        }
    }
    let mut e = e;
    for odd in odd.chunks(2) {
        let (a, b) = (odd[0], odd[1]);
        let k = e.len();
        e.push((a, b));
        g[a].push((b, k));
        g[b].push((a, k));
    }
    if e.len() & 1 == 1 {
        let k = e.len();
        e.push((0, 0));
        g[0].push((0, k));
        g[0].push((0, k));
    }
    let mut used = vec![false; e.len()];
    let mut p = vec![];
    dfs(0, &mut g, &mut used, &mut p);
    writeln!(out, "{}", p.len()).ok();
    for (i, &(mut a, mut b)) in p.iter().enumerate() {
        if i & 1 == 1 {
            std::mem::swap(&mut a, &mut b);
        }
        writeln!(out, "{} {}", a, b).ok();
    }
}

fn main() {
    run();
}
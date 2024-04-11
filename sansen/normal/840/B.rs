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

//

use std::io::Write;

fn dfs(v: usize, used: &mut [bool], ans: &mut Vec<usize>, deg: &mut [i32], d: &[i32], g: &[Vec<(usize, usize)>]) {
    used[v] = true;
    for &(u, k) in g[v].iter() {
        if used[u] {
            continue;
        }
        dfs(u, used, ans, deg, d, g);
        if d[u] != -1 && deg[u] % 2 != d[u] % 2 {
            deg[v] += 1;
            deg[u] += 1;
            ans.push(k);
        }
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        d: [i32; n],
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for (i, &(a, b)) in e.iter().enumerate() {
        g[a].push((b, i));
        g[b].push((a, i));
    }
    let root = d.iter().position(|d| *d == -1).unwrap_or(0);
    let mut used = vec![false; n];
    let mut ans = vec![];
    let mut deg = vec![0; n];
    dfs(root, &mut used, &mut ans, &mut deg, &d, &g);
    if deg.iter().zip(d.iter()).all(|(deg, d)| *d == -1 || *deg % 2 == *d % 2) {
        let out = std::io::stdout();
        let mut out = std::io::BufWriter::new(out.lock());
        writeln!(out, "{}", ans.len()).ok();
        ans.sort();
        for a in ans {
            writeln!(out, "{}", a + 1).ok();
        }
    } else {
        println!("-1");
    }
}

fn main() {
    run();
}
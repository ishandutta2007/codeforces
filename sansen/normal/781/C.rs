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

fn dfs(v: usize, g: &[Vec<usize>], used: &mut [bool], tour: &mut Vec<usize>) {
    used[v] = true;
    tour.push(v);
    for &u in g[v].iter() {
        if used[u] {
            continue;
        }
        dfs(u, g, used, tour);
        tour.push(v);
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        e: [(usize, usize); m],
    }
    let mut g = vec![vec![]; n + 1];
    let mut set = std::collections::BTreeSet::new();
    for (mut a, mut b) in e {
        if a > b {
            std::mem::swap(&mut a, &mut b);
        }
        if a == b || !set.insert((a, b)) {
            continue;
        }
        g[a].push(b);
        g[b].push(a);
    }
    let mut used = vec![false; n + 1];
    let mut tour = vec![];
    dfs(1, &g, &mut used, &mut tour);
    let len = (2 * n + k - 1) / k;
    let tour = tour.iter().chain(tour.iter().skip(1).cycle()).take(len * k).cloned().collect::<Vec<_>>();
    let mut ans = String::new();
    for v in tour.chunks(len) {
        ans.push_str(&format!("{}", v.len()));
        for v in v.iter() {
            ans.push_str(&format!(" {}", *v));
        }
        ans.push('\n');
    }
    print!("{}", ans);
}

fn main() {
    run();
}
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

fn run() {
    input! {
        n: usize,
        m: usize,
        a: [usize; n],
        ask: [(usize1, usize, usize); m],
    }
    let mut g = vec![vec![]; 1_000_000 + 1];
    for (i, a) in a.iter().enumerate() {
        g[*a].push(i);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r, x) in ask {
        let g = &g[x];
        let mut s = g.binary_search_by_key(&(l, 0), |p| (*p, 1)).unwrap_err();
        let mut t = g.binary_search_by_key(&(r, 0), |p| (*p, 1)).unwrap_err();
        if t - s == r - l {
            writeln!(out, "-1").ok();
            continue;
        }
        if g.get(s).is_none() {
            writeln!(out, "{}", l + 1).ok();
            continue;
        }
        if l < g[s] {
            writeln!(out, "{}", l + 1).ok();
            continue;
        }
        while s + 1 < t {
            let m = (s + t) / 2;
            let x = g[m];
            if m - s < x - g[s] {
                t = m;
            } else {
                s = m;
            }
        }
        let mut k = g[s];
        while g.binary_search(&k).is_ok() {
            k += 1;
        }
        writeln!(out, "{}", k + 1).ok();
    }
}

fn main() {
    run();
}
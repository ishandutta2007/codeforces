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
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        w: i32,
        h: i32,
        p: [(u8, i32, i32); n],
    }
    let mut map = Map::new();
    for (i, &(_, p, t)) in p.iter().enumerate() {
        let d = p - t;
        map.entry(d).or_insert(vec![]).push(i);
    }
    let mut ans = vec![(0, 0); n];
    for (d, index) in map {
        let mut start = vec![];
        let mut end = vec![];
        for &k in index.iter() {
            let (op, p, t) = p[k];
            let src = if op == 1 {
                p
            } else {
                -t
            };
            let dst = if op == 1 {
                (p, h)
            } else {
                (w, p)
            };
            start.push((src, k));
            end.push(dst);
        }
        start.sort();
        end.sort_by(|a, b| a.0.cmp(&b.0).then(b.1.cmp(&a.1)));
        for (&(_, k), pos) in start.iter().zip(end) {
            ans[k] = pos;
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (x, y) in ans {
        writeln!(out, "{} {}", x, y).ok();
    }
}

fn main() {
    run();
}
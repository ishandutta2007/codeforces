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

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1, i32); m],
    }
    let mut map = vec![Map::new(); n];
    for map in map.iter_mut() {
        map.insert(-1, 0);
    }
    for (s, t, w) in e {
        let v = *map[s].range(..w).rev().next().unwrap().1 + 1;
        if *map[t].range(..=w).next_back().unwrap().1 >= v {
            continue;
        }
        let del = map[t]
            .range(w..)
            .take_while(|p| *p.1 <= v)
            .map(|p| *p.0)
            .collect::<Vec<_>>();
        for k in del {
            map[t].remove(&k);
        }
        map[t].insert(w, v);
    }
    let ans = map.into_iter().flatten().map(|p| p.1).max().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
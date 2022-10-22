// 
// 
//
// 
// 
// green0
// map

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        t: i64,
        p: [(i64, i64); n],
        d: [i64; n - 1],
    }
    let mut geta = 0;
    let mut p = p;
    for i in 0..n {
        p[i].1 = (t - p[i].1) % t;
        if i > 0 {
        geta += d[i - 1];
        p[i].1 += t -  geta % t;
        p[i].1 %= t;
        }
    }
    let mut map = Map::new();
    map.insert((0, t), 0i64);
    for &(g, c) in p.iter() {
        let mut del = vec![];
        if c + g < t {
            del = vec![(c + g, t), (0, c)];
        } else {
            del = vec![((c + g) % t, c)];
        }
        del.retain(|p| p.0 < p.1);
        let last = c;
        let mut val = std::i64::MAX;
        for &(l, r) in del.iter() {
            for &p in [l, r].iter() {
                if let Some((&(s, t), &v)) = map.range(..(p, p)).next_back() {
                    if s < p && p < t {
                        map.remove(&(s, t));
                        map.insert((s, p), v);
                        map.insert((p, t), v);
                    }
                }
            }
            while let Some((&key, &v)) = map.range((l, l)..(r, r)).next() {
                map.remove(&key);
                if key.1 <= last {
                    val = val.min(v + last - key.1 + 1);
                } else {
                    val = val.min(v + last + (t - key.1 + 1));
                }
            }
        }
        if val == std::i64::MAX {
            continue;
        }
        if let Some((&key, &v)) = map.range((last, last)..).next() {
            if key.0 == last {
                if v > val {
                    map.remove(&key);
                    if key.0 + 1 < key.1 {
                        map.insert((key.0 + 1, key.1), v);
                    }
                    map.insert((last, last + 1), val);
                }
            } else {
                map.insert((last, last + 1), val);
            }
        } else {
            map.insert((last, last + 1), val);
        }
    }
    let ans = *map.values().min().unwrap() + d.iter().sum::<i64>();
    println!("{}", ans);
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
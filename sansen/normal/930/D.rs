// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 
// 
// parity
// 
// 
// 
// 
// 
//
// 
// 45ok [L, inf) (-inf, R] 

fn calc(p: Vec<(i64, i64)>) -> i64 {
    if p.is_empty() {
        return 0;
    }
    let n = p.len();
    let mut p = p.into_iter().map(|p| (p.0 + p.1, p.0 - p.1)).collect::<Vec<_>>();
    p.sort_by_key(|p| p.0);
    let min = p[0].0;
    let max = p[n - 1].0;
    let mut i = 0;
    let mut range = vec![];
    let inf = std::i64::MAX / 10;
    let mut left = inf;
    let mut right = -inf;
    for x in (min..=max).step_by(2) {
        while i < n && p[i].0 == x {
            let y = p[i].1;
            i += 1;
            left.chmin(y);
            right.chmax(y);
        }
        range.push((left, right));
    }
    let save = range;
    p.reverse();
    let mut i = 0;
    let mut range = vec![];
    let inf = std::i64::MAX / 10;
    let mut left = inf;
    let mut right = -inf;
    for x in (min..=max).rev().step_by(2) {
        while i < n && p[i].0 == x {
            let y = p[i].1;
            i += 1;
            left.chmin(y);
            right.chmax(y);
        }
        range.push((left, right));
    }
    range.reverse();
    let mut ans = 0;
    for (&(a, b), &(c, d)) in range.iter().skip(1).zip(save.iter()) {
        let l = a.max(c);
        let r = b.min(d);
        ans += ((r - l) / 2).max(0);
    }
    ans
}

fn run() {
    input! {
        n: usize,
        p: [(i64, i64); n],
    }
    let mut point = vec![vec![]; 2];
    for (x, y) in p {
        let v = x.abs() + y.abs();
        point[(v & 1) as usize].push((x, y));
    }
    let mut ans = 0;
    for p in point {
        ans += calc(p);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
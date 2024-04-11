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
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn calc(c: f64, m: f64, p: f64, v: f64) -> f64 {
    let mut ans = 1f64;
    if c > 0.00001 {
        let sub = c.min(v);
        let add = if m > 0.00001 { sub * 0.5 } else { 0f64 };
        ans += c * calc(c - sub, m + add, p + sub - add, v);
    }
    if m > 0.00001 {
        let sub = m.min(v);
        let add = if c > 0.00001 { sub * 0.5 } else { 0f64 };
        ans += m * calc(c + add, m - sub, p + sub - add, v);
    }
    ans
}

fn run() {
    input! {
        t: usize,
        ask: [(f64, f64, f64, f64); t],
    }
    for (c, m, p, v) in ask {
        let ans = calc(c, m, p, v);
        println!("{:.7}", ans);
    }
}

fn main() {
    run();
}
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

fn calc(x: u64, y: u64) -> bool {
    let mut set = Set::new();
    let mut s = vec![];
    let mut x = x;
    while x > 0 {
        s.push(x % 2);
        x /= 2;
    }
    set.insert(s.clone());
    let fix = |s: &mut Vec<u64>| {
        while *s.last().unwrap() == 0 {
            s.pop();
        }
    };
    let mut dfs = vec![s];
    while let Some(s) = dfs.pop() {
        for &d in [0, 1].iter() {
            let mut s = s.clone();
            s.insert(0, d);
            s.reverse();
            fix(&mut s);
            if s.len() <= 60 && set.insert(s.clone()) {
                dfs.push(s);
            }
        }
    }
    let mut s = vec![];
    let mut y = y;
    while y > 0 {
        s.push(y % 2);
        y /= 2;
    }
    set.contains(&s)
}

fn run() {
    input!(x: u64, y: u64);
    if calc(x, y) {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    run();
}
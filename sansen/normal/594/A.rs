fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}

fn shuffle<T>(a: &mut [T]) {
    for i in 1..a.len() {
        let p = rand() % (i + 1);
        a.swap(i, p);
    }
}

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


fn calc(x: Vec<u64>, k: usize, dp: &mut Map<(Vec<u64>, usize), u64>) -> u64 {
    if x.len() <= 2 {
        return x[1] - x[0];
    }
    if let Some(&v) = dp.get(&(x.clone(), k)) {
        return v;
    }
    let mut min = std::u64::MAX;
    let mut max = std::u64::MIN;
    for i in 0..x.len() {
        let mut x = x.clone();
        x.remove(i);
        let v = calc(x, k ^ 1, dp);
        min = min.min(v);
        max = max.max(v);
    }
    let res = if k == 0 {
        min
    } else {
        max
    };
    if k == 0 {
        let n = x.len();
        let m = n / 2;
        let p = x.iter().zip(x[m..].iter()).map(|p| *p.1 - *p.0).min().unwrap();
        println!("{:?}: {} {}", x, res, p);
    }
    dp.insert((x, k), res);
    res
}

fn run() {
    input! {
        n: usize,
        x: [u64; n],
    }
    let mut x = x;
    x.sort();
    let ans = x.iter().zip(x[(n / 2)..].iter()).map(|p| *p.1 - *p.0).min().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
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

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 
// N
// i A_i 
// M
// jB_j
//
// 
// jj
// ij C_{i, j} 
//
// 
// () - () > 0
// 
//
// 
// -1
//
// 1 <= N, M <= 6
// 1 <= A_i, B_j <= 4
// 1 <= C_{i, j} <= 10^7
//
//
// 
// sum b < sum a -1
// 
// 
// 
// 
// 
// 
//  O(2^(NM) * 2^(M) * N) 
// 
// 
// 
// src -> i b_i
// j -> i inf
// i -> dst a_i
// 
// sum a_i > ()
// 
// 
// 
// 0
// 
// ->dst 
// N, M, A, B dp
// 
// 
// 

fn run() {
    input! {
        n: usize,
        m: usize,
        a: [i32; n],
        b: [i32; m],
        c: [[i32; m]; n],
    }
    let mut memo = Map::new();
    memo.insert(b, 0);
    for (a, c) in a.into_iter().zip(c) {
        let mut dp = Map::new();
        for (b, v) in memo.into_iter() {
            dp.insert((a, b), v);
        }
        for (i, c) in c.into_iter().enumerate() {
            let mut next = dp.clone();
            for ((a, b), v) in dp {
                let v = v + c;
                for k in 1..=b[i].min(a) {
                    let mut b = b.clone();
                    b[i] -= k;
                    let a = a - k;
                    next.entry((a, b)).or_insert(v).chmin(v);
                }
            }
            dp = next;
        }
        memo = Map::new();
        for ((a, b), v) in dp {
            if a == 0 {
                memo.entry(b).or_insert(v).chmin(v);
            }
        }
    }
    let ans = memo.values().min().cloned().unwrap_or(-1);
    println!("{}", ans);
}

fn main() {
    run();
}
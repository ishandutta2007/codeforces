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
// ---------- begin super slice ----------
pub trait SuperSlice {
    type Item;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn lower_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn lower_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn upper_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn upper_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
}

impl<T> SuperSlice for [T] {
    type Item = T;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.lower_bound_by(|p| p.cmp(key))
    }
    fn lower_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Greater))
            .unwrap_err()
    }
    fn lower_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.lower_bound_by(|p| f(p).cmp(key))
    }
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.upper_bound_by(|p| p.cmp(key))
    }
    fn upper_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Less))
            .unwrap_err()
    }
    fn upper_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.upper_bound_by(|p| f(p).cmp(key))
    }
}
// ---------- end super slice ----------
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
// bitdp
//  logN * (kN + 2^k * k * logN)
// 

fn run() {
    input! {
        n: usize,
        k: usize,
        s: bytes,
    }
//    let s = vec![b'?'; n];
    let mut sum = vec![vec![0; n + 1]; k];
    for (i, c) in s.iter().enumerate().rev() {
        for (j, sum) in sum.iter_mut().enumerate() {
            sum[i] = sum[i + 1];
            if *c == b'a' + j as u8 {
                sum[i] += 1;
            }
        }
    }
    let mut trans = vec![vec![]; k];
    let mut valid = |m: usize| -> bool {
        if k * m > n {
            return false;
        }
        trans.iter_mut().for_each(|p| p.clear());
        for j in 0..=(n - m) {
            let mut a = [0; 17];
            let a = &mut a[..k];
            for (a, sum) in a.iter_mut().zip(&sum) {
                *a = sum[j] - sum[j + m];
            }
            let sum = a.iter().sum::<usize>();
            for (i, a) in a.iter().enumerate() {
                if *a == sum {
                    trans[i].push(j);
                }
            }
        }
        let mut dp = vec![n + 1; 1 << k];
        dp[0] = 0;
        for i in 0..(1 << k) {
            let s = dp[i];
            if s > n {
                continue;
            }
            for (j, trans) in trans.iter().enumerate() {
                if i >> j & 1 == 1 {
                    continue;
                }
                let x = trans.lower_bound(&s);
                if x < trans.len() {
                    let t = trans[x] + m;
                    dp[i | (1 << j)].chmin(t);
                }
            }
        }
        dp[(1 << k) - 1] <= n
    };
    let mut ok = 0;
    let mut ng = 1;
    while valid(ng) {
        ok = ng;
        ng *= 2;
    }
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        if valid(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{}", ok);
}

fn main() {
    run();
}
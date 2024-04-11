// ---------- begin bitwise transform ----------
fn bitwise_transform<T, F>(a: &mut [T], mut f: F)
where
    F: FnMut(&mut T, &mut T)
{
    let n = a.len().trailing_zeros() as usize;
    assert!(a.len() == 1 << n);
    for i in 0..n {
        for a in a.chunks_exact_mut(2 << i) {
            let (x, y) = a.split_at_mut(1 << i);
            for (x, y) in x.iter_mut().zip(y) {
                f(x, y);
            }
        }
    }
}
// ---------- end bitwise transform ----------
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

fn factorize(mut n: u64) -> Vec<(u64, u32)> {
    let mut res = vec![];
    for k in 2.. {
        if k * k > n {
            break;
        }
        let mut c = 0;
        while n % k == 0 {
            n /= k;
            c += 1;
        }
        if c > 0 {
            res.push((k, c));
        }
    }
    if n > 1 {
        res.push((n, 1));
    }
    res
}

fn gcd(mut a: u64, mut b: u64) -> u64 {
    while b > 0 {
        let r = a % b;
        a = b;
        b = r;
    }
    a
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

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        k: u64,
        a: [u64; n],
        e: [u64; n],
    }
    let g = a.iter().fold(0, |s, a| gcd(s, *a));
    let f = factorize(g);
    let mut a = a;
    for a in a.iter_mut() {
        let mut v = 1;
        for &(p, _) in f.iter() {
            while *a % p == 0 {
                *a /= p;
                v *= p;
            }
        }
        *a = v;
    }
    let mut map = Map::new();
    for (a, e) in a.iter().zip(e.iter()) {
        map.entry(*a).or_insert(vec![]).push(*e);
    }
    let n = f.len();
    let mut trans = Map::new();
    for (mut a, mut e) in map {
        let mut d = vec![1];
        for &(p, _) in f.iter() {
            let mut v = 1;
            while a % p == 0 {
                a /= p;
                v *= p;
            }
            let len = d.len();
            for i in 0..len {
                let v = v * d[i];
                d.push(v);
            }
        }
        let mut cnt = vec![0; 1 << n];
        for (cnt, d) in cnt.iter_mut().zip(d) {
            if d <= k {
                *cnt = 1;
            }
        }
        bitwise_transform(&mut cnt, |a, b| *a += *b);
        let mut mask = vec![];
        for (i, cnt) in cnt.iter().enumerate() {
            if *cnt == 1 {
                mask.push(!i & ((1 << n) - 1));
            }
        }
        mask.sort();
        trans.entry(mask).or_insert(vec![]).append(&mut e);
    }
    let inf = std::u64::MAX / 10;
    let mut dp = vec![vec![inf; 1 << n]; n + 1];
    dp[0][(1 << n) - 1] = 0;
    for (mask, mut e) in trans {
        e.sort_unstable();
        for e in e.iter() {
            let mut update = false;
            for i in (0..n).rev() {
                for j in 0..(1 << n) {
                    let v = dp[i][j] + *e;
                    for mask in mask.iter() {
                        update |= dp[i + 1][j & *mask].chmin(v);
                    }
                }
            }
            if !update {
                break;
            }
        }
    }
    let mut ans = inf;
    for (i, dp) in dp.iter().enumerate() {
        if dp[0] < inf {
            ans.chmin(i as u64 * dp[0]);
        }
    }
    if ans < inf {
        println!("{}", ans);
    } else {
        println!("-1");
    }
}

fn main() {
    run();
}
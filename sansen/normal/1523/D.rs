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
// ---------- begin Run Length Encoding ----------
fn run_length_encoding<T: Clone + Eq>(a: &[T]) -> Vec<(T, usize)> {
    let mut a = a.iter().map(|a| (a.clone(), 1)).collect::<Vec<_>>();
    a.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 += a.1;
            true
        }
    });
    a
}
// ---------- end Run Length Encoding ----------

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

fn run() {
    input! {
        n: usize,
        m: usize,
        p: usize,
        s: [String; n],
    }
    let mut a = vec![0u64; n];
    for (a, s) in a.iter_mut().zip(s) {
        *a = u64::from_str_radix(&s, 2).unwrap();
    }
    a.sort();
    let mut ans = 0u64;
    for _ in 0..30 {
        let x = a[rand() % n];
        let mut bit = vec![];
        for i in 0..m {
            if x >> i & 1 == 1 {
                bit.push(i);
            }
        }
        let m = bit.len();
        let mut dp = vec![0; 1 << m];
        for a in a.iter() {
            let mut x = 0;
            for (j, k) in bit.iter().enumerate() {
                if *a >> *k & 1 == 1 {
                    x |= 1 << j;
                }
            }
            dp[x] += 1;
        }
        bitwise_transform(&mut dp, |a, b| *a += *b);
        for (i, dp) in dp.iter().enumerate() {
            if i.count_ones() > ans.count_ones() && *dp >= (n + 1) / 2 {
                ans = 0;
                for (j, x) in bit.iter().enumerate() {
                    if i >> j & 1 == 1 {
                        ans |= 1u64 << *x;
                    }
                }
            }
        }
    }
    for i in (0..m).rev() {
        print!("{}", ans >> i & 1);
    }
    println!();
}

fn main() {
    run();
}
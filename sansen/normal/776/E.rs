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

// f(n) = phi(n)
// = ** (p - 1)p^(a - 1)
//
// g(n) = n

const MOD: usize = 1_000_000_007;

fn phi(mut n: usize) -> usize {
    let mut ans = n;
    for p in 2.. {
        if p * p > n {
            break;
        }
        if n % p == 0 {
            while n % p == 0 {
                n /= p;
            }
            ans -= ans / p;
        }
    }
    if n > 1 {
        ans -= ans / n;
    }
    ans
}

fn calc(n: usize, k: usize) -> usize {
    if k >= 100 {
        return 1;
    }
    if k == 1 {
        return phi(n);
    }
    if k % 2 == 0 {
        calc(n, k - 1)
    } else {
        phi(calc(n, k - 1))
    }
}

fn run() {
    input! {
        n: usize,
        k: usize,
    }
    let ans = calc(n, k) % MOD;
    println!("{}", ans);
}

fn main() {
    run();
}
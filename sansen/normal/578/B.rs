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

fn run() {
    input! {
        n: usize,
        k: u32,
        x: u64,
        a: [u64; n],
    }
    let mut a = a;
    a.sort();
    let mut cnt = vec![0; 60];
    for a in a.iter() {
        for (j, c) in cnt.iter_mut().enumerate() {
            *c += *a >> j & 1;
        }
    }
    let mut ans = 0;
    for &a in a.iter() {
        for (j, c) in cnt.iter_mut().enumerate() {
            *c -= a >> j & 1;
        }
        let v = a * x.pow(k);
        let mut val = 0u64;
        for (j, c) in cnt.iter().enumerate() {
            let c = *c + (v >> j & 1);
            if c > 0 {
                val |= 1 << j;
            }
        }
        ans = ans.max(val);
        for (j, c) in cnt.iter_mut().enumerate() {
            *c += a >> j & 1;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
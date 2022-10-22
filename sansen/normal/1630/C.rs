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

// i < j < k, c_i = c_j = c_k = 0, a_i = a_k
// i, j, k  c_j <- 1 
// sum_i c_i 
// N <= 2*10^5
// 1 <= a_i <= N
// 
// 
// N-2
//
// 
// x-y-x-y
// N-3
//
// 
// 

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut dp = vec![0; n + 1];
    for (i, a) in a.iter().enumerate() {
        dp[*a] = i;
    }
    let mut ans = n;
    let mut l = 0;
    while l < n {
        if l == dp[a[l]] {
            ans -= 1;
            l += 1;
            continue;
        }
        ans -= 2;
        let mut r = dp[a[l]];
        loop {
            let mut next = r;
            while l <= r {
                next = next.max(dp[a[l]]);
                l += 1;
            }
            if next == r {
                break;
            } else {
                ans -= 1;
                r = next;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
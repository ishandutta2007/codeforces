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

// binary string 
// 1flip
// ab
//
// 
// k1
// 1+n-1-(k-1) =n-k+1 1
// 1
// 
// 11, 00 
// 10, 01 ...
//
// k=n-k+1, k=(n+1)/2 
// 
// 01, 10 
//

fn run() {
    input! {
        n: usize,
        ask: [(i32, bytes, bytes); n],
    }
    let inf = 1000000i32;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, a, b) in ask {
        let mut cnt = [[0; 2]; 2];
        let mut one = 0;
        for (a, b) in a.iter().zip(&b) {
            cnt[(*a - b'0') as usize][(*b - b'0') as usize] += 1;
            if *a == b'1' {
                one += 1;
            }
        }
        let mut ans = inf;
        if (cnt[1][1] + cnt[0][0]) % 2 == 1 && 0 <= cnt[1][1] - cnt[0][0] && cnt[1][1] - cnt[0][0] <= 1 {
            ans = ans.min(cnt[0][0] + cnt[1][1]);
        }
        if (cnt[0][1] + cnt[1][0]) % 2 == 0 && 0 <= cnt[1][0] - cnt[0][1] && cnt[1][0] - cnt[0][1] <= 1 {
            ans = ans.min(cnt[0][1] + cnt[1][0]);
        }
        if ans == inf {
            ans = -1;
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
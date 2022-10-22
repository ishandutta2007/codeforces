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
        t: usize,
        ask: [(usize, usize, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, k, s) in ask {
        let mut cnt = [0usize; 26];
        for s in s {
            cnt[(s - b'a') as usize] += 1;
        }
        let valid = |m: usize| -> bool {
            let mut cnt = cnt;
            for _ in 0..k {
                if m % 2 == 1 {
                    if let Some(x) = cnt.iter_mut().find(|c| **c % 2 == 1) {
                        *x -= 1;
                    } else if let Some(x) = cnt.iter_mut().find(|c| **c > 0) {
                        *x -= 1;
                    } else {
                        return false;
                    }
                }
                let mut m = m / 2;
                for c in cnt.iter_mut() {
                    let q = std::cmp::min(*c / 2, m);
                    *c -= 2 * q;
                    m -= q;
                }
                if m > 0 {
                    return false;
                }
            }
            true
        };
        let mut ok = 1;
        let mut ng = n + 1;
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            if valid(mid) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        writeln!(out, "{}", ok).ok();
    }
}

fn main() {
    run();
}
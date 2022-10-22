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
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// N=4
// 0, 1, 2 
// 
//
// 
// N2
// 0
// n-1 k
// (n-1)-k
// !k-0
// 
// n-1
//

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(usize, usize); t],
    }
    for (n, k) in ask {
        if (n, k) == (4, 3) {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut ans = vec![];
        if k == 0 {
            for i in 0..(n / 2) {
                ans.push((i, !i & (n - 1)));
            }
        } else if k < n - 1 {
            ans.push((k, n - 1));
            ans.push((0, !k & (n - 1)));
            for i in 0..(n / 2) {
                if i != 0 && i != k && i != !k & (n - 1) {
                    ans.push((i, !i & (n - 1)));
                }
            }
        } else {
            ans.push((0, n - 4));
            ans.push((1, 3));
            ans.push((n - 2, n - 1));
            for i in 0..(n / 2) {
                if i != 0 && i != 1 && i != 3 {
                    ans.push((i, !i & (n - 1)));
                }
            }
        }
        let mut sum = 0;
        for p in ans.iter() {
            sum += p.0 & p.1;
        }
        assert_eq!(k, sum);
        for (a, b) in ans {
            writeln!(out, "{} {}", a, b).ok();
        }
    }
}

fn main() {
    run();
}
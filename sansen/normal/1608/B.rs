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
        ask: [(usize, usize, usize); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, a, b) in ask {
        if a + b > n - 2 || a.max(b) - a.min(b) > 1 {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut p = (1..=n).collect::<Vec<_>>();
        if a == b {
            for i in 0..a {
                p.swap(2 * i + 2, 2 * i + 1);
            }
        } else {
            p.clear();
            p.push(1);
            p.push(n);
            for x in 1..a.max(b) {
                p.push(x + 1);
                p.push(n - x);
            }
            let mut used = vec![false; n + 1];
            for p in p.iter() {
                used[*p] = true;
            }
            for i in (1..=n).rev() {
                if !used[i] {
                    p.push(i);
                }
            }
            if a < b {
                for p in p.iter_mut() {
                    *p = n + 1 - *p;
                }
            }
        }
        for (i, p) in p.iter().enumerate() {
            if i > 0 {
                write!(out, " ").ok();
            }
            write!(out, "{}", *p).ok();
        }
        writeln!(out).ok();
    }
}

fn main() {
    run();
}
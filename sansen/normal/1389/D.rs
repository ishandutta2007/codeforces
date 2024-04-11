//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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

//

use std::io::Write;
use std::cmp::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(i64, i64, i64, i64, i64, i64); t],
    }
    for (n, k, a, b, c, d) in ask {
        let x = max(a, c);
        let y = min(b, d);
        if (y - x) * n >= k {
            writeln!(out, "0").ok();
            continue;
        }
        let valid = |t: i64| -> bool {
            if x <= y {
                let k = k - n * (y - x);
                let rem = n * (x - min(a, c) + max(b, d) - y);
                if k <= rem && k <= t {
                    return true;
                }
                if t <= rem {
                    return false;
                }
                let t = t - rem;
                let k = k - rem;
                return 2 * k <= t;
            }
            for i in 1..=n {
                if t <= i * (x - y) {
                    return false;
                }
                let t = t - i * (x - y);
                let d = i * (max(b, d) - min(a, c));
                if t >= k && d >= k {
                    return true;
                }
                if t <= d {
                    continue;
                }
                let t = t - d;
                let req = k - d;
                if 2 * req <= t {
                    return true;
                }
            }
            false
        };
        let mut ng = 0;
        let mut ok = std::i64::MAX / 2;
        while ok - ng > 1 {
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
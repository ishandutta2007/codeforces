// 
// 
//

use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        q: usize,
        ask: [(usize, usize, usize); q],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (t, x, y) in ask {
        if t < x + y {
            writeln!(out, "NO").ok();
            continue;
        }
        let m = 120;
        let mut state = vec![vec![0; m]; m];
        if t - x - y > 0 {
            let mut dp = vec![vec![0; m + 1]; m + 1];
            dp[0][0] = t - x - y;
            for i in 0..m {
                for j in 0..m {
                    let v = dp[i][j];
                    let a = (v + 1) / 2;
                    let b = v - a;
                    dp[i][j + 1] += a;
                    dp[i + 1][j] += b;
                    state[i][j] ^= v % 2;
                }
            }
        }
        let mut a = 0;
        let mut b = 0;
        while (a, b) != (x, y) && a < m && b < m {
            if state[a][b] == 0 {
                b += 1;
            } else {
                a += 1;
            }
        }
        let mut ans = "NO";
        if (a, b) == (x, y) {
            ans = "YES";
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
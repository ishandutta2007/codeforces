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
        ask: [u64; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for n in ask {
        let mut n = n;
        let mut d = vec![];
        while n > 0 {
            d.push(n % 10);
            n /= 10;
        }
        // dp[][carry] = Option<(7, 4 )>
        let mut dp = vec![vec![None; 5]; d.len() + 1];
        dp[0][0] = Some((0, 0, 0));
        for (i, d) in d.iter().enumerate() {
            let pre = std::mem::take(&mut dp[i]);
            for (carry, _) in pre.iter().enumerate().filter(|p| p.1.is_some()) {
                for a in 0..=6 {
                    for b in 0..=(6 - a) {
                        let add = carry + 7 * a + 4 * b;
                        let next = add / 10;
                        let digit = add % 10;
                        if digit == *d as usize {
                            dp[i + 1][next] = Some((carry, a, b));
                        }
                    }
                }
            }
            dp[i] = pre;
        }
        if dp[d.len()][0].is_none() {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut ans = vec![0u64; 6];
        let mut pos = 0;
        for i in (1..=d.len()).rev() {
            let (next, a, b) = dp[i][pos].unwrap();
            pos = next;
            for (j, ans) in ans.iter_mut().enumerate() {
                *ans *= 10;
                if j < a {
                    *ans += 7;
                } else if j < a + b {
                    *ans += 4;
                }
            }
        }
        writeln!(out, "{} {} {} {} {} {}", ans[0], ans[1], ans[2], ans[3], ans[4], ans[5],).ok();
    }
}

fn main() {
    run();
}
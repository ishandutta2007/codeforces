use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        t: usize,
        ask: [(usize, i64, i64, bytes, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, x, y, mut a, mut b) in ask {
        a.iter_mut().chain(b.iter_mut()).for_each(|p| *p -= b'0');
        let a = a
            .iter()
            .zip(b.iter())
            .map(|p| (*p.0 ^ *p.1) as usize)
            .collect::<Vec<_>>();
        let c = a.iter().sum::<usize>();
        if c % 2 == 1 {
            writeln!(out, "-1").ok();
            continue;
        }
        let ans = if y <= x {
            if c == 2 && a.windows(2).any(|a| a[0] == 1 && a[1] == 1) {
                (2 * y).min(x)
            } else {
                (c / 2) as i64 * y
            }
        } else {
            let k = (c / 2) as usize;
            let inf = std::i64::MAX / 2;
            let mut dp = vec![vec![inf; k + 1]; 2];
            dp[0][0] = 0;
            dp[1][0] = 0;
            let pos = (0..n).filter(|x| a[*x] == 1).collect::<Vec<_>>();
            for i in 1..pos.len() {
                let mut next = dp[1].clone();
                for j in 1..=k {
                    next[j].chmin(dp[0][j - 1] + (pos[i] - pos[i - 1]) as i64 * x);
                }
                dp.push(next);
                dp.remove(0);
            }
            let dp = dp.pop().unwrap();
            dp.iter().enumerate().map(|(i, dp)| *dp + (k - i) as i64 * y).min().unwrap()
        };
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
// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
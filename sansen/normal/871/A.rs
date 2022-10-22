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

fn is_prime(n: u64) -> bool {
    (2u64..).take_while(|p| p * p <= n).all(|p| n % p != 0)
}

// 4, 6, 8, 9, 10, 

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let w = 100;
    let mut dp = vec![0; w + 1];
    for a in 4..=w {
        if !is_prime(a as u64) {
            for i in a..=w {
                if i == a || dp[i - a] > 0 {
                    dp[i] = std::cmp::max(dp[i - a] + 1, dp[i]);
                }
            }
        }
    }
    input! {
        q: usize,
        n: [usize; q],
    }
    for n in n {
        let way = if n <= w {
            dp[n]
        } else {
            n / 4 - (n & 1)
        };
        if way > 0 {
            writeln!(out, "{}", way).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn main() {
    run();
}
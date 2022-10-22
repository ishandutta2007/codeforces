// 
// Alice 2
// Bob ... ..
// Alice 
// 
// 
//
// T <= 10^4
// N <= 5*10^5
// RorB
// WW 
// , 
//
// R2, B2 RB or RW (?)
// RB 
// RB R, B
// AliceRB
// R >= B Alice
// Bob..
// R <= B Bob
//
// R != B 
// R=B 
// RB 
//

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn test() -> Vec<usize> {
    let n = 200;
    let mut dp = vec![0; n + 1];
    for i in 2..=n {
        let mut g = vec![false; i + 1];
        for j in 2..=i {
            let x = dp[j - 2] ^ dp[i - j];
            if x <= i {
                g[x] = true;
            }
        }
        dp[i] = g.iter().position(|g| !*g).unwrap();
    }
    dp
}

fn run() {
    let memo = test();
    input! {
        t: usize,
        ask: [(usize, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (_, s) in ask {
        let ans = if solve(s, &memo) {"Alice"} else {"Bob"};
        writeln!(out, "{}", ans).ok();
    }
}

fn solve(s: Vec<u8>, memo: &[usize]) -> bool {
    let n = s.len();
    let r = s.iter().filter(|s| **s == b'R').count();
    let b = n - r;
    if r > b {
        return true;
    }
    if r < b {
        return false;
    }
    let mut xor = 0;
    let mut i = 0;
    while i + 1 < n {
        if s[i] == s[i + 1] {
            i += 1;
            continue;
        }
        let mut x = i;
        while x + 1 < n && s[x] != s[x + 1] {
            x += 1;
        }
        let mut len = x - i + 1;
        while len >= memo.len() {
            len -= 34;
        }
        xor ^= memo[len];
        i = x;
    }
    xor != 0
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
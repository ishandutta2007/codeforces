// ---------- begin next_permutation ----------
fn next_permutation<T: Ord>(a: &mut [T]) -> bool {
    a.windows(2).rposition(|a| a[0] < a[1]).map_or(false, |x| {
        let y = a.iter().rposition(|b| a[x] < *b).unwrap();
        a.swap(x, y);
        a[(x + 1)..].reverse();
        true
    })
}
// ---------- end next_permutation ----------
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

fn run() {
    input! {
        n: usize,
        q: usize,
        s: bytes,
        ask: [(usize1, usize); q],
    }
    let mut op = "abc".bytes().collect::<Vec<_>>();
    let mut table = vec![];
    while {
        let mut dp = vec![0; n + 1];
        for ((dp, s), op) in dp.iter_mut().zip(&s).zip(op.iter().cycle()) {
            if *s != *op {
                *dp = 1;
            }
        }
        for i in (0..n).rev() {
            dp[i] += dp[i + 1];
        }
        table.push(dp);
        next_permutation(&mut op)
    } {}
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r) in ask {
        let ans = table.iter().map(|dp| dp[l] - dp[r]).min().unwrap();
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
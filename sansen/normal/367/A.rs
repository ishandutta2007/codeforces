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
        s: bytes,
        q: usize,
        ask: [(usize1, usize); q],
    }
    let n = s.len();
    let mut cnt = vec![[0; 3]; n + 1];
    for (i, c) in s.iter().enumerate().rev() {
        cnt[i] = cnt[i + 1];
        cnt[i][(*c - b'x') as usize] += 1;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r) in ask {
        let mut a = cnt[l];
        for i in 0..3 {
            a[i] -= cnt[r][i];
        }
        a.sort();
        if r - l >= 3 && a[2] - a[0] > 1 {
            writeln!(out, "NO").ok();
        } else {
            writeln!(out, "YES").ok();
        }
    }
}

fn main() {
    run();
}
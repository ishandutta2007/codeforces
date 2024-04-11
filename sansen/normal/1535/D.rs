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
        k: usize,
        s: bytes,
        q: usize,
        ask: [(usize, bytes); q],
    }
    let size = 1 << k;
    let mut s = s;
    s.reverse();
    s.insert(0, 0);
    let mut seg = vec![1; 2 * size];
    for (x, s) in s.iter().enumerate().rev() {
        let mut cnt = 0;
        if *s == b'?' {
            cnt += seg[2 * x] + seg[2 * x + 1];
        } else if *s == b'0' {
            cnt += seg[2 * x + 1];
        } else {
            cnt += seg[2 * x];
        }
        seg[x] = cnt;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (pos, op) in ask {
        let mut x = size - 1 - (pos - 1);
        s[x] = op[0];
        while x >= 1 {
            let mut cnt = 0;
            if s[x] == b'?' {
                cnt += seg[2 * x] + seg[2 * x + 1];
            } else if s[x] == b'0' {
                cnt += seg[2 * x + 1];
            } else {
                cnt += seg[2 * x];
            }
            seg[x] = cnt;
            x >>= 1;
        }
        writeln!(out, "{}", seg[1]).ok();
    }
}

fn main() {
    run();
}
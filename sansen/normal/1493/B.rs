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
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(i32, i32, bytes); t],
    }
    let invalid = 10;
    let trans = [0, 1, 5, invalid, invalid, 2, invalid, invalid, 8, invalid];
    for (h, m, s) in ask {
        let p = [10 * m, m, 10, 1];
        let convert = |t: i32| -> [i32; 4] {
            let mut t = (t + h * m) % (h * m);
            let mut ans = [0; 4];
            for (ans, p) in ans.iter_mut().zip(p.iter()) {
                *ans = t / *p;
                t %= *p;
            }
            ans
        };
        let valid = |t: i32| -> bool {
            let a = convert(t);
            let mut b = [0; 10];
            for (b, a) in b.iter_mut().zip(a.iter()) {
                *b = trans[*a as usize];
                if *b == invalid {
                    return false;
                }
            }
            let x = b[3] * 10 + b[2];
            let y = b[1] * 10 + b[0];
            x < h && y < m
        };
        let mut s = s;
        s.iter_mut().for_each(|c| *c -= b'0');
        let t = (s[0] as i32 * 10 + s[1] as i32) * m + (s[3] as i32 * 10 + s[4] as i32);
        let x = (t..).find(|t| valid(*t)).unwrap();
        let p = convert(x);
        writeln!(out, "{}{}:{}{}", p[0], p[1], p[2], p[3]).ok();
    }
}

fn main() {
    run();
}
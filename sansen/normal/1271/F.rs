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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use std::io::Write;
use std::cmp::min;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [([i32; 3], [i32; 3], [i32; 7]); t],
    }
    'query: for (x, y, z) in ask {
        let mut cnt = [0; 3];
        for i in 0..7 {
            for j in 0..3 {
                if (i >> (2 - j)) & 1 == 0 {
                    cnt[j] += z[i];
                }
            }
        }
        for i in 0..3 {
            if cnt[i] > x[i] + y[i] {
                writeln!(out, "-1").ok();
                continue 'query;
            }
        }
        let mut ans: Option<Vec<i32>> = None;
        'outer: for i in 0..=z[1] {
            for j in 0..=z[2] {
                for k in 0..=z[4] {
                    let a = x[0] - i - j;
                    let b = x[1] - i - k;
                    let c = x[2] - j - k;
                    let e = y[0] - z[1] - z[2] + i + j;
                    let f = y[1] - z[1] - z[4] + i + k;
                    let g = y[2] - z[2] - z[4] + j + k;
                    let p = min(a, min(b, c));
                    let q = min(e, min(f, g));
                    if p >= 0 && q >= 0 && p + q >= z[0] {
                        let mut out = vec![0; 7];
                        out[0] = min(p, z[0]);
                        out[1] = i;
                        out[2] = j;
                        out[3] = min(z[3], a - out[0]);
                        out[4] = k;
                        out[5] = min(z[5], b - out[0]);
                        out[6] = min(z[6], c - out[0]);
                        ans = Some(out);
                        break 'outer;
                    }
                }
            }
        }
        if let Some(a) = ans {
            let mut c = vec![0; 3];
            for i in 0..7 {
                for j in 0..3 {
                    if (i >> (2 - j)) & 1 == 0 {
                        c[j] += a[i];
                    }
                }
            }
            for i in 0..3 {
                assert!(c[i] <= x[i] && cnt[i] - c[i] <= y[i]);
            }
            for i in 0..7 {
                if i > 0 {
                    write!(out, " ").ok();
                }
                write!(out, "{}", a[i]).ok();
            }
            writeln!(out, "").ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn main() {
    run();
}
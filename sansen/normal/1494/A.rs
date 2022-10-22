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
        s: [bytes; t],
    }
    for s in s {
        let mut cnt = [0; 3];
        for c in s.iter() {
            let k = (*c - b'A') as usize;
            cnt[k] += 1;
        }
        let m = s.len() / 2;
        let mut ok = false;
        for i in 0..3 {
            if cnt[i] == m {
                for &v in [1, -1].iter() {
                    let mut sum = 0;
                    let mut valid = true;
                    for c in s.iter() {
                        let k = (*c - b'A') as usize;
                        if k == i {
                            sum += v;
                        } else {
                            sum -= v;
                        }
                        valid &= sum >= 0;
                    }
                    valid &= sum == 0;
                    ok |= valid;
                }
            }
        }
        let ans = if ok {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
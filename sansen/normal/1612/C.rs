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
        t: usize,
        ask: [(u64, u64); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (k, x) in ask {
        let mut ans = 0;
        if k * k <= x {
            ans = 2 * k - 1;
        } else if (k - 1) * k / 2 < x {
            ans += k - 1;
            let x = x - (k - 1) * k / 2;
            let mut ok = 0;
            let mut ng = k;
            while ng - ok > 1 {
                let m = (ok + ng) / 2;
                if (k + k - m + 1) * m / 2 < x {
                    ok = m;
                } else {
                    ng = m;
                }
            }
            ans += ng;
        } else {
            let mut ok = 0;
            let mut ng = k;
            while ng - ok > 1 {
                let m = (ok + ng) / 2;
                if m * (m + 1) / 2 < x {
                    ok = m;
                } else {
                    ng = m;
                }
            }
            ans = ng;
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
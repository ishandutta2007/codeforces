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
        n: usize,
        q: usize,
        a: [usize; n],
        x: [usize1; q],
    }
    let m = 500000;
    let mut f = (0..=m).collect::<Vec<_>>();
    let mut mobius = vec![1i64; m + 1];
    for i in 2..=m {
        if i == f[i] {
            for j in 1..=(m / i) {
                mobius[j * i] *= -1;
                f[j * i] = i;
            }
        }
    }
    let mut elem = vec![false; n];
    let mut dp = vec![0; m + 1];
    let mut ans = 0i64;
    for x in x {
        let sign = if elem[x] {
            -1
        } else {
            1
        };
        elem[x] ^= true;
        let mut p = vec![1];
        let mut x = a[x];
        while x > 1 {
            let q = f[x];
            while x % q == 0 {
                x /= q;
            }
            let len = p.len();
            for i in 0..len {
                let v = p[i] * q;
                p.push(v);
            }
        }
        for p in p {
            if sign < 0 {
                dp[p] += sign;
                ans += sign * mobius[p] * dp[p];
            } else {
                ans += sign * mobius[p] * dp[p];
                dp[p] += sign;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
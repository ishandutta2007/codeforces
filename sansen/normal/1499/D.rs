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
    let m = 20_000_000;
    let mut f = (0..=m).collect::<Vec<_>>();
    for i in (2..).take_while(|p| p * p <= m) {
        if i == f[i] {
            for j in i..=(m / i) {
                f[j * i] = i;
            }
        }
    }
    let enumerate = |mut x: usize| -> Vec<usize> {
        let mut res = vec![1];
        while x > 1 {
            let p = f[x];
            let mut cnt = 0;
            while x % p == 0 {
                x /= p;
                cnt += 1;
            }
            let len = res.len();
            let mut mul = 1;
            for _ in 0..cnt {
                mul *= p;
                for i in 0..len {
                    let v = res[i] * mul;
                    res.push(v);
                }
            }
        }
        res
    };
    let func = |mut x: usize| -> usize {
        let mut ans = 1;
        while x > 1 {
            ans *= 2;
            let p = f[x];
            while x % p == 0 {
                x /= p;
            }
        }
        ans
    };
    input! {
        t: usize,
        ask: [(usize, usize, usize); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (c, d, x) in ask {
        let mut ans = 0;
        for x in enumerate(x) {
            if (x + d) % c != 0 {
                continue;
            }
            ans += func((x + d) / c);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
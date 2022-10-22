// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u32, b: u32) -> u32 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
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

fn run() {
    input! {
        t: usize,
        ask: [(u32, u32, u32); t],
    }
    use std::io::*;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (a, b, k) in ask {
        let ans = if k == 1 {
            if a == b {
                "NO"
            } else {
                let g = binary_gcd(a, b);
                if a == g || b == g {
                    "YES"
                } else {
                    "NO"
                }
            }
        } else {
            let mut cnt = 0;
            for a in [a, b].iter() {
                let mut x = *a;
                for p in 2.. {
                    if p * p > x {
                        break;
                    }
                    while x % p == 0 {
                        x /= p;
                        cnt += 1;
                    }
                }
                if x > 1 {
                    cnt += 1;
                }
            }
            if cnt >= k {
                "YES"
            } else {
                "NO"
            }
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
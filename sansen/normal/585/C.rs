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

fn gcd(a: u128, b: u128) -> u128 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    input! {
        x: u128,
        y: u128,
    }
    if gcd(x, y) > 1 {
        println!("Impossible");
        return;
    }
    // a / b < c / d
    let small = |a, b, c, d| a * d < b * c;
    // a / b > c / d
    let large = |a, b, c, d| a * d > b * c;
    let mut l = (0, 1);
    let mut r = (1, 0);
    let mut ans = vec![];
    while l.0 + r.0 < x || l.1 + r.1 < y {
        let (p, q) = (l.0 + r.0, l.1 + r.1);
        if small(p, q, x, y) {
            let mut ok = 1;
            let mut ng = 2;
            while small(l.0 + ng * r.0, l.1 + ng * r.1, x, y) {
                ok = ng;
                ng *= 2;
            }
            while ng - ok > 1 {
                let mid = (ok + ng) / 2;
                if small(l.0 + mid * r.0, l.1 + mid * r.1, x, y) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            ans.push((ok, 'A'));
            l = (l.0 + ok * r.0, l.1 + ok * r.1);
        } else {
            let mut ok = 1;
            let mut ng = 2;
            while large(ng * l.0 + r.0, ng * l.1 + r.1, x, y) {
                ok = ng;
                ng *= 2;
            }
            while ng - ok > 1 {
                let mid = (ok + ng) / 2;
                if large(mid * l.0 + r.0, mid * l.1 + r.1, x, y) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            ans.push((ok, 'B'));
            r = (ok * l.0 + r.0, ok * l.1 + r.1);
        }
    }
    let mut s = String::new();
    for (c, op) in ans {
        s.push_str(&format!("{}{}", c, op));
    }
    println!("{}", s);
}

fn main() {
    run();
}
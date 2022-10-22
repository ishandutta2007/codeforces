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

// n, m
// ans = n.pow(2) - (n / m).pow(2)
// m^2 - 1 <= 10^9
// 1 <= m <= sqrt(10^9 + 1)

fn run() {
    input! {
        t: usize,
        x: [i64; t],
    }
    for x in x {
        let ans = || -> (i64, i64) {
            if x == 0 {
                return (1, 1);
            }
            for m in (2..).take_while(|m| m * m - 1 <= x) {
                let count = |n: i64| n.pow(2) - (n / m).pow(2);
                let mut ng = m - 1;
                let mut ok = 2 * ng;
                while count(ok) < x {
                    ng = ok;
                    ok *= 2;
                }
                while ok - ng > 1 {
                    let mid = (ok + ng) / 2;
                    if count(mid) >= x {
                        ok = mid;
                    } else {
                        ng = mid;
                    }
                }
                if count(ok) == x {
                    return (ok, m);
                }
            }
            (-1, -1)
        }();
        if ans.0 == -1 {
            println!("-1");
        } else {
            println!("{} {}", ans.0, ans.1);
        }
    }
}

fn main() {
    run();
}
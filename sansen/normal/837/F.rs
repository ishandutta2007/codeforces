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
        n: usize,
        k: u64,
        a: [u64; n],
    }
    let mut a = a;
    let x = a.iter().position(|a| *a != 0).unwrap();
    a.rotate_left(x);
    a.truncate(n - x);
    let ans = if a.iter().any(|a| *a >= k) {
        0
    } else if a.len() <= 4 {
        let valid = |m: u64| -> bool {
            let mut mul = 1;
            let mut sum = 0;
            for (i, a) in a.iter().rev().enumerate() {
                sum += *a * mul;
                mul = mul * (m + i as u64) / (i + 1) as u64;
            }
            sum >= k
        };
        let mut ng = 0;
        let mut ok = 1;
        while !valid(ok) {
            ng = ok;
            ok *= 2;
        }
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            if valid(mid) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ok
    } else {
        let mut ans = 0;
        let n = a.len();
        while a[n - 1] < k {
            for i in 1..n {
                a[i] += a[i - 1];
            }
            ans += 1;
        }
        ans
    };
    println!("{}", ans);
}

fn main() {
    run();
}
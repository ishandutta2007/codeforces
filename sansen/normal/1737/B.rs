use std::io::Write;

fn run() {
    input! {
        t: usize,
        ask: [(u64, u64); t],
    }
    let calc = |n: u64| -> u64 {
        if n == 0 {
            return 0;
        }
        let k = kth_root(n, 2);
        let mut ans = 3 * (k - 1);
        for i in 0..3 {
            if k * (k + i) <= n {
                ans += 1;
            }
        }
        ans
    };
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r) in ask {
        let ans = calc(r) - calc(l - 1);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
// floor(a ^ (1 / k))
pub fn kth_root(a: u64, k: u64) -> u64 {
    assert!(k > 0);
    if a == 0 {
        return 0;
    }
    if k >= 64 {
        return 1;
    }
    if k == 1 {
        return a;
    }
    let valid = |x: u64| -> bool {
        let mut t = x;
        for _ in 1..k {
            let (val, ok) = t.overflowing_mul(x);
            if !(!ok && val <= a) {
                return false;
            }
            t = val;
        }
        true
    };
    let mut ok = 1;
    let mut ng = 2;
    while valid(ng) {
        ok = ng;
        ng *= 2;
    }
    while ng - ok > 1 {
        let mid = ok + (ng - ok) / 2;
        if valid(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ok
}
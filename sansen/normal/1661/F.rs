fn run() {
    input! {
        n: usize,
        a: [i64; n],
        m: i64,
    }
    let mut a = a;
    a.insert(0, 0);
    let d = a.windows(2).map(|a| a[1] - a[0]).collect::<Vec<_>>();
    // 
    let cost = |d: i64, k: i64| -> i64 {
        assert!(1 <= k && k <= d);
        let q = d / k;
        let r = d % k;
        (q + 1).pow(2) * r + q.pow(2) * (k - r)
    };
    // 
    let diff = |d: i64, k: i64| -> i64 {
        assert!(1 <= k);
        if k >= d {
            return 0;
        }
        cost(d, k) - cost(d, k + 1)
    };
    // diff >= delta 
    let eval = |delta: i64| -> (i64, i64) {
        let mut sum = 0;
        let mut cnt = 0;
        for &d in d.iter() {
            let mut ok = d;
            let mut ng = 0;
            while ok - ng > 1 {
                let mid = (ok + ng) / 2;
                if diff(d, mid) < delta {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            sum += cost(d, ok);
            cnt += ok - 1;
        }
        (sum, cnt)
    };
    let mut ok = 1;
    let mut ng = 10i64.pow(18);
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        if eval(mid).0 <= m {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let (s, c) = eval(ok);
    let ans = c - (m - s) / ok;
    println!("{}", ans);
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
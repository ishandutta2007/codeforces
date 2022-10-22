//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

fn count_pre(m: u64, n: u64) -> u64 {
    let mut ans = 0;
    let mut k = 0;
    while (m << k) <= n {
        if (m << k) + (1 << k) - 1 <= n {
            ans += 1 << k;
        } else {
            ans += n - (m << k) + 1;
        }
        k += 1;
    }
    ans
}

fn count(m: u64, n: u64) -> u64 {
    if m % 2 == 1 {
        count_pre(m, n)
    } else {
        count_pre(m, n) + count_pre(m + 1, n)
    }
}

fn run() {
    input! {
        n: u64,
        k: u64,
    }
    let mut ans = 1;
    let mut ok = 0;
    let mut ng = n / 2 + 1;
    while ng - ok > 1 {
        let m = (ok + ng) / 2;
        if count(2 * m + 1, n) >= k {
            ok = m;
        } else {
            ng = m;
        }
    }
    ans = std::cmp::max(ans, 2 * ok + 1);
    if count(2, n) >= k {
        let mut ok = 1;
        let mut ng = n / 2 + 1;
        while ng - ok > 1 {
            let m = (ok + ng) / 2;
            if count(2 * m, n) >= k {
                ok = m;
            } else {
                ng = m;
            }
        }
        ans = std::cmp::max(ans, 2 * ok);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
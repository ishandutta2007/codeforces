fn run() {
    input! {
        n: i32,
        k: i32,
        l: usize,
        s: bytes,
    }
    let mut ans = n;
    let mut s = s
        .into_iter()
        .map(|s| s.is_ascii_uppercase())
        .collect::<Vec<_>>();
    for _ in 0..2 {
        let mut cnt = vec![0; s.len() + 1];
        for (i, c) in s.iter().enumerate().rev() {
            cnt[i] = cnt[i + 1];
            if *c {
                cnt[i] += 1;
            }
        }
        let mut dp = vec![(0, 0); s.len() + 1];
        let mut calc = |m: i32| -> (i32, i32) {
            dp.fill((0, 0));
            for i in (0..s.len()).rev() {
                dp[i] = dp[i + 1];
                if i + l <= s.len() {
                    let p = dp[i + l];
                    dp[i] = dp[i].max((p.0 + cnt[i] - cnt[i + l] - m, p.1 + 1));
                }
            }
            dp[0]
        };
        let mut ok = 0;
        let mut ng = l as i32 + 1;
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            if calc(mid).1 >= k {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans = ans.min(cnt[0] - calc(ok).0 - ok * k);
        s.iter_mut().for_each(|s| *s ^= true);
    }
    if k as usize * l >= s.len() {
        ans = 0;
    }
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
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
        s: bytes,
    }
    if &s == &[b'_'] {
        println!("1");
        return;
    }
    let mut x = 1;
    if s.contains(&b'X') {
        x = 10;
    }
    let mut ans = 0u64;
    for v in 0..x {
        let mut s = s.clone();
        s.iter_mut().for_each(|s| {
            if *s == b'X' {
                *s = b'0' + v as u8;
            }
        });
        if s[0] == b'0' && s.len() > 1 {
            continue;
        }
        let mut dp = [0; 25];
        dp[0] = 1;
        for (i, s) in s.iter().enumerate() {
            if *s == b'_' {
                let mut s = 0;
                if i == 0 {
                    s = 1;
                }
                let mut next = [0; 25];
                for d in s..10 {
                    for (i, dp) in dp.iter().enumerate() {
                        next[(i * 10 + d) % 25] += *dp;
                    }
                }
                dp = next;
            } else {
                assert!(b'0' <= *s && *s <= b'9');
                let k = (*s - b'0') as usize;
                let mut next = [0; 25];
                for d in k..(k + 1) {
                    for (i, dp) in dp.iter().enumerate() {
                        next[(i * 10 + d) % 25] += *dp;
                    }
                }
                dp = next;
            }
        }
        ans += dp[0];
    }
    println!("{}", ans);
}

fn main() {
    run();
}
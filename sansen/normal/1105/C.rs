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
        n: u64,
        l: u64,
        r: u64,
    }
    let mut cnt = [r / 3 - (l - 1) / 3; 3];
    for c in cnt[1..].iter_mut().take(((l - 1) % 3) as usize) {
        *c -= 1;
    }
    for c in cnt[1..].iter_mut().take((r % 3) as usize) {
        *c += 1;
    }
    const MOD: u64 = 1_000_000_007;
    let mut dp = [1, 0, 0];
    for _ in 0..n {
        let mut next = [0; 3];
        for (i, dp) in dp.iter().enumerate() {
            for (j, c) in cnt.iter().enumerate() {
                next[(i + j) % 3] += *c * *dp;
            }
        }
        dp = next;
        for dp in dp.iter_mut() {
            *dp %= MOD;
        }
    }
    println!("{}", dp[0]);
}

fn main() {
    run();
}
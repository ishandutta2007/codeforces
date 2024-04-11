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

fn gcd(a: u64, b: u64) -> u64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn lcm(a: u64, b: u64) -> u64 {
    if a == 0 || b == 0 {
        a + b
    } else {
        a / gcd(a, b) * b
    }
}

fn run() {
    input! {
        w: u64,
        c: [u64; 8],
    }
    let m = (1..=8).fold(0, |s, a| lcm(s, a));
    let mut ans = 0;
    let mut w = w;
    let mut c = c;
    for (i, c) in c.iter_mut().enumerate() {
        let k = (i + 1) as u64;
        let v = m / k;
        let q = *c / v;
        let d = std::cmp::min(w / m * m, q * v * k);
        ans += d;
        w -= d;
        *c -= d / k;
        if *c > v {
            *c = v;
        }
    }
    if w >= 8 * m {
        ans += c.iter().enumerate().fold(0, |s, (i, c)| s + (i + 1) as u64 * c);
    } else {
        let w = w as usize;
        let mut dp = vec![false; w + 1];
        dp[0] = true;
        for (i, &c) in c.iter().enumerate() {
            let k = i + 1;
            for _ in 0..c {
                for j in (k..=w).rev() {
                    dp[j] |= dp[j - k];
                }
            }
            println!();
        }
        ans += dp.iter().rposition(|p| *p).unwrap() as u64;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
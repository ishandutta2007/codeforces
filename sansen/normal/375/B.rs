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
        h: usize,
        w: usize,
        s: [bytes; h],
    }
    let n = h.max(w);
    let mut dp = vec![vec![0i16; n + 1]; n + 1];
    for s in s {
        let mut l = 0;
        while l < w {
            if s[l] == b'0' {
                l += 1;
            } else {
                let mut r = l;
                while r < w && s[r] == b'1' {
                    r += 1;
                }
                dp[l][l] += 1;
                dp[l][r] -= 1;
                dp[r][l] -= 1;
                dp[r][r] += 1;
                l = r;
            }
        }
    }
    let mut ans = 0u32;
    for i in 0..=n {
        for j in 0..=n {
            let mut val = dp[i][j];
            if i > 0 {
                val += dp[i - 1][j];
            }
            if j > 0 {
                val += dp[i][j - 1];
            }
            if i > 0 && j > 0 {
                val -= dp[i - 1][j - 1];
            }
            dp[i][j] = val;
            if i <= j {
                ans = ans.max(val as u32 * (j - i + 1) as u32);
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
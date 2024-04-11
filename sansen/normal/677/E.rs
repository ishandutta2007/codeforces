// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
// ---------- begin rotate ----------
// 1 2
// 3 4
// =>
// 3 1
// 4 2
fn rotate<T: Clone>(a: &[Vec<T>]) -> Vec<Vec<T>> {
    if a.is_empty() {
        return vec![];
    }
    let h = a.len();
    let w = a[0].len();
    assert!(a.iter().all(|a| a.len() == w));
    let mut b = (0..w).map(|_| Vec::with_capacity(h)).collect::<Vec<_>>();
    for a in a.iter().rev() {
        for (b, a) in b.iter_mut().zip(a.iter()) {
            b.push(a.clone());
        }
    }
    b
}
// ---------- end rotate ----------
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
        s: [bytes; n],
    }
    let mut s = s;
    let mut max = vec![vec![n; n]; n];
    for _ in 0..4 {
        for (max, s) in max.iter_mut().zip(s.iter()) {
            let mut cnt = 0;
            for (max, s) in max.iter_mut().zip(s.iter()) {
                if *s == b'0' {
                    cnt = 0;
                } else {
                    cnt += 1;
                }
                max.chmin(cnt);
            }
        }
        s = rotate(&s);
        max = rotate(&max);
    }
    let mut dp = vec![vec![[0; 2]; n]; n];
    for _ in 0..4 {
        for ((s, max), dp) in s.iter().zip(max.iter()).zip(dp.iter_mut()) {
            let mut cnt = vec![[0; 2]; n + 1];
            for i in (0..n).rev() {
                cnt[i] = cnt[i + 1];
                if s[i] >= b'2' {
                    cnt[i][(s[i] - b'2') as usize] += 1;
                }
            }
            for (i, (dp, max)) in dp.iter_mut().zip(max.iter()).enumerate() {
                let a = cnt[i];
                for (dp, (a, c)) in dp.iter_mut().zip(a.iter().zip(cnt[i + *max].iter())) {
                    *dp += *a - *c;
                }
            }
        }
        s = rotate(&s);
        max = rotate(&max);
        dp = rotate(&dp);
    }
    let mut ans = (0f64, [0; 2]);
    for (s, dp) in s.iter().zip(dp.iter()) {
        for (s, dp) in s.iter().zip(dp.iter()) {
            if *s == b'0' {
                continue;
            }
            let mut a = dp[0];
            let mut b = dp[1];
            if *s == b'2' {
                a -= 3;
            } else if *s == b'3' {
                b -= 3;
            }
            let val = a as f64 * 2f64.ln() + b as f64 * 3f64.ln();
            ans.chmax((val, [a, b]));
        }
    }
    let mut max = vec![vec![n; n]; n];
    for _ in 0..4 {
        let mut cnt = vec![vec![0; n]; n];
        for i in (0..n).rev() {
            for j in (0..n).rev() {
                let mut val = if i + 1 < n && j + 1 < n {
                    cnt[i + 1][j + 1]
                } else {
                    0
                };
                if s[i][j] == b'0' {
                    val = 0;
                } else {
                    val += 1;
                }
                cnt[i][j] = val;
                max[i][j].chmin(val);
            }
        }
        s = rotate(&s);
        max = rotate(&max);
    }
    let mut dp = vec![vec![[0; 2]; n]; n];
    for _ in 0..4 {
        let mut cnt = vec![vec![[0; 2]; n + 1]; n + 1];
        for i in (0..n).rev() {
            for j in (0..n).rev() {
                cnt[i][j] = cnt[i + 1][j + 1];
                if s[i][j] >= b'2' {
                    cnt[i][j][(s[i][j] - b'2') as usize] += 1;
                }
                if s[i][j] == b'0' {
                    continue;
                }
                let a = cnt[i][j];
                let max = max[i][j];
                for (dp, (a, c)) in dp[i][j].iter_mut().zip(a.iter().zip(cnt[i + max][j + max].iter())) {
                    *dp += *a - *c;
                }
            }
        }
        s = rotate(&s);
        max = rotate(&max);
        dp = rotate(&dp);
    }
    for (s, dp) in s.iter().zip(dp.iter()) {
        for (s, dp) in s.iter().zip(dp.iter()) {
            if *s == b'0' {
                continue;
            }
            let mut a = dp[0];
            let mut b = dp[1];
            if *s == b'2' {
                a -= 3;
            } else if *s == b'3' {
                b -= 3;
            }
            let val = a as f64 * 2f64.ln() + b as f64 * 3f64.ln();
            ans.chmax((val, [a, b]));
        }
    }
    let cnt = ans.1;
    let mut val = 1;
    const MOD: u64 = 1_000_000_007;
    if cnt == [0, 0] {
        if s.iter().flatten().all(|s| *s == b'0') {
            val = 0;
        }
    } else {
        for _ in 0..cnt[0] {
            val = 2 * val % MOD;
        }
        for _ in 0..cnt[1] {
            val = 3 * val % MOD;
        }
    }
    println!("{}", val);
}

fn main() {
    run();
}
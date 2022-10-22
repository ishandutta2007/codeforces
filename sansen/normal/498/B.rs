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
        w: usize,
        p: [(u32, usize); n],
    }
    let mut ans = 0f64;
    let mut dp = vec![0f64; w + 1];
    dp[0] = 1f64;
    for (i, &(p, t)) in p.iter().enumerate() {
        let p = p as f64 / 100f64;
        let q = 1f64 - p;
        let pow = q.powi(t as i32);
        let mut next = vec![0f64; w + 1];
        let mut sum = 0f64;
        for (j, (next, &v)) in next.iter_mut().zip(dp.iter()).enumerate() {
            *next += p * sum;
            sum *= q;
            if j >= t {
                *next += dp[j - t] * pow;
                sum -= dp[j - t] * pow;
            }
            sum += v;
        }
        ans += i as f64 * sum;
        dp = next;
    }
    ans += n as f64 * dp.iter().sum::<f64>();
    println!("{:.7}", ans);
}

fn main() {
    run();
}
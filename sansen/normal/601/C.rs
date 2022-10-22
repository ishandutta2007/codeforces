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
        m: usize,
        x: [usize; n],
    }
    if m == 1 {
        println!("1.0");
        return;
    }
    let p = 1f64 / (m - 1) as f64;
    let mut dp = vec![1f64];
    for &x in x.iter() {
        let mut next = vec![0f64; dp.len() + m + 1];
        for (i, dp) in dp.iter().enumerate() {
            let v = *dp * p;
            next[i + 1] += v;
            next[i + x] -= v;
            next[i + x + 1] += v;
            next[i + m + 1] -= v;
        }
        for i in 1..next.len() {
            next[i] += next[i - 1];
        }
        next.pop();
        dp = next;
    }
    let s = x.iter().sum::<usize>();
    let ans = 1f64 + dp[..s].iter().sum::<f64>() * (m - 1) as f64;
    println!("{:.10}", ans);
}

fn main() {
    run();
}
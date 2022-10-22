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

// 
// 1000 round % 1000 
// sum
// 0ceil, floor 

fn run() {
    input! {
        n: usize,
        a: [f64; 2 * n],
    }
    let m = 1000;
    let mut a = a.iter().map(|a| (*a * m as f64).round() as i64 % m).collect::<Vec<_>>();
    let sum = a.iter().sum::<i64>();
    let zero = a.iter().filter(|a| **a == 0).count();
    let one = 2 * n - zero;
    let mut ans = std::i64::MAX;
    for f in 0..=one {
        let c = one - f;
        let v = c.min(f);
        if c + f - 2 * v <= zero {
            ans = ans.min((sum - 1000 * c as i64).abs());
        }
    }
    println!("{}.{:<03}", ans / m, ans % m);
}

fn main() {
    run();
}
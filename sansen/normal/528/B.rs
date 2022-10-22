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
        p: [(i64, i64); n],
    }
    let mut e = vec![];
    let mut z = vec![];
    for (x, w) in p {
        e.push((x - w, x + w));
        z.push(x - w);
        z.push(x + w);
    }
    z.sort();
    z.dedup();
    e.sort_by_key(|e| e.0);
    let mut dp = vec![0; z.len() + 1];
    let mut x = z.len();
    for &(l, r) in e.iter().rev() {
        let l = z.binary_search(&l).unwrap();
        let r = z.binary_search(&r).unwrap();
        while x > l {
            x -= 1;
            dp[x] = std::cmp::max(dp[x], dp[x + 1]);
        }
        dp[l] = std::cmp::max(dp[l], dp[r] + 1);
    }
    println!("{}", dp[0]);
}

fn main() {
    run();
}
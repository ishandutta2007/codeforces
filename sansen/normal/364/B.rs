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
        d: usize,
        c: [usize; n],
    }
    let mut c = c;
    c.sort();
    let mut s = 0;
    let mut x = 0;
    while x < n && s + d >= c[x] {
        s += c[x];
        x += 1;
    }
    c.truncate(x);
    let mut dp = vec![true];
    for c in c {
        let mut next = vec![false; dp.len() + c];
        for (i, dp) in dp.iter().enumerate() {
            next[i] |= *dp;
            next[i + c] |= *dp;
        }
        dp = next;
    }
    let mut pos = 0;
    let mut ans = 0;
    while pos + 1 < dp.len() {
        if dp[pos] {
            pos += d;
            ans += 1;
        } else {
            pos -= 1;
        }
    }
    println!("{} {}", dp.len() - 1, ans);
}

fn main() {
    run();
}
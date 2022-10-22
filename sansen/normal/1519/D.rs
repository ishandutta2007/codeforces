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
        a: [i64; n],
        b: [i64; n],
    }
    let sum = a.iter().zip(b.iter()).fold(0, |s, a| s + *a.0 * *a.1);
    let mut ans = sum;
    for c in 0..n {
        let mut val = sum;
        let mut j = 1;
        while c + j < n && j <= c {
            let l = c - j;
            let r = c + j;
            val -= a[l] * b[l] + a[r] * b[r];
            val += a[l] * b[r] + a[r] * b[l];
            ans = ans.max(val);
            j += 1;
        }
    }
    for c in 1..n {
        let mut val = sum;
        let mut j = 1;
        while c + j - 1 < n && j <= c {
            let l = c - j;
            let r = c + j - 1;
            val -= a[l] * b[l] + a[r] * b[r];
            val += a[l] * b[r] + a[r] * b[l];
            ans = ans.max(val);
            j += 1;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
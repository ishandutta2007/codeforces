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

use std::cmp::*;

fn run() {
    input! {
        a: u64,
        b: u64,
    }
    let mut m = 1;
    while m * (m + 1) / 2 <= a + b {
        m += 1;
    }
    m -= 1;
    let mut x = vec![];
    let mut y = vec![];
    let mut a = a;
    let mut b = b;
    for k in (1..=m).rev() {
        if k <= min(a, b) {
            if a <= b {
                a -= k;
                x.push(k);
            } else {
                b -= k;
                y.push(k);
            }
        } else {
            if k <= a {
                a -= k;
                x.push(k);
            } else if k <= b {
                b -= k;
                y.push(k);
            }
        }
    }
    let mut s = String::new();
    for x in [x, y].iter() {
        s.push_str(&format!("{}\n", x.len()));
        for &a in x.iter() {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        s.push('\n');
    }
    print!("{}", s);
}

fn main() {
    run();
}
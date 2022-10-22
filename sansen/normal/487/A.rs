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
        yang: (i64, i64, i64),
        mons: (i64, i64, i64),
        h: i64,
        a: i64,
        d: i64,
    }
    let win = |h: i64, a: i64, b: i64| -> bool {
        let yang = (yang.0 + h, yang.1 + a, yang.2 + b);
        let x = max(yang.1 - mons.2, 0);
        if x <= 0 {
            return false;
        }
        let y = max(mons.1 - yang.2, 0);
        if y <= 0 {
            return true;
        }
        let a = (yang.0 + y - 1) / y;
        let b = (mons.0 + x - 1) / x;
        a > b
    };
    // DEF100, ATK 100
    let mut ans = 100 * a + 100 * d;
    for i in 0..=21000 {
        if i * h > ans {
            break;
        }
        for j in 0..=200 {
            if j * a > ans - i * h {
                break;
            }
            for k in 0..=200 {
                if win(i, j, k) {
                    ans = min(ans, i * h + j * a + k * d);
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
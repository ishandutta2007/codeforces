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
        l: i64,
        x: i64,
        y: i64,
        a: [i64; n],
    }
    let can = |v: i64| -> Option<usize> {
        assert!(v > 0);
        let mut r = 0;
        for (i, &x) in a.iter().enumerate() {
            while r < a.len() && a[r] - x < v {
                r += 1;
            }
            if r < a.len() && a[r] - x == v {
                return Some(i);
            }
        }
        None
    };
    let p = can(x);
    let q = can(y);
    if p.is_some() && q.is_some() {
        println!("0");
    } else if p.is_some() {
        println!("1\n{}", y);
    } else if q.is_some() {
        println!("1\n{}", x);
    } else if let Some(k) = can(x + y) {
        println!("1\n{}", a[k] + x);
    } else {
        let v = y - x;
        let mut r = 0;
        for (i, &s) in a.iter().enumerate() {
            while r < n && a[r] - s < v {
                r += 1;
            }
            if r < n && a[r] - s == v {
                if s + y <= l {
                    println!("1\n{}", s + y);
                    return;
                } else if s - x >= 0 {
                    println!("1\n{}", s - x);
                    return;
                }
            }
        }
        println!("2\n{} {}", x, y);
    }
}

fn main() {
    run();
}
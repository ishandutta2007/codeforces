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
        k: usize,
        x: i64,
        a: [i64; n],
    }
    let mut k = k;
    let mut a = a;
    let sign = a.iter().map(|a| a.signum()).product::<i64>();
    if sign == 1 {
        let (p, _) = a.iter().enumerate().min_by_key(|p| p.1.abs()).unwrap();
        let po = &mut a[p];
        if *po < 0 {
            while k > 0 && *po <= 0 {
                *po += x;
                k -= 1;
            }
        } else {
            while k > 0 && *po >= 0 {
                *po -= x;
                k -= 1;
            }
        }
    } else if sign == 0 {
        let s = a.iter().filter(|a| **a != 0).map(|a| a.signum()).product::<i64>();
        if s > 0 {
            let p = a.iter().position(|a| *a == 0).unwrap();
            a[p] -= x;
            k -= 1;
        }
        for i in 0..n {
            if a[i] == 0 && k > 0 {
                a[i] += x;
                k -= 1;
            }
        }
    }
    let mut h = std::collections::BinaryHeap::new();
    for (i, a) in a.iter().enumerate() {
        h.push((-a.abs(), i));
    }
    for _ in 0..k {
        let (_, p) = h.pop().unwrap();
        if a[p] > 0 {
            a[p] += x;
        } else {
            a[p] -= x;
        }
        h.push((-a[p].abs(), p));
    }
    let mut s = String::new();
    for a in a {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
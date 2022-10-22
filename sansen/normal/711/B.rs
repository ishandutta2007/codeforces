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
        a: [[i64; n]; n],
    }
    if n == 1 {
        println!("1");
        return;
    }
    let mut a = a;
    let v = a
        .iter()
        .find(|a| a.iter().all(|a| *a != 0))
        .unwrap()
        .iter()
        .sum::<i64>();
    let x = a.iter().position(|a| a.iter().any(|a| *a == 0)).unwrap();
    let s = a[x].iter().sum::<i64>();
    for a in a[x].iter_mut() {
        if *a == 0 {
            *a = v - s;
        }
    }
    let mut ok = s < v;
    ok &= a.iter().all(|a| a.iter().sum::<i64>() == v);
    ok &= (0..n).all(|k| a.iter().map(|a| a[k]).sum::<i64>() == v);
    ok &= a.iter().enumerate().map(|p| p.1[p.0]).sum::<i64>() == v;
    ok &= a.iter().enumerate().map(|p| p.1[n - 1 - p.0]).sum::<i64>() == v;
    if ok {
        println!("{}", v - s);
    } else {
        println!("-1");
    }
}

fn main() {
    run();
}
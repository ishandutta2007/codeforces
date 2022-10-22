//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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

//

// T = (sum xt) / (sum x)
// sum (xt - xT) = 0
// sum (t - T)x = 0
// 

fn run() {
    input! {
        n: usize,
        t: i64,
        a: [i64; n],
        b: [i64; n],
    }
    let mut p = vec![];
    for (&a, &b) in a.iter().zip(b.iter()) {
        p.push((b - t, a));
    }
    p.sort_by(|a, b| a.0.cmp(&b.0));
    let mut v = p.iter().fold(0, |s, p| s + p.1);
    let mut tv = p.iter().fold(0, |s, p| s + p.0 * p.1);
    let mut i = 0;
    let mut j = n;
    while i < j && tv != 0 {
        let (b, a) = if tv < 0 {
            i += 1;
            p[i - 1]
        } else {
            j -= 1;
            p[j]
        };
        if tv.signum() != (tv - a * b).signum() {
            let x = (tv as f64) / (b as f64);
            let ans = v as f64 - x;
            println!("{:.7}", ans);
            return;
        } else {
            tv -= a * b;
            v -= a;
        }
    }
    println!("{}", v);
}

fn main() {
    run();
}
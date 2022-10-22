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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        a: [i64; n],
    }
    let mut b = vec![0; n];
    let mut sum = 0;
    for i in 0..n {
        b[i] = a[i] / 2;
        sum += b[i];
    }
    if sum < 0 {
        for i in 0..n {
            if sum < 0 && a[i] > 0 && a[i] % 2 != 0 {
                b[i] += 1;
                sum += 1;
            }
        }
    } else if sum > 0 {
        for i in 0..n {
            if sum > 0 && a[i] < 0 && a[i] % 2 != 0 {
                b[i] -= 1;
                sum -= 1;
            }
        }
    }
    assert!(sum == 0);
    for i in 0..n {
        writeln!(out, "{}", b[i]).ok();
    }
}

fn main() {
    run();
}
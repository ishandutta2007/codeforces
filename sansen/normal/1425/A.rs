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

use std::io::Write;

fn run() {
    /*
    let w = 100;
    let mut dp = vec![0; w + 1];
    for i in 1..=w {
        if i & 1 == 1 {
            dp[i] = 1 + (i - 1) - dp[i - 1];
        } else {
            dp[i] = std::cmp::max(1 + (i - 1) - dp[i - 1], i / 2 + i / 2 - dp[i / 2]);
        }
        let mut p = i;
        let mut val = 0;
        let mut add = true;
        while p > 0 {
            let v = if p & 1 == 1 {
                1
            } else if p % 4 == 2 || p == 4 {
                p / 2
            } else {
                1
            };
            if add {
                val += v;
            }
            p -= v;
            add ^= true;
        }
        println!("{}: {} {}", i, dp[i], val);
    }
    */
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        a: [u64; t],
    }
    for n in a {
        let mut p = n;
        let mut val = 0;
        let mut add = true;
        while p > 0 {
            let v = if p & 1 == 1 {
                1
            } else if p % 4 == 2 || p == 4 {
                p / 2
            } else {
                1
            };
            if add {
                val += v;
            }
            p -= v;
            add ^= true;
        }
        writeln!(out, "{}", val).ok();
    }
}

fn main() {
    run();
}
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
        t: usize,
        ask: [(u64, u64, u64); t],
    }
    for (h, c, t) in ask {
        if 2 * t <= h + c {
            writeln!(out, "2").ok();
            continue;
        }
        let func = |k: u64| -> (u64, u64) {
            assert!(k > 0);
            let a = k * h + (k - 1) * c;
            let b = 2 * k - 1;
            (a, b)
        };
        let x = (t - c) / (2 * t - h - c);
        let (a, b) = func(x);
        let a = a - b * t;
        let (c, d) = func(x + 1);
        let c = t * d - c;
        let ans = if a * d <= c * b {
            x
        } else {
            x + 1
        };
        writeln!(out, "{}", 2 * ans - 1).ok();
    }
}

fn main() {
    run();
}
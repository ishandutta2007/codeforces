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
        q: usize,
        p: [(u64, u64, u64); q],
    }
    for (a, b, m) in p {
        if b < a {
            writeln!(out, "-1").ok();
            continue;
        }
        if a == b {
            writeln!(out, "1 {}", a).ok();
            continue;
        }
        let mut k = 1;
        let mut bit = 0;
        while k * a + k * m < b {
            k *= 2;
            bit += 1;
        }
        if k * a + k > b {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut r = vec![1; bit + 1];
        let mut rem = b - k * a - k;
        k = std::cmp::max(k / 2, 1);
        for i in 0..=bit {
            let v = std::cmp::min(m - 1, rem / k);
            r[i] += v;
            rem -= k * v;
            k = std::cmp::max(k / 2, 1);
        }
        assert!(rem == 0);
        let mut p = vec![];
        p.push(a);
        for i in 0..=bit {
            let sum = p.iter().fold(0, |s, p| s + *p);
            p.push(sum + r[i]);
        }
        assert!(*p.last().unwrap() == b);
        let mut s = String::new();
        s.push_str(&p.len().to_string());
        for v in p {
            s.push(' ');
            s.push_str(&v.to_string());
        }
        writeln!(out, "{}", s).ok();
    }
}

fn main() {
    run();
}
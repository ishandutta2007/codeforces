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

fn gcd(a: u64, b: u64) -> u64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        p: [(u64, u64); t],
    }
    for (a, m) in p {
        let g = gcd(a, m);
        let m = m / g;
        let mut n = m;
        let mut f = vec![1];
        for k in 2.. {
            if k * k > n {
                break;
            }
            if n % k == 0 {
                for i in 0..f.len() {
                    let v = f[i] * k;
                    f.push(v);
                }
                while n % k == 0 {
                    n /= k;
                }
            }
        }
        if n > 1 {
            for i in 0..f.len() {
                let v = f[i] * n;
                f.push(v);
            }
        }
        let mut ans = 0;
        for (i, &d) in f.iter().enumerate() {
            if i.count_ones() % 2 == 0 {
                ans += m / d;
            } else {
                ans -= m / d;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
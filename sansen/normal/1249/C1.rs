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
        a: [u64; q],
    }
    for a in a {
        let mut n = a;
        let mut d = vec![];
        while n > 0 {
            d.push(n % 3);
            n /= 3;
        }
        d.push(0);
        for i in (0..d.len()).rev() {
            if d[i] == 2 {
                let mut j = i;
                while d[j] == 2 {
                    d[j + 1] += 1;
                    d[j] = 0;
                    j += 1;
                }
                for k in 0..j {
                    d[k] = 0;
                }
                break;
            }
        }
        let mut ans = 0;
        for &d in d.iter().rev() {
            ans = 3 * ans + d;
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
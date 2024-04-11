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
        s: [chars; t],
    }
    for s in s {
        let s: Vec<usize> = s
            .into_iter()
            .map(|c| c.to_digit(10).unwrap() as usize)
            .collect();
        let n = s.len();
        let mut right = vec![n; n + 1];
        for i in (0..n).rev() {
            if s[i] == 1 {
                right[i] = i;
            } else {
                right[i] = right[i + 1];
            }
        }
        let mut ans = 0;
        for l in 0..n {
            let mut r = right[l];
            if r >= n {
                break;
            }
            let mut val = 1;
            while val <= n {
                if r - l + 1 == val {
                    ans += 1;
                }
                if r >= n - 1 {
                    break;
                }
                r += 1;
                val = 2 * val + s[r];
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
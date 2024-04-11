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
use std::ops::Bound::*;

fn run() {
    input! {
        t: usize,
        ask: [(usize, usize, chars); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, k, s) in ask {
        let mut set: std::collections::BTreeSet<usize> = (0..n).collect();
        for (i, c) in s.iter().enumerate() {
            if *c == '1' {
                let l = if i >= k {
                    i - k
                } else {
                    0
                };
                let mut a = vec![];
                for &v in set.range((Included(&l), Included(&(i + k)))) {
                    a.push(v);
                }
                for v in a {
                    set.remove(&v);
                }
            }
        }
        let mut ans = 0;
        while set.len() > 0 {
            let v = *set.iter().next().unwrap();
            ans += 1;
            let mut a = vec![];
            for &x in set.range((Included(&v), Included(&(v + k)))) {
                a.push(x);
            }
            for a in a {
                set.remove(&a);
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
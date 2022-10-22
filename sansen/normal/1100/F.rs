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
    input! {
        n: usize,
        c: [u32; n],
        q: usize,
        p: [(usize1, usize); q],
    }
    let mut ask = vec![vec![]; n];
    for (i, (l, r)) in p.into_iter().enumerate() {
        ask[l].push((r, i));
    }
    let mut index = vec![n; 20];
    let mut base = vec![0; 20];
    let mut ans = vec![0; q];
    for (i, (c, ask)) in c.iter().zip(ask.iter()).enumerate().rev() {
        let mut k = i;
        let mut v = *c;
        for (j, (base, index)) in base.iter_mut().zip(index.iter_mut()).enumerate().rev() {
            if v >> j & 1 == 0 {
                continue;
            }
            if *index == n {
                *index = k;
                *base = v;
                break;
            }
            if k < *index {
                std::mem::swap(&mut v, base);
                std::mem::swap(&mut k, index);
            }
            v ^= *base;
        }
        for &(r, k) in ask.iter() {
            let mut val = 0;
            for (base, _) in base.iter().zip(index.iter()).rev().filter(|p| *p.1 < r) {
                val = val.max(val ^ *base);
            }
            ans[k] = val;
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
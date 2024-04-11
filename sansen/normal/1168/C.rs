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
        q: usize,
        a: [usize; n],
        p: [(usize1, usize1); q],
    }
    const F: usize = 19;
    let mut memo = vec![vec![n; n + 1]; F];
    let mut next = vec![n; F];
    for i in (0..n).rev() {
        for j in 0..F {
            if (a[i] >> j) & 1 == 0 {
                continue;
            }
            memo[j][i] = i;
            for k in 0..F {
                memo[k][i] = std::cmp::min(memo[k][i], memo[k][next[j]]);
            }
        }
        for j in 0..F {
            if (a[i] >> j) & 1 == 1 {
                next[j] = i;
            }
        }
    }
    for (x, y) in p {
        let mut ans = false;
        for i in 0..F {
            if (a[y] >> i) & 1 == 1 && memo[i][x] <= y {
                ans = true;
            }
        }
        let s = if ans {"Shi"} else {"Fou"};
        writeln!(out, "{}", s).ok();
    }
}

fn main() {
    run();
}
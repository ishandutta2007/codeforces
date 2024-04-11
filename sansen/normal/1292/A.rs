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
        p: [(usize1, usize1); q],
    }
    let mut state = vec![vec![false; n]; 2];
    let mut cnt = 0i32;
    for (a, b) in p {
        if state[a][b] {
            state[a][b] = false;
            for &x in [a - 1, a + 1].iter() {
                for &y in [b - 1, b, b + 1].iter() {
                    if x < 2 && y < n && state[x][y] {
                        cnt -= 1;
                    }
                }
            }
        } else {
            for &x in [a - 1, a + 1].iter() {
                for &y in [b - 1, b, b + 1].iter() {
                    if x < 2 && y < n && state[x][y] {
                        cnt += 1;
                    }
                }
            }
            state[a][b] = true;
        }
        if cnt > 0 {
            writeln!(out, "No").ok();
        } else {
            writeln!(out, "Yes").ok();
        }
    }
}

fn main() {
    run();
}
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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
// ---------- end input macro ----------

use std::io::Write;
use std::cmp::*;

fn run() {
    input! {
        n: usize,
        p: [usize; n],
    }
    let mut ans = vec![vec![0; n]; n];
    for (i, p) in p.iter().enumerate() {
        let v = *p;
        let mut pos = (i, i);
        let mut cnt = v;
        while cnt > 0 {
            if ans[pos.0][pos.1] == 0 {
                ans[pos.0][pos.1] = v;
                cnt -= 1;
            }
            if pos.0 > pos.1 && ans[pos.0 - 1][pos.1] == 0 {
                pos.0 -= 1;
            } else if pos.1 > 0 && ans[pos.0][pos.1 - 1] == 0 {
                pos.1 -= 1;
            } else {
                pos.0 += 1;
            }
        }
    }
    let mut s = String::new();
    for (i, a) in ans.iter().enumerate() {
        for a in a.iter().take(i + 1) {
            s.push_str(&format!("{} ", *a));
        }
        s.pop();
        s.push('\n');
    }
    print!("{}", s);
}

fn main() {
    run();
}
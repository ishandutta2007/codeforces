// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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

use std::cmp::*;

// 
// 
// 
fn run() {
    input! {
        n: usize,
        a: [[i32; 5]; n],
    }
    let mut cnt = [0; 5];
    for a in a.iter() {
        for (a, c) in a.iter().zip(cnt.iter_mut()) {
            if *a >=0 {
                *c += 1;
            }
        }
    }
    let mut can = [false; 5];
    let mut diff = [0; 5];
    for i in 0..5 {
        if a[0][i] >= 0 {
            can[i] = true;
        }
        if a[1][i] >= 0 && a[0][i] >= 0 {
            diff[i] = a[1][i] - a[0][i];
        } else if a[1][i] >= 0 {
            diff[i] = -(250 - a[1][i]);
        } else if a[0][i] >= 0 {
            diff[i] = 250 - a[0][i];
        }
    }
    let point = |n: usize, k: usize| -> i32 {
        if k * 32 <= n {
            3000
        } else if k * 16 <= n {
            2500
        } else if k * 8 <= n {
            2000
        } else if k * 4 <= n {
            1500
        } else if k * 2 <= n {
            1000
        } else {
            500
        }
    };
    let w = 10000000;
    let mut score = vec![0; w + 1];
    for (diff, (can, cnt)) in diff.iter().zip(can.iter().zip(cnt.iter())) {
        for (i, score) in score.iter_mut().enumerate() {
            let mut add = point(i + n, *cnt) / 250 * *diff;
            if *can && *diff < 0 {
                add.chmax(point(i + n, i + *cnt) / 250 * *diff);
            }
            *score += add;
        }
    }
    for (i, score) in score.iter().enumerate() {
        if *score > 0 {
            println!("{}", i);
            return;
        }
    }
    println!("-1");
}

fn main() {
    run();
}
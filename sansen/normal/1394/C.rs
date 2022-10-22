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

fn run() {
    input! {
        n: usize,
        s: [bytes; n],
    }
    let mut point = vec![];
    for s in s.into_iter() {
        let a = s.iter().filter(|p| **p == b'B').count() as i32;
        let b = s.iter().filter(|p| **p == b'N').count() as i32;
        point.push((a, b));
    }
    point.sort();
    point.dedup();
    let valid = |m: i32| -> Option<(i32, i32)> {
        let mut row = (std::i32::MIN, std::i32::MAX);
        let mut col = (std::i32::MIN, std::i32::MAX);
        let mut dig = (std::i32::MIN, std::i32::MAX);
        for &(x, y) in point.iter() {
            row.0.chmax(y - m);
            row.1.chmin(y + m);
            col.0.chmax(x - m);
            col.1.chmin(x + m);
            dig.0.chmax(y - x - m);
            dig.1.chmin(y - x + m);
        }
        for &(x, y) in [(col.1, row.1), (col.1, col.1 + dig.1), (row.1 - dig.0, row.1)].iter() {
            if row.0 <= y && y <= row.1 && col.0 <= x && x <= col.1 && dig.0 <= y - x && y - x <= dig.1 {
                return Some((x, y));
            }
        }
        None
    };
    let mut ng = -1;
    let mut ok = 500_000;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        if valid(mid).is_some() {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let (a, b) = valid(ok).unwrap();
    let ans = vec!['B'; a as usize].into_iter().chain(vec!['N'; b as usize].into_iter()).collect::<String>();
    println!("{}\n{}", ok, ans);
}

fn main() {
    run();
}
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
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        t: [usize1; n],
        ask: [(usize1, usize1); m - 1],
    }
    let mut set = vec![Some(std::collections::BTreeSet::new()); m];
    for (i, t) in t.into_iter().enumerate() {
        let set = set[t].as_mut().unwrap();
        if set.is_empty() {
            set.insert((i, i + 1));
            continue;
        }
        let (l, r) = *set.iter().rev().next().unwrap();
        if r == i {
            set.remove(&(l, r));
            set.insert((l, i + 1));
        } else {
            set.insert((i, i + 1));
        }
    }
    let mut cnt = set.iter().fold(0, |s, a| s + a.as_ref().unwrap().len());
    writeln!(out, "{}", cnt - 1).ok();
    for (a, b) in ask {
        let mut x = set[a].take().unwrap();
        let mut y = set[b].take().unwrap();
        if x.len() < y.len() {
            std::mem::swap(&mut x, &mut y);
        }
        for (l, r) in y {
            let left = match x.range((Unbounded, Included(&(l, r)))).rev().next() {
                Some(&(p, q)) if q == l => {
                    x.remove(&(p, q));
                    cnt -= 1;
                    p
                },
                _ => {
                    l
                },
            };
            let right = match x.range((Included(&(l, r)), Unbounded)).next() {
                Some(&(p, q)) if p == r => {
                    x.remove(&(p, q));
                    cnt -= 1;
                    q
                },
                _ => {
                    r
                },
            };
            x.insert((left, right));
        }
        set[a] = Some(x);
        writeln!(out, "{}", cnt - 1).ok();
    }
}

fn main() {
    run();
}
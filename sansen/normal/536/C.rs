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

fn run() {
    input! {
        n: usize,
        p: [(i64, i64); n],
    }
    let mut map = std::collections::BTreeMap::new();
    for (i, &(r, s)) in p.iter().enumerate() {
        map.entry(r).or_insert(vec![]).push((s, i));
    }
    let mut res = vec![];
    for (r, a) in map {
        let max = a.iter().map(|p| p.0).max().unwrap();
        let mut b = vec![];
        for (s, k) in a {
            if s == max {
                b.push(k);
            }
        }
        res.push((r, max, b));
    }
    let mut stack: Vec<(i64, i64, Vec<usize>)> = vec![];
    for (r, s, b) in res {
        while stack.last().map_or(false, |p| p.1 <= s) {
            stack.pop();
        }
        stack.push((r, s, b));
    }
    let mut p = stack;
    let mut cht: Vec<(i64, i64, Vec<usize>)> = vec![];
    for (a, b, mut p) in p.into_iter().rev() {
        while cht.len() >= 2 {
            let a = a as i128;
            let b = b as i128;
            let len = cht.len();
            let (c, d) = (cht[len - 1].0 as i128, cht[len - 1].1 as i128);
            let (e, f) = (cht[len - 2].0 as i128, cht[len - 2].1 as i128);
            //if c * (b - d) / (d * (c - a)) < e * (b - f) / (f * (e - a)) {
            let v = (c * (b - d) * f * (e - a)).cmp(&(e * (b - f) * d * (c - a)));
            use std::cmp::Ordering::*;
            match v {
                Equal => {
                    p.append(&mut cht.pop().unwrap().2);
                },
                Greater => {
                    cht.pop();
                },
                _ => {
                    break;
                },
            }
        }
        cht.push((a, b, p));
    }
    let mut ans = cht.into_iter().map(|p| p.2).flatten().collect::<Vec<_>>();
    ans.sort();
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a + 1));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
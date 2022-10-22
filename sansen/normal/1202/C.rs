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
use std::cmp::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        s: [chars; t],
    }
    let mut map = std::collections::BTreeMap::<char, (i64, i64)>::new();
    map.insert('W', (0, 1));
    map.insert('S', (0, -1));
    map.insert('A', (-1, 0));
    map.insert('D', (1, 0));
    let map = map;
    for s in s {
        let mut pos = (0i64, 0i64);
        let mut rect = (0, 0, 0, 0);
        let mut dp = vec![((0, 0, 0, 0), (0, 0))];
        for &c in s.iter() {
            let (x, y) = *map.get(&c).unwrap();
            pos.0 += x;
            pos.1 += y;
            rect.0 = min(rect.0, pos.0);
            rect.1 = max(rect.1, pos.0);
            rect.2 = min(rect.2, pos.1);
            rect.3 = max(rect.3, pos.1);
            dp.push((rect, pos));
        }
        let mut ans = (rect.1 - rect.0 + 1) * (rect.3 - rect.2 + 1);
        let mut pos = (0i64, 0i64);
        let mut rect = (0, 0, 0, 0);
        for (i, &c) in s.iter().enumerate().rev() {
            let (x, y) = *map.get(&c).unwrap();
            pos.0 -= x;
            pos.1 -= y;
            rect.0 = min(rect.0, pos.0);
            rect.1 = max(rect.1, pos.0);
            rect.2 = min(rect.2, pos.1);
            rect.3 = max(rect.3, pos.1);
            let (pre, q) = dp[i];
            for &v in map.values() {
                let a = min(pre.0, q.0 + v.0 + rect.0 - pos.0);
                let b = max(pre.1, q.0 + v.0 + rect.1 - pos.0);
                let c = min(pre.2, q.1 + v.1 + rect.2 - pos.1);
                let d = max(pre.3, q.1 + v.1 + rect.3 - pos.1);
                ans = min(ans, (b - a + 1) * (d - c + 1));
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
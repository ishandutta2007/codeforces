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
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        k: i64,
        a: [i64; n],
    }
    let mut memo = vec![];
    for i in 0.. {
        let d = k.pow(i);
        let mut ans = 0;
        let mut sum = 0;
        let mut dp = Map::new();
        dp.insert(sum, 1);
        for &a in a.iter() {
            sum += a;
            ans += dp.get(&(sum - d)).map_or(0, |p| *p);
            *dp.entry(sum).or_insert(0) += 1;
        }
        memo.push(ans);
        if d.abs() > 10i64.pow(9 + 5) || k == 1 || (k == -1 && i == 1) {
            break;
        }
    }
    let ans = memo.iter().sum::<i64>();
    println!("{}", ans);
}

fn main() {
    run();
}
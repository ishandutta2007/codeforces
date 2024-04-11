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
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        h: i32,
        m: i32,
        s: i32,
        src: i32,
        dst: i32,
    }
    let mut block = vec![];
    if m == 0 && s == 0 {
        block.push(2 * h);
    } else {
        block.push(2 * h + 1);
    }
    if s == 0 && m % 5 == 0 {
        block.push(2 * (m / 5));
    } else {
        block.push(2 * (m / 5) + 1);
    }
    if s % 5 == 0 {
        block.push(2 * (s / 5));
    } else {
        block.push(2 * (s / 5) + 1);
    }
    block.sort();
    for i in 0..block.len() {
        let t = block[i];
        block.push(t + 24);
    }
    let mut ans = 1000;
    let (s, t) = (2 * src.min(dst), 2 * src.max(dst));
    for &(src, dst) in [(s, t), (t, s + 24)].iter() {
        if !block.iter().any(|p| src <= *p && *p <= dst) {
            ans = (dst - src).min(ans);
        }
    }
    ans /= 2;
    if ans > 12 {
        println!("NO");
    } else {
        println!("YES");
    }
}

fn main() {
    run();
}
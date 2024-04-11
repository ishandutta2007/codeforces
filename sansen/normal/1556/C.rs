// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
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
        n: usize,
        c: [i64; n],
    }
    let mut ans = 0i64;
    for i in 0..c.len() {
        if i & 1 == 1 {
            continue;
        }
        let mut h = c[i];
        let mut min = h;
        for j in (i + 1)..c.len() {
            if j & 1 == 1 {
                let (u, d) = (h - 1, h - c[j]);
                ans += 0i64.max(min.min(u) - d.max(0) + 1);
                min.chmin(d);
                h = d;
            } else {
                h += c[j];
            }
        }
    }
    println!("{}", ans);
    /*
    let mut stack: Vec<(i64, i64)> = vec![(1, 1)];
    for (i, &c) in c.iter().enumerate() {
        if i & 1 == 0 {
            stack.push((c, 1));
        } else {
            let mut c = c;
            while let Some((len, cnt)) = stack.pop() {
                if len >= c {
                    ans += cnt * c;
                    if len > c {
                        stack.push((len - c, cnt));
                    }
                    break;
                }
                ans += cnt * len;
                c -= len;
                stack.pop();
            }
            if let Some((len, cnt)) = stack.pop() {
                if len > 1 {
                    stack.push((len - 1, cnt));
                }
                stack.push((1, cnt + 1));
            }
        }
        println!("{:?} {}", stack, ans);
    }
    println!("{}", ans);
    */
}

fn main() {
    run();
}
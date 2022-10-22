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
        n: i64,
        m: i64,
        k: usize,
        p: [(i64, i64); k],
    }
    let mut add = Map::new();
    let mut sub = Map::new();
    for (i, &(x, y)) in p.iter().enumerate() {
        add.entry(x + y).or_insert(vec![]).push(i);
        sub.entry(x - y).or_insert(vec![]).push(i);
    }
    let inf = n * m * 10;
    let mut ans = vec![inf; k];
    let mut sum = 0;
    let mut pos = (0, 0);
    let mut dir = (1, 1);
    loop {
        if dir.0 == dir.1 {
            if let Some(index) = sub.remove(&(pos.0 - pos.1)) {
                for k in index {
                    let x = p[k].0;
                    ans[k].chmin(sum + (x - pos.0) / dir.0);
                }
            }
        } else {
            if let Some(index) = add.remove(&(pos.0 + pos.1)) {
                for k in index {
                    let x = p[k].0;
                    ans[k].chmin(sum + (x - pos.0) / dir.0);
                }
            }
        }
        let mut t = inf;
        if dir.0 > 0 {
            t.chmin(n - pos.0);
        } else {
            t.chmin(pos.0);
        }
        if dir.1 > 0 {
            t.chmin(m - pos.1);
        } else {
            t.chmin(pos.1);
        }
        pos.0 += dir.0 * t;
        pos.1 += dir.1 * t;
        sum += t;
        if pos.0 == n || pos.0 == 0 {
            dir.0 *= -1;
        }
        if pos.1 == m || pos.1 == 0 {
            dir.1 *= -1;
        }
        if pos == (0, 0) || pos == (n, 0) || pos == (0, m) || pos == (n, m) {
            break;
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for mut a in ans {
        if a == inf {
            a = -1;
        }
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
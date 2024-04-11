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

fn calc(len: usize, bit: usize, s: &[Vec<u8>], map: &mut Map<(usize, usize), i32>) -> i32 {
    if len == 2 * s.len() - 2 {
        return 0;
    }
    if let Some(&v) = map.get(&(len, bit)) {
        return v;
    }
    let mut next = vec![];
    let mut op = vec![];
    for i in 0..=(len + 1) {
        let j = len + 1 - i;
        if !(i < s.len() && j < s.len()) {
            continue;
        }
        if bit >> i & 1 == 1 || (i > 0 && bit >> (i - 1) & 1 == 1) {
            next.push((s[i][j], i));
            op.push(s[i][j]);
        }
    }
    next.sort();
    next.dedup();
    op.sort();
    op.dedup();
    let mut val = std::i32::MIN;
    for &c in op.iter() {
        let mut b = 0;
        for &(d, k) in next.iter() {
            if d == c {
                b |= 1 << k;
            }
        }
        let mut res = -calc(len + 1, b, s, map);
        if c == b'a' {
            if len & 1 == 1 {
                res += 1;
            } else {
                res -= 1;
            }
        }
        if c == b'b' {
            if len & 1 == 0 {
                res += 1;
            } else {
                res -= 1;
            }
        }
        val.chmax(res);
    }
    map.insert((len, bit), val);
    val
}

fn run() {
    input! {
        n: usize,
        s: [bytes; n],
    }
    let mut ans = -calc(0, 1, &s, &mut Map::new());
    if s[0][0] == b'a' {
        ans += 1;
    }
    if s[0][0] == b'b' {
        ans -= 1;
    }
    if ans > 0 {
        println!("FIRST");
    } else if ans == 0 {
        println!("DRAW");
    } else {
        println!("SECOND");
    }
}

fn main() {
    run();
}
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

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        k: usize,
        p: [(usize, usize); k],
    }
    let mut h = 1;
    while (h + 1) * (h + 2) / 2 <= 3 * k {
        h += 1;
    }
    let mut cnt = 0;
    let mut a = vec![vec![]; n];
    for (r, c) in p {
        let k = n - r + 1;
        if k <= h {
            a[c - 1].push(k - 1);
        } else {
            cnt += 1;
        }
    }
    let inf = std::usize::MAX / 2;
    let mut dp = vec![inf; h];
    dp[0] = 0;
    for mut a in a {
        a.sort();
//        println!("{:?}", a);
        let min = dp.iter().min().unwrap();
        let mut one = 0;
        let mut next = vec![inf; h];
        for i in (0..h).rev() {
            next[i].chmin(min + one + (i + 1) * (i + 2) / 2 + 2);
            if i + 1 < h {
                next[i].chmin(dp[i + 1] + one);
            }
            if a.last().map_or(false, |a| *a == i) {
                a.pop();
                one += 3;
            }
        }
        next[0].chmin(min + one);
        dp = next;
//        println!("{:?}", dp);
    }
    let ans = 3 * cnt + *dp.iter().min().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
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
        a: [usize; n],
        b: [usize; n],
    }
    let mut a = a;
    let mut b = b;
    a.insert(0, 0);
    b.insert(0, 0);
    let inf = n + 1;
    let mut dp = vec![(inf, 0, 0); n + 1];
    dp[n].0 = 0;
    let mut set = Set::new();
    for i in 0..n {
        set.insert(i);
    }
    let mut q = Deque::new();
    q.push_back(n);
    while let Some(v) = q.pop_front() {
        let dis = dp[v].0 + 1;
        let pos = set.range((v - a[v])..=v).cloned().collect::<Vec<_>>();
        for &pos in pos.iter() {
            set.remove(&pos);
            if pos == 0 {
                dp[0] = (dis, 0, v);
                break;
            } else if dp[pos + b[pos]].0 > dis {
                dp[pos + b[pos]] = (dis, pos, v);
                q.push_back(pos + b[pos]);
            }
        }
    }
    if dp[0].0 == inf {
        println!("-1");
        return;
    }
    let mut ans = vec![];
    let mut pos = 0;
    while pos < n {
        ans.push(dp[pos].1);
        pos = dp[pos].2;
    }
    ans.reverse();
    println!("{}", ans.len());
    println!("{}", ans.iter().map(|a| a.to_string()).collect::<Vec<_>>().join(" "));
}

fn main() {
    run();
}
// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
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

use std::iter::*;

fn run() {
    input! {
        t: usize,
        ask: [(usize, u8, bytes); t],
    }
    for (n, k, mut s) in ask {
        s.iter_mut().for_each(|c| *c -= b'a');
        let shift = |c: u8| c.min((c + 1) % k).min((c + k - 1) % k);
        let mut dp = vec![];
        let mut dp_pre = vec![];
        let mut ans = vec![];
        for (i, &c) in s.iter().enumerate() {
            let mut next = dp.clone();
            let mut next_pre = dp.clone();
            next.push(shift(c));
            next_pre.push(c);
            let len = dp.len();
            if i > 0 {
                next = next.min(dp[..(len - 1)].iter().cloned().chain(once(c)).chain(once(dp[len - 1])).collect());
            }
            if i > 0 {
                next = next.min(dp_pre[..(len - 1)].iter().cloned().chain(once(shift(c))).chain(once(dp_pre[len - 1])).collect());
            }
            if i > 1 {
                next = next.min(dp_pre[..(len - 2)].iter().cloned().chain(once(c)).chain(dp_pre[(len - 2)..].iter().cloned()).collect());
            }
            next = next.min(dp_pre.iter().cloned().chain(once(c)).collect());
            dp = next;
            dp_pre = next_pre;
            if i > 2 {
                ans.push(dp.remove(0));
                dp_pre.remove(0);
            }
        }
        ans.extend_from_slice(&dp);
        let s = ans.into_iter().map(|c| (b'a' + c) as char).collect::<String>();
        println!("{}", s);
    }
}

fn main() {
    run();
}
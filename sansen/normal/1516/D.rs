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

fn run() {
    input! {
        n: usize,
        q: usize,
        a: [usize; n],
        ask: [(usize1, usize); q],
    }
    let m = *a.iter().max().unwrap();
    let mut f = (0..=m).collect::<Vec<_>>();
    for i in 2..=m {
        if i == f[i] {
            for j in i..=(m / i) {
                f[j * i] = i;
            }
        }
    }
    let f = f;
    let mut index = vec![vec![]; m + 1];
    for (i, &a) in a.iter().enumerate() {
        let mut x = a;
        while x > 1 {
            let p = f[x];
            while x % p == 0 {
                x /= p;
            }
            index[p].push(i);
        }
    }
    let mut next = vec![n; n + 1];
    for index in index {
        for x in index.windows(2) {
            next[x[0]].chmin(x[1]);
        }
    }
    for i in (0..n).rev() {
        next[i] = next[i].min(next[i + 1]);
    }
    let mut memo = vec![];
    while next[0] < n {
        let mut dp = vec![n; n + 1];
        for i in 0..=n {
            dp[i] = next[next[i]];
        }
        memo.push(next);
        next = dp;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r) in ask {
        let mut ans = 1;
        let mut pos = l;
        for (i, memo) in memo.iter().enumerate().rev() {
            if memo[pos] < r {
                pos = memo[pos];
                ans += 1 << i;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
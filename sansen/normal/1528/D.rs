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

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize, usize, usize); m],
    }
    let inf = std::usize::MAX / 2;
    let mut pre = vec![vec![inf; 3 * n]; n];
    for (a, b, c) in e {
        for i in 0..3 {
            pre[a][i * n + b].chmin(c);
        }
    }
    for pre in pre.iter_mut() {
        for i in 1..(3 * n) {
            pre[i] = pre[i].min(pre[i - 1] + 1);
        }
    }
    let mut ans = String::new();
    for i in 0..n {
        let mut dp = vec![inf; n];
        dp[i] = 0;
        let mut used = vec![false; n];
        for _ in 1..n {
            let v = (0..n).filter(|u| !used[*u]).min_by_key(|p| dp[*p]).unwrap();
            used[v] = true;
            let d = dp[v];
            let s = 2 * n - d % n;
            for (dp, &c) in dp.iter_mut().zip(&pre[v][s..]) {
                dp.chmin(c + d);
            }
        }
        for d in dp {
            ans.push_str(&format!("{} ", d));
        }
        ans.pop();
        ans.push('\n');
    }
    print!("{}", ans);
}

fn main() {
    run();
}
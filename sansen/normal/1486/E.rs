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
        e: [(usize1, usize1, i64); m],
    }
    let mut g = vec![vec![]; n];
    for (a, b, c) in e {
        g[a].push((b, c));
        g[b].push((a, c));
    }
    let inf = std::i64::MAX / 3;
    let mut dp = vec![inf; n];
    let mut dp2 = vec![vec![inf; n]; 51];
    dp[0] = 0;
    let mut h = std::collections::BinaryHeap::new();
    h.push((0, 0, 0, 0));
    while let Some((d, v, k, op)) = h.pop() {
        let d = -d;
        if op == 0 {
            if d > dp[v] {
                continue;
            }
            for &(u, w) in g[v].iter() {
                if dp2[w as usize][u].chmin(d) {
                    h.push((-d, u, w, 1));
                }
            }
        } else {
            if d > dp2[k as usize][v] {
                continue;
            }
            for &(u, w) in g[v].iter() {
                let d = d + (k as i64 + w).pow(2);
                if dp[u].chmin(d) {
                    h.push((-d, u, 0, 0));
                }
            }
        }
    }
    let mut s = String::new();
    for dp in dp {
        s.push_str(&format!("{} ", if dp < inf { dp } else { -1 }));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
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
        a: bytes,
        n: usize,
        b: [bytes; n],
        cost: [i32; 10],
    }
    let m = 1001;
    let a = a.into_iter().rev().collect::<Vec<_>>();
    let mut b: Vec<Vec<usize>> = b
        .into_iter()
        .map(|b| b.into_iter().map(|b| (b - b'0') as usize).rev().collect())
        .collect();
    let len = b.iter().map(|b| b.len()).collect::<Vec<_>>();
    for b in b.iter_mut() {
        while b.len() < m {
            b.push(0);
        }
    }
    let b = b;
    let mut ord = (0..n).collect::<Vec<_>>();
    let ini = -1;
    let mut dp = vec![ini; n + 1];
    dp[n] = 0;
    for i in 0..m {
        let prev = ord.clone();
        ord.sort_by_key(|p| b[*p][i]);
        let mut to = vec![0; n];
        for (i, p) in ord.iter().enumerate() {
            to[*p] = i;
        }
        let mut next = vec![ini; n + 1];
        for c in b'0'..=b'9' {
            if i < a.len() {
                let op = a[i];
                if op != b'?' && op != c {
                    continue;
                }
                if i == a.len() - 1 && c == b'0' {
                    continue;
                }
            } else {
                if c != b'0' {
                    continue;
                }
            }
            let c = (c - b'0') as usize;
            let mut add = 0;
            let mut pos = n;
            for (j, &p) in ord.iter().enumerate().rev() {
                let v = c + b[p][i];
                if v > 0 || i < len[p].max(a.len()) {
                    add += cost[v % 10];
                }
                if v >= 10 {
                    pos.chmin(j);
                }
            }
            let mut pre = n;
            for (j, &dp) in dp.iter().enumerate().rev() {
                if dp < 0 {
                    continue;
                }
                for x in j..pre {
                    let y = prev[x];
                    let v = c + b[y][i];
                    if v > 0 || i < len[y].max(a.len()) {
                        add -= cost[v % 10];
                    }
                    add += cost[(v + 1) % 10];
                    if v + 1 == 10 {
                        pos.chmin(to[y]);
                    }
                }
                pre = j;
                next[pos].chmax(dp + add);
            }
        }
        dp = next;
    }
    println!("{}", dp[n]);
}

fn main() {
    run();
}
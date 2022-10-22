// ---------- begin rotate ----------
// 1 2
// 3 4
// =>
// 3 1
// 4 2
fn rotate<T: Clone>(a: &[Vec<T>]) -> Vec<Vec<T>> {
    if a.is_empty() {
        return vec![];
    }
    let h = a.len();
    let w = a[0].len();
    assert!(a.iter().all(|a| a.len() == w));
    let mut b = (0..w).map(|_| Vec::with_capacity(h)).collect::<Vec<_>>();
    for a in a.iter().rev() {
        for (b, a) in b.iter_mut().zip(a.iter()) {
            b.push(a.clone());
        }
    }
    b
}
// ---------- end rotate ----------
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
        h: usize,
        w: usize,
        q: usize,
        s: [[u8; w]; h],
        ask: [(u8, usize1, usize1); q],
    }
    let mut s = s;
    let mut memo = vec![];
    for _ in 0..4 {
        let h = s.len();
        let w = s[0].len();
        let mut dp = vec![vec![0; w + 1]; h];
        let mut d = vec![0; w + 1];
        for (dp, s) in dp.iter_mut().zip(s.iter()) {
            for (j, c) in s.iter().enumerate() {
                if *c == 1 {
                    d[j] += 1;
                } else {
                    d[j] = 0;
                }
                dp[j] = d[j];
            }
        }
        memo.push((s.clone(), dp));
        s = rotate(&s);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (op, x, y) in ask {
        if op == 1 {
            let mut p = (x, y);
            for (s, dp) in memo.iter_mut() {
                s[p.0][p.1] ^= 1;
                let mut d = 0;
                for (dp, s) in dp.iter_mut().zip(s.iter()) {
                    if s[p.1] == 1 {
                        d += 1;
                    } else {
                        d = 0;
                    }
                    dp[p.1] = d;
                }
                p = (p.1, s.len() - 1 - p.0);
            }
        } else {
            let mut ans = 0;
            let mut p = (x, y);
            for (s, dp) in memo.iter() {
                let mut stack: Vec<(usize, usize)> = vec![];
                for (i, d) in dp[p.0].iter().enumerate() {
                    let mut w = 0;
                    while stack.last().map_or(false, |p| p.0 >= *d) {
                        let (a, b) = stack.pop().unwrap();
                        w += b;
                        if i - w <= p.1 && p.1 < i {
                            ans = ans.max(a * w);
                        }
                    }
                    stack.push((*d, w + 1));
                }
                p = (p.1, s.len() - 1 - p.0);
            }
            writeln!(out, "{}", ans).ok();
        }
    }
}

fn main() {
    run();
}
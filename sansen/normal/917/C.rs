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
        x: usize,
        k: usize,
        n: usize,
        q: usize,
        c: [i64; k],
        p: [(usize1, i64); q],
    }
    let inf = std::i64::MAX / 10;
    let mut z = vec![];
    for i in 1usize..(1 << k) {
        if i.count_ones() == x as u32 {
            z.push(i);
        }
    }
    let size = z.len();
    let id = |b: usize| -> usize {
        z.binary_search(&b).unwrap()
    };
    let mut mat = vec![vec![inf; size]; size];
    for src in 0..size {
        if z[src] & 1 == 0 {
            let dst = id(z[src] >> 1);
            mat[src][dst].chmin(0);
            continue;
        }
        for (j, c) in c.iter().enumerate() {
            let dst = z[src] >> 1;
            if dst >> j & 1 == 0 {
                let dst = id(dst | (1 << j));
                mat[src][dst].chmin(*c);
            }
        }
    }
    let mut memo = vec![];
    for _ in 0..30 {
        memo.push(mat.clone());
        let mut next = vec![vec![inf; size]; size];
        for (c, a) in next.iter_mut().zip(&mat) {
            for (a, b) in a.iter().zip(&mat) {
                for (c, b) in c.iter_mut().zip(b) {
                    c.chmin(*a + *b);
                }
            }
        }
        mat = next;
    }
    let mut q = vec![];
    let mut add = 0;
    for (a, b) in p {
        if n - x <= a {
            add += b;
        } else {
            q.push((a, b));
        }
    }
    q.push((0, 0));
    q.push((n - x, 0));
    q.sort();
    let mut dp = vec![inf; size];
    dp[id((1 << x) - 1)] = 0;
    for p in q.windows(2) {
        let step = p[1].0 - p[0].0;
        for (i, mat) in memo.iter().enumerate().rev() {
            if step >> i & 1 == 1 {
                let mut next = vec![inf; size];
                for (dp, mat) in dp.iter().zip(mat) {
                    for (next, mat) in next.iter_mut().zip(mat) {
                        next.chmin(*dp + *mat);
                    }
                }
                dp = next;
            }
        }
        for (i, dp) in dp.iter_mut().enumerate() {
            if z[i] & 1 == 1 {
                *dp += p[1].1;
            }
        }
    }
    let ans = dp[id((1 << x) - 1)] + add;
    println!("{}", ans);
}

fn main() {
    run();
}
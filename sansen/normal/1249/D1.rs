// 1-indexedBIT
// x[1,x], ([1,x])>=s x
// ---------- begin fenwick tree ----------
#[allow(dead_code)]
mod fenwick {
    type T = i32;
    const ZERO: T = 0;
    pub struct Tree {
        a: Vec<T>,
    }
    impl Tree {
        pub fn new(n: usize) -> Tree {
            Tree {
                a: vec![ZERO; n + 1],
            }
        }
        pub fn add(&mut self, mut x: usize, v: T) {
            while x < self.a.len() {
                self.a[x] += v;
                x += x & (!x + 1);
            }
        }
        pub fn sum(&self, mut x: usize) -> T {
            debug_assert!(x < self.a.len());
            let mut res = ZERO;
            while x > 0 {
                res += self.a[x];
                x -= x & (!x + 1);
            }
            res
        }
        pub fn search(&self, s: T) -> usize {
            debug_assert!(self.sum(self.a.len() - 1) >= s);
            let mut k = 1;
            while 2 * k < self.a.len() {
                k *= 2;
            }
            let mut x = 0;
            let mut w = ZERO;
            while k > 0 {
                if k + x < self.a.len() && w + self.a[x + k] < s {
                    w += self.a[x + k];
                    x += k;
                }
                k >>= 1;
            }
            x + 1
        }
    }
}
// ---------- end fenwick tree ----------
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        k: i32,
        p: [(usize, usize); n],
    }
    let m = 200_000;
    let mut bit = fenwick::Tree::new(m + 1);
    let mut g = vec![vec![]; m + 1];
    for i in 0..n {
        let (l, r) = p[i];
        bit.add(l, 1);
        bit.add(r + 1, -1);
        g[l].push((r, i + 1));
    }
    let mut ans = vec![];
    let mut h = std::collections::BinaryHeap::new();
    for i in 1..=m {
        for &(r, k) in &g[i] {
            h.push((r, i, k));
        }
        while bit.sum(i) > k {
            let (r, l, k) = h.pop().unwrap();
            bit.add(l, -1);
            bit.add(r + 1, 1);
            ans.push(k);
        }
    }
    writeln!(out, "{}", ans.len()).ok();
    for i in 0..ans.len() {
        if i > 0 {
            write!(out, " ").ok();
        }
        write!(out, "{}", ans[i]).ok();
    }
    writeln!(out, "").ok();
}

fn main() {
    run();
}
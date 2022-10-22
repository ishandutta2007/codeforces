// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T, F> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(&T, &T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            let a = &mut self.a;
            for k in (1..(self.n)).rev() {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            let a = &self.a;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(&p, &a[l]);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(&a[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
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

// [L, R] 
// R 
// 
// L 
// 

use std::io::Write;

fn run() {
    input! {
        n: usize,
        p: [(u32, u32); n],
        q: usize,
        ask: [(usize1, usize1); q],
    }
    let mut seg = segment_tree::PURQ::new(n, (0, 0), |a, b| std::cmp::max(*a, *b));
    for (i, &(p, l)) in p.iter().enumerate() {
        seg.update_tmp(i, (p + l, i));
    }
    seg.update_all();
    let mut next = vec![(n, 0); n + 1];
    for (i, &(a, b)) in p.iter().enumerate() {
        let r = p.binary_search_by_key(&(a + b, 1), |p| (p.0, 0)).unwrap_err();
        let v = seg.find(i, r);
        if v.0 <= a + b {
            if r == n {
                next[i] = (n, 0);
            } else {
                next[i] = (r, p[r].0 - a - b);
            }
        } else {
            next[i] = (v.1, 0);
        }
    }
    let mut dp = next;
    let mut memo = vec![];
    while dp.iter().any(|p| p.0 < n) {
        let mut next = dp.clone();
        for (next, &(a, b)) in next.iter_mut().zip(dp.iter()) {
            let (c, d) = dp[a];
            *next = (c, b + d);
        }
        memo.push(dp);
        dp = next;
    }
    memo.push(dp);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (mut x, y) in ask {
        let mut ans = 0;
        for dp in memo.iter().rev() {
            if dp[x].0 <= y {
                ans += dp[x].1;
                x = dp[x].0;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
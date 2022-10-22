use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        d: [(i64, i64, i64, i64); n - 1],
        m: usize,
        ask: [((i64, i64), (i64, i64)); m],
    }
    type Mat = [[i64; 2]; 2];
    let inf = std::i64::MAX / 2;
    let mul = |a: &Mat, b: &Mat| -> Mat {
        let mut c = [[inf; 2]; 2];
        for (c, a) in c.iter_mut().zip(a.iter()) {
            for (a, b) in a.iter().zip(b) {
                for (c, b) in c.iter_mut().zip(b) {
                    *c = std::cmp::min(*c, *a + *b)
                }
            }
        }
        c
    };
    let zero = [[0, inf], [inf, 0]];
    let mut seg = segment_tree::PURQ::new(n, zero, mul);
    for (i, d) in d.windows(2).enumerate() {
        let (a, b) = (d[0], d[1]);
        let mut m = [[inf; 2]; 2];
        m[0][0] = 1 + (a.0 + 1 - b.0).abs() + (a.1 - b.1).abs();
        m[0][1] = 1 + (a.0 + 1 - b.2).abs() + (a.1 - b.3).abs();
        m[1][0] = 1 + (a.2 - b.0).abs() + (a.3 + 1 - b.1).abs();
        m[1][1] = 1 + (a.2 - b.2).abs() + (a.3 + 1 - b.3).abs();
        m[0][1] = m[0][1].min((a.0 - a.2).abs() + (a.1 - a.3).abs() + m[1][1]);
        m[1][0] = m[1][0].min((a.0 - a.2).abs() + (a.1 - a.3).abs() + m[0][0]);
        seg.update_tmp(i, m);
    }
    seg.update_all();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (mut s, mut t) in ask {
        let a = s.0.max(s.1);
        let b = t.0.max(t.1);
        let ans = if a == b {
            (s.0 - t.0).abs() + (s.1 - t.1).abs()
        } else {
            if a > b {
                std::mem::swap(&mut s, &mut t);
            }
            let a = s.0.max(s.1);
            let b = t.0.max(t.1);
            let l = (a - 1) as usize;
            let r = (b - 2) as usize;
            let mat = seg.find(l, r);
            let p = d[l];
            let mut dp = [
                (s.0 - p.0).abs() + (s.1 - p.1).abs(),
                (s.0 - p.2).abs() + (s.1 - p.3).abs(),
            ];
            dp = [
                std::cmp::min(dp[0] + mat[0][0], dp[1] + mat[1][0]),
                std::cmp::min(dp[0] + mat[0][1], dp[1] + mat[1][1]),
            ];
            let p = d[r];
            let ans = std::cmp::min(
                dp[0] + 1 + (p.0 + 1 - t.0).abs() + (p.1 - t.1).abs(),
                dp[1] + 1 + (p.2 - t.0).abs() + (p.3 + 1 - t.1).abs(),
            );
            ans
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T, F> {
        size: usize,
        data: Vec<T>,
        e: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T, F> PURQ<T, F>
    where
        T: Clone,
        F: Fn(&T, &T) -> T,
    {
        pub fn new(size: usize, e: T, op: F) -> PURQ<T, F> {
            let size = size.next_power_of_two();
            PURQ {
                size,
                data: vec![e.clone(); 2 * size],
                e: e,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            assert!(x < self.size);
            let mut x = x + self.size;
            let data = &mut self.data;
            data[x] = v;
            x >>= 1;
            while x > 0 {
                data[x] = (self.op)(&data[2 * x], &data[2 * x + 1]);
                x >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            assert!(x < self.size);
            self.data[x + self.size] = v;
        }
        pub fn update_all(&mut self) {
            let data = &mut self.data;
            for k in (1..self.size).rev() {
                data[k] = (self.op)(&data[2 * k], &data[2 * k + 1]);
            }
        }
        pub fn find(&self, l: usize, r: usize) -> T {
            assert!(l <= r && r <= self.size);
            if l == r {
                return self.e.clone();
            }
            let mut p = self.e.clone();
            let mut q = self.e.clone();
            let mut l = l + self.size;
            let mut r = r + self.size;
            let data = &self.data;
            while l < r {
                if l & 1 == 1 {
                    p = (self.op)(&p, &data[l]);
                    l += 1;
                }
                if r & 1 == 1 {
                    r -= 1;
                    q = (self.op)(&data[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
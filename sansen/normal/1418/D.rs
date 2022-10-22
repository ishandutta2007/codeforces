// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(&T, &T) -> T> {
        size: usize,
        a: Vec<Option<T>>,
        fold: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(&T, &T) -> T> PURQ<T, F> {
        pub fn new(len: usize, fold: F) -> PURQ<T, F> {
            let size = len.next_power_of_two();
            PURQ {
                size: size,
                a: vec![None; 2 * size],
                fold: fold,
            }
        }
        pub fn update(&mut self, x: usize, v: Option<T>) {
            let mut k = self.size + x;
            self.a[k] = v;
            k >>= 1;
            while k > 0 {
                self.a[k] = self.merge(&self.a[2 * k], &self.a[2 * k + 1]);
                k >>= 1;
            }
        }
        fn merge(&self, a: &Option<T>, b: &Option<T>) -> Option<T> {
            match (a.as_ref(), b.as_ref()) {
                (Some(a), Some(b)) => Some((self.fold)(a, b)),
                (Some(a), None) => Some(a.clone()),
                (None, Some(b)) => Some(b.clone()),
                (None, None) => None,
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: Option<T>) {
            self.a[x + self.size] = v;
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.size)).rev() {
                self.a[k] = self.merge(&self.a[2 * k], &self.a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> Option<T> {
            let mut p: Option<T> = None;
            let mut q: Option<T> = None;
            let a = &self.a;
            l += self.size;
            r += self.size;
            while l < r {
                if (l & 1) == 1 {
                    p = self.merge(&p, &a[l]);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = self.merge(&a[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            self.merge(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
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

//

use std::io::Write;
use std::cmp::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        q: usize,
        p: [i64; n],
        ask: [(u8, i64); q],
    }
    let mut z = p.clone();
    for &(_, x) in ask.iter() {
        z.push(x);
    }
    z.sort();
    z.dedup();
    type T = (i64, i64, i64);// min, max, len
    let f = |a: &T, b: &T| -> T {
        (a.0, b.1, max(a.2, max(b.2, b.0 - a.1)))
    };
    let mut seg = segment_tree::PURQ::new(z.len(), f);
    let mut cnt = vec![0; z.len()];
    for p in p.iter() {
        let k = z.binary_search(p).unwrap();
        cnt[k] += 1;
        seg.update_tmp(k, Some((*p, *p, 0)));
    }
    seg.update_all();
    let (a, b, c) = seg.find(0, z.len()).unwrap();
    writeln!(out, "{}", b - a - c).ok();
    for (op, x) in ask {
        let k = z.binary_search(&x).unwrap();
        if op == 0 {
            cnt[k] -= 1;
            if cnt[k] == 0 {
                seg.update(k, None);
            }
        } else {
            cnt[k] += 1;
            seg.update(k, Some((x, x, 0)));
        }
        let ans = if let Some((a, b, c)) = seg.find(0, z.len()) {
            b - a - c
        } else {
            0
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
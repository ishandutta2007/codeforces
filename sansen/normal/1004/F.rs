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
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.size + x;
            self.a[k] = Some(v);
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
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.size] = Some(v);
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.size)).rev() {
                self.a[k] = self.merge(&self.a[2 * k], &self.a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
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
            self.merge(&p, &q).unwrap()
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

//

use std::io::Write;

// x
// (bitwise or bitwise or ,
// x)
// 
// log 
// ?
// log 2TLE
// 

fn run() {
    input! {
        n: usize,
        m: usize,
        x: u32,
        a: [u32; n],
        ask: [(u8, usize1, u32); m],
    }
    // 
    type T = (Box<[(u32, u32)]>, Box<[(u32, u32)]>, u64);
    let fold = |a: &T, b: &T| -> T {
        let mut left: Vec<_> = a.0.iter().cloned().collect();
        for &(b, c) in b.0.iter() {
            left.push((b | a.0.last().unwrap().0, c));
        }
        left.dedup_by(|a, b| {
            let x = a.0 == b.0;
            if x {
                b.1 += a.1;
            }
            x
        });
        let mut right: Vec<_> = b.1.iter().cloned().collect();
        for &(a, c) in a.1.iter() {
            right.push((a | b.1.last().unwrap().0, c));
        }
        right.dedup_by(|a, b| {
            let x = a.0 == b.0;
            if x {
                b.1 += a.1;
            }
            x
        });
        let mut cnt = a.2 + b.2;
        let mut sum = 0;
        let mut i = a.1.len();
        for &(b, c) in b.0.iter() {
            while i > 0 && a.1[i - 1].0 | b >= x {
                sum += a.1[i - 1].1 as u64;
                i -= 1;
            }
            cnt += c as u64 * sum;
        }
        (left.into_boxed_slice(), right.into_boxed_slice(), cnt)
    };
    let mut seg = segment_tree::PURQ::new(n, fold);
    for (i, a) in a.into_iter().enumerate() {
        seg.update_tmp(i, (vec![(a, 1)].into_boxed_slice(), vec![(a, 1)].into_boxed_slice(), if a >= x {1} else {0}));
    }
    seg.update_all();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (op, p, q) in ask {
        if op == 1 {
            seg.update(p, (vec![(q, 1)].into_boxed_slice(), vec![(q, 1)].into_boxed_slice(), if q >= x {1} else {0}));
        } else {
            let ans = seg.find(p, q as usize).2;
            writeln!(out, "{}", ans).ok();
        }
    }
}

fn main() {
    run();
}
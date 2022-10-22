//---------- begin SegmentTree Point update Range query ----------
pub trait PURQ {
    type T: Clone;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T;
    fn e() -> Self::T;
}

struct SegmentTreePURQ<R: PURQ> {
    seg: Vec<R::T>,
    size: usize,
}

#[allow(dead_code)]
impl<R: PURQ> SegmentTreePURQ<R> {
    fn new(n: usize) -> SegmentTreePURQ<R> {
        let size = n.next_power_of_two();
        SegmentTreePURQ {
            seg: vec![R::e(); 2 * size],
            size: size,
        }
    }
    fn build_by(a: &[R::T]) -> SegmentTreePURQ<R> {
        let size = a.len().next_power_of_two();
        let mut b = vec![R::e(); 2 * size];
        for i in 0..a.len() {
            b[i + size] = a[i].clone();
        }
        let mut seg = SegmentTreePURQ {
            seg: b,
            size: size,
        };
        seg.update_all();
        seg
    }
    fn update(&mut self, x: usize, v: R::T) {
        let mut x = x + self.size;
        let a = &mut self.seg;
        a[x] = v;
        x >>= 1;
        while x > 0 {
            a[x] = R::fold(&a[2 * x], &a[2 * x + 1]);
            x >>= 1;
        }
    }
    fn update_tmp(&mut self, x: usize, v: R::T) {
        self.seg[self.size + x] = v;
    }
    fn update_all(&mut self) {
        let a = &mut self.seg;
        for i in (1..self.size).rev() {
            a[i] = R::fold(&a[2 * i], &a[2 * i + 1]);
        }
    }
    fn find(&self, l: usize, r: usize) -> R::T {
        let mut x = R::e();
        let mut y = R::e();
        let mut l = l + self.size;
        let mut r = r + self.size;
        let a = &self.seg;
        while l < r {
            if l & 1 == 1 {
                x = R::fold(&x, &a[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                y = R::fold(&a[r], &y);
            }
            l >>= 1;
            r >>= 1;
        }
        R::fold(&x, &y)
    }
    fn search<F>(&self, l: usize, f: F) -> usize
    where
        F: Fn(&R::T) -> bool,
    {
        let mut v = R::e();
        assert!(!f(&v));
        let a = &self.seg;
        let mut r = self.size * 2;
        let mut l = l + self.size;
        while l < r {
            if l & 1 == 1 {
                let u = R::fold(&v, &a[l]);
                if f(&u) {
                    break;
                } else {
                    v = u;
                }
                l += 1;
            }
            l >>= 1;
            r >>= 1;
        }
        if l == r {
            return self.size;
        }
        while l < self.size {
            let u = R::fold(&v, &a[2 * l]);
            if f(&u) {
                l = 2 * l;
            } else {
                v = u;
                l = 2 * l + 1;
            }
        }
        l - self.size
    }
}
//---------- end SegmentTree Point update Range query ----------
// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
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

use std::cmp::*;

struct R;
impl PURQ for R {
    type T = (usize, usize);
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        (min(l.0, r.0), max(l.1, r.1))
    }
    fn e() -> Self::T {
        (std::usize::MAX, 0)
    }
}

fn run() {
    input! {
        n: usize,
        h: [usize; n],
    }
    let mut dp = vec![n; n];
    dp[0] = 0;
    let mut seg = SegmentTreePURQ::<R>::new(n);
    for i in 0..n {
        seg.update_tmp(i, (h[i], h[i]));
    }
    seg.update_all();
    for i in 0..(n - 1) {
        let v = dp[i] + 1;
        dp[i + 1].chmin(v);
        if h[i] == h[i + 1] {
        } else if h[i] < h[i + 1] {
            let d = h[i];
            let mut u = h[i + 1];
            let mut j = i + 2;
            while j < n && d < u {
                let k = seg.search(j, |p| {
                    p.0 < u
                });
                if k >= n {
                    break;
                }
                dp[k].chmin(v);
                u.chmin(h[k]);
                j = k + 1;
            }
        } else {
            let mut d = h[i + 1];
            let u = h[i];
            let mut j = i + 2;
            while j < n && d < u {
                let k = seg.search(j, |p| {
                    p.1 > d
                });
                if k >= n {
                    break;
                }
                dp[k].chmin(v);
                d.chmax(h[k]);
                j = k + 1;
            }
        }
    }
    let ans = dp[n - 1];
    println!("{}", ans);
}

fn main() {
    run();
}
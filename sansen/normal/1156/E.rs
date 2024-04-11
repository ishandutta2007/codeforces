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
        let mut seg = SegmentTreePURQ { seg: b, size: size };
        seg.update_all();
        seg
    }
    fn update(&mut self, x: usize, v: R::T) {
        assert!(x < self.size);
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
        assert!(l <= r && r <= self.size);
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
    // f(a[l..k]) kfalse, false, ..., true 
    // x
    // f(&a[l..x]) = false
    // f(&a[l..=x]) = true
    // 
    fn search_right<F>(&self, l: usize, f: F) -> usize
    where
        F: Fn(&R::T) -> bool,
    {
        let a = &self.seg;
        let mut v = R::e();
        let mut r = self.size * 2;
        let mut l = l + self.size;
        while l < r {
            if l & 1 == 1 {
                let u = R::fold(&v, &a[l]);
                if f(&u) {
                    break;
                }
                l += 1;
                v = u;
            }
            l >>= 1;
            r >>= 1;
        }
        if l == r {
            return self.size;
        }
        while l < self.size {
            let x = 2 * l;
            let u = R::fold(&v, &a[x]);
            if f(&u) {
                l = x;
            } else {
                l = x + 1;
                v = u;
            }
        }
        l - self.size
    }
}
//---------- end SegmentTree Point update Range query ----------

use std::io::Read;

struct RMQ;

impl PURQ for RMQ {
    type T = (usize, usize);
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        std::cmp::max(*l, *r)
    }
    fn e() -> Self::T {
        (0, 200000)
    }
}

fn dfs(l: usize, r: usize, elem: &mut [bool], p: &[usize], rmq: &SegmentTreePURQ<RMQ>) -> usize {
    if l >= r {
        return 0;
    }
    let (val, mid) = rmq.find(l, r);
    let (small, large) = if mid - l <= r - mid {
        ((l, mid), (mid + 1, r))
    } else {
        ((mid + 1, r), (l, mid))
    };
    elem[val] = false;
    let mut ans = 0;
    for p in p[small.0..small.1].iter() {
        elem[*p] = false;
    }
    for p in p[small.0..small.1].iter() {
        if elem[val - *p] {
            ans += 1;
        }
    }
    ans += dfs(large.0, large.1, elem, p, rmq);
    for p in p[small.0..small.1].iter() {
        elem[*p] = true;
    }
    ans + dfs(small.0, small.1, elem, p, rmq)
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    it.next();
    let p: Vec<usize> = it.map(|s| s.parse().unwrap()).collect();
    let mut elem = vec![true; p.len() + 1];
    elem[0] = false;
    let mut rmq = SegmentTreePURQ::new(p.len());
    for (i, p) in p.iter().enumerate() {
        rmq.update_tmp(i, (*p, i));
    }
    rmq.update_all();
    let ans = dfs(0, p.len(), &mut elem, &p, &rmq);
    println!("{}", ans);
}

fn main() {
    run();
}
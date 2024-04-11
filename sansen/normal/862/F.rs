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
//---------- begin SegmentTree Point update Range query ----------
pub trait PURQ {
    type T: Clone;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T;
    fn fold_option(l: &Option<Self::T>, r: &Option<Self::T>) -> Option<Self::T> {
        match (l.as_ref(), r.as_ref()) {
            (Some(l), Some(r)) => Some(Self::fold(l, r)),
            (Some(l), None) => Some(l.clone()),
            (None, Some(r)) => Some(r.clone()),
            _ => None,
        }
    }
}

struct SegmentTreePURQ<R: PURQ> {
    seg: Vec<Option<R::T>>,
    size: usize,
}

#[allow(dead_code)]
impl<R: PURQ> SegmentTreePURQ<R> {
    fn new(n: usize) -> SegmentTreePURQ<R> {
        let size = n.next_power_of_two();
        SegmentTreePURQ {
            seg: (0..(2 * size)).map(|_| None).collect(),
            size: size,
        }
    }
    fn update(&mut self, x: usize, v: Option<R::T>) {
        let mut x = x + self.size;
        let a = &mut self.seg;
        a[x] = v;
        x >>= 1;
        while x > 0 {
            a[x] = R::fold_option(&a[2 * x], &a[2 * x + 1]);
            x >>= 1;
        }
    }
    fn update_tmp(&mut self, x: usize, v: Option<R::T>) {
        self.seg[self.size + x] = v;
    }
    fn update_all(&mut self) {
        let a = &mut self.seg;
        for i in (1..self.size).rev() {
            a[i] = R::fold_option(&a[2 * i], &a[2 * i + 1]);
        }
    }
    fn find(&self, l: usize, r: usize) -> Option<R::T> {
        let mut x = None;
        let mut y = None;
        let mut l = l + self.size;
        let mut r = r + self.size;
        let a = &self.seg;
        while l < r {
            if l & 1 == 1 {
                x = R::fold_option(&x, &a[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                y = R::fold_option(&a[r], &y);
            }
            l >>= 1;
            r >>= 1;
        }
        R::fold_option(&x, &y)
    }
}
//---------- end SegmentTree Point update Range query ----------
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std;
    use std::io::Read;
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error"),
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

struct RMQ;
impl PURQ for RMQ {
    type T = usize;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        std::cmp::max(*l, *r)
    }
}

struct LargestRectangle;
impl PURQ for LargestRectangle {
    // >>>, <<<
    type T = (usize, Vec<(usize, usize)>, Vec<(usize, usize)>);
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        let mut val = std::cmp::max(l.0, r.0);
        let mut p = l.1.clone();
        for &(h, w) in r.1.iter() {
            let mut sum = 0;
            while p.last().map_or(false, |p| p.0 >= h) {
                sum += p.pop().unwrap().1;
            }
            p.push((h, w + sum));
        }
        let mut q = r.2.clone();
        for &(h, w) in l.2.iter() {
            let mut sum = 0;
            while q.last().map_or(false, |p| p.0 >= h) {
                sum += q.pop().unwrap().1;
            }
            q.push((h, w + sum));
        }
        let mut a = l.1.clone();
        for &(h, w) in r.2.iter().rev() {
            let mut sum = 0;
            while a.last().map_or(false, |p| p.0 >= h) {
                let (y, x) = a.pop().unwrap();
                sum += x;
                val.chmax(y * (sum + 1));
            }
            a.push((h, w + sum));
        }
        (val, p, q)
    }
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let mut s = Vec::with_capacity(n);
    let mut rmq = SegmentTreePURQ::<RMQ>::new(n);
    for i in 0..n {
        let a: Vec<char> = sc.next_chars();
        rmq.update_tmp(i, Some(a.len()));
        s.push(a);
    }
    rmq.update_all();
    let lcp = |a: &[char], b: &[char]| -> usize {
        a.iter().zip(b.iter()).take_while(|p| *p.0 == *p.1).count()
    };
    let gen = |lcp: usize| -> Option<<LargestRectangle as PURQ>::T> {
        Some((2 * lcp, vec![(lcp, 1)], vec![(lcp, 1)]))
    };
    let mut seg = SegmentTreePURQ::<LargestRectangle>::new(n);
    for (i, s) in s.windows(2).enumerate() {
        seg.update_tmp(i, gen(lcp(&s[0], &s[1])));
    }
    seg.update_all();
    for _ in 0..m {
        let op: u8 = sc.next();
        if op == 1 {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let mut ans = rmq.find(l, r).unwrap();
            if l + 1 < r {
                let (val, l, r) = seg.find(l, r - 1).unwrap();
                ans.chmax(val);
                for p in [l, r].iter() {
                    let mut sum = 0;
                    for &(h, w) in p.iter().rev() {
                        sum += w;
                        ans.chmax(h * (sum + 1));
                    }
                }
            }
            writeln!(out, "{}", ans).ok();
        } else {
            let x = sc.next::<usize>() - 1;
            let a = sc.next_chars();
            rmq.update(x, Some(a.len()));
            if x > 0 {
                seg.update(x - 1, gen(lcp(&a, &s[x - 1])));
            }
            if x + 1 < n {
                seg.update(x, gen(lcp(&a, &s[x + 1])));
            }
            s[x] = a;
        }
    }
}
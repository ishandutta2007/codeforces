// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

// (l, r)  or 
//  l - r 
// 
// 
// O(N^2) 
// M, M-1, .., 2, 1, M + 1, M + 2, ..., N
// N=1 
// 1, N 
// 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<u32> = sc.next_vec(n);
        let inf = 1000000;
        let mut seg = SegmentTreePURQ::new(n, ((0u32, 0), (inf, 0)), |a, b| {
            (std::cmp::max(a.0, b.0), std::cmp::min(a.1, b.1))
        });
        for (i, a) in a.iter().enumerate() {
            seg.update_tmp(i, ((*a, i), (*a, i)));
        }
        seg.update_all();
        let mut dp = vec![inf; n + 1];
        dp[0] = 0;
        let mut deq = Deque::new();
        deq.push_back(0);
        while let Some(v) = deq.pop_front() {
            if v >= n - 1 {
                continue;
            }
            let d = dp[v] + 1;
            let (p, q) = (a[v], a[v + 1]);
            if p < q {
                let pos = seg.max_right(v, |&(a, b)| b.0 >= p);
                let ((_, k), _) = seg.find(v, pos);
                if dp[k].chmin(d) {
                    deq.push_back(k);
                }
            } else {
                let pos = seg.max_right(v, |&(a, b)| a.0 <= p);
                let (_, (_, k)) = seg.find(v, pos);
                if dp[k].chmin(d) {
                    deq.push_back(k);
                }
            }
        }
        writeln!(out, "{}", dp[n - 1]).ok();
    }
}

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
// ---------- end chmin, chmax ---------r
// ---------- begin segment tree Point Update Range Query ----------
pub struct SegmentTreePURQ<T, F> {
    n: usize,
    size: usize,
    data: Vec<T>,
    e: T,
    op: F,
}

impl<T, F> SegmentTreePURQ<T, F>
where
    T: Clone,
    F: Fn(&T, &T) -> T,
{
    pub fn new(n: usize, e: T, op: F) -> Self {
        assert!(n > 0);
        let size = n.next_power_of_two();
        let data = vec![e.clone(); 2 * size];
        SegmentTreePURQ {
            n,
            size,
            data,
            e,
            op,
        }
    }
    pub fn update_tmp(&mut self, x: usize, v: T) {
        assert!(x < self.n);
        self.data[x + self.size] = v;
    }
    pub fn update_all(&mut self) {
        for i in (1..self.size).rev() {
            self.data[i] = (self.op)(&self.data[2 * i], &self.data[2 * i + 1]);
        }
    }
    pub fn update(&mut self, x: usize, v: T) {
        assert!(x < self.n);
        let mut x = x + self.size;
        self.data[x] = v;
        x >>= 1;
        while x > 0 {
            self.data[x] = (self.op)(&self.data[2 * x], &self.data[2 * x + 1]);
            x >>= 1;
        }
    }
    pub fn find(&self, l: usize, r: usize) -> T {
        assert!(l <= r && r <= self.n);
        if l == r {
            return self.e.clone();
        }
        let mut l = self.size + l;
        let mut r = self.size + r;
        let mut x = self.e.clone();
        let mut y = self.e.clone();
        while l < r {
            if l & 1 == 1 {
                x = (self.op)(&x, &self.data[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                y = (self.op)(&self.data[r], &y);
            }
            l >>= 1;
            r >>= 1;
        }
        (self.op)(&x, &y)
    }
    pub fn max_right<P>(&self, l: usize, f: P) -> usize
    where
        P: Fn(&T) -> bool,
    {
        assert!(l <= self.n);
        assert!(f(&self.e));
        if l == self.n {
            return self.n;
        }
        let mut l = l + self.size;
        let mut sum = self.e.clone();
        while {
            l >>= l.trailing_zeros();
            let v = (self.op)(&sum, &self.data[l]);
            if !f(&v) {
                while l < self.size {
                    l <<= 1;
                    let v = (self.op)(&sum, &self.data[l]);
                    if f(&v) {
                        sum = v;
                        l += 1;
                    }
                }
                return l - self.size;
            }
            sum = v;
            l += 1;
            l.count_ones() > 1
        } {}
        self.n
    }
}
// ---------- end segment tree Point Update Range Query ----------
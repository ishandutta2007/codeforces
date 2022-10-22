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
    pub fn min_left<P>(&self, r: usize, f: P) -> usize
    where
        P: Fn(&T) -> bool,
    {
        assert!(r <= self.n);
        assert!(f(&self.e));
        if r == 0 {
            return 0;
        }
        let mut r = r + self.size;
        let mut sum = self.e.clone();
        while {
            r -= 1;
            while r > 1 && r & 1 == 1 {
                r >>= 1;
            }
            let v = (self.op)(&self.data[r], &sum);
            if !f(&v) {
                while r < self.size {
                    r = 2 * r + 1;
                    let v = (self.op)(&self.data[r], &sum);
                    if f(&v) {
                        sum = v;
                        r -= 1;
                    }
                }
                return r + 1 - self.size;
            }
            sum = v;
            (r & (!r + 1)) != r
        } {}
        0
    }
}
// ---------- end segment tree Point Update Range Query ----------
// ---------- begin rand ----------
fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}

fn shuffle<T>(a: &mut [T]) {
    for i in 1..a.len() {
        let p = rand() % (i + 1);
        a.swap(i, p);
    }
}
// ---------- end rand ----------
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

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let q: usize = sc.next();
    let mut a = sc.next_vec::<usize>(n);
    let mut op = (0..q)
        .map(|_| {
            let op = sc.next::<u8>();
            if op == 1 {
                let i = sc.next::<usize>() - 1;
                let x = sc.next::<usize>();
                (op, i, x, 0)
            } else {
                let l = sc.next::<usize>() - 1;
                let r = sc.next::<usize>();
                let k = sc.next::<usize>();
                (op, l, r, k)
            }
        })
        .collect::<Vec<_>>();
    let mut z = a.clone();
    z.extend(op.iter().filter(|p| p.0 == 1).map(|p| p.2));
    z.sort();
    z.dedup();
    for a in a.iter_mut() {
        *a = z.binary_search(a).unwrap();
    }
    for op in op.iter_mut() {
        if op.0 == 1 {
            op.2 = z.binary_search(&op.2).unwrap();
        }
    }
    let (a, op) = (a, op);
    let mut ans = vec![true; q];
    for _ in 0..30 {
        let mut seg = SegmentTreePURQ::new(n, 0, |a, b| *a + *b);
        let hash = (0..z.len())
            .map(|_| rand() % 1000000000)
            .collect::<Vec<_>>();
        for (i, a) in a.iter().enumerate() {
            seg.update_tmp(i, hash[*a]);
        }
        seg.update_all();
        for (ans, op) in ans.iter_mut().zip(op.iter()) {
            if op.0 == 1 {
                seg.update(op.1, hash[op.2]);
            } else {
                let (_, l, r, k) = *op;
                *ans &= seg.find(l, r) % k == 0;
            }
        }
    }
    for (ans, _) in ans.iter().zip(op.iter()).filter(|&(_, op)| op.0 == 2) {
        let s = if *ans { "YES" } else { "NO" };
        writeln!(out, "{}", s).ok();
    }
}
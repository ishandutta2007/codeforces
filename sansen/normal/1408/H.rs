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

// 
// 
// 0
// disjoint 
// 
// 
// 
// 2
//
// 
// hall nlogn 
// N<=5*10^5, 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<usize> = sc.next_vec(n);
        let mut z = a.clone();
        z.sort();
        z.dedup();
        if z[0] != 0 {
            writeln!(out, "0").ok();
            continue;
        }
        for a in a.iter_mut() {
            *a = z.binary_search(a).unwrap();
        }
        let zero = a.iter().filter(|a| **a == 0).count();
        let valid = |m: usize| -> bool {
            if m > std::cmp::min(zero / 2, z.len() - 1) {
                return false;
            }
            let mut last = vec![n; n];
            let mut seg = segment_tree::PURQ::new(n + 1, (0i32, 0i32), |a, b| (a.0.min(a.1 + b.0), a.1 + b.1));
            let mut index = vec![];
            let mut cnt = 0;
            for (i, &a) in a.iter().enumerate().rev() {
                if a != 0 {
                    let last = &mut last[a];
                    seg.update(*last, (0, 0));
                    *last = i;
                    seg.update(*last, (0, 1));
                    continue;
                }
                if cnt < m {
                    index.push(i);
                } else if zero - cnt <= m {
                    let x = index[m - (zero - cnt)];
                    seg.update(x, (-1, -1));
                    if seg.find(i, n).0 < 0 {
                        return false;
                    }
                }
                cnt += 1;
            }
            true
        };
        let mut ok = 0;
        let mut ng = std::cmp::min(zero / 2, z.len() - 1) + 1;
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            if valid(mid) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        writeln!(out, "{}", ok).ok();
    }
}
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

// b 
// swap
// 
// 
// 00, 01, 11 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let a: Vec<usize> = sc.next_vec(n);
        let b: Vec<usize> = sc.next_vec(m);
        #[derive(Clone, Copy, Eq, PartialEq, PartialOrd, Ord)]
        enum Event {
            ZERO(usize),
            ASK,
            ONE(usize),
        }
        let inf = 10u32.pow(7);
        let mut e = vec![];
        for (i, &a) in a.iter().enumerate() {
            e.push((a, Event::ZERO(i)));
            e.push((a, Event::ONE(i)));
        }
        for b in b.iter() {
            e.push((*b, Event::ASK));
        }
        e.sort();
        let mut seg = segment_tree::PURQ::new(n, (0, inf, 0), |a, b| {
            (a.0 + b.0, (a.0 + b.1).min(a.0 + b.2).min(a.1 + b.2), a.2 + b.2)
        });
        for i in 0..n {
            seg.update_tmp(i, (1, inf, 0));
        }
        seg.update_all();
        let mut ans = 0;
        for (_, op) in e {
            match op {
                Event::ZERO(k) => {
                    seg.update(k, (0, inf, 0));
                },
                Event::ASK => {
                    let p = seg.find(0, n);
                    ans += p.0.min(p.1).min(p.2) as u64;
                }
                Event::ONE(k) => {
                    seg.update(k, (0, inf, 1));
                },
            }
        }
        let mut a = a;
        ans += inv(&mut a);
        writeln!(out, "{}", ans).ok();
    }
}

fn inv(a: &mut [usize]) -> u64 {
    if a.len() == 1 {
        return 0;
    }
    let m = a.len() / 2;
    let mut ans = inv(&mut a[..m]) + inv(&mut a[m..]);
    let mut i = 0;
    let mut j = m;
    let mut tmp = vec![];
    while i < m && j < a.len() {
        if a[i] <= a[j] {
            tmp.push(a[i]);
            i += 1;
        } else {
            ans += (m - i) as u64;
            tmp.push(a[j]);
            j += 1;
        }
    }
    while i < m {
        tmp.push(a[i]);
        i += 1;
    }
    for (a, t) in a.iter_mut().zip(tmp) {
        *a = t;
    }
    ans
}
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
    let t: u32 = sc.next();
    for _ in 0..t {
        run(&mut sc, &mut out);
    }
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let a: Vec<usize> = sc.next_vec(n);
    let mut b = vec![];
    for _ in 0..m {
        let k: usize = sc.next();
        let x = sc.next_vec::<usize>(k);
        b.push(x);
    }
    let mut z = vec![];
    z.extend(a.iter().map(|a| (*a, 1)));
    let key = |s: usize, d: usize| -> usize {
        if s % d == 0 {
            s / d
        } else {
            s / d + 1
        }
    };
    for b in b.iter() {
        let sum = b.iter().sum::<usize>();
        let len = b.len();
        z.push((key(sum, len), 0));
        for b in b.iter() {
            z.push((key(sum - *b, len - 1), 0));
        }
    }
    z.sort();
    z.dedup();
    // sum, min
    let mut seg = segment_tree::PURQ::new(z.len(), (0, 0), |a, b| {
        (a.0 + b.0, b.1.min(a.1 + b.0))
    });
    for a in a.iter() {
        let pos = z.binary_search(&(*a, 1)).unwrap();
        let v = seg.find(pos, pos + 1);
        seg.update(pos, (v.0 + 1, 1));
    }
    for b in b.iter() {
        let sum = b.iter().sum::<usize>();
        let v = key(sum, b.len());
        let pos = z.binary_search(&(v, 0)).unwrap();
        let v = seg.find(pos, pos + 1);
        seg.update(pos, (v.0 - 1, v.0 - 1));
    }
    let mut ans = String::new();
    for b in b.iter() {
        let sum = b.iter().sum::<usize>();
        let v = key(sum, b.len());
        let pos = z.binary_search(&(v, 0)).unwrap();
        let save = seg.find(pos, pos + 1);
        seg.update(pos, (save.0 + 1, save.0 + 1));
        for &sub in b.iter() {
            let v = key(sum - sub, b.len() - 1);
            let pos = z.binary_search(&(v, 0)).unwrap();
            let save = seg.find(pos, pos + 1);
            seg.update(pos, (save.0 - 1, save.1 - 1));
            let res = seg.find(0, z.len());
            if res.1 >= 0 {
                ans.push('1');
            } else {
                ans.push('0');
            }
            seg.update(pos, save);
        }
        seg.update(pos, save);
    }
    writeln!(out, "{}", ans).ok();
}
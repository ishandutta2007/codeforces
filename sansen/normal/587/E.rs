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
// xor
// A_l, A_{l + 1}, ..., A_r 
// A_l, A_l^A_{l + 1}, ..., A_{r - 1}^A_r 
//  a_1^a_2, a_2 ^ a_3, ... 
// xor 2
// [l, r)  {a_l, a_l^a_{l + 1},...,a_{r - 2}^a_{r - 1}} 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let q: usize = sc.next();
    let mut a = vec![0u32; n + 1];
    for a in a[0..n].iter_mut() {
        *a = sc.next();
    }
    let merge = |a: &Vec<u32>, b: &Vec<u32>| -> Vec<u32> {
        let mut c = a.clone();
        for b in b {
            let mut x = *b;
            for c in c.iter() {
                x = x.min(x ^ *c);
            }
            if x > 0 {
                c.push(x);
            }
        }
        c
    };
    let ini = |a: u32| -> Vec<u32> {
        let mut res = vec![];
        if a != 0 {
            res.push(a);
        }
        res
    };
    let mut base = segment_tree::PURQ::new(n + 1, vec![], merge);
    for i in 0..n {
        base.update_tmp(i, ini(a[i] ^ a[i + 1]));
    }
    base.update_all();
    let mut xor = segment_tree::PURQ::new(n + 1, 0u32, |a, b| *a ^ *b);
    for _ in 0..q {
        let op: u8 = sc.next();
        let l = sc.next::<usize>() - 1;
        let r = sc.next::<usize>();
        if op == 1 {
            let k = sc.next::<u32>();
            for &x in [l - 1, r - 1].iter() {
                if x < n {
                    let p = base.find(x, x + 1).get(0).map_or(0, |p| *p);
                    base.update(x, ini(p ^ k));
                }
            }
            for &x in [l, r].iter() {
                let v = xor.find(x, x + 1);
                xor.update(x, v ^ k);
            }
        } else {
            let s = a[l] ^ xor.find(0, l + 1);
            let len = merge(&base.find(l, r - 1), &vec![s]).len();
            let ans = 1u64 << len;
            writeln!(out, "{}", ans).ok();
        }
    }
}
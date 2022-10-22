//---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(T, T) -> T> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(T, T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(a[2 * k].clone(), a[2 * k + 1].clone());
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.n)).rev() {
                self.a[k] = (self.op)(self.a[2 * k].clone(), self.a[2 * k + 1].clone());
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(p, self.a[l].clone());
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(self.a[r].clone(), q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(p, q)
        }
    }
}
//---------- end SegmentTree Point update Range query ----------
//---------- begin scannner ----------
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
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
//---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let out = std::io::BufWriter::new(out.lock());
    run(sc, out);
}

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let k: usize = sc.next();
    let f = |a, b| std::cmp::max(a, b);
    let mut s = Vec::with_capacity(1 << k);
    for _ in 0..(1 << k) {
        s.push(segment_tree::PURQ::new(n, -5_000_000, f));
    }
    for i in 0..n {
        let mut a = vec![0i32; k];
        for j in 0..k {
            a[j] = sc.next();
        }
        for j in 0..(1 << k) {
            let mut sum = 0;
            for l in 0..k {
                sum += if (j >> l) & 1 == 1 { -1 } else { 1 } * a[l];
            }
            s[j].update_tmp(i, sum);
        }
    }
    for i in 0..(1 << k) {
        s[i].update_all();
    }
    let q: usize = sc.next();
    for _ in 0..q {
        let op: u8 = sc.next();
        if op == 1 {
            let i = sc.next::<usize>() - 1;
            let mut a = vec![0i32; k];
            for j in 0..k {
                a[j] = sc.next();
            }
            for j in 0..(1 << k) {
                let mut sum = 0;
                for l in 0..k {
                    sum += if (j >> l) & 1 == 1 { -1 } else { 1 } * a[l];
                }
                s[j].update(i, sum);
            }
        } else {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let mask = (1 << k) - 1;
            let mut ans = 0;
            for i in (0..(1 << k)).step_by(2) {
                let v = s[i].find(l, r) + s[i ^ mask].find(l, r);
                ans = std::cmp::max(ans, v.abs());
            }
            writeln!(out, "{}", ans).unwrap();
        }
    }
}
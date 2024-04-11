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
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
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

type Top2 = (u32, u32);
fn min_top2(a: Top2, b: Top2) -> Top2 {
    if a.0 <= b.0 {
        (a.0, if b.0 <= a.1 {b.0} else {a.1})
    } else {
        (b.0, if a.0 <= b.1 {a.0} else {b.1})
    }
}

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let a: Vec<u32> = (0..n).map(|_| sc.next()).collect();
    let mut s = vec![];
    let len = 9;
    let inf = 1_000_000_000;
    for _ in 0..len {
        s.push(segment_tree::PURQ::new(n, (inf, inf), min_top2));
    }
    for i in 0..n {
        let mut d = 1;
        for j in 0..len {
            if a[i] / d % 10 != 0 {
                s[j].update_tmp(i, (a[i], inf));
            }
            d *= 10;
        }
    }
    for i in 0..len {
        s[i].update_all();
    }
    for _ in 0..m {
        let op: u8 = sc.next();
        if op == 1 {
            let k = sc.next::<usize>() - 1;
            let x: u32 = sc.next();
            let mut d = 1;
            for i in 0..len {
                if x / d % 10 == 0 {
                    s[i].update(k, (inf, inf));
                } else {
                    s[i].update(k, (x, inf));
                }
                d *= 10;
            }
        } else {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let mut ans = (inf, inf);
            for i in 0..len {
                let (a, b) = s[i].find(l, r);
                if b < inf && a + b < ans.0 + ans.1 {
                    ans = (a, b);
                }
            }
            if ans.1 < inf {
                writeln!(out, "{}", ans.0 + ans.1).unwrap();
            } else {
                writeln!(out, "-1").unwrap();
            }
        }
    }
}
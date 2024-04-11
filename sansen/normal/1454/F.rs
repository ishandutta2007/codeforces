// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T, F> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(&T, &T) -> T> PURQ<T, F> {
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
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            let a = &mut self.a;
            for k in (1..(self.n)).rev() {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            let a = &self.a;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(&p, &a[l]);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(&a[r], &q);
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

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<u32> = sc.next_vec(n);
        let inf = 1_000_000_000 + 1;
        let mut map = std::collections::BTreeMap::new();
        let mut seg = segment_tree::PURQ::new(n, (inf, 0), |a, b| (a.0.min(b.0), a.1.max(b.1)));
        for (i, a) in a.iter().enumerate() {
            seg.update_tmp(i, (*a, *a));
            map.entry(*a).or_insert(vec![]).push(i);
        }
        seg.update_all();
        let mut ans = None;
        let mut fst = true;
        let mut l = n;
        let mut r = 0;
        for (&val, index) in map.iter().rev() {
            if fst {
                fst = false;
                if index.len() >= 3 {
                    let b = index[1];
                    ans = Some((b, 1, n - b - 1));
                    break;
                }
                l = index[0];
                r = *index.last().unwrap();
            } else {
                while l > 0 && seg.find(0, l).1 > val {
                    l -= 1;
                }
                while l > 1 && seg.find(0, l - 1).1 == val && a[l - 1] >= val {
                    l -= 1;
                }
                while r < n && seg.find(r, n).1 > val {
                    r += 1;
                }
                while r + 1 < n && seg.find(r + 1, n).1 == val && a[r] >= val {
                    r += 1;
                }
                if l > 0 && r < n && seg.find(0, l).1 == val && seg.find(r, n).1 == val && seg.find(l, r).0 == val {
                    ans = Some((l, r - l, n - r));
                    break;
                }
            }
        }
        if let Some((a, b, c)) = ans {
            assert!(seg.find(0, a).1 == seg.find(a, a + b).0 && seg.find(a, a + b).0 == seg.find(a + b, n).1);
            assert!(a + b + c == n);
            writeln!(out, "YES\n{} {} {}", a, b, c).ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
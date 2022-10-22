// ---------- begin fenwick tree ----------
#[allow(dead_code)]
mod fenwick {
    type T = i32;
    const ZERO: T = 0;
    pub struct Tree {
        a: Vec<T>,
    }
    impl Tree {
        pub fn new(n: usize) -> Tree {
            Tree {
                a: vec![ZERO; n + 1],
            }
        }
        pub fn add(&mut self, mut x: usize, v: T) {
            while x < self.a.len() {
                self.a[x] += v;
                x += x & (!x + 1);
            }
        }
        pub fn sum(&self, mut x: usize) -> T {
            debug_assert!(x < self.a.len());
            let mut res = ZERO;
            while x > 0 {
                res += self.a[x];
                x -= x & (!x + 1);
            }
            res
        }
        pub fn search(&self, s: T) -> usize {
            debug_assert!(self.sum(self.a.len() - 1) >= s);
            let mut k = 1;
            while 2 * k < self.a.len() {
                k *= 2;
            }
            let mut x = 0;
            let mut w = ZERO;
            while k > 0 {
                if k + x < self.a.len() && w + self.a[x + k] < s {
                    w += self.a[x + k];
                    x += k;
                }
                k >>= 1;
            }
            x + 1
        }
    }
}
// ---------- end fenwick tree ----------
//---------- begin scanner ----------
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
//---------- end scanner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn gcd(a: i64, b: i64) -> i64 {
    if a < b {
        gcd(b, a)
    } else if b < 0 {
        gcd(a, -b)
    } else if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn fix(x: i64, y: i64) -> (i64, i64) {
    let g = gcd(x, y);
    (x / g, y / g)
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let mut b = vec![];
    let mut left = vec![];
    let mut right = vec![];
    let mut z = vec![];
    let mut sum = 0;
    for _ in 0..n {
        let k: usize = sc.next();
        let mut a = vec![];
        for _ in 0..k {
            let x: i64 = sc.next();
            let y: i64 = sc.next();
            a.push((x, y));
        }
        for (&s, &t) in a.iter().zip(a.iter().cycle().skip(1)) {
            let p = fix(t.0 - s.0, t.1 - s.1);
            b.push(p);
            z.push(p);
        }
        left.push(sum);
        sum += k;
        right.push(sum);
    }
    let sum = sum;
    z.sort();
    z.dedup();
    let b: Vec<usize> = b.into_iter().map(|p| z.binary_search(&p).unwrap()).collect();
    let mut g = vec![vec![]; z.len()];
    for (i, &b) in b.iter().enumerate().rev() {
        g[b].push(i);
    }
    let q: usize = sc.next();
    let mut ask = vec![vec![]; sum];
    for i in 0..q {
        let l: usize = sc.next();
        let r: usize = sc.next();
        ask[left[l - 1]].push((right[r - 1], i));
    }
    let mut bit = fenwick::Tree::new(sum);
    for g in g.iter_mut() {
        let x = g.pop().unwrap();
        bit.add(x + 1, 1);
    }
    let mut ans = vec![0; q];
    for (l, ask) in ask.iter().enumerate() {
        for &(r, k) in ask.iter() {
            ans[k] = bit.sum(r);
        }
        bit.add(l + 1, -1);
        let x = b[l];
        if let Some(v) = g[x].pop() {
            bit.add(v + 1, 1);
        }
    }
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}
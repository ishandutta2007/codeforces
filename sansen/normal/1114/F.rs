// ---------- begin Lazy Segment Tree ----------
pub trait TE {
    type T: Clone;
    type E: Clone;
    fn fold(l: Self::T, r: Self::T) -> Self::T;
    fn eval(x: Self::T, f: Self::E) -> Self::T;
    fn merge(g: Self::E, h: Self::E) -> Self::E;
    fn e() -> Self::T;
    fn id() -> Self::E;
}

pub struct LazySegmentTree<R: TE> {
    size: usize,
    bit: usize,
    a: Vec<(R::T, R::E)>,
}

impl <R: TE> LazySegmentTree<R> {
    pub fn new(n: usize) -> LazySegmentTree<R> {
        let mut bit = 0;
        while (1 << bit) < n {
            bit += 1;
        }
        LazySegmentTree {
            size: 1 << bit,
            bit: bit,
            a: vec![(R::e(), R::id()); 2 << bit],
        }
    }
    pub fn build_by(z: &[R::T]) -> LazySegmentTree<R> {
        let n = z.len();
        let mut bit = 0;
        while (1 << bit) < n {
            bit += 1;
        }
        let mut a = vec![(R::e(), R::id()); 2 << bit];
        for (a, z) in a[(1 << bit)..].iter_mut().zip(z.iter()) {
            a.0 = z.clone();
        }
        for i in (1..(1 << bit)).rev() {
            let l = R::eval(a[2 * i].0.clone(), a[2 * i].1.clone());
            let r = R::eval(a[2 * i + 1].0.clone(), a[2 * i + 1].1.clone());
            a[i].0 = R::fold(l, r);
        }
        LazySegmentTree {
            size: 1 << bit,
            bit : bit,
            a: a,
        }
    }
    fn eval(&self, k: usize) -> R::T {
        R::eval(self.a[k].0.clone(), self.a[k].1.clone())
    }
    fn propagate(&mut self, x: usize) {
        let x = x + self.size;
        for i in (1..(self.bit + 1)).rev() {
            let k = x >> i;
            self.a[2 * k].1 = R::merge(self.a[2 * k].1.clone(), self.a[k].1.clone());
            self.a[2 * k + 1].1 = R::merge(self.a[2 * k + 1].1.clone(), self.a[k].1.clone());
            self.a[k].1 = R::id();
            self.a[k].0 = R::fold(self.eval(2 * k), self.eval(2 * k + 1));
        }
    }
    fn save(&mut self, x: usize) {
        let x = x + self.size;
        for i in 1..(self.bit + 1) {
            let k = x >> i;
            self.a[k].0 = R::fold(self.eval(2 * k), self.eval(2 * k + 1));
        }
    }
    pub fn update(&mut self, l: usize, r: usize, op: R::E) {
//        self.propagate(l);
//        self.propagate(r - 1);
        let mut x = l + self.size;
        let mut y = r + self.size;
        while x < y {
            if x & 1 == 1 {
                self.a[x].1 = R::merge(self.a[x].1.clone(), op.clone());
                x += 1;
            }
            if y & 1 == 1 {
                y -= 1;
                self.a[y].1 = R::merge(self.a[y].1.clone(), op.clone());
            }
            x >>= 1;
            y >>= 1;
        }
        self.save(l);
        self.save(r - 1);
    }
    pub fn find(&mut self, l: usize, r: usize) -> R::T {
        self.propagate(l);
        self.propagate(r - 1);
        let mut x = l + self.size;
        let mut y = r + self.size;
        let mut p = R::e();
        let mut q = R::e();
        while x < y {
            if x & 1 == 1 {
                p = R::fold(p, self.eval(x));
                x += 1;
            }
            if y & 1 == 1 {
                y -= 1;
                q = R::fold(self.eval(y), q);
            }
            x >>= 1;
            y >>= 1;
        }
        R::fold(p, q)
    }
}

// ---------- end Lazy Segment Tree ----------
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

const MOD: u32 = 1_000_000_007;

fn mul(a: u32, b: u32) -> u32 {
    (a as u64 * b as u64 % MOD as u64) as u32
}

fn mod_pow(r: u32, mut n: u32) -> u32 {
    let mut t = 1;
    let mut s = r;
    while n > 0 {
        if n & 1 == 1 {
            t = mul(t, s);
        }
        s = mul(s, s);
        n >>= 1;
    }
    t
}

struct MUL;
impl TE for MUL {
    type T = (u32, u32);
    type E = u32;
    fn fold(l: Self::T, r: Self::T) -> Self::T {
        (mul(l.0, r.0), l.1 + r.1)
    }
    fn eval(x: Self::T, f: Self::E) -> Self::T {
        (mul(x.0, mod_pow(f, x.1)), x.1)
    }
    fn merge(g: Self::E, h: Self::E) -> Self::E {
        mul(g, h)
    }
    fn e() -> Self::T {
        (1, 0)
    }
    fn id() -> Self::E {
        1
    }
}

struct ELEM;
impl TE for ELEM {
    type T = u64;
    type E = u64;
    fn fold(l: Self::T, r: Self::T) -> Self::T {
        l | r
    }
    fn eval(x: Self::T, f: Self::E) -> Self::T {
        x | f
    }
    fn merge(g: Self::E, h: Self::E) -> Self::E {
        g | h
    }
    fn e() -> Self::T {
        0
    }
    fn id() -> Self::E {
        0
    }
}

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let q: usize = sc.next();
    const L: usize = 62;
    const P: [u32; L] = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293];
    let mut ip = P.clone();
    for p in ip.iter_mut() {
        *p = mul(mod_pow(*p, MOD - 2), *p - 1)
    }
    let mut a: Vec<(u32, u32)> = (0..n).map(|_| (sc.next(), 1)).collect();
    let mut s = LazySegmentTree::<MUL>::build_by(&a);
    let mut elem = vec![0u64; n];
    for k in 0..L {
        let p = P[k];
        for i in 0..n {
            while a[i].0 % p == 0 {
                a[i].0 /= p;
                elem[i] |= 1u64 << k;
            }
        }
    }
    let mut u = LazySegmentTree::<ELEM>::build_by(&elem);
    for _ in 0..q {
        let op = sc.next_chars();
        let l = sc.next::<usize>() - 1;
        let r = sc.next::<usize>();
        if op[0] == 'M' {
            let mut x: u32 = sc.next();
            s.update(l, r, x);
            let mut b = 0u64;
            for i in 0..L {
                let p = P[i];
                while x % p == 0 {
                    x /= p;
                    b |= 1 << i;
                }
            }
            u.update(l, r, b);
        } else {
            let mut ans = s.find(l, r).0;
            let b = u.find(l, r);
            for i in 0..L {
                if (b >> i) & 1 == 0 {
                    continue;
                }
                ans = mul(ans, ip[i]);
            }
            writeln!(out, "{}", ans).unwrap();
        }
    }
}
// ---------- begin SegmentTree Point update Range query ----------
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
// ---------- end SegmentTree Point update Range query ----------

const MOD: u64 = (1u64 << 61) - 1;

#[derive(Clone, Copy, PartialEq, Eq)]
struct ModInt(u64);

impl std::ops::Add for ModInt {
    type Output = Self;
    fn add(self, rhs: Self) -> Self::Output {
        assert!(self.0 < MOD && rhs.0 < MOD);
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::Sub for ModInt {
    type Output = Self;
    fn sub(self, rhs: Self) -> Self::Output {
        assert!(self.0 < MOD && rhs.0 < MOD);
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::Mul for ModInt {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self::Output {
        assert!(self.0 < MOD && rhs.0 < MOD);
        const MASK31: u64 = (1u64 << 31) - 1;
        const MASK30: u64 = (1u64 << 30) - 1;
        let au = self.0 >> 31;
        let ad = self.0 & MASK31;
        let bu = rhs.0 >> 31;
        let bd = rhs.0 & MASK31;
        let mid = ad * bu + au * bd;
        let midu = mid >> 30;
        let midd = mid & MASK30;
        let sum = au * bu * 2 + midu + (midd << 31) + ad * bd;
        let mut ans = (sum >> 61) + (sum & MOD);
        if ans >= MOD {
            ans -= MOD;
        }
        ModInt(ans)
    }
}

impl ModInt {
    fn new(v: u64) -> Self {
        ModInt(v % MOD)
    }
    fn zero() -> Self {
        ModInt(0)
    }
    fn pow(&self, n: u64) -> Self {
        let mut t = ModInt(1);
        let mut s = *self;
        let mut n = n;
        while n > 0 {
            if n & 1 == 1 {
                t = t * s;
            }
            s = s * s;
            n >>= 1;
        }
        t
    }
    fn inv(&self) -> Self {
        assert!(self.0 > 0);
        self.pow(MOD - 2)
    }
}

pub const BASE_NUM: usize = 2;

#[derive(Clone, PartialEq, Eq)]
pub struct ModVector {
    val: [ModInt; BASE_NUM],
}

impl ModVector {
    pub fn zero() -> Self {
        ModVector {
            val: [ModInt::zero(); BASE_NUM],
        }
    }
    pub fn new(v: &[u64]) -> Self {
        assert!(v.len() >= BASE_NUM);
        let mut ans = ModVector::zero();
        for (x, a) in ans.val.iter_mut().zip(v.iter()) {
            *x = ModInt::new(*a);
        }
        ans
    }
    pub fn one(v: u64) -> Self {
        ModVector::new(&[v; BASE_NUM])
    }
    pub fn add(&self, rhs: &Self) -> Self {
        let mut ans = ModVector::zero();
        for (c, (a, b)) in ans.val.iter_mut().zip(self.val.iter().zip(rhs.val.iter())) {
            *c = *a + *b;
        }
        ans
    }
    pub fn sub(&self, rhs: &Self) -> Self {
        let mut ans = ModVector::zero();
        for (c, (a, b)) in ans.val.iter_mut().zip(self.val.iter().zip(rhs.val.iter())) {
            *c = *a - *b;
        }
        ans
    }
    pub fn mul(&self, rhs: &Self) -> Self {
        let mut ans = ModVector::zero();
        for (c, (a, b)) in ans.val.iter_mut().zip(self.val.iter().zip(rhs.val.iter())) {
            *c = *a * *b;
        }
        ans
    }
    pub fn inv(&self) -> Self {
        let mut ans = ModVector::zero();
        for (x, a) in ans.val.iter_mut().zip(self.val.iter()) {
            *x = a.inv();
        }
        ans
    }
}

pub fn rand_time() -> u32 {
    use std::time::{SystemTime, UNIX_EPOCH};
    SystemTime::now().duration_since(UNIX_EPOCH).unwrap().subsec_nanos()
}

pub fn rand_memory() -> u32 {
    Box::into_raw(Box::new("I hope this is a random number")) as u32
}

use std::io::Read;
use std::io::Write;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let t: Vec<u32> = it.next().unwrap().chars().map(|c| c.to_digit(10).unwrap()).collect();
    let rad = ModVector::new(&vec![rand_time() as u64, rand_memory() as u64]);
    let inv = rad.inv();
    let mut pow = vec![ModVector::new(&[1, 1])];
    for _ in 0..n {
        let v = pow.last().unwrap().mul(&rad);
        pow.push(v);
    }
    type T = (ModVector, usize, bool, bool);
    let fold = |a: T, b: T| -> T {
        if a.1 == 0 {
            return b;
        }
        if b.1 == 0 {
            return a;
        }
        if a.3 && b.2 {
            let mut val = a.0.sub(&ModVector::one(2).mul(&pow[a.1 - 1]));
            val = val.add(&pow[a.1 - 1].mul(&inv.mul(&b.0.sub(&ModVector::one(2)))));
            let len = a.1 + b.1 - 2;
            match (a.1 == 1, b.1 == 1) {
                (true, true) => (val, len, false, false),
                (true, false) => (val, len, false, b.3),
                (false, true) => (val, len, a.2, false),
                (false, false) => (val, len, a.2, b.3),
            }
        } else {
            let val = a.0.add(&b.0.mul(&pow[a.1]));
            let len = a.1 + b.1;
            (val, len, a.2, b.3)
        }
    };
    let mut seg = segment_tree::PURQ::new(n, (ModVector::zero(), 0, false, false), fold);
    for (i, &c) in t.iter().enumerate() {
        if c == 1 {
            seg.update_tmp(i, (ModVector::one(2), 1, true, true));
        } else {
            seg.update_tmp(i, (ModVector::one(1), 1, false, false));
        }
    }
    seg.update_all();
    let q: usize = it.next().unwrap().parse().unwrap();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for _ in 0..q {
        let a: usize = it.next().unwrap().parse().unwrap();
        let b: usize = it.next().unwrap().parse().unwrap();
        let len: usize = it.next().unwrap().parse().unwrap();
        let x = seg.find(a - 1, a - 1 + len);
        let y = seg.find(b - 1, b - 1 + len);
        let ans = if x == y {
            "Yes"
        } else {
            "No"
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
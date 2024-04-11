// ---------- begin ModInt ----------
const MOD: u32 = 998_244_353;
#[derive(Clone, Copy)]
struct ModInt(u32);

impl std::ops::Add for ModInt {
    type Output = ModInt;
    fn add(self, rhs: ModInt) -> ModInt {
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::Mul for ModInt {
    type Output = ModInt;
    fn mul(self, rhs: ModInt) -> ModInt {
        ModInt((self.0 as u64 * rhs.0 as u64 % MOD as u64) as u32)
    }
}

impl std::ops::Sub for ModInt {
    type Output = ModInt;
    fn sub(self, rhs: ModInt) -> ModInt {
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::Neg for ModInt {
    type Output = ModInt;
    fn neg(self) -> ModInt {
        if self.0 == 0 {self} else {ModInt(MOD - self.0)}
    }
}

impl std::ops::AddAssign for ModInt {
    fn add_assign(&mut self, rhs: ModInt) {
        *self = *self + rhs;
    }
}

impl std::ops::MulAssign for ModInt {
    fn mul_assign(&mut self, rhs: ModInt) {
        *self = *self * rhs;
    }
}

impl std::ops::SubAssign for ModInt {
    fn sub_assign(&mut self, rhs: ModInt) {
        *self = *self - rhs;
    }
}

#[allow(dead_code)]
impl ModInt {
    pub fn new(v: u32) -> ModInt {
        ModInt(v % MOD)
    }
    pub fn zero() -> ModInt {
        ModInt(0)
    }
    pub fn one() -> ModInt {
        ModInt(1)
    }
    pub fn pow(self, mut n: u32) -> ModInt {
        let mut t = ModInt::one();
        let mut s = self;
        while n > 0 {
            if n & 1 == 1 {
                t = t * s;
            }
            s = s * s;
            n >>= 1;
        }
        t
    }
    pub fn inv(self) -> ModInt {
        self.pow(MOD - 2)
    }
}
// ---------- end ModInt ----------
// ---------- begin NTT ----------
fn ntt(f: &mut [ModInt]) {
    let n = f.len();
    assert!(n.count_ones() == 1);
    let len = n.trailing_zeros() as usize;
    for i in 1..(n - 1){
        let mut x = i;
        let mut j = 0;
        for _ in 0..len {
            j = (j << 1) | (x & 1);
            x >>= 1;
        }
        if i < j {
            f.swap(i, j);
        }
    }
    for k in 0..(n.trailing_zeros() as usize) {
        let m = 1 << k;
        let z = ModInt(3).pow((MOD - 1) >> (k + 1) as u32);
        for j in 0..(n / (2 * m)) {
            let mut q = ModInt::one();
            for i in (2 * m * j)..(2 * m * j + m) {
                let a = f[i];
                let b = q * f[i + m];
                f[i] = a + b;
                f[i + m] = a - b;
                q *= z;
            }
        }
    }
}

fn intt(f: &mut [ModInt]) {
    ntt(f);
    f[1..].reverse();
    let ik = ModInt(f.len() as u32).inv();
    for f in f.iter_mut() {
        *f *= ik;
    }
}

fn multiply(a: &[ModInt], b: &[ModInt]) -> Vec<ModInt> {
    let n = a.len() + b.len() - 1;
    let mut k = 1;
    while k < n {
        k *= 2;
    }
    assert!(k <= (1 << 23));
    let mut f = Vec::with_capacity(k);
    let mut g = Vec::with_capacity(k);
    f.extend_from_slice(a);
    f.resize(k, ModInt::zero());
    ntt(&mut f);
    g.extend_from_slice(b);
    g.resize(k, ModInt::zero());
    ntt(&mut g);
    for (f, g) in f.iter_mut().zip(g.iter()) {
        *f *= *g;
    }
    intt(&mut f);
    f.resize(n, ModInt::zero());
    f
}
// ---------- end NTT ----------

use std::io::Read;
use std::cmp::*;

// 
struct Polynomial {
    a: Vec<ModInt>,
}

impl PartialEq for Polynomial {
    fn eq(&self, other: &Self) -> bool {
        self.a.len() == other.a.len()
    }
}

impl Eq for Polynomial {}

impl PartialOrd for Polynomial {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for Polynomial {
    fn cmp(&self, other: &Self) -> Ordering {
        other.a.len().cmp(&self.a.len())
    }
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let m = 3 * 1_000_000;
    let mut cnt = vec![0; m + 1];
    for s in it {
        let p: usize = s.parse().unwrap();
        cnt[p] += 1;
    }
    let mut h = std::collections::BinaryHeap::new();
    for i in 0..=m {
        if cnt[i] == 0 {
            continue;
        }
        let p: Vec<ModInt> = std::iter::repeat(ModInt::one()).take(cnt[i] + 1).collect();
        h.push(Polynomial{a: p});
    }
    while let Some(x) = h.pop() {
        if let Some(y) = h.pop() {
            let z = multiply(&x.a, &y.a);
            h.push(Polynomial{a: z});
        } else {
            let ans = x.a[n / 2];
            println!("{}", ans.0);
            return;
        }
    }
}

fn main() {
    run();
}
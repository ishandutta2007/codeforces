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

impl std::str::FromStr for ModInt {
    type Err = std::num::ParseIntError;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let v = s.parse::<u32>()?;
        Ok(ModInt(v))
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
// ---------- begin Precalc ----------
#[allow(dead_code)]
struct Precalc {
    n: usize,
    inv: Vec<ModInt>,
    fact: Vec<ModInt>,
    ifact: Vec<ModInt>,
}

#[allow(dead_code)]
impl Precalc {
    pub fn new(n: usize) -> Precalc {
        let mut inv = vec![ModInt::one(); n + 1];
        let mut fact = vec![ModInt::one(); n + 1];
        let mut ifact = vec![ModInt::one(); n + 1];
        for i in 2..(n + 1) {
            inv[i] = -inv[MOD as usize % i] * ModInt(MOD / i as u32);
            fact[i] = fact[i - 1] * ModInt(i as u32);
            ifact[i] = ifact[i - 1] * inv[i];
        }
        Precalc {
            n: n,
            inv: inv,
            fact: fact,
            ifact: ifact,
        }
    }
    pub fn fact(&self, n: usize) -> ModInt {
        self.fact[n]
    }
    pub fn comb(&self, n: usize, k: usize) -> ModInt {
        self.fact[n] * self.ifact[k] * self.ifact[n - k]
    }
    pub fn inv(&self, n: usize) -> ModInt {
        self.inv[n]
    }
}

// ---------- end Precalc ----------
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
use std::io::Write;

fn calc(a: &[ModInt]) -> Vec<ModInt> {
    let n = a.len();
    if n == 1 {
        return vec![ModInt::one(), a[0]];
    }
    let m = n / 2;
    let l = calc(&a[..m]);
    let r = calc(&a[m..]);
    multiply(&l, &r)
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let k: usize = it.next().unwrap().parse().unwrap();
    let a: Vec<ModInt> = (0..n).map(|_| it.next().unwrap().parse().unwrap()).collect();
    let q: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..q {
        let op: usize = it.next().unwrap().parse().unwrap();
        let q: ModInt = it.next().unwrap().parse().unwrap();
        let mut b = a.clone();
        if op == 1 {
            let k = it.next().unwrap().parse::<usize>().unwrap() - 1;
            let d: ModInt = it.next().unwrap().parse().unwrap();
            b[k] = d;
        } else {
            let l = it.next().unwrap().parse::<usize>().unwrap() - 1;
            let r = it.next().unwrap().parse::<usize>().unwrap();
            let d: ModInt = it.next().unwrap().parse().unwrap();
            for b in b[l..r].iter_mut() {
                *b += d;
            }
        }
        for b in b.iter_mut() {
            *b = q - *b;
        }
        let ans = calc(&b)[k];
        writeln!(out, "{}", ans.0).ok();
    }
}

fn main() {
    run();
}
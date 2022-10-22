// ---------- begin ModInt ----------
const MOD: u32 = 1_000_000_007;

#[derive(Clone, Copy)]
struct ModInt(u32);

use std::ops::{Add, AddAssign, Sub, SubAssign, Mul, MulAssign, Neg};

impl Add for ModInt {
    type Output = ModInt;
    fn add(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl AddAssign for ModInt {
    fn add_assign(&mut self, rhs: ModInt) {
        *self = *self + rhs;
    }
}

impl Sub for ModInt {
    type Output = ModInt;
    fn sub(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl SubAssign for ModInt {
    fn sub_assign(&mut self, rhs: ModInt) {
        *self = *self - rhs;
    }
}

impl Mul for ModInt {
    type Output = ModInt;
    fn mul(self, rhs: ModInt) -> Self::Output {
        ModInt((self.0 as u64 * rhs.0 as u64 % MOD as u64) as u32)
    }
}

impl MulAssign for ModInt {
    fn mul_assign(&mut self, rhs: ModInt) {
        *self = *self * rhs;
    }
}

impl Neg for ModInt {
    type Output = ModInt;
    fn neg(self) -> Self::Output {
        ModInt(if self.0 == 0 {0} else {MOD - self.0})
    }
}

#[allow(dead_code)]
impl ModInt {
    pub fn new(n: u32) -> ModInt {
        ModInt(n % MOD)
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
                t *= s;
            }
            s *= s;
            n >>= 1;
        }
        t
    }
    pub fn inv(self) -> ModInt {
        self.pow(MOD - 2)
    }
    pub fn comb(n: u32, k: u32) -> ModInt {
        if k > n {
            return ModInt::zero();
        }
        let k = std::cmp::min(k, n - k);
        let mut nu = ModInt::one();
        let mut de = ModInt::one();
        for i in 0..k {
            nu *= ModInt(n - i);
            de *= ModInt(i + 1);
        }
        nu * de.inv()
    }
}

#[allow(dead_code)]
struct Precalc {
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
            inv: inv,
            fact: fact,
            ifact: ifact,
        }
    }
    pub fn inv(&self, n: usize) -> ModInt {
        self.inv[n]
    }
    pub fn fact(&self, n: usize) -> ModInt {
        self.fact[n]
    }
    pub fn ifact(&self, n: usize) -> ModInt {
        self.ifact[n]
    }
    pub fn comb(&self, n: usize, k: usize) -> ModInt {
        if k > n {
            return ModInt::zero();
        }
        self.fact[n] * self.ifact[k] * self.ifact[n - k]
    }
}
// ---------- end ModInt ----------

fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let mut n: u64 = it.next().unwrap().parse().unwrap();
    let k: usize = it.next().unwrap().parse().unwrap();
    let pc = Precalc::new(50);
    let mut ans = ModInt::one();
    let mut d = 2u64;
    while d * d <= n {
        if n % d == 0 {
            let mut c = 0;
            while n % d == 0 {
                c += 1;
                n /= d;
            }
            let mut dp = vec![ModInt::zero(); c + 1];
            dp[c] = ModInt::one();
            for _ in 0..k {
                let mut next = vec![ModInt::zero(); c + 1];
                for i in 0..=c {
                    next[i] += dp[i] * pc.inv(i + 1);
                }
                for i in (0..c).rev() {
                    next[i] = next[i] + next[i + 1];
                }
                dp = next;
            }
            let mut s = ModInt::zero();
            let mut f = 1u64;
            for i in 0..=c {
                s += ModInt((f % MOD as u64) as u32) * dp[i];
                f *= d;
            }
            ans *= s;
        }
        d += 1;
    }
    if n > 1 {
        let p = pc.inv(2).pow(k as u32);
        ans *= (ModInt::one() - p) + ModInt((n % MOD as u64) as u32) * p;
    }
    println!("{}", ans.0);
}

fn main() {
    run();
}
// ---------- begin ModInt ----------
const MOD: u32 = 998_244_353;

#[derive(Clone, Copy)]
struct ModInt(u32);

impl std::ops::Add for ModInt {
    type Output = ModInt;
    fn add(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::AddAssign for ModInt {
    fn add_assign(&mut self, rhs: ModInt) {
        *self = *self + rhs;
    }
}

impl std::ops::Sub for ModInt {
    type Output = ModInt;
    fn sub(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::SubAssign for ModInt {
    fn sub_assign(&mut self, rhs: ModInt) {
        *self = *self - rhs;
    }
}

impl std::ops::Mul for ModInt {
    type Output = ModInt;
    fn mul(self, rhs: ModInt) -> Self::Output {
        ModInt((self.0 as u64 * rhs.0 as u64 % MOD as u64) as u32)
    }
}

impl std::ops::MulAssign for ModInt {
    fn mul_assign(&mut self, rhs: ModInt) {
        *self = *self * rhs;
    }
}

impl std::ops::Neg for ModInt {
    type Output = ModInt;
    fn neg(self) -> Self::Output {
        ModInt(if self.0 == 0 {0} else {MOD - self.0})
    }
}

impl std::fmt::Display for ModInt {
    fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
        write!(f, "{}", self.0)
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
use std::io::Read;

fn calc(a: &[bool]) -> Vec<ModInt> {
    let n = a.len();
    let mut dp1 = vec![ModInt::zero(); n];
    let mut dp2 = vec![ModInt::zero(); n];
    dp1[0] = ModInt::one();
    dp2[0] = ModInt::one();
    for i in 1..n {
        let mut next = dp1.clone();
        if !a[i] && !a[i - 1] {
            for j in 1..n {
                next[j] += dp2[j - 1];
            }
        }
        dp2 = dp1;
        dp1 = next;
    }
    dp1
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let h: usize = it.next().unwrap().parse().unwrap();
    let w: usize = it.next().unwrap().parse().unwrap();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut row = vec![false; h];
    let mut col = vec![false; w];
    for _ in 0..(2 * n) {
        let r = it.next().unwrap().parse::<usize>().unwrap() - 1;
        let c = it.next().unwrap().parse::<usize>().unwrap() - 1;
        row[r] = true;
        col[c] = true;
    }
    let a = calc(&row);
    let b = calc(&col);
    let row_free = row.iter().filter(|p| !**p).count();
    let col_free = col.iter().filter(|p| !**p).count();
    let pc = Precalc::new(h + w);
    let mut ans = ModInt::zero();
    for i in 0..=h {
        for j in 0..=w {
            if 2 * i + j <= row_free && i + 2 * j <= col_free {
                ans += a[i] * b[j] * pc.fact(row_free - 2 * i) * pc.ifact(row_free - 2 * i - j) * pc.fact(col_free - 2 * j) * pc.ifact(col_free - 2 * j - i);
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
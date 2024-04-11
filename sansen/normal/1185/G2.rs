// ---------- begin ModInt ----------
const MOD: u32 = 1_000_000_007;

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

impl std::str::FromStr for ModInt {
    type Err = std::num::ParseIntError;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let val = s.parse::<u32>()?;
        Ok(ModInt::new(val))
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
}
// ---------- end ModInt ----------
// ---------- begin Precalc ----------
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
// ---------- end Precalc ----------
use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let w: usize = it.next().unwrap().parse().unwrap();
    let mut a = vec![vec![]; 3];
    for _ in 0..n {
        let t: usize = it.next().unwrap().parse().unwrap();
        let g: usize = it.next().unwrap().parse().unwrap();
        a[g - 1].push(t);
    }
    let mut way = vec![vec![vec![vec![ModInt::zero(); a[2].len() + 2]; a[1].len() + 2]; a[0].len() + 2]; 3];
    way[0][1][0][0] = ModInt::one();
    way[1][0][1][0] = ModInt::one();
    way[2][0][0][1] = ModInt::one();
    for i in 0..=a[0].len() {
        for j in 0..=a[1].len() {
            for k in 0..=a[2].len() {
                for l in 0..3 {
                    let v = way[l][i][j][k];
                    for (g, &(x, y, z)) in [(i + 1, j, k), (i, j + 1, k), (i, j, k + 1)].iter().enumerate() {
                        if g != l {
                            way[g][x][y][z] += v;
                        }
                    }
                }
            }
        }
    }
    let mut dp1 = vec![vec![vec![ModInt::zero(); w + 1]; a[1].len() + 1]; a[0].len() + 1];
    dp1[0][0][0] = ModInt::one();
    for &b in a[0].iter() {
        for i in (1..=a[0].len()).rev() {
            for t in (b..=w).rev() {
                let v = dp1[i - 1][0][t - b];
                dp1[i][0][t] += v;
            }
        }
    }
    for &b in a[1].iter() {
        for i in 0..=a[0].len() {
            for j in (1..=a[1].len()).rev() {
                for t in (b..=w).rev() {
                    let v = dp1[i][j - 1][t - b];
                    dp1[i][j][t] += v;
                }
            }
        }
    }
    let mut dp2 = vec![vec![ModInt::zero(); w + 1]; a[2].len() + 1];
    dp2[0][0] = ModInt::one();
    for &b in a[2].iter() {
        for i in (1..=a[2].len()).rev() {
            for t in (b..=w).rev() {
                let v = dp2[i - 1][t - b];
                dp2[i][t] += v;
            }
        }
    }
    let pc = Precalc::new(n);
    let mut ans = ModInt::zero();
    for i in 0..=a[0].len() {
        for j in 0..=a[1].len() {
            for k in 0..=a[2].len() {
                for t in 0..=w {
                    let way = way[0][i][j][k] + way[1][i][j][k] + way[2][i][j][k];
                    ans += dp1[i][j][t] * dp2[k][w - t] * way * pc.fact(i) * pc.fact(j) * pc.fact(k);
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
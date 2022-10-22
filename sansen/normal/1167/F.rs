// ---------- begin ModInt ----------
const MOD: u32 = 1_000_000_007;

#[derive(Clone, Copy)]
pub struct ModInt(u32);

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

/* 
impl std::fmt::Display for ModInt {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}
*/

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
// ---------- begin fenwick tree ----------
#[allow(dead_code)]
mod fenwick {
    use super::ModInt;
    type T = ModInt;
    const ZERO: T = ModInt(0);
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
    }
}
// ---------- end fenwick tree ----------
use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let a: Vec<u32> = (0..n).map(|_| it.next().unwrap().parse().unwrap()).collect();
    let mut b = vec![];
    let mut left = fenwick::Tree::new(n);
    let mut right = fenwick::Tree::new(n);
    for i in 0..n {
        b.push((a[i], i));
        left.add(i + 1, ModInt(a[i]) * ModInt((i + 1) as u32));
        right.add(n - i, ModInt(a[i]) * ModInt((n - i) as u32));
    }
    b.sort();
    let mut ans = ModInt::zero();
    for (a, k) in b {
        let a = ModInt(a);
        ans += a * ModInt((k + 1) as u32) * ModInt((n - k) as u32);
        left.add(k + 1, -a * ModInt((k + 1) as u32));
        right.add(n - k, -a * ModInt((n - k) as u32));
        ans += left.sum(k + 1) * ModInt((n - k) as u32);
        ans += right.sum(n - k) * ModInt((k + 1) as u32);
    }
    println!("{}", ans.0);
}

fn main() {
    run();
}
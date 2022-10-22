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
fn z_algorithm<T: Eq>(s: &[T]) -> Vec<usize> {
    let len = s.len();
    let mut a = vec![0; len];
    a[0] = len;
    let mut i = 1;
    let mut j = 0;
    while i < len {
        while i + j < len && s[j] == s[i + j] {
            j += 1;
        }
        a[i] = j;
        if j == 0 {
            i += 1;
            continue;
        }
        let mut k = 1;
        while i + k < len && k + a[k] < j {
            a[i + k] = a[k];
            k += 1;
        }
        i += k;
        j -= k;
    }
    a
}

use std::io::Read;

fn calc_prefix(a: &[char], b: &[char]) -> Vec<usize> {
    let mut x = vec![];
    x.extend_from_slice(b);
    x.push('$');
    let len = x.len();
    x.extend_from_slice(a);
    z_algorithm(&x).split_off(len)
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let a: Vec<char> = it.next().unwrap().chars().collect();
    let l: Vec<char> = it.next().unwrap().chars().collect();
    let r: Vec<char> = it.next().unwrap().chars().collect();
    let x = calc_prefix(&a, &l);
    let y = calc_prefix(&a, &r);
    let n = a.len();
    let mut way = vec![ModInt::zero(); n + 2];
    way[n] = ModInt::one();
    let mut sum = vec![ModInt::zero(); n + 2];
    sum[n] = ModInt::one();
    for i in (0..n).rev() {
        sum[i] = sum[i + 1];
        if i + l.len() > n {
            continue;
        }
        if a[i] == '0' {
            if l[0] == '0' {
                way[i] = way[i + 1];
                sum[i] += way[i];
            }
            continue;
        }
        let p = if x[i] == l.len() || a[i + x[i]] > l[x[i]] {
            i + l.len()
        } else {
            i + l.len() + 1
        };
        let q = if i + r.len() > n {
            n
        } else if y[i] == r.len() || a[i + y[i]] < r[y[i]] {
            i + r.len()
        } else {
            i + r.len() - 1
        };
        way[i] = sum[p] - sum[q + 1];
        sum[i] += way[i];
    }
    println!("{}", way[0]);
}

fn main() {
    run();
}
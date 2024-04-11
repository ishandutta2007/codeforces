use std::io::Write;

fn run() {
    input! {
        n: usize,
        l: usize,
        r: usize,
        z: usize,
    }
    let pc = Precalc::new(n);
    let mut dp = vec![vec![vec![M::zero(); n + 1]; 2]; 2];
    dp[1][1][0] = M::one();
    for i in 0..60 {
        let mut next = vec![vec![vec![M::zero(); n + 1]; 2]; 2];
        let l = l >> i & 1;
        let r = r >> i & 1;
        let z = z >> i & 1;
        for (x, dp) in dp.iter().enumerate() {
            for (y, dp) in dp.iter().enumerate() {
                let mut mul = vec![M::zero(); n + 1];
                for (i, mul) in mul.iter_mut().enumerate() {
                    if i & 1 == z {
                        *mul = pc.binom(n, i);
                    }
                }
                let res = multiply(&dp, &mul, M::zero());
                for (sum, res) in res.iter().enumerate() {
                    let s = sum & 1;
                    let carry = sum / 2;
                    let nx = l < s || (l == s && x == 1);
                    let ny = s < r || (s == r && y == 1);
                    next[nx as usize][ny as usize][carry] += *res;
                }
                /*
                for (carry, dp) in dp.iter().enumerate() {
                    for i in 0..=n {
                        if i & 1 != z {
                            continue;
                        }
                        let sum = carry + i;
                        let s = sum & 1;
                        let carry = sum / 2;
                        let nx = l < s || (l == s && x == 1);
                        let ny = s < r || (s == r && y == 1);
                        next[nx as usize][ny as usize][carry] += *dp * pc.binom(n, i);
                    }
                }
                */
            }
        }
        dp = next;
    }
    let ans = dp[1][1][0];
    println!("{}", ans);
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------
// ---------- begin modint ----------
use std::marker::*;
use std::ops::*;

pub trait Modulo {
    fn modulo() -> u32;
}

pub struct ConstantModulo<const M: u32>;

impl<const M: u32> Modulo for ConstantModulo<{ M }> {
    fn modulo() -> u32 {
        M
    }
}

pub struct ModInt<T>(u32, PhantomData<T>);

impl<T> Clone for ModInt<T> {
    fn clone(&self) -> Self {
        Self::new_unchecked(self.0)
    }
}

impl<T> Copy for ModInt<T> {}

impl<T: Modulo> Add for ModInt<T> {
    type Output = ModInt<T>;
    fn add(self, rhs: Self) -> Self::Output {
        let mut v = self.0 + rhs.0;
        if v >= T::modulo() {
            v -= T::modulo();
        }
        Self::new_unchecked(v)
    }
}

impl<T: Modulo> AddAssign for ModInt<T> {
    fn add_assign(&mut self, rhs: Self) {
        *self = *self + rhs;
    }
}

impl<T: Modulo> Sub for ModInt<T> {
    type Output = ModInt<T>;
    fn sub(self, rhs: Self) -> Self::Output {
        let mut v = self.0 - rhs.0;
        if self.0 < rhs.0 {
            v += T::modulo();
        }
        Self::new_unchecked(v)
    }
}

impl<T: Modulo> SubAssign for ModInt<T> {
    fn sub_assign(&mut self, rhs: Self) {
        *self = *self - rhs;
    }
}

impl<T: Modulo> Mul for ModInt<T> {
    type Output = ModInt<T>;
    fn mul(self, rhs: Self) -> Self::Output {
        let v = self.0 as u64 * rhs.0 as u64 % T::modulo() as u64;
        Self::new_unchecked(v as u32)
    }
}

impl<T: Modulo> MulAssign for ModInt<T> {
    fn mul_assign(&mut self, rhs: Self) {
        *self = *self * rhs;
    }
}

impl<T: Modulo> Neg for ModInt<T> {
    type Output = ModInt<T>;
    fn neg(self) -> Self::Output {
        if self.is_zero() {
            Self::zero()
        } else {
            Self::new_unchecked(T::modulo() - self.0)
        }
    }
}

impl<T> std::fmt::Display for ModInt<T> {
    fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl<T> std::fmt::Debug for ModInt<T> {
    fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl<T> Default for ModInt<T> {
    fn default() -> Self {
        Self::zero()
    }
}

impl<T: Modulo> std::str::FromStr for ModInt<T> {
    type Err = std::num::ParseIntError;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let val = s.parse::<u32>()?;
        Ok(ModInt::new(val))
    }
}

impl<T: Modulo> From<usize> for ModInt<T> {
    fn from(val: usize) -> ModInt<T> {
        ModInt::new_unchecked((val % T::modulo() as usize) as u32)
    }
}

impl<T: Modulo> From<u64> for ModInt<T> {
    fn from(val: u64) -> ModInt<T> {
        ModInt::new_unchecked((val % T::modulo() as u64) as u32)
    }
}

impl<T: Modulo> From<i64> for ModInt<T> {
    fn from(val: i64) -> ModInt<T> {
        let mut v = ((val % T::modulo() as i64) + T::modulo() as i64) as u32;
        if v >= T::modulo() {
            v -= T::modulo();
        }
        ModInt::new_unchecked(v)
    }
}

impl<T> ModInt<T> {
    pub fn new_unchecked(n: u32) -> Self {
        ModInt(n, PhantomData)
    }
    pub fn zero() -> Self {
        ModInt::new_unchecked(0)
    }
    pub fn one() -> Self {
        ModInt::new_unchecked(1)
    }
    pub fn is_zero(&self) -> bool {
        self.0 == 0
    }
}

impl<T: Modulo> ModInt<T> {
    pub fn new(d: u32) -> Self {
        ModInt::new_unchecked(d % T::modulo())
    }
    pub fn pow(&self, mut n: u64) -> Self {
        let mut t = Self::one();
        let mut s = *self;
        while n > 0 {
            if n & 1 == 1 {
                t *= s;
            }
            s *= s;
            n >>= 1;
        }
        t
    }
    pub fn inv(&self) -> Self {
        assert!(!self.is_zero());
        self.pow(T::modulo() as u64 - 2)
    }
    pub fn fact(n: usize) -> Self {
        (1..=n).fold(Self::one(), |s, a| s * Self::from(a))
    }
    pub fn perm(n: usize, k: usize) -> Self {
        if k > n {
            return Self::zero();
        }
        ((n - k + 1)..=n).fold(Self::one(), |s, a| s * Self::from(a))
    }
    pub fn binom(n: usize, k: usize) -> Self {
        if k > n {
            return Self::zero();
        }
        let k = k.min(n - k);
        let mut nu = Self::one();
        let mut de = Self::one();
        for i in 0..k {
            nu *= Self::from(n - i);
            de *= Self::from(i + 1);
        }
        nu * de.inv()
    }
}
// ---------- end modint ----------
// ---------- begin precalc ----------
pub struct Precalc<T> {
    fact: Vec<ModInt<T>>,
    ifact: Vec<ModInt<T>>,
    inv: Vec<ModInt<T>>,
}

impl<T: Modulo> Precalc<T> {
    pub fn new(n: usize) -> Precalc<T> {
        let mut inv = vec![ModInt::one(); n + 1];
        let mut fact = vec![ModInt::one(); n + 1];
        let mut ifact = vec![ModInt::one(); n + 1];
        for i in 2..=n {
            fact[i] = fact[i - 1] * ModInt::new_unchecked(i as u32);
        }
        ifact[n] = fact[n].inv();
        if n > 0 {
            inv[n] = ifact[n] * fact[n - 1];
        }
        for i in (1..n).rev() {
            ifact[i] = ifact[i + 1] * ModInt::new_unchecked((i + 1) as u32);
            inv[i] = ifact[i] * fact[i - 1];
        }
        Precalc { fact, ifact, inv }
    }
    pub fn inv(&self, n: usize) -> ModInt<T> {
        assert!(n > 0);
        self.inv[n]
    }
    pub fn fact(&self, n: usize) -> ModInt<T> {
        self.fact[n]
    }
    pub fn ifact(&self, n: usize) -> ModInt<T> {
        self.ifact[n]
    }
    pub fn perm(&self, n: usize, k: usize) -> ModInt<T> {
        if k > n {
            return ModInt::zero();
        }
        self.fact[n] * self.ifact[n - k]
    }
    pub fn binom(&self, n: usize, k: usize) -> ModInt<T> {
        if k > n {
            return ModInt::zero();
        }
        self.fact[n] * self.ifact[k] * self.ifact[n - k]
    }
}
// ---------- end precalc ----------

type M = ModInt<ConstantModulo<1_000_000_007>>;

// ---------- begin karatsuba multiplication ----------
fn karatsuba<T>(a: &[T], b: &[T], c: &mut [T], zero: T, buf: &mut [T])
where T: std::marker::Copy +
         std::ops::Add<Output = T> +
         std::ops::Sub<Output = T> +
         std::ops::Mul<Output = T> +
{
    assert!(a.len() == b.len());
    let n = a.len();
    if n <= 16 {
        for (i, a) in a.iter().enumerate() {
            for (c, b) in c[i..].iter_mut().zip(b) {
                *c = *c + *a * *b;
            }
        }
        return;
    }
    if n & 1 == 1 {
        karatsuba(&a[1..], &b[1..], &mut c[2..], zero, buf);
        let x = a[0];
        let y = b[0];
        c[0] = c[0] + x * y;
        for ((c, a), b) in c[1..].iter_mut().zip(&a[1..]).zip(&b[1..]) {
            *c = *c + x * *b + *a * y;
        }
        return;
    }
    let m = n / 2;
    let (fa, ta) = a.split_at(m);
    let (fb, tb) = b.split_at(m);
    karatsuba(fa, fb, &mut c[..n], zero, buf);
    karatsuba(ta, tb, &mut c[n..], zero, buf);
    let (x, buf) = buf.split_at_mut(m);
    let (y, buf) = buf.split_at_mut(m);
    let (z, buf) = buf.split_at_mut(n);
    z.iter_mut().for_each(|z| *z = zero);
    let xpq = x.iter_mut().zip(fa).zip(ta);
    let yrs = y.iter_mut().zip(fb).zip(tb);
    for (((x, p), q), ((y, r), s)) in xpq.zip(yrs) {
        *x = *p + *q;
        *y = *r + *s;
    }
    karatsuba(x, y, z, zero, buf);
    for ((z, p), q) in z.iter_mut().zip(&c[..n]).zip(&c[n..]) {
        *z = *z - (*p + *q);
    }
    for (c, z) in c[m..].iter_mut().zip(z) {
        *c = *c + *z;
    }
}

pub fn multiply<T>(a: &[T], b: &[T], zero: T) -> Vec<T>
where T: std::marker::Copy +
         std::ops::Add<Output = T> +
         std::ops::Sub<Output = T> +
         std::ops::Mul<Output = T> +
{
    assert!(!a.is_empty() && !b.is_empty());
    let mut i = 0;
    let mut j = 0;
    let mut ans = vec![zero; a.len() + b.len() - 1];
    let mut buf = vec![zero; 4 * a.len().min(b.len())];
    let mut c = Vec::with_capacity(2 * a.len().min(b.len()));
    while i < a.len() && j < b.len() {
        let x = a.len() - i;
        let y = b.len() - j;
        let z = x.min(y);
        c.clear();
        c.resize(2 * z, zero);
        karatsuba(&a[i..(i + z)], &b[j..(j + z)], &mut c, zero, &mut buf);
        for (ans, c) in ans[(i + j)..].iter_mut().zip(c.iter()) {
            *ans = *ans + *c;
        }
        if x <= y {
            j += z;
        } else {
            i += z;
        }
    }
    ans.truncate(a.len() + b.len() - 1);
    ans
}
// ---------- end karatsuba multiplication ----------
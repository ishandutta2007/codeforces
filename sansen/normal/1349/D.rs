// sum_i a_i = m 
// E_m = 0
// E_0 = 1 + (n-2)/(n - 1) * E_0 + 1/(n - 1) * E_1
// E_i = 1 + (i/m) * E_{i - 1} + (m - i)/m * {(n - 2)/(n - 1) * E_i + 1/(n - 1) * E_{i + 1}}
// m(n - 1) E_i = m(n - 1) + i(n - 1)E_{i - 1} + (m - i)(n - 2)E_i + (m - i)E_{i + 1}
// E_i 
//
// S = sum_i P_{a_i} * E_{a_i}
// P_{a_i} * E_{a_i} = E_{a_i} - sum_{j != i} P_{a_j} * (E_{a_j} + E_{0})
// S = sum_i E_{a_i} - (n - 1)S - (n - 1)E_0

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let m = a.iter().sum::<usize>();
    let pc = Precalc::new(n + m);
    // const, E_0
    let mut dp = vec![P::zero(); m + 1];
    dp[0] = P(M::zero(), M::one());
    dp[1] = P(-M::from(n - 1), M::one());
    for i in 2..=m {
        let mut l = dp[i - 1] * M::from(m * (n - 1));
        l = l - P::one() * M::from(m * (n - 1));
        l = l - dp[i - 2] * M::from((i - 1) * (n - 1));
        l = l - dp[i - 1] * M::from((m - (i - 1)) * (n - 2));
        dp[i] = l * pc.inv(m - (i - 1));
    }
    let P(x, y) = dp[m];
    let v = -x * y.inv();
    let dp = dp.into_iter().map(|P(a, b)| a + b * v).collect::<Vec<_>>();
    let mut ans = -M::from(n - 1) * dp[0];
    for a in a {
        ans += dp[a];
    }
    ans *= M::from(n).inv();
    println!("{}", ans);
}

#[derive(Clone, Copy, Debug)]
struct P(M, M);

impl P {
    fn zero() -> Self {
        P(M::zero(), M::zero())
    }
    fn one() -> Self {
        P(M::one(), M::zero())
    }
}

impl Add for P {
    type Output = Self;
    fn add(self, rhs: Self) -> Self {
        P(self.0 + rhs.0, self.1 + rhs.1)
    }
}

impl Sub for P {
    type Output = Self;
    fn sub(self, rhs: Self) -> Self {
        P(self.0 - rhs.0, self.1 - rhs.1)
    }
}

impl Mul<M> for P {
    type Output = Self;
    fn mul(self, rhs: M) -> Self {
        P(self.0 * rhs, self.1 * rhs)
    }
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

type M = ModInt<ConstantModulo<998_244_353>>;
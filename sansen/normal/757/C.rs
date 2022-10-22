// ---------- begin Run Length Encoding ----------
fn run_length_encoding<T: Eq>(a: Vec<T>) -> Vec<(T, usize)> {
    let mut a = a.into_iter().map(|a| (a, 1)).collect::<Vec<_>>();
    a.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 += a.1;
            true
        }
    });
    a
}
// ---------- end Run Length Encoding ----------
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

fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let mut hash = vec![0; m];
    for _ in 0..n {
        let c: usize = sc.next();
        let mut a = sc.next_vec::<usize>(c);
        a.sort();
        let z = run_length_encoding(a);
        let mut map = std::collections::BTreeMap::new();
        for (v, c) in z {
            map.entry(c).or_insert(vec![]).push(v);
        }
        for (_, x) in map {
            let v = rand() * 3;
            for x in x {
                hash[x - 1] ^= v;
            }
        }
    }
    hash.sort();
    let z = run_length_encoding(hash);
    let pc = Precalc::new(m);
    let mut ans = M::one();
    for (_, c) in z {
        ans *= pc.fact(c);
    }
    println!("{}", ans);
}
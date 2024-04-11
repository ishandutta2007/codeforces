// ---------- begin ModInt ----------
mod modint {

    #[allow(dead_code)]
    pub struct Mod;
    impl ConstantModulo for Mod {
        const MOD: u32 = 1_000_000_007;
    }

    #[allow(dead_code)]
    pub struct StaticMod;
    static mut STATIC_MOD: u32 = 0;
    impl Modulo for StaticMod {
        fn modulo() -> u32 {
            unsafe { STATIC_MOD }
        }
    }

    #[allow(dead_code)]
    impl StaticMod {
        pub fn set_modulo(p: u32) {
            unsafe {
                STATIC_MOD = p;
            }
        }
    }

    use std::marker::*;
    use std::ops::*;

    pub trait Modulo {
        fn modulo() -> u32;
    }

    pub trait ConstantModulo {
        const MOD: u32;
    }

    impl<T> Modulo for T
    where
        T: ConstantModulo,
    {
        fn modulo() -> u32 {
            T::MOD
        }
    }

    pub struct ModularInteger<T>(pub u32, PhantomData<T>);

    impl<T> Clone for ModularInteger<T> {
        fn clone(&self) -> Self {
            ModularInteger::new_unchecked(self.0)
        }
    }

    impl<T> Copy for ModularInteger<T> {}

    impl<T: Modulo> Add for ModularInteger<T> {
        type Output = ModularInteger<T>;
        fn add(self, rhs: Self) -> Self::Output {
            let mut d = self.0 + rhs.0;
            if d >= T::modulo() {
                d -= T::modulo();
            }
            ModularInteger::new_unchecked(d)
        }
    }

    impl<T: Modulo> AddAssign for ModularInteger<T> {
        fn add_assign(&mut self, rhs: Self) {
            *self = *self + rhs;
        }
    }

    impl<T: Modulo> Sub for ModularInteger<T> {
        type Output = ModularInteger<T>;
        fn sub(self, rhs: Self) -> Self::Output {
            let mut d = T::modulo() + self.0 - rhs.0;
            if d >= T::modulo() {
                d -= T::modulo();
            }
            ModularInteger::new_unchecked(d)
        }
    }

    impl<T: Modulo> SubAssign for ModularInteger<T> {
        fn sub_assign(&mut self, rhs: Self) {
            *self = *self - rhs;
        }
    }

    impl<T: Modulo> Mul for ModularInteger<T> {
        type Output = ModularInteger<T>;
        fn mul(self, rhs: Self) -> Self::Output {
            let v = self.0 as u64 * rhs.0 as u64 % T::modulo() as u64;
            ModularInteger::new_unchecked(v as u32)
        }
    }

    impl<T: Modulo> MulAssign for ModularInteger<T> {
        fn mul_assign(&mut self, rhs: Self) {
            *self = *self * rhs;
        }
    }

    impl<T: Modulo> Neg for ModularInteger<T> {
        type Output = ModularInteger<T>;
        fn neg(self) -> Self::Output {
            if self.0 == 0 {
                Self::zero()
            } else {
                Self::new_unchecked(T::modulo() - self.0)
            }
        }
    }

    impl<T> std::fmt::Display for ModularInteger<T> {
        fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
            write!(f, "{}", self.0)
        }
    }

    impl<T: Modulo> std::str::FromStr for ModularInteger<T> {
        type Err = std::num::ParseIntError;
        fn from_str(s: &str) -> Result<Self, Self::Err> {
            let val = s.parse::<u32>()?;
            Ok(ModularInteger::new(val))
        }
    }

    impl<T: Modulo> From<usize> for ModularInteger<T> {
        fn from(val: usize) -> ModularInteger<T> {
            ModularInteger::new_unchecked((val % T::modulo() as usize) as u32)
        }
    }

    impl<T: Modulo> From<i64> for ModularInteger<T> {
        fn from(val: i64) -> ModularInteger<T> {
            let m = T::modulo() as i64;
            ModularInteger::new((val % m + m) as u32)
        }
    }

    #[allow(dead_code)]
    impl<T> ModularInteger<T> {
        pub fn new_unchecked(d: u32) -> Self {
            ModularInteger(d, PhantomData)
        }
        pub fn zero() -> Self {
            ModularInteger::new_unchecked(0)
        }
        pub fn one() -> Self {
            ModularInteger::new_unchecked(1)
        }
        pub fn is_zero(&self) -> bool {
            self.0 == 0
        }
    }

    #[allow(dead_code)]
    impl<T: Modulo> ModularInteger<T> {
        pub fn new(d: u32) -> Self {
            ModularInteger::new_unchecked(d % T::modulo())
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
            assert!(self.0 != 0);
            self.pow(T::modulo() as u64 - 2)
        }
    }

    #[allow(dead_code)]
    pub fn mod_pow(r: u64, mut n: u64, m: u64) -> u64 {
        let mut t = 1 % m;
        let mut s = r % m;
        while n > 0 {
            if n & 1 == 1 {
                t = t * s % m;
            }
            s = s * s % m;
            n >>= 1;
        }
        t
    }
}
// ---------- end ModInt ----------
// ---------- begin Precalc ----------
mod precalc {
    use super::modint::*;
    #[allow(dead_code)]
    pub struct Precalc<T> {
        inv: Vec<ModularInteger<T>>,
        fact: Vec<ModularInteger<T>>,
        ifact: Vec<ModularInteger<T>>,
    }
    #[allow(dead_code)]
    impl<T: Modulo> Precalc<T> {
        pub fn new(n: usize) -> Precalc<T> {
            let mut inv = vec![ModularInteger::one(); n + 1];
            let mut fact = vec![ModularInteger::one(); n + 1];
            let mut ifact = vec![ModularInteger::one(); n + 1];
            for i in 2..(n + 1) {
                fact[i] = fact[i - 1] * ModularInteger::new_unchecked(i as u32);
            }
            ifact[n] = fact[n].inv();
            if n > 0 {
                inv[n] = ifact[n] * fact[n - 1];
            }
            for i in (1..n).rev() {
                ifact[i] = ifact[i + 1] * ModularInteger::new_unchecked((i + 1) as u32);
                inv[i] = ifact[i] * fact[i - 1];
            }
            Precalc {
                inv: inv,
                fact: fact,
                ifact: ifact,
            }
        }
        pub fn inv(&self, n: usize) -> ModularInteger<T> {
            assert!(n > 0);
            self.inv[n]
        }
        pub fn fact(&self, n: usize) -> ModularInteger<T> {
            self.fact[n]
        }
        pub fn ifact(&self, n: usize) -> ModularInteger<T> {
            self.ifact[n]
        }
        pub fn perm(&self, n: usize, k: usize) -> ModularInteger<T> {
            if k > n {
                return ModularInteger::zero();
            }
            self.fact[n] * self.ifact[n - k]
        }
        pub fn comb(&self, n: usize, k: usize) -> ModularInteger<T> {
            if k > n {
                return ModularInteger::zero();
            }
            self.fact[n] * self.ifact[k] * self.ifact[n - k]
        }
    }
}
// ---------- end Precalc ----------
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;
use modint::*;
use precalc::*;
type ModInt = ModularInteger<Mod>;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

// len n
// sum[i = len..=n] binom(i - 1, len - 1) * 25^(-len) * 26^n * (25 / 26)^i

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let pc = Precalc::new(200_000);
    let rad = ModInt::new(25) * ModInt::new(26).inv();
    let n = 100_000usize;
    let mut memo = vec![vec![]];
    let batch = (n as f64).sqrt().ceil() as usize;
    let generate = |len: usize| -> Vec<ModInt> {
        let mut sum = vec![ModInt::zero(); n + 1];
        let mut mul = rad.pow(len as u64);
        for i in len..=n {
            sum[i] = sum[i - 1] + pc.comb(i - 1, len - 1) * mul;
            mul *= rad;
        }
        sum
    };
    for len in 1..=batch {
        memo.push(generate(len));
    }
    let m: usize = sc.next();
    let mut len = sc.next_chars().len();
    let mut now = vec![];
    if len > batch {
        now = generate(len);
    }
    for _ in 0..m {
        let op: usize = sc.next();
        if op == 1 {
            len = sc.next_chars().len();
            if len > batch {
                now = generate(len);
            }
        } else {
            let n: usize = sc.next();
            let ans = if n < len {
                ModInt::zero()
            } else if len <= batch {
                memo[len][n] * ModInt::new(25).inv().pow(len as u64) * ModInt::new(26).pow(n as u64)
            } else {
                now[n] * ModInt::new(25).inv().pow(len as u64) * ModInt::new(26).pow(n as u64)
            };
            writeln!(out, "{}", ans).ok();
        }
    }
}
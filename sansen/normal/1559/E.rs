// ---------- begin enumerate prime ----------
fn enumerate_prime<F>(n: usize, mut f: F)
where
    F: FnMut(usize),
{
    assert!(1 <= n && n <= 5 * 10usize.pow(8));
    let batch = (n as f64).sqrt().ceil() as usize;
    let mut is_prime = vec![true; batch + 1];
    for i in (2..).take_while(|p| p * p <= batch) {
        if is_prime[i] {
            let mut j = i * i;
            while let Some(p) = is_prime.get_mut(j) {
                *p = false;
                j += i;
            }
        }
    }
    let mut prime = vec![];
    for (i, p) in is_prime.iter().enumerate().skip(2) {
        if *p && i <= n {
            f(i);
            prime.push(i);
        }
    }
    let mut l = batch + 1;
    while l <= n {
        let r = std::cmp::min(l + batch, n + 1);
        is_prime.clear();
        is_prime.resize(r - l, true);
        for &p in prime.iter() {
            let mut j = (l + p - 1) / p * p - l;
            while let Some(is_prime) = is_prime.get_mut(j) {
                *is_prime = false;
                j += p;
            }
        }
        for (i, _) in is_prime.iter().enumerate().filter(|p| *p.1) {
            f(i + l);
        }
        l += batch;
    }
}
// ---------- end enumerate prime ----------
// ---------- begin ModInt ----------
// 
// Codeforces
// 
// new_unchecked x 0 <= x < modulo 
// ModInt 
// 
mod modint {

    use std::marker::*;
    use std::ops::*;

    pub trait Modulo {
        fn modulo() -> u32;
        fn rem() -> u32;
        fn ini() -> u64;
        fn reduce(x: u64) -> u32 {
            assert!(x < (Self::modulo() as u64) << 32);
            let b = (x as u32 * Self::rem()) as u64;
            let t = x + b * Self::modulo() as u64;
            let mut c = (t >> 32) as u32;
            if c >= Self::modulo() {
                c -= Self::modulo();
            }
            c as u32
        }
    }

    #[allow(dead_code)]
    pub enum Mod1_000_000_007 {}

    impl Modulo for Mod1_000_000_007 {
        fn modulo() -> u32 {
            1_000_000_007
        }
        fn rem() -> u32 {
            2226617417
        }
        fn ini() -> u64 {
            582344008
        }
    }

    #[allow(dead_code)]
    pub enum Mod998_244_353 {}

    impl Modulo for Mod998_244_353 {
        fn modulo() -> u32 {
            998_244_353
        }
        fn rem() -> u32 {
            998244351
        }
        fn ini() -> u64 {
            932051910
        }
    }

    #[allow(dead_code)]
    pub fn generate_umekomi_modulo(p: u32) {
        assert!(p < (1 << 31) && p > 2 && p & 1 == 1 && (2u32..).take_while(|v| v * v <= p).all(|k| p % k != 0));
        let mut t = 1u32;
        let mut s = !p + 1;
        let mut n = !0u32 >> 2;
        while n > 0 {
            if n & 1 == 1 {
                t *= s;
            }
            s *= s;
            n >>= 1;
        }
        let mut ini = (1u64 << 32) % p as u64;
        ini = (ini << 32) % p as u64;
        assert!(t * p == !0);
        println!("pub enum Mod{} {{}}", p);
        println!("impl Modulo for Mod{} {{", p);
        println!("    fn modulo() -> u32 {{");
        println!("        {}", p);
        println!("    }}");
        println!("    fn rem() -> u32 {{");
        println!("        {}", t);
        println!("    }}");
        println!("    fn ini() -> u32 {{");
        println!("        {}", ini);
        println!("    }}");
        println!("}}");
        let mut f = vec![];
        let mut n = p - 1;
        for i in 2.. {
            if i * i > n {
                break;
            }
            if n % i == 0 {
                f.push(i);
                while n % i == 0 {
                    n /= i;
                }
            }
        }
        if n > 1 {
            f.push(n);
        }
        let mut order = 1;
        let mut n = p - 1;
        while n % 2 == 0 {
            n /= 2;
            order <<= 1;
        }
        let z = (2u64..).find(|z| {
            f.iter().all(|f| mod_pow(*z, ((p - 1) / *f) as u64, p as u64) != 1)
        }).unwrap();
        let zeta = mod_pow(z, ((p - 1) / order) as u64, p as u64);
        println!("impl transform::NTTFriendly for Mod{} {{", p);
        println!("    fn order() -> usize {{");
        println!("        {}", order);
        println!("    }}");
        println!("    fn zeta() -> u32 {{");
        println!("        {}", zeta);
        println!("    }}");
        println!("}}");
    }

    pub struct ModInt<T>(u32, PhantomData<T>);

    impl<T> Clone for ModInt<T> {
        fn clone(&self) -> Self {
            ModInt::build(self.0)
        }
    }

    impl<T> Copy for ModInt<T> {}

    impl<T: Modulo> Add for ModInt<T> {
        type Output = ModInt<T>;
        fn add(self, rhs: Self) -> Self::Output {
            let mut d = self.0 + rhs.0;
            if d >= T::modulo() {
                d -= T::modulo();
            }
            Self::build(d)
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
            let mut d = self.0 - rhs.0;
            if d >= T::modulo() {
                d += T::modulo();
            }
            Self::build(d)
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
            Self::build(T::reduce(self.0 as u64 * rhs.0 as u64))
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
            if self.0 == 0 {
                Self::zero()
            } else {
                Self::build(T::modulo() - self.0)
            }
        }
    }

    impl<T: Modulo> std::fmt::Display for ModInt<T> {
        fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
            write!(f, "{}", self.get())
        }
    }

    impl<T: Modulo> std::fmt::Debug for ModInt<T> {
        fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
            write!(f, "{}", self.get())
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
            let m = T::modulo() as i64;
            ModInt::new((val % m + m) as u32)
        }
    }

    #[allow(dead_code)]
    impl<T> ModInt<T> {
        fn build(d: u32) -> Self {
            ModInt(d, PhantomData)
        }
        pub fn zero() -> Self {
            Self::build(0)
        }
        pub fn is_zero(&self) -> bool {
            self.0 == 0
        }
    }

    #[allow(dead_code)]
    impl<T: Modulo> ModInt<T> {
        pub fn new_unchecked(d: u32) -> Self {
            Self::build(T::reduce(d as u64 * T::ini()))
        }
        pub fn new(d: u32) -> Self {
            Self::new_unchecked(d % T::modulo())
        }
        pub fn one() -> Self {
            Self::new_unchecked(1)
        }
        pub fn get(&self) -> u32 {
            T::reduce(self.0 as u64)
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
            self.pow((T::modulo() - 2) as u64)
        }
    }

    pub fn mod_pow(mut r: u64, mut n: u64, m: u64) -> u64 {
        let mut t = 1 % m;
        while n > 0 {
            if n & 1 == 1 {
                t = t * r % m;
            }
            r = r * r % m;
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
        inv: Vec<ModInt<T>>,
        fact: Vec<ModInt<T>>,
        ifact: Vec<ModInt<T>>,
    }
    #[allow(dead_code)]
    impl<T: Modulo> Precalc<T> {
        pub fn new(n: usize) -> Precalc<T> {
            let mut inv = vec![ModInt::one(); n + 1];
            let mut fact = vec![ModInt::one(); n + 1];
            let mut ifact = vec![ModInt::one(); n + 1];
            for i in 2..(n + 1) {
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
            Precalc {
                inv: inv,
                fact: fact,
                ifact: ifact,
            }
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
        pub fn comb(&self, n: usize, k: usize) -> ModInt<T> {
            if k > n {
                return ModInt::zero();
            }
            self.fact[n] * self.ifact[k] * self.ifact[n - k]
        }
    }
}
// ---------- end Precalc ----------
// ---------- begin NTT ----------
#[allow(dead_code)]
mod transform {
    use super::modint::*;
    pub trait NTTFriendly: Modulo {
        fn order() -> usize;
        fn zeta() -> u32;
    }
    pub fn ntt<T: NTTFriendly>(f: &mut [ModInt<T>]) {
        let n = f.len();
        assert!(n.count_ones() == 1);
        assert!(n <= T::order());
        let len = n.trailing_zeros() as usize;
        let mut zeta = Vec::with_capacity(len);
        let mut r = ModInt::new_unchecked(T::zeta()).pow((T::order() >> len) as u64);
        for _ in 0..len {
            zeta.push(r);
            r = r * r;
        }
        let mut q = Vec::with_capacity(len / 2);
        for (k, &z) in zeta.iter().rev().enumerate().rev() {
            let m = 1 << k;
            q.clear();
            let mut r = ModInt::one();
            for _ in 0..m {
                q.push(r);
                r *= z;
            }
            for f in f.chunks_exact_mut(2 * m) {
                let (x, y) = f.split_at_mut(m);
                for ((x, y), q) in x.iter_mut().zip(y.iter_mut()).zip(q.iter()) {
                    let a = *x;
                    let b = *y;
                    *x = a + b;
                    *y = (a - b) * *q;
                }
            }
        }
    }
    pub fn intt<T: NTTFriendly>(f: &mut [ModInt<T>]) {
        let n = f.len();
        assert!(n.count_ones() == 1);
        assert!(n <= T::order());
        let len = n.trailing_zeros() as usize;
        let mut zeta = Vec::with_capacity(len);
        let mut r = ModInt::new_unchecked(T::zeta()).inv().pow((T::order() >> len) as u64);
        for _ in 0..len {
            zeta.push(r);
            r = r * r;
        }
        let mut q = Vec::with_capacity(len / 2);
        for (k, &z) in zeta.iter().rev().enumerate() {
            let m = 1 << k;
            q.clear();
            let mut r = ModInt::one();
            for _ in 0..m {
                q.push(r);
                r *= z;
            }
            for f in f.chunks_exact_mut(2 * m) {
                let (x, y) = f.split_at_mut(m);
                for ((x, y), q) in x.iter_mut().zip(y.iter_mut()).zip(q.iter()) {
                    let a = *x;
                    let b = *y * *q;
                    *x = a + b;
                    *y = a - b;
                }
            }
        }
        let ik = ModInt::new_unchecked((T::modulo() + 1) >> 1).pow(len as u64);
        for f in f.iter_mut() {
            *f *= ik;
        }
    }
    pub fn multiply<T: NTTFriendly>(a: &[ModInt<T>], b: &[ModInt<T>]) -> Vec<ModInt<T>> {
        if a.is_empty() || b.is_empty() {
            return vec![];
        }
        let n = a.len() + b.len() - 1;
        let k = n.next_power_of_two();
        assert!(k <= T::order());
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
        f.truncate(n);
        f
    }
}
// ---------- end NTT ----------

use modint::*;

type M = ModInt<Mod998_244_353>;

impl transform::NTTFriendly for Mod998_244_353 {
    fn order() -> usize {
        8388608
    }
    fn zeta() -> u32 {
        15311432
    }
}


// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

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

fn run() {
    input! {
        n: usize,
        m: usize,
        p: [(usize, usize); n],
    }
    let mut prime = vec![];
    enumerate_prime(m, |p| {
        prime.push(p);
    });
    let mut dp = vec![M::zero(); m + 1];
    dp[1] = M::one();
    let mut dfs = vec![(1, 0)];
    while let Some((x, mut k)) = dfs.pop() {
        let s = dp[x];
        while k < prime.len() && prime[k] <= m / x {
            dp[x * prime[k]] = -s;
            dfs.push((x * prime[k], k + 1));
            k += 1;
        }
    }
    let mut ans = M::zero();
    for (i, &sign) in dp.iter().enumerate() {
        if sign.is_zero() {
            continue;
        }
        let m = m / i;
        let mut dp = vec![M::one()];
        for &(l, r) in p.iter() {
            let r = r / i;
            let l = (l + i - 1) / i;
            if l > r {
                dp = vec![];
                break;
            }
            let mut next = vec![M::zero(); dp.len() + r + 1];
            for (i, &v) in dp.iter().enumerate() {
                next[i + l] += v;
                next[i + r + 1] -= v;
            }
            for i in 1..next.len() {
                next[i] = next[i] + next[i - 1];
            }
            dp = next;
            dp.truncate(m + 1);
        }
        ans += sign * dp.iter().fold(M::zero(), |s, a| s + *a);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
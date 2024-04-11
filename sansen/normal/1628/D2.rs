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
            debug_assert!(x < (Self::modulo() as u64) << 32);
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
        assert!(
            p < (1 << 31)
                && p > 2
                && p & 1 == 1
                && (2u32..).take_while(|v| v * v <= p).all(|k| p % k != 0)
        );
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
        println!("    fn ini() -> u64 {{");
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
        let z = (2u64..)
            .find(|z| {
                f.iter()
                    .all(|f| mod_pow(*z, ((p - 1) / *f) as u64, p as u64) != 1)
            })
            .unwrap();
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
            if self.0 < rhs.0 {
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

use modint::*;

pub trait NTTFriendly: modint::Modulo {
    fn order() -> usize;
    fn zeta() -> u32;
}

type M = ModInt<Mod1_000_000_007>;

// 
// modint, primitive type 
// +, -, *
// zero 
//
// 
// 
// dotok
// 
// 0
// dot
// dot?
// 0

use std::ops::*;

pub trait Zero: Sized + Add<Output = Self> {
    fn zero() -> Self;
}

pub fn zero<T: Zero>() -> T {
    T::zero()
}

impl<T: Modulo> Zero for ModInt<T> {
    fn zero() -> Self {
        Self::zero()
    }
}

impl Zero for usize {
    fn zero() -> Self {
        0
    }
}

pub trait ArrayAdd {
    type Item;
    fn add(&self, rhs: &[Self::Item]) -> Vec<Self::Item>;
}

impl<T> ArrayAdd for [T]
where
    T: Zero + Copy,
{
    type Item = T;
    fn add(&self, rhs: &[Self::Item]) -> Vec<Self::Item> {
        let mut c = vec![T::zero(); self.len().max(rhs.len())];
        c[..self.len()].copy_from_slice(self);
        c.add_assign(rhs);
        c
    }
}

pub trait ArrayAddAssign {
    type Item;
    fn add_assign(&mut self, rhs: &[Self::Item]);
}

impl<T> ArrayAddAssign for [T]
where
    T: Add<Output = T> + Copy,
{
    type Item = T;
    fn add_assign(&mut self, rhs: &[Self::Item]) {
        assert!(self.len() >= rhs.len());
        self.iter_mut().zip(rhs).for_each(|(x, a)| *x = *x + *a);
    }
}

impl<T> ArrayAddAssign for Vec<T>
where
    T: Zero + Add<Output = T> + Copy,
{
    type Item = T;
    fn add_assign(&mut self, rhs: &[Self::Item]) {
        if self.len() < rhs.len() {
            self.resize(rhs.len(), T::zero());
        }
        self.as_mut_slice().add_assign(rhs);
    }
}

pub trait ArraySub {
    type Item;
    fn sub(&self, rhs: &[Self::Item]) -> Vec<Self::Item>;
}

impl<T> ArraySub for [T]
where
    T: Zero + Sub<Output = T> + Copy,
{
    type Item = T;
    fn sub(&self, rhs: &[Self::Item]) -> Vec<Self::Item> {
        let mut c = vec![T::zero(); self.len().max(rhs.len())];
        c[..self.len()].copy_from_slice(self);
        c.sub_assign(rhs);
        c
    }
}

pub trait ArraySubAssign {
    type Item;
    fn sub_assign(&mut self, rhs: &[Self::Item]);
}

impl<T> ArraySubAssign for [T]
where
    T: Sub<Output = T> + Copy,
{
    type Item = T;
    fn sub_assign(&mut self, rhs: &[Self::Item]) {
        assert!(self.len() >= rhs.len());
        self.iter_mut().zip(rhs).for_each(|(x, a)| *x = *x - *a);
    }
}

impl<T> ArraySubAssign for Vec<T>
where
    T: Zero + Sub<Output = T> + Copy,
{
    type Item = T;
    fn sub_assign(&mut self, rhs: &[Self::Item]) {
        if self.len() < rhs.len() {
            self.resize(rhs.len(), T::zero());
        }
        self.as_mut_slice().sub_assign(rhs);
    }
}

pub trait ArrayDot {
    type Item;
    fn dot(&self, rhs: &[Self::Item]) -> Vec<Self::Item>;
}

impl<T> ArrayDot for [T]
where
    T: Mul<Output = T> + Copy,
{
    type Item = T;
    fn dot(&self, rhs: &[Self::Item]) -> Vec<Self::Item> {
        assert!(self.len() == rhs.len());
        self.iter().zip(rhs).map(|p| *p.0 * *p.1).collect()
    }
}

pub trait ArrayDotAssign {
    type Item;
    fn dot_assign(&mut self, rhs: &[Self::Item]);
}

impl<T> ArrayDotAssign for [T]
where
    T: MulAssign + Copy,
{
    type Item = T;
    fn dot_assign(&mut self, rhs: &[Self::Item]) {
        assert!(self.len() == rhs.len());
        self.iter_mut().zip(rhs).for_each(|(x, a)| *x *= *a);
    }
}

pub trait ArrayMul {
    type Item;
    fn mul(&self, rhs: &[Self::Item]) -> Vec<Self::Item>;
}

impl<T> ArrayMul for [T]
where
    T: Zero + Mul<Output = T> + Copy,
{
    type Item = T;
    fn mul(&self, rhs: &[Self::Item]) -> Vec<Self::Item> {
        if self.is_empty() || rhs.is_empty() {
            return vec![];
        }
        let mut res = vec![zero(); self.len() + rhs.len() - 1];
        for (i, a) in self.iter().enumerate() {
            for (c, b) in res[i..].iter_mut().zip(rhs) {
                *c = *c + *a * *b;
            }
        }
        res
    }
}

pub trait ArrayNTT {
    type Item;
    fn ntt(&mut self);
    fn intt(&mut self);
    fn multiply(&self, rhs: &[Self::Item]) -> Vec<Self::Item>;
}

impl<T> ArrayNTT for [ModInt<T>]
where
    T: NTTFriendly,
{
    type Item = ModInt<T>;
    fn ntt(&mut self) {
        let f = self;
        let n = f.len();
        assert!(n.count_ones() == 1);
        assert!(n <= T::order());
        let len = n.trailing_zeros() as usize;
        let mut es = [ModInt::zero(); 30];
        let mut ies = [ModInt::zero(); 30];
        let mut sum_e = [ModInt::zero(); 30];
        let cnt2 = T::order().trailing_zeros() as usize;
        let mut e = ModInt::new_unchecked(T::zeta());
        let mut ie = e.inv();
        for i in (2..=cnt2).rev() {
            es[i - 2] = e;
            ies[i - 2] = ie;
            e = e * e;
            ie = ie * ie;
        }
        let mut now = ModInt::one();
        for i in 0..(cnt2 - 1) {
            sum_e[i] = es[i] * now;
            now *= ies[i];
        }
        for ph in 1..=len {
            let p = 1 << (len - ph);
            let mut now = ModInt::one();
            for (i, f) in f.chunks_exact_mut(2 * p).enumerate() {
                let (x, y) = f.split_at_mut(p);
                for (x, y) in x.iter_mut().zip(y.iter_mut()) {
                    let l = *x;
                    let r = *y * now;
                    *x = l + r;
                    *y = l - r;
                }
                now *= sum_e[(!i).trailing_zeros() as usize];
            }
        }
    }
    fn intt(&mut self) {
        let f = self;
        let n = f.len();
        assert!(n.count_ones() == 1);
        assert!(n <= T::order());
        let len = n.trailing_zeros() as usize;
        let mut es = [ModInt::zero(); 30];
        let mut ies = [ModInt::zero(); 30];
        let mut sum_ie = [ModInt::zero(); 30];
        let cnt2 = T::order().trailing_zeros() as usize;
        let mut e = ModInt::new_unchecked(T::zeta());
        let mut ie = e.inv();
        for i in (2..=cnt2).rev() {
            es[i - 2] = e;
            ies[i - 2] = ie;
            e = e * e;
            ie = ie * ie;
        }
        let mut now = ModInt::one();
        for i in 0..(cnt2 - 1) {
            sum_ie[i] = ies[i] * now;
            now *= es[i];
        }
        for ph in (1..=len).rev() {
            let p = 1 << (len - ph);
            let mut inow = ModInt::one();
            for (i, f) in f.chunks_exact_mut(2 * p).enumerate() {
                let (x, y) = f.split_at_mut(p);
                for (x, y) in x.iter_mut().zip(y.iter_mut()) {
                    let l = *x;
                    let r = *y;
                    *x = l + r;
                    *y = (l - r) * inow;
                }
                inow *= sum_ie[(!i).trailing_zeros() as usize];
            }
        }
        let ik = ModInt::new_unchecked((T::modulo() + 1) >> 1).pow(len as u64);
        for f in f.iter_mut() {
            *f *= ik;
        }
    }
    fn multiply(&self, rhs: &[Self::Item]) -> Vec<Self::Item> {
        if self.len().min(rhs.len()) <= 32 {
            return self.mul(rhs);
        }
        let size = (self.len() + rhs.len() - 1).next_power_of_two();
        let mut f = vec![ModInt::zero(); size];
        let mut g = vec![ModInt::zero(); size];
        f[..self.len()].copy_from_slice(self);
        g[..rhs.len()].copy_from_slice(rhs);
        f.ntt();
        g.ntt();
        f.dot_assign(&g);
        f.intt();
        f.truncate(self.len() + rhs.len() - 1);
        f
    }
}

pub trait PolynomialOperation {
    type Item;
    fn eval(&self, x: Self::Item) -> Self::Item;
    fn derivative(&self) -> Vec<Self::Item>;
    fn integral(&self) -> Vec<Self::Item>;
}

impl<T: Modulo> PolynomialOperation for [ModInt<T>] {
    type Item = ModInt<T>;
    fn eval(&self, x: Self::Item) -> Self::Item {
        self.iter().rev().fold(ModInt::zero(), |s, a| s * x + *a)
    }
    fn derivative(&self) -> Vec<Self::Item> {
        if self.len() <= 1 {
            return vec![];
        }
        self[1..]
            .iter()
            .enumerate()
            .map(|(k, a)| ModInt::new_unchecked(k as u32 + 1) * *a)
            .collect()
    }
    fn integral(&self) -> Vec<Self::Item> {
        if self.is_empty() {
            return vec![];
        }
        let mut inv = vec![ModInt::one(); self.len() + 1];
        let mut mul = ModInt::zero();
        for i in 1..=self.len() {
            mul += ModInt::one();
            inv[i] = inv[i - 1] * mul;
        }
        let mut prod = inv[self.len()].inv();
        for i in (1..=self.len()).rev() {
            inv[i] = self[i - 1] * inv[i - 1] * prod;
            prod *= mul;
            mul -= ModInt::one();
        }
        inv[0] = ModInt::zero();
        inv
    }
}

pub trait FPSOperation {
    type Item;
    fn inverse(&self, n: usize) -> Vec<Self::Item>;
    fn log(&self, n: usize) -> Vec<Self::Item>;
    fn exp(&self, n: usize) -> Vec<Self::Item>;
}

impl<T: NTTFriendly> FPSOperation for [ModInt<T>] {
    type Item = ModInt<T>;
    fn inverse(&self, n: usize) -> Vec<Self::Item> {
        assert!(self.len() > 0 && !self[0].is_zero());
        let len = n.next_power_of_two();
        assert!(2 * len <= T::order());
        let mut b = vec![ModInt::zero(); n];
        b[0] = self[0].inv();
        let mut f = Vec::with_capacity(2 * len);
        let mut g = Vec::with_capacity(2 * len);
        let mut size = 1;
        while size < n {
            g.clear();
            g.extend(b.iter().take(size));
            g.resize(2 * size, ModInt::zero());
            f.clear();
            f.extend(self.iter().take(2 * size));
            f.resize(2 * size, ModInt::zero());
            f.ntt();
            g.ntt();
            f.dot_assign(&g);
            f.intt();
            f[..size].iter_mut().for_each(|f| *f = ModInt::zero());
            f.ntt();
            f.dot_assign(&g);
            f.intt();
            for (b, g) in b[size..].iter_mut().zip(&f[size..]) {
                *b = *b - *g;
            }
            size *= 2;
        }
        b
    }
    fn log(&self, n: usize) -> Vec<Self::Item> {
        assert!(self.get(0).map_or(false, |p| p.get() == 1));
        let mut b = self.derivative().multiply(&self.inverse(n));
        b.truncate(n - 1);
        let mut b = b.integral();
        b.resize(n, ModInt::zero());
        b
    }
    fn exp(&self, n: usize) -> Vec<Self::Item> {
        assert!(self.get(0).map_or(true, |a| a.is_zero()));
        assert!(n <= T::order());
        let mut b = vec![ModInt::one()];
        let mut size = 1;
        while size < n {
            size <<= 1;
            let f = b.log(size);
            let g = self[..self.len().min(size)].sub(&f);
            b = b.multiply(&g).add(&b);
            b.truncate(size);
        }
        b.truncate(n);
        b.resize(n, ModInt::zero());
        b
    }
}

// test
//  yuki907: https://yukicoder.me/submissions/712523
//  hhkb2020: https://atcoder.jp/contests/hhkb2020/submissions/26997806
//

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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 
// subk
// add0
// add a, sub b
// dp[a][b] = max_x min(x + dp[a - 1][b], -x + dp[a][b - 1])

fn run() {
    input! {
        t: usize,
        ask: [(usize, usize, usize); t],
    }
    let pc = precalc::Precalc::new(2000000);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, m, k) in ask {
        let add = m;
        let sub = n - m;
        let mut ans = M::zero();
        if sub == 0 {
            ans = M::from(add * k);
        } else {
            let inv = M::new(2).inv();
            for i in 1..=add {
                ans += M::from(k * i)
                    * pc.comb(add - i + sub - 1, sub - 1)
                    * inv.pow((add - i + sub) as u64);
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
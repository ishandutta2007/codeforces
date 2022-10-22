// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(T, T) -> T> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(T, T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(a[2 * k].clone(), a[2 * k + 1].clone());
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.n)).rev() {
                self.a[k] = (self.op)(self.a[2 * k].clone(), self.a[2 * k + 1].clone());
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(p, self.a[l].clone());
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(self.a[r].clone(), q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(p, q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
// ---------- begin Matrix ----------
#[allow(dead_code)]
mod matrix {
    use std::ops::{Add, Mul};
    pub trait SemiRing: Add<Output = Self> + Mul<Output = Self> + Copy {
        fn zero() -> Self;
        fn one() -> Self;
    }
    pub const SIZE: usize = 2;
    #[derive(Clone)]
    pub struct SquareMatrix<T: SemiRing> {
        buf: [[T; SIZE]; SIZE],
    }
    impl<T: SemiRing> SquareMatrix<T> {
        pub fn zero() -> Self {
            let z = T::zero();
            SquareMatrix {
                buf: [[z; SIZE]; SIZE],
            }
        }
        pub fn identity() -> Self {
            let mut m = Self::zero();
            for i in 0..SIZE {
                m.buf[i][i] = T::one();
            }
            m
        }
        pub fn set_at(&mut self, i: usize, j: usize, v: T) {
            self.buf[i][j] = v;
        }
        pub fn get_at(&self, i: usize, j: usize) -> T {
            self.buf[i][j]
        }
        pub fn matmul(&self, rhs: &Self) -> Self {
            let mut res = Self::zero();
            for (x, a) in res.buf.iter_mut().zip(self.buf.iter()) {
                for (a, b) in a.iter().zip(rhs.buf.iter()) {
                    for (x, b) in x.iter_mut().zip(b.iter()) {
                        *x = *x + *a * *b;
                    }
                }
            }
            res
        }
        pub fn matadd(&self, rhs: &Self) -> Self {
            let mut c = Self::zero();
            for (c, (a, b)) in c.buf.iter_mut().zip(self.buf.iter().zip(rhs.buf.iter())) {
                for (c, (a, b)) in c.iter_mut().zip(a.iter().zip(b.iter())) {
                    *c = *a + *b;
                }
            }
            c
        }
        pub fn matpow(&self, mut n: usize) -> Self {
            let mut t = Self::identity();
            let mut s = self.clone();
            while n > 0 {
                if n & 1 == 1 {
                    t = t.matmul(&s);
                }
                s = s.matmul(&s);
                n >>= 1;
            }
            t
        }
    }
}
// ---------- end Matrix ----------
// ---------- begin ModInt ----------
mod modint {

    #[allow(dead_code)]
    pub struct Mod;
    impl ConstantModulo for Mod {
        const MOD: u32 = 998_244_353;
    }

    #[allow(dead_code)]
    pub struct RuntimeMod;
    static mut RUNTIME_MOD: u32 = 0;
    impl Modulo for RuntimeMod {
        fn modulo() -> u32 {
            unsafe { RUNTIME_MOD }
        }
    }

    #[allow(dead_code)]
    impl RuntimeMod {
        pub fn set_modulo(p: u32) {
            unsafe {
                RUNTIME_MOD = p;
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
        fn new_unchecked(d: u32) -> Self {
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

    // ---------- begin Precalc ----------
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
    // ---------- end Precalc ----------
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
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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

//

use std::io::Write;

use modint::*;
use matrix::*;

type ModInt = ModularInteger<Mod>;
type Matrix = SquareMatrix<ModInt>;

impl SemiRing for ModInt {
    fn zero() -> Self {
        ModInt::zero()
    }
    fn one() -> Self {
        ModInt::one()
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        s: bytes,
        ask: [(usize1, usize); m],
    }
    let gen = |k: usize| -> Matrix {
        let mut mat = Matrix::zero();
        mat.set_at(0, 0, ModInt::from(k + 1));
        mat.set_at(1, 0, ModInt::from(9 - k));
        if k == 1 {
            mat.set_at(0, 1, ModInt::one());
        }
        mat
    };
    let mut seg = segment_tree::PURQ::new(n, Matrix::identity(), |a, b| a.matmul(&b));
    for (i, c) in s.iter().enumerate() {
        let k = (c - b'0') as usize;
        seg.update_tmp(i, gen(k));
    }
    seg.update_all();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (x, d) in ask {
        seg.update(x, gen(d));
        let ans = seg.find(0, n).get_at(0, 0);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
// ---------- begin Matrix ----------

#[allow(dead_code)]
mod matrix {
    use std::ops::Add;
    use std::ops::Mul;
    pub trait SemiRing: Add<Output = Self> + Mul<Output = Self> + Copy {
        fn zero() -> Self;
        fn one() -> Self;
    }
    #[derive(Clone)]
    pub struct SquareMatrix<T: SemiRing> {
        n: usize,
        a: Vec<T>,
    }
    impl<T: SemiRing> SquareMatrix<T> {
        pub fn zero(n: usize) -> Self {
            let z = T::zero();
            SquareMatrix {
                n: n,
                a: vec![z; n * n],
            }
        }
        pub fn identity(n: usize) -> Self {
            let mut m = Self::zero(n);
            for i in 0..n {
                m.a[i * n + i] = T::one();
            }
            m
        }
        pub fn set_at(&mut self, i: usize, j: usize, v: T) {
            debug_assert!(i < self.n && j < self.n);
            self.a[i * self.n + j] = v;
        }
        pub fn get_at(&self, i: usize, j: usize) -> T {
            debug_assert!(i < self.n && j < self.n);
            self.a[i * self.n + j]
        }
        pub fn matmul(l: Self, r: Self) -> Self {
            l * r
        }
    }
    impl<T: SemiRing> Add for SquareMatrix<T> {
        type Output = Self;
        fn add(self, rhs: Self) -> Self {
            debug_assert!(self.n == rhs.n);
            let n = self.n;
            let mut c = Self::zero(n);
            for i in 0..(n * n) {
                c.a[i] = self.a[i] + rhs.a[i];
            }
            c
        }
    }
    impl<T: SemiRing> Mul for SquareMatrix<T> {
        type Output = Self;
        fn mul(self, rhs: Self) -> Self {
            debug_assert!(self.n == rhs.n);
            let n = self.n;
            let mut c = Self::zero(n);
            for i in 0..n {
                for k in 0..n {
                    let a = self.a[i * n + k];
                    for (x, y) in c.a[(i * n)..((i + 1) * n)].iter_mut().zip(rhs.a[(k * n)..((k + 1) * n)].iter()) {
                        *x = *x + a * *y;
                    }
                }
            }
            c
        }
    }
}

// ---------- end Matrix ----------
// ---------- begin ModInt ----------

//https://github.com/kenkoooo/competitive-programming-rs/blob/master/src/math/mod_int.rs
//
#[allow(dead_code)]
mod modint {
    pub const MOD: u32 = 1000000000 + 7;
    use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Neg, Sub, SubAssign};
    #[derive(Clone, Copy)]
    pub struct ModInt<T: Copy + Clone>(pub T);
    pub type Num = u32;
    impl Add<ModInt<Num>> for ModInt<Num> {
        type Output = ModInt<Num>;
        fn add(self, other: ModInt<Num>) -> ModInt<Num> {
            let mut d = self.0 + other.0;
            if d >= MOD {
                d -= MOD;
            }
            ModInt(d)
        }
    }
    impl AddAssign<ModInt<Num>> for ModInt<Num> {
        fn add_assign(&mut self, other: ModInt<Num>) {
            *self = *self + other;
        }
    }
    impl Sub<ModInt<Num>> for ModInt<Num> {
        type Output = ModInt<Num>;
        fn sub(self, other: ModInt<Num>) -> ModInt<Num> {
            let mut d = self.0 + MOD - other.0;
            if d >= MOD {
                d -= MOD;
            }
            ModInt(d)
        }
    }
    impl SubAssign<ModInt<Num>> for ModInt<Num> {
        fn sub_assign(&mut self, other: ModInt<Num>) {
            *self = *self - other;
        }
    }
    impl Mul<ModInt<Num>> for ModInt<Num> {
        type Output = ModInt<Num>;
        fn mul(self, other: ModInt<Num>) -> ModInt<Num> {
            ModInt(((self.0 as u64) * (other.0 as u64) % (MOD as u64)) as u32)
        }
    }
    impl MulAssign<ModInt<Num>> for ModInt<Num> {
        fn mul_assign(&mut self, other: ModInt<Num>) {
            *self = *self * other;
        }
    }
    impl Div<Num> for ModInt<Num> {
        type Output = ModInt<Num>;
        fn div(self, other: Num) -> ModInt<Num> {
            self * ModInt(other).pow(MOD - 2)
        }
    }
    impl Div<ModInt<Num>> for ModInt<Num> {
        type Output = ModInt<Num>;
        fn div(self, other: ModInt<Num>) -> ModInt<Num> {
            self * other.pow(MOD - 2)
        }
    }
    impl DivAssign<ModInt<Num>> for ModInt<Num> {
        fn div_assign(&mut self, other: ModInt<Num>) {
            *self = *self / other;
        }
    }
    impl Neg for ModInt<Num> {
        type Output = ModInt<Num>;
        fn neg(self) -> ModInt<Num> {
            ModInt(if self.0 == 0 { 0 } else { MOD - self.0 })
        }
    }
    impl ModInt<Num> {
        pub fn new(v: u32) -> ModInt<Num> {
            ModInt(v % MOD)
        }
        pub fn pow(self, mut n: u32) -> ModInt<Num> {
            let mut t = ModInt::new(1);
            let mut s = self;
            while n > 0 {
                if (n & 1) == 1 {
                    t *= s;
                }
                s *= s;
                n >>= 1;
            }
            t
        }
    }
    pub struct Precalc {
        n: usize,
        inv: Vec<ModInt<Num>>,
        fact: Vec<ModInt<Num>>,
        ifact: Vec<ModInt<Num>>,
    }
    impl Precalc {
        pub fn new(n: usize) -> Precalc {
            let mut inv = vec![ModInt(1); n + 1];
            let mut fact = vec![ModInt(1); n + 1];
            let mut ifact = vec![ModInt(1); n + 1];
            for i in 1..(n + 1) {
                if i > 2 {
                    inv[i] = -inv[(MOD as usize) % i] * ModInt(MOD / (i as u32));
                }
                fact[i] = ModInt(i as u32) * fact[i - 1];
                ifact[i] = inv[i] * ifact[i - 1];
            }
            Precalc {
                n: n,
                inv: inv,
                fact: fact,
                ifact: ifact,
            }
        }
        pub fn fact(self, n: usize) -> ModInt<Num> {
            self.fact[n]
        }
        pub fn inv(self, x: usize) -> ModInt<Num> {
            self.inv[x]
        }
        pub fn ifact(self, x: usize) -> ModInt<Num> {
            self.ifact[x]
        }
        pub fn comb(self, n: usize, k: usize) -> ModInt<Num> {
            if !(k <= n) {
                return ModInt(0);
            }
            self.fact[n] * self.ifact[k] * self.ifact[n - k]
        }
    }
    use std;
    impl std::fmt::Display for ModInt<Num> {
        fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
            write!(f, "{}", self.0)
        }
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use matrix::SquareMatrix;
use modint::ModInt;

impl matrix::SemiRing for ModInt<modint::Num> {
    fn one() -> Self {ModInt(1)}
    fn zero() -> Self {ModInt(0)}
}

fn run() {
    input! {
        n: u64,
        m: usize,
    }
    type M = SquareMatrix<ModInt<modint::Num>>;
    let mut t = M::identity(m);
    let mut s = M::zero(m);
    for i in 1..m {
        s.set_at(i - 1, i , ModInt(1));
    }
    s.set_at(m - 1, 0, ModInt(1));
    s.set_at(m - 1, m - 1, ModInt(1));
    let mut n = n;
    while n > 0 {
        if (n & 1) == 1 {
            t = t * s.clone();
        }
        s = s.clone() * s;
        n >>= 1;
    }
    let ans = t.get_at(m - 1, m - 1);
    println!("{}", ans);
}

fn main() {
    run();
}
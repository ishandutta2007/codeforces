// ---------- begin ModInt ----------
mod modint {

    #[allow(dead_code)]
    pub struct Mod;
    impl ConstantModulo for Mod {
        const MOD: u32 = 1_000_000_007;
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
        pub fn pow(&self, mut n: u32) -> Self {
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
            self.pow(T::modulo() - 2)
        }
    }
}
// ---------- end ModInt ----------
// ---------- begin Matrix ----------
#[allow(dead_code)]
mod matrix {
    use std::ops::{Add, Mul};
    pub trait SemiRing: Add<Output = Self> + Mul<Output = Self> + Copy {
        fn zero() -> Self;
        fn one() -> Self;
    }
    pub const SIZE: usize = 3;
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
        pub fn matpow(&self, mut n: u64) -> Self {
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
        m: u64,
        block: [(usize1, u64, u64); n],
    }
    let mut event = vec![];
    for (a, l, r) in block {
        event.push((l - 1, a, 1));
        event.push((r, a, -1));
    }
    event.sort();
    let mut mat = vec![];
    for i in 0..8 {
        let mut p = Matrix::zero();
        for a in 0..3 {
            for b in 0..3 {
                if a + 1 >= b && b + 1 >= a && (i >> a) & 1 == 0 {
                    p.set_at(a, b, ModInt::one());
                }
            }
        }
        mat.push(p);
    }
    let index = |cnt: &[i32]| -> usize {
        let mut res = 0;
        for (i, c) in cnt.iter().enumerate() {
            assert!(*c >= 0);
            if *c > 0 {
                res |= 1 << i;
            }
        }
        res
    };
    let mut cnt = vec![0; 3];
    let mut i = 0;
    let mut pos = 0;
    let mut ans = Matrix::identity();
    while i < event.len() {
        let next = event[i].0;
        ans = mat[index(&cnt)].matpow(next - pos - 1).matmul(&ans);
        pos = next - 1;
        while i < event.len() && event[i].0 == next {
            let (_, a, v) = event[i];
            cnt[a] += v;
            i += 1;
        }
        ans = mat[index(&cnt)].matmul(&ans);
        pos += 1;
    }
    ans = mat[0].matpow(m - pos - 1).matmul(&ans);
    println!("{}", ans.get_at(1, 1));
}

fn main() {
    run();
}
// ---------- begin ModInt ----------
const MOD: u32 = 1_000_000_007;

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

impl From<usize> for ModInt {
    fn from(val: usize) -> ModInt {
        ModInt((val % MOD as usize) as u32)
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
        assert!(self.0 > 0);
        self.pow(MOD - 2)
    }
}
// ---------- end ModInt ----------
// ---------- begin Matrix ----------
mod matrix {
    use std::ops::*;
    pub trait SemiRing: Add<Output = Self> + Mul<Output = Self> + Copy {
        fn zero() -> Self;
        fn one() -> Self;
    }
    #[derive(Clone)]
    pub struct SquareMatrix<R> {
        size: usize,
        buf: Box<[R]>,
    }
    #[allow(dead_code)]
    impl<R: SemiRing> SquareMatrix<R> {
        pub fn zero(size: usize) -> Self {
            SquareMatrix {
                size: size,
                buf: vec![R::zero(); size * size].into_boxed_slice(),
            }
        }
        pub fn identity(size: usize) -> Self {
            let mut e = Self::zero(size);
            for i in 0..size {
                e.buf[i * size + i] = R::one();
            }
            e
        }
        pub fn set_at(&mut self, x: usize, y: usize, val: R) {
            assert!(x < self.size && y < self.size);
            self.buf[x * self.size + y] = val;
        }
        pub fn get_at(&self, x: usize, y: usize) -> R {
            assert!(x < self.size && y < self.size);
            self.buf[x * self.size + y]
        }
        pub fn matadd(&self, rhs: &Self) -> Self {
            assert!(self.size == rhs.size);
            let buf: Vec<R> = self
                .buf
                .iter()
                .zip(rhs.buf.iter())
                .map(|p| *p.0 + *p.1)
                .collect();
            SquareMatrix {
                size: self.size,
                buf: buf.into_boxed_slice(),
            }
        }
        pub fn matmul(&self, rhs: &Self) -> Self {
            let size = self.size;
            assert!(size == rhs.size);
            let mut res = Self::zero(size);
            for (x, a) in res.buf.chunks_mut(size).zip(self.buf.chunks(size)) {
                for (a, b) in a.iter().zip(rhs.buf.chunks(size)) {
                    for (x, b) in x.iter_mut().zip(b.iter()) {
                        *x = *x + *a * *b;
                    }
                }
            }
            res
        }
        pub fn mat_pow(&self, mut n: u64) -> Self {
            let size = self.size;
            let mut t = Self::identity(size);
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
    #[allow(dead_code)]
    impl<R: SemiRing + Sub<Output = R>> SquareMatrix<R> {
        pub fn matsub(&self, rhs: &Self) -> Self {
            assert!(self.size == rhs.size);
            let buf: Vec<R> = self
                .buf
                .iter()
                .zip(rhs.buf.iter())
                .map(|p| *p.0 - *p.1)
                .collect();
            SquareMatrix {
                size: self.size,
                buf: buf.into_boxed_slice(),
            }
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

//

use matrix::*;

type M = SquareMatrix<ModInt>;

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
        k: u64,
        a: [u64; n],
    }
    let mut s = M::zero(n);
    for (i, &x) in a.iter().enumerate() {
        for (j, &y) in a.iter().enumerate() {
            if (x ^ y).count_ones() % 3 == 0 {
                s.set_at(i, j, ModInt::one());
            }
        }
    }
    let mat = s.mat_pow(k - 1);
    let mut ans = ModInt::zero();
    for i in 0..n {
        for j in 0..n {
            ans += mat.get_at(i, j);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
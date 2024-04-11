// ---------- begin ModInt ----------
const MOD: u32 = 998_244_353;

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
        self.pow(MOD - 2)
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
    pub const SIZE: usize = 64;
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

impl SemiRing for ModInt {
    fn zero() -> Self {
        ModInt::zero()
    }
    fn one() -> Self {
        ModInt::one()
    }
}

fn mul(a: &SquareMatrix<ModInt>, b: &[ModInt]) -> Vec<ModInt> {
    assert!(b.len() == SIZE);
    let mut c = vec![];
    for i in 0..SIZE {
        let mut sum = ModInt::zero();
        for j in 0..SIZE {
            sum += a.get_at(i, j) * b[j];
        }
        c.push(sum);
    }
    c
}

fn run() {
    input! {
        n: usize,
        a: [usize; n],
        m: usize,
        p: [(usize1, usize, usize1); m],
        f: [[usize; 3]; 3],
    }
    let mut mat = vec![SquareMatrix::<ModInt>::zero(); 4];
    for x in 0..4 {
        for y in 0..4 {
            for z in 0..4 {
                for c in 0..3 {
                    let mut u = vec![false; 4];
                    if f[c][0] == 1 {
                        u[x] = true;
                    }
                    if f[c][1] == 1 {
                        u[y] = true;
                    }
                    if f[c][2] == 1 {
                        u[z] = true;
                    }
                    let mut g = 0;
                    while u[g] {
                        g += 1;
                    }
                    let v = mat[c].get_at(16 * g + 4 * x + y, 16 * x + 4 * y + z);
                    mat[c].set_at(16 * g + 4 * x + y, 16 * x + 4 * y + z, v + ModInt::one());
                }
            }
        }
    }
    mat[3] = mat[0].matadd(&mat[1]).matadd(&mat[2]);
    let mut pow = vec![];
    let mut s = mat[3].clone();
    for _ in 0..30 {
        pow.push(s.clone());
        s = s.matmul(&s);
    }
    let mut q = vec![vec![]; n];
    for (x, y, c) in p {
        q[x].push((y, c));
    }
    let mut dp = vec![ModInt::zero(); 4];
    dp[0] = ModInt::one();
    for (mut q, a) in q.into_iter().zip(a.into_iter()) {
        q.sort();
        let mut now = vec![ModInt::zero(); SIZE];
        now[3 * 16 + 3 * 4 + 3] = ModInt::one();
        let mut pos = 0;
        for (y, c) in q.into_iter() {
            let m = y - pos - 1;
            for k in 0..30 {
                if (m >> k) & 1 == 1 {
                    now = mul(&pow[k], &now);
                }
            }
            now = mul(&mat[c], &now);
            pos = y;
        }
        if pos < a {
            let m = a - pos;
            for k in 0..30 {
                if (m >> k) & 1 == 1 {
                    now = mul(&pow[k], &now);
                }
            }
        }
        let mut next = vec![ModInt::zero(); 4];
        for i in 0..4 {
            for j in 0..SIZE {
                let x = j / 16;
                next[x ^ i] += dp[i] * now[j];
            }
        }
        dp = next;
    }
    let ans = dp[0];
    println!("{}", ans);
}

fn main() {
    run();
}
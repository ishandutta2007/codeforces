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

    pub struct ModInt<T>(pub u32, PhantomData<T>);

    impl<T> Clone for ModInt<T> {
        fn clone(&self) -> Self {
            ModInt::new_unchecked(self.0)
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
            ModInt::new_unchecked(d)
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
            let mut d = T::modulo() + self.0 - rhs.0;
            if d >= T::modulo() {
                d -= T::modulo();
            }
            ModInt::new_unchecked(d)
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
            ModInt::new_unchecked(v as u32)
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
                Self::new_unchecked(T::modulo() - self.0)
            }
        }
    }

    impl<T> std::fmt::Display for ModInt<T> {
        fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
            write!(f, "{}", self.0)
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
        pub fn new_unchecked(d: u32) -> Self {
            ModInt(d, PhantomData)
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

    #[allow(dead_code)]
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
// ---------- begin NTT ----------
#[allow(dead_code)]
mod transform {
    use super::modint::*;
    pub trait NTTFriendly: ConstantModulo {
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
        for (k, &z) in zeta.iter().rev().enumerate().rev() {
            let m = 1 << k;
            for f in f.chunks_exact_mut(2 * m) {
                let mut q = ModInt::one();
                let (x, y) = f.split_at_mut(m);
                for (x, y) in x.iter_mut().zip(y.iter_mut()) {
                    let a = *x;
                    let b = *y;
                    *x = a + b;
                    *y = (a - b) * q;
                    q *= z;
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
        for (k, &z) in zeta.iter().rev().enumerate() {
            let m = 1 << k;
            for f in f.chunks_exact_mut(2 * m) {
                let mut q = ModInt::one();
                let (x, y) = f.split_at_mut(m);
                for (x, y) in x.iter_mut().zip(y.iter_mut()) {
                    let a = *x;
                    let b = *y * q;
                    *x = a + b;
                    *y = a - b;
                    q *= z;
                }
            }
        }
        let ik = ModInt::new_unchecked((T::MOD + 1) >> 1).pow(len as u64);
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

struct P;
impl ConstantModulo for P {
    const MOD: u32 = 998_244_353;
}

impl transform::NTTFriendly for P {
    fn order() -> usize {
        1 << 23
    }
    fn zeta() -> u32 {
        let p = Self::MOD as u64;
        mod_pow(3, (p - 1) >> 23, p) as u32
    }
}

type M = ModInt<P>;

use transform::*;

fn run() {
    input! {
        n: usize,
        x: usize,
        y: usize,
        a: [usize; n + 1],
        q: usize,
        ask: [usize; q],
    }
    let mut b = vec![M::zero(); x + 1];
    for a in a {
        b[a]= M::one();
    }
    let mut c = b.clone();
    c.reverse();
    let a = multiply(&b, &c);
    let w = 1_000_000;
    let mut ans = vec![-1; w + 1];
    for (i, p) in a[x..].iter().enumerate().skip(1) {
        if !p.is_zero() {
            ans[2 * i + 2 * y] = (2 * i + 2 * y) as i32;
        }
    }
    let mut p = vec![true; w + 1];
    for i in (2..).take_while(|p| p * p <= w) {
        if p[i] {
            for j in i..=(w / i) {
                p[j * i] = false;
            }
        }
    }
    for (p, _) in p.iter().enumerate().skip(2).filter(|p| *p.1) {
        for i in 1..=(w / p) {
            ans[i * p] = std::cmp::max(ans[i * p], ans[i]);
        }
    }
    let mut s = String::new();
    for l in ask {
        s.push_str(&format!("{} ", ans[l]));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
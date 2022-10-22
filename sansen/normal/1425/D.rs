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
type M = ModInt<Mod>;

fn run() {
    input! {
        n: usize,
        m: usize,
        rad: usize,
        p: [(usize1, usize1, M); n],
    }
    let w = 1000;
    let mut cnt = vec![vec![0usize; w + 1]; w + 1];
    for &(x, y, _) in p.iter() {
        cnt[x][y] += 1;
    }
    for i in (0..w).rev() {
        for j in (0..w).rev() {
            cnt[i][j] += cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
        }
    }
    let find = |l: usize, r: usize, u: usize, d: usize| -> usize {
        cnt[u][l] - cnt[u][r] - cnt[d][l] + cnt[d][r]
    };
    let pc = precalc::Precalc::new(n);
    let all = pc.comb(n, m);
    let mut ans = M::zero();
    let mut way = vec![M::zero(); n];
    let mut cnt = vec![0; n];
    for (i, (way, &(x, y, p))) in way.iter_mut().zip(p.iter()).enumerate() {
        let u = x.saturating_sub(rad);
        let l = y.saturating_sub(rad);
        let d = std::cmp::min(x + rad + 1, w);
        let r = std::cmp::min(y + rad + 1, w);
        cnt[i] = find(l, r, u, d);
        let s = n - cnt[i];
        if s >= m {
            *way = all - pc.comb(s, m);
        } else {
            *way = all;
        }
//        println!("{}: {}", p, way);
        ans += p * p * *way;
    }
    for (i, (x, &(a, b, c))) in way.iter().zip(p.iter()).enumerate() {
        for (j, (y, &(p, q, r))) in way.iter().zip(p.iter()).enumerate().take(i) {
            let or = {
                let u = std::cmp::max(a.saturating_sub(rad), p.saturating_sub(rad));
                let l = std::cmp::max(b.saturating_sub(rad), q.saturating_sub(rad));
                let d = std::cmp::min(w, std::cmp::min(a + rad + 1, p + rad + 1));
                let r = std::cmp::min(w, std::cmp::min(b + rad + 1, q + rad + 1));
                let s = if u >= d || l >= r {
                    n - cnt[i] - cnt[j]
                } else {
                    n - cnt[i] - cnt[j] + find(l, r, u, d)
                };
                if s >= m {
                    all - pc.comb(s, m)
                } else {
                    all
                }
            };
//            println!("{} {}: {}", c, r, or);
            let and = *x + *y - or;
            ans += M::new(2) * c * r * and;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
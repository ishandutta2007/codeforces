//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    pub struct UF {
        p: Vec<i32>,
    }
    impl UF {
        pub fn new(n: usize) -> UF {
            UF { p: vec![-1; n] }
        }
        pub fn init(&mut self) {
            for p in self.p.iter_mut() {
                *p = -1;
            }
        }
        pub fn root(&self, mut x: usize) -> usize {
            while self.p[x] >= 0 {
                x = self.p[x] as usize;
            }
            x
        }
        pub fn same(&self, x: usize, y: usize) -> bool {
            self.root(x) == self.root(y)
        }
        pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
            let mut x = self.root(x);
            let mut y = self.root(y);
            if x == y {
                return None;
            }
            if self.p[x] > self.p[y] {
                std::mem::swap(&mut x, &mut y);
            }
            self.p[x] += self.p[y];
            self.p[y] = x as i32;
            Some((x, y))
        }
        pub fn parent(&self, x: usize) -> Option<usize> {
            let p = self.p[x];
            if p >= 0 {
                Some(p as usize)
            } else {
                None
            }
        }
        pub fn get_size(&self, x: usize) -> usize {
            let r = self.root(x);
            (-self.p[r]) as usize
        }
    }
}
//---------- end union_find ----------
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
            let mut d = T::modulo() + self.0 - rhs.0;
            if d >= T::modulo() {
                d -= T::modulo();
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
use transform::*;
type M = ModInt<Mod998_244_353>;

impl transform::NTTFriendly for Mod998_244_353 {
    fn order() -> usize {
        1 << 23
    }
    fn zeta() -> u32 {
        let p = Self::modulo() as u64;
        modint::mod_pow(3, (p - 1) >> 23, p) as u32
    }
}

fn run() {
    input! {
        s: bytes,
        t: bytes,
    }
    let size = 6;
    let len = (s.len() + t.len()).next_power_of_two();
    let mut a = vec![vec![M::zero(); len]; size];
    let mut b = vec![vec![M::zero(); len]; size];
    for (a, s) in [(&mut a, &s), (&mut b, &t)].iter_mut() {
        for (i, c) in s.iter().enumerate() {
            let k = (*c - b'a') as usize;
            a[k][i] = M::one();
        }
    }
    for b in b.iter_mut() {
        b[..t.len()].reverse();
    }
    for a in a.iter_mut().chain(b.iter_mut()) {
        ntt(a);
    }
    let mut u = (0..(s.len() - t.len() + 1))
        .map(|_| union_find::UF::new(size))
        .collect::<Vec<_>>();
    for i in 0..size {
        for j in 0..size {
            if i == j {
                continue;
            }
            let mut c = vec![M::zero(); len];
            for (c, (a, b)) in c.iter_mut().zip(a[i].iter().zip(b[j].iter())) {
                *c = *a * *b;
            }
            intt(&mut c);
            for (u, c) in u.iter_mut().zip(c.iter().skip(t.len() - 1)) {
                if !c.is_zero() {
                    u.unite(i, j);
                }
            }
        }
    }
    let mut ans = String::new();
    for u in u.iter() {
        let mut c = 0;
        for i in 0..size {
            if i == u.root(i) {
                c += u.get_size(i) - 1;
            }
        }
        ans.push_str(&format!("{} ", c));
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}
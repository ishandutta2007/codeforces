fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}
// ---------- begin Matrix ----------
mod matrix {
    use std::ops::*;
    pub trait SemiRing: Add<Output = Self> + Mul<Output = Self> + Copy {
        fn zero() -> Self;
        fn one() -> Self;
    }
    pub trait Inverse: SemiRing {
        fn is_zero() -> bool;
        fn inv(self) -> Self;
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
        pub fn get_mut(&mut self, x: usize, y: usize) -> &mut R {
            assert!(x < self.size && y < self.size);
            &mut self.buf[x * self.size + y]
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
        pub fn mat_pow(&self, mut n: usize) -> Self {
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
    /*
    #[allow(dead_code)]
    impl<R: Inverse + Sub<Output = R>> SquareMatrix<R> {
        pub fn inverse(&self) -> Self {
        }
    }
    */
}
// ---------- end Matrix ----------
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

use modint::*;

type M = ModInt<Mod998_244_353>;

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

use matrix::*;
type Mat = SquareMatrix<M>;

impl SemiRing for M {
    fn zero() -> Self {
        M::zero()
    }
    fn one() -> Self {
        M::one()
    }
}

fn lcp(x: &[u8], y: &[u8]) -> usize {
    x.iter().zip(y).take_while(|p| *p.0 == *p.1).count()
}

fn run() {
    input! {
        n: usize,
        m: usize,
        s: [bytes; n],
    }
    let mut id = 0;
    let mut map = std::collections::BTreeMap::new();
    let mut get_id = |s: &Vec<u8>| -> usize {
        *map.entry(s.clone()).or_insert_with(|| {
            let v = id;
            id += 1;
            v
        })
    };
    get_id(&vec![]);
    let mut dfs = vec![vec![]];
    let mut set = std::collections::BTreeSet::new();
    set.insert(vec![]);
    let mut e = vec![];
    while let Some(a) = dfs.pop() {
        let mut edge = vec![];
        if a.is_empty() {
            for a in s.iter() {
                for b in s.iter() {
                    let len = lcp(a, b);
                    let a = a[len..].iter().cloned().collect::<Vec<_>>();
                    let b = b[len..].iter().cloned().collect::<Vec<_>>();
                    if a.is_empty() {
                        if set.insert(b.clone()) {
                            dfs.push(b.clone());
                        }
                        let dst = get_id(&b);
                        edge.push((len, dst));
                    } else if b.is_empty() {
                        if set.insert(a.clone()) {
                            dfs.push(a.clone());
                        }
                        let dst = get_id(&a);
                        edge.push((len, dst));
                    }
                }
            }
        } else {
            for b in s.iter() {
                let len = lcp(&a, b);
                let a = a[len..].iter().cloned().collect::<Vec<_>>();
                let b = b[len..].iter().cloned().collect::<Vec<_>>();
                if a.is_empty() {
                    if set.insert(b.clone()) {
                        dfs.push(b.clone());
                    }
                    let dst = get_id(&b);
                    edge.push((len, dst));
                } else if b.is_empty() {
                    if set.insert(a.clone()) {
                        dfs.push(a.clone());
                    }
                    let dst = get_id(&a);
                    edge.push((len, dst));
                }
            }
        }
        edge.sort();
        let mut pre = get_id(&a);
        let mut cnt = 1;
        for (len, dst) in edge {
            while cnt < len {
                let key = rand().to_be_bytes().to_vec();
                let v = get_id(&key);
                e.push((pre, v));
                pre = v;
                cnt += 1;
            }
            e.push((pre, dst));
        }
    }
    let size = e.iter().map(|p| p.0.max(p.1)).max().unwrap() + 1;
    let mut mat = Mat::zero(size);
    for (a, b) in e {
        *mat.get_mut(a, b) += M::one();
    }
    let ans = mat.mat_pow(m).get_at(0, 0);
    println!("{}", ans);
}

fn main() {
    run();
}
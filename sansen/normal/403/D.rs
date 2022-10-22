// ---------- begin karatsuba multiplication ----------
fn karatsuba<T>(a: &[T], b: &[T], c: &mut [T], zero: T, buf: &mut [T]) 
where T: std::marker::Copy +
         std::ops::Add<Output = T> +
         std::ops::Sub<Output = T> +
         std::ops::Mul<Output = T> +
{
    assert!(a.len() == b.len());
    let n = a.len();
    if n <= 16 {
        for (i, a) in a.iter().enumerate() {
            for (c, b) in c[i..].iter_mut().zip(b.iter()) {
                *c = *c + *a * *b;
            }
        }
        return;
    }
    if n & 1 == 1 {
        karatsuba(&a[1..], &b[1..], &mut c[2..], zero, buf);
        let x = a[0];
        let y = b[0];
        c[0] = c[0] + x * y;
        for (c, (a, b)) in c[1..].iter_mut().zip(a[1..].iter().zip(b[1..].iter())) {
            *c = *c + x * *b + *a * y;
        }
        return;
    }
    let m = n / 2;
    let (fa, ta) = a.split_at(m);
    let (fb, tb) = b.split_at(m);
    karatsuba(fa, fb, &mut c[..n], zero, buf);
    karatsuba(ta, tb, &mut c[n..], zero, buf);
    let (x, buf) = buf.split_at_mut(m);
    let (y, buf) = buf.split_at_mut(m);
    let (z, buf) = buf.split_at_mut(n);
    z.iter_mut().for_each(|z| *z = zero);
    let xpq = x.iter_mut().zip(fa.iter().zip(ta.iter()));
    let yrs = y.iter_mut().zip(fb.iter().zip(tb.iter()));
    for ((x, (p, q)), (y, (r, s))) in xpq.zip(yrs) {
        *x = *p + *q;
        *y = *r + *s;
    }
    karatsuba(x, y, z, zero, buf);
    for (z, (p, q)) in z.iter_mut().zip(c[..n].iter().zip(c[n..].iter())) {
        *z = *z - (*p + *q);
    }
    for (c, z) in c[m..].iter_mut().zip(z.iter()) {
        *c = *c + *z;
    }
}

fn multiply<T>(a: &[T], b: &[T], zero: T) -> Vec<T>
where T: std::marker::Copy +
         std::ops::Add<Output = T> +
         std::ops::Sub<Output = T> +
         std::ops::Mul<Output = T> +
{
    let mut i = 0;
    let mut j = 0;
    let mut ans = vec![zero; a.len() + b.len()];
    let mut buf = vec![zero; 4 * a.len().min(b.len())];
    let mut c = Vec::with_capacity(2 * a.len().min(b.len()));
    while i < a.len() && j < b.len() {
        let x = a.len() - i;
        let y = b.len() - j;
        let z = x.min(y);
        c.clear();
        c.resize(2 * z, zero);
        karatsuba(&a[i..(i + z)], &b[j..(j + z)], &mut c, zero, &mut buf);
        for (ans, c) in ans[(i + j)..].iter_mut().zip(c.iter()) {
            *ans = *ans + *c;
        }
        if x <= y {
            j += z;
        } else {
            i += z;
        }
    }
    ans.truncate(a.len() + b.len() - 1);
    ans
}
// ---------- end karatsuba multiplication ----------
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
        let z = (2u64..).find(|z| {
            f.iter().all(|f| mod_pow(*z, ((p - 1) / *f) as u64, p as u64) != 1)
        }).unwrap();
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
            if d >= T::modulo() {
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

type M = ModInt<Mod1_000_000_007>;

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

use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        t: usize,
        ask: [(usize, usize); t],
    }
    let w = 1000;
    let mut s = 0;
    let mut a = 0;
    while s + a <= w {
        s += a;
        a += 1;
    }
    let mut dp = vec![vec![M::zero(); w + 1]; a + 1];
    dp[0][0] = M::one();
    for d in 0..=w {
        for i in (1..=a).rev() {
            for j in ((i - 2) * (i - 1) / 2 + d)..=w {
                dp[i][j] = dp[i][j] + dp[i - 1][j - d];
            }
        }
    }
    let pc = precalc::Precalc::new(2 * w);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, k) in ask {
        let mut ans = M::zero();
        if n - 1 >= k - 1 && k < dp.len() {
            let rem = n - 1 - k + 1;
            for (j, dp) in dp[k][..=rem].iter().enumerate() {
                ans += *dp * pc.comb(n - j, k);
            }
        }
        ans *= pc.fact(k);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
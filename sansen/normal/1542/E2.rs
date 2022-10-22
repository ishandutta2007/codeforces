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

    impl<T> std::fmt::Debug for ModInt<T> {
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
    }
}
// ---------- end ModInt ----------

use modint::*;
type M = ModInt<StaticMod>;

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

use std::collections::*;
use std::io::Write;

type Map<K, V> = HashMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input!(n: usize, modulo: u32);
    StaticMod::set_modulo(modulo);
    /*
    for n in 1..=6 {
        let mut ans = 0;
        let mut a = (0..n).collect::<Vec<_>>();
        while {
            let mut b = a.clone();
            next_permutation(&mut b);
            while {
                let inv = |a: &[usize]| -> usize {
                    let mut cnt = 0;
                    for i in 0..a.len() {
                        for j in (i + 1)..a.len() {
                            if a[i] > a[j] {
                                cnt += 1;
                            }
                        }
                    }
                    cnt
                };
                if inv(&a) > inv(&b) {
                    ans += 1;
                }
                next_permutation(&mut b)
            }{}
            next_permutation(&mut a)
        }{}
        println!("{}: {}", n, ans);
    }
    */
    let mut binom  = vec![vec![M::zero(); n + 1]; n + 1];
    binom[0][0] = M::one();
    for i in 1..=n {
        binom[i][0] = M::one();
        for j in 1..=i {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
    let mut fact = vec![M::one(); n + 1];
    for i in 1..=n {
        fact[i] = M::from(i) * fact[i - 1];;
    }
    let mut ans = M::zero();
    let mut geta = 0;
    let mut dp = vec![M::one()];
    for rem in 1..=n {
        for i in (0..(dp.len() - 1)).rev() {
            dp[i] = dp[i] + dp[i + 1];
        }
        for i in 0..rem {
            for j in (i + 1)..rem {
                let req = geta - i + j + 1;
                ans += fact[n - rem] * binom[n][rem] * dp.get(req).cloned().unwrap_or(M::zero());
            }
        }
        for i in 0..(dp.len() - 1) {
            dp[i] = dp[i] - dp[i + 1];
        }
        for _ in 0..2 {
            let mut sum = M::zero();
            let mut next = vec![M::zero(); dp.len() + rem - 1];
            for (i, next) in next.iter_mut().enumerate() {
                sum += dp.get(i).cloned().unwrap_or(M::zero());
                *next = sum;
                if i >= rem - 1 {
                    sum -= dp[i - rem + 1];
                }
            }
            dp = next;
        }
        /*
        let mut a = vec![M::zero(); 2 * rem - 1];
        for x in 0..rem {
            for y in 0..rem {
                a[x - y + rem - 1] += M::one();
            }
        }
        dp = multiply(&dp, &a, M::zero());
        */
        geta += rem - 1;
    }
    let ans = ans.0 % modulo;
    println!("{}", ans);
}

fn main() {
    run();
}
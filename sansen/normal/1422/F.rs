// ---------- begin recurse ----------
// reference
// https://twitter.com/noshi91/status/1393952665566994434
// https://twitter.com/shino16_cp/status/1393933468082397190
pub fn recurse<A, R, F>(f: F) -> impl Fn(A) -> R
where
    F: Fn(&dyn Fn(A) -> R, A) -> R,
{
    fn call<A, R, F>(f: &F, a: A) -> R
    where
        F: Fn(&dyn Fn(A) -> R, A) -> R,
    {
        f(&|a| call(f, a), a)
    }
    move |a| call(&f, a)
}
// ---------- end recurse ----------
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

use modint::*;

type M = ModInt<Mod1_000_000_007>;

// ---------- end SegmentTree Point update Range query ----------
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

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        a: [usize; n],
        q: usize,
        ask: [(usize, usize); q],
    }
    let m = *a.iter().max().unwrap();
    let mut f = (0..=m).collect::<Vec<_>>();
    for i in 2..=m {
        if i == f[i] {
            for j in i..=(m / i) {
                f[j * i] = i;
            }
        }
    }
    let mut map = Map::new();
    let mut prod = vec![M::one(); n + 1];
    for (i, mut a) in a.into_iter().enumerate() {
        prod[i] = M::from(a);
        while a > 1 {
            let p = f[a];
            let mut cnt = 0;
            while a % p == 0 {
                cnt += 1;
                a /= p;
                map.entry((p, cnt)).or_insert(vec![]).push(i);
            }
        }
    }
    for i in (0..n).rev() {
        prod[i] = prod[i] * prod[i + 1];
    }
    let mut event = vec![vec![]; n];
    for ((p, _), x) in map {
        let a = M::from(p);
        let inv = a.inv();
        for x in x.windows(2) {
            event[x[1]].push((n - x[0], inv));
        }
    }
    use std::cell::*;
    let node = RefCell::new(vec![(M::one(), 0, 0)]);
    let mut root = 0;
    let mut a = vec![M::one(); n + 1];
    let mut memo = vec![];
    for mut e in event {
        e.sort_by_key(|e| e.0);
        e.dedup_by(|a, b| {
            a.0 == b.0 && {
                b.1 *= a.1;
                true
            }
        });
        let mut p = vec![];
        for (x, v) in e {
            a[x] *= v;
            p.push((x, a[x]));
        }
        if p.len() > 0 {
            p.reverse();
            let p = RefCell::new(p);
            root = recurse(|f, (v, left, right): (usize, usize, usize)| -> usize {
                let u = {
                    let mut po = node.borrow_mut();
                    let res = po.len();
                    po.push((M::one(), 0, 0));
                    res
                };
                if left + 1 == right {
                    let val = p.borrow_mut().pop().unwrap();
                    node.borrow_mut()[u].0 = val.1;
                    return u;
                }
                let mid = (left + right) / 2;
                let (_, mut l, mut r) = node.borrow()[v];
                if p.borrow().last().map_or(false, |p| p.0 < mid) {
                    l = f((l, left, mid));
                }
                if p.borrow().last().map_or(false, |p| p.0 < right) {
                    r = f((r, mid, right));
                }
                let val = node.borrow()[l].0 * node.borrow()[r].0;
                node.borrow_mut()[u] = (val, l, r);
                u
            })((root, 0, n + 1));
        }
        memo.push(root);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut last = 0;
    for (x, y) in ask {
        let mut l = (last + x) % n + 1;
        let mut r = (last + y) % n + 1;
        if l > r {
            std::mem::swap(&mut l, &mut r);
        }
        l -= 1;
        r -= 1;
        let ans = prod[l] * prod[r + 1].inv() * recurse(|f, (v, s, t): (usize, usize, usize)| -> M {
            if v == 0 || n - l + 1 <= s {
                return M::one();
            }
            if t <= n - l + 1 {
                return node.borrow()[v].0;
            }
            let m = (s + t) / 2;
            let (_, x, y) = node.borrow()[v];
            f((x, s, m)) * f((y, m, t))
        })((memo[r], 0, n + 1));
        writeln!(out, "{}", ans).ok();
        last = ans.get() as usize;
    }
}

fn main() {
    run();
}
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

type Path = std::collections::VecDeque<(usize, usize, usize, u32)>;

use std::io::*;
use std::cell::*;

fn run() {
    let stdin = std::io::stdin();
    let mut stdin = stdin.lock();
    let mut read = || -> Vec<usize> {
        let mut s = String::new();
        stdin.read_line(&mut s).unwrap();
        s.trim()
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect()
    };
    let (l, r, m) = {
        let a = read();
        (a[0], a[1], a[2])
    };
    let mut pow = vec![M::one(); m + 200000];
    for i in 1..pow.len() {
        pow[i] = M::new(2) * pow[i - 1];
    }
    let concat = |a: &mut Path, b: &mut Path| -> M {
        if a.len() < b.len() {
            std::mem::swap(a, b);
        }
        let mut diff = M::zero();
        while !b.is_empty() {
            if a[0].0 == b[0].0 {
                for &(x, y, k, c) in b.iter() {
                    diff -= M::new(c) * pow[k];
                    let c = a[0].3 ^ 1;
                    diff += M::new(c) * pow[k];
                    a.push_front((y, x, k, c));
                }
                b.clear();
            } else if a.back().unwrap().1 == b[0].0 {
                for &(x, y, k, c) in b.iter() {
                    diff -= M::new(c) * pow[k];
                    let c = a.back().unwrap().3 ^ 1;
                    diff += M::new(c) * pow[k];
                    a.push_back((x, y, k, c));
                }
                b.clear();
            }
            let len = b.len();
            for i in 0..len {
                if i >= len - 1 - i {
                    break;
                }
                b.swap(i, len - 1 - i);
            }
            b.iter_mut()
                .for_each(|p| std::mem::swap(&mut p.0, &mut p.1));
        }
        diff
    };
    let mut edge = 0;
    let info = RefCell::new(vec![]);
    let hash = RefCell::new(M::zero());
    let mut end = vec![None; l + r];
    let mut add_edge = |x: usize, y: usize| {
        assert!(x < l && y < r);
        let (x, y) = (x, y + l);
        let i = edge;
        edge += 1;
        let mut path = Path::new();
        path.push_back((x, y, i, 0));
        let mut hash = hash.borrow_mut();
        let mut info = info.borrow_mut();
        match (end[x].take(), end[y].take()) {
            (None, None) => {
                let id = info.len();
                info.push(path);
                end[x] = Some(id);
                end[y] = Some(id);
            }
            (Some(p), Some(q)) if p == q => {
                *hash += concat(&mut info[p], &mut path);
            }
            (Some(p), Some(q)) => {
                let mut a = std::mem::take(&mut info[p]);
                let mut b = std::mem::take(&mut info[q]);
                *hash += concat(&mut a, &mut path);
                *hash += concat(&mut a, &mut b);
                end[a[0].0] = Some(p);
                end[a.back().unwrap().1] = Some(p);
                info[p] = a;
            }
            (p, q) => {
                let p = p.or(q).unwrap();
                *hash += concat(&mut info[p], &mut path);
                end[info[p][0].0] = Some(p);
                end[info[p].back().unwrap().1] = Some(p);
            }
        }
    };
    for _ in 0..m {
        let a = read();
        add_edge(a[0] - 1, a[1] - 1);
    }
    let q = read()[0];
    for _ in 0..q {
        let a = read();
        if a[0] == 1 {
            add_edge(a[1] - 1, a[2] - 1);
            println!("{}", M::new(2) * *hash.borrow());
        } else {
            let mut ans = vec![];
            for &(_, _, k, c) in info.borrow().iter().flatten() {
                if c == 1 {
                    ans.push(k + 1);
                }
            }
            ans.sort();
            let mut s = String::new();
            s.push_str(&format!("{}", ans.len()));
            for a in ans {
                s.push_str(&format!(" {}", a));
            }
            println!("{}", s);
        }
    }
}

fn main() {
    run();
}
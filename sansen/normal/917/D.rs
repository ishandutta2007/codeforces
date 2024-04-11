// O(N^2) 
// x=0..n ok
// determinant
// 
// F, 1E, D_x 
// D_x - (x - 1)F - E
// 
// 
// sum_{p} sign(p) ** (D_x_{i, p_i} - (x - 1)F_{i, p_i} - E_{i, p_i})
// 
// E_{i, p_i} 22swap
// E_{i, p_i} 1
// dp
// 
//
// 
// 
// 
// E
// 
//
// 
// 
// E
// 
//  
//  free
//  
// 
//

use util::*;

fn fast(n: usize, e: &[(usize, usize)]) -> Vec<M> {
    let mut g = vec![vec![]; n];
    for &(a, b) in e.iter() {
        g[a].push(b);
        g[b].push(a);
    }
    let root = g.iter().position(|g| g.len() == 1).unwrap();
    let mut topo = vec![root];
    for i in 0..n {
        let v = topo[i];
        for u in g[v].clone() {
            g[u].retain(|e| *e != v);
            topo.push(u);
        }
    }
    let mut sample = vec![];
    for x in 0..n {
        let x = M::from(x);
        #[derive(Clone, Copy, Debug)]
        struct State {
            used: M,
            free: M,
            path: M,
        }
        let zero = State {
            used: M::zero(),
            free: M::zero(),
            path: M::zero(),
        };
        let mut dp = vec![[zero; 2]; n];
        for &v in topo[1..].iter().rev() {
            let deg = g[v].len() + 1;
            let mut val = [zero; 2];
            val[0].free = M::one();
            val[0].used = x * M::from(deg) + M::from(n - 1 - deg) + M::one();
            val[1].used = -M::one();
            for &u in g[v].iter() {
                let b = dp[u];
                let mut next = [zero; 2];
                for (c_e, b) in b.iter().enumerate() {
                    for (v_e, a) in val.iter().enumerate() {
                        if (c_e, v_e) == (1, 1) {
                            continue;
                        }
                        let e = c_e | v_e;
                        next[e].used += a.used * b.used;
                        next[e].path += a.path * b.used;
                        next[e].free += a.free * b.used;
                        next[e].used -= a.free * b.free * (-(x - M::one())).pow(2);
                        next[e].path -= a.free * b.free * -(x - M::one());
                        next[e].path -= a.free * b.path * -(x - M::one());
                        if (c_e, v_e) == (0, 0) {
                            next[1].used -= M::new(2)
                                * (b.path + b.free)
                                * (a.path + a.free)
                                * -(x - M::one())
                                * -M::one();
                        }
                    }
                }
                val = next;
            }
            dp[v] = val;
        }
        let v = topo[1];
        sample.push(dp[v][0].used + dp[v][1].used);
    }
    lagrange_interpolation(sample)
}

fn determinant(mat: Vec<Vec<M>>) -> M {
    fn inner(mut mat: Vec<Vec<M>>) -> Option<M> {
        let n = mat.len();
        assert!(mat.iter().all(|mat| mat.len() == n));
        let mut ans = M::one();
        for i in 0..n {
            let x = (i..n).find(|k| !mat[*k][i].is_zero())?;
            if x != i {
                mat.swap(i, x);
                ans = -ans;
            }
            let mut a = std::mem::take(&mut mat[i]);
            ans *= a[i];
            let inv = a[i].inv();
            a[i..].iter_mut().for_each(|a| *a *= inv);
            for mat in mat[(i + 1)..].iter_mut() {
                let mul = mat[i];
                for (mat, a) in mat[i..].iter_mut().zip(a[i..].iter()) {
                    *mat -= mul * *a;
                }
            }
        }
        Some(ans)
    }
    inner(mat).unwrap_or(M::zero())
}

fn lagrange_interpolation(a: Vec<M>) -> Vec<M> {
    let n = a.len();
    let mut dp = vec![M::zero(); n + 1];
    dp[0] = M::one();
    for i in 0..n {
        let v = M::from(i);
        for j in (0..=i).rev() {
            let u = dp[j];
            dp[j + 1] += u;
            dp[j] = -v * u;
        }
    }
    let mut ans = vec![M::zero(); n];
    for (i, a) in a.into_iter().enumerate() {
        let prod = (0..i)
            .chain((i + 1)..n)
            .fold(M::one(), |s, a| s * (M::from(i) - M::from(a)));
        let mut dp = dp.clone();
        let mut f = vec![M::zero(); n];
        for j in (1..dp.len()).rev() {
            let q = dp[j];
            f[j - 1] = q;
            dp[j - 1] -= q * -M::from(i);
        }
        let mul = a * prod.inv();
        for (ans, f) in ans.iter_mut().zip(f) {
            *ans += f * mul;
        }
    }
    ans
}

fn naive(n: usize, e: &[(usize, usize)]) -> Vec<M> {
    let mut test = vec![];
    for x in 0..n {
        let mut mat = vec![vec![M::zero(); n]; n];
        for i in 0..n {
            for j in 0..i {
                mat[i][j] -= M::one();
                mat[j][i] -= M::one();
                mat[i][i] += M::one();
                mat[j][j] += M::one();
            }
        }
        for &(a, b) in e.iter() {
            mat[a][b] -= M::from(x) - M::one();
            mat[b][a] -= M::from(x) - M::one();
            mat[a][a] += M::from(x) - M::one();
            mat[b][b] += M::from(x) - M::one();
        }
        for mat in mat.iter_mut() {
            mat.pop();
        }
        mat.pop();
        let det = determinant(mat);
        test.push(det);
    }
    lagrange_interpolation(test)
}

fn main() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    println!("{}", fast(n, &e).iter().join(" "));
}

// ---------- begin util ----------
mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
}
// ---------- end util ----------
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
// ---------- begin modint ----------
use std::marker::*;
use std::ops::*;

pub trait Modulo {
    fn modulo() -> u32;
}

pub struct ConstantModulo<const M: u32>;

impl<const M: u32> Modulo for ConstantModulo<{ M }> {
    fn modulo() -> u32 {
        M
    }
}

pub struct ModInt<T>(u32, PhantomData<T>);

impl<T> Clone for ModInt<T> {
    fn clone(&self) -> Self {
        Self::new_unchecked(self.0)
    }
}

impl<T> Copy for ModInt<T> {}

impl<T: Modulo> Add for ModInt<T> {
    type Output = ModInt<T>;
    fn add(self, rhs: Self) -> Self::Output {
        let mut v = self.0 + rhs.0;
        if v >= T::modulo() {
            v -= T::modulo();
        }
        Self::new_unchecked(v)
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
        let mut v = self.0 - rhs.0;
        if self.0 < rhs.0 {
            v += T::modulo();
        }
        Self::new_unchecked(v)
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
        Self::new_unchecked(v as u32)
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
        if self.is_zero() {
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

impl<T> Default for ModInt<T> {
    fn default() -> Self {
        Self::zero()
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
        let mut v = ((val % T::modulo() as i64) + T::modulo() as i64) as u32;
        if v >= T::modulo() {
            v -= T::modulo();
        }
        ModInt::new_unchecked(v)
    }
}

impl<T> ModInt<T> {
    pub fn new_unchecked(n: u32) -> Self {
        ModInt(n, PhantomData)
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
        assert!(!self.is_zero());
        self.pow(T::modulo() as u64 - 2)
    }
    pub fn fact(n: usize) -> Self {
        (1..=n).fold(Self::one(), |s, a| s * Self::from(a))
    }
    pub fn perm(n: usize, k: usize) -> Self {
        if k > n {
            return Self::zero();
        }
        ((n - k + 1)..=n).fold(Self::one(), |s, a| s * Self::from(a))
    }
    pub fn binom(n: usize, k: usize) -> Self {
        if k > n {
            return Self::zero();
        }
        let k = k.min(n - k);
        let mut nu = Self::one();
        let mut de = Self::one();
        for i in 0..k {
            nu *= Self::from(n - i);
            de *= Self::from(i + 1);
        }
        nu * de.inv()
    }
}
// ---------- end modint ----------
// ---------- begin precalc ----------
pub struct Precalc<T> {
    fact: Vec<ModInt<T>>,
    ifact: Vec<ModInt<T>>,
    inv: Vec<ModInt<T>>,
}

impl<T: Modulo> Precalc<T> {
    pub fn new(n: usize) -> Precalc<T> {
        let mut inv = vec![ModInt::one(); n + 1];
        let mut fact = vec![ModInt::one(); n + 1];
        let mut ifact = vec![ModInt::one(); n + 1];
        for i in 2..=n {
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
        Precalc { fact, ifact, inv }
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
    pub fn binom(&self, n: usize, k: usize) -> ModInt<T> {
        if k > n {
            return ModInt::zero();
        }
        self.fact[n] * self.ifact[k] * self.ifact[n - k]
    }
}
// ---------- end precalc ----------

type M = ModInt<ConstantModulo<1_000_000_007>>;
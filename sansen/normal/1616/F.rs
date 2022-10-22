// ---------- begin modint ----------
use std::marker::*;
use std::ops::*;

pub trait Zero: Sized {
    fn zero() -> Self;
    fn is_zero(&self) -> bool;
}

pub trait One {
    fn one() -> Self;
}

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
        Self::new(self.0 * rhs.0)
        //        let v = self.0 as u64 * rhs.0 as u64 % T::modulo() as u64;
        //        Self::new_unchecked(v as u32)
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
}

impl<T> Zero for ModInt<T> {
    fn zero() -> Self {
        ModInt::new_unchecked(0)
    }
    fn is_zero(&self) -> bool {
        self.0 == 0
    }
}

impl<T> One for ModInt<T> {
    fn one() -> Self {
        ModInt::new_unchecked(1)
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

impl<T: Modulo> Div for ModInt<T> {
    type Output = Self;
    fn div(self, rhs: Self) -> Self::Output {
        assert!(!rhs.is_zero());
        self * rhs.inv()
    }
}

impl<T: Modulo> DivAssign for ModInt<T> {
    fn div_assign(&mut self, rhs: Self) {
        *self = *self / rhs;
    }
}

type M = ModInt<ConstantModulo<3>>;

pub trait Field:
    Copy
    + Zero
    + One
    + Add<Output = Self>
    + Sub<Output = Self>
    + Mul<Output = Self>
    + Div<Output = Self>
    + Neg<Output = Self>
{
}

impl<T: Modulo> Field for ModInt<T> {}

pub struct LinerEquation<T> {
    size: usize,
    mat: Vec<T>,
}

impl<T: Field> LinerEquation<T> {
    pub fn new(size: usize) -> Self {
        assert!(size > 0);
        Self {
            size: size,
            mat: vec![],
        }
    }
    pub fn add_equation(&mut self, a: &[T], b: T) {
        assert!(a.len() == self.size);
        self.mat.extend(a);
        self.mat.push(b);
    }
    pub fn solve(&mut self) -> Option<(Vec<T>, Vec<Vec<T>>)> {
        let w = self.size + 1;
        let h = self.mat.len() / w;
        let pos = |x, y| x * w + y;
        let mut mat = std::mem::take(&mut self.mat);
        let mut index = vec![];
        let mut elem = vec![false; w - 1];
        let mut tmp = vec![T::zero(); w];
        for j in 0..(w - 1) {
            let u = index.len();
            if let Some(x) = (u..h).find(|x| !mat[pos(*x, j)].is_zero()) {
                index.push(j);
                elem[j] = true;
                if x != u {
                    let (f, t) = mat.split_at_mut(x * w);
                    f[(u * w)..(u * w + w)].swap_with_slice(&mut t[..w]);
                }
                tmp.copy_from_slice(&mat[(u * w)..(u * w + w)]);
                let inv = T::one() / tmp[j];
                tmp[j..].iter_mut().for_each(|p| *p = *p * inv);
                for (i, mat) in mat.chunks_exact_mut(w).enumerate() {
                    if i == u || mat[j].is_zero() {
                        continue;
                    }
                    let v = mat[j];
                    mat[j..].iter_mut().zip(&tmp[j..]).for_each(|(a, b)| *a = *a - v * *b);
                }
                mat[(u * w)..(u * w + w)].copy_from_slice(&tmp);
            }
        }
        let u = index.len();
        if (u..h).any(|x| !mat[pos(x, w - 1)].is_zero()) {
            return None;
        }
        let mut c = vec![T::zero(); w - 1];
        for (i, index) in index.iter().enumerate() {
            c[*index] = mat[pos(i, w - 1)];
        }
        let mut base = vec![];
        for (j, _) in elem.into_iter().enumerate().filter(|p| !p.1) {
            let mut d = vec![T::zero(); w - 1];
            d[j] = T::one();
            for (mat, index) in mat.chunks_exact(w).zip(&index) {
                d[*index] = -mat[j];
            }
            base.push(d);
        }
        Some((c, base))
    }
}

// sep
pub fn join<T: std::fmt::Display>(a: &[T], sep: &str) -> String {
    use std::fmt::Write;
    let mut s = String::new();
    for (i, a) in a.iter().enumerate() {
        if i > 0 {
            write!(&mut s, "{}", sep).ok();
        }
        write!(&mut s, "{}", a).ok();
    }
    s
}

fn read() -> Vec<(usize, Vec<(usize, usize, i32)>)> {
    let mut s = String::new();
    use std::io::Read;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace().flat_map(|s| s.parse::<i32>());
    let mut next = || it.next().unwrap();
    let t = next();
    (0..t)
        .map(|_| {
            let n = next() as usize;
            let m = next();
            (
                n,
                (0..m)
                    .map(|_| {
                        let a = next() as usize - 1;
                        let b = next() as usize - 1;
                        let c = next();
                        (a, b, c)
                    })
                    .collect(),
            )
        })
        .collect()
}

fn main() {
    let ask = read();
    for (n, e) in ask {
        let m = e.len();
        let mut mat = vec![vec![None; n]; n];
        let mut solver = LinerEquation::new(m);
        for (i, (x, y, c)) in e.into_iter().enumerate() {
            mat[x][y] = Some(i);
            mat[y][x] = Some(i);
            if c != -1 {
                let c = M::new((c - 1) as u32);
                let mut p = vec![M::zero(); m];
                p[i] = M::one();
                solver.add_equation(&p, c);
            }
        }
        for i in 0..n {
            for j in 0..i {
                for k in 0..j {
                    if let (Some(x), Some(y), Some(z)) = (mat[i][j], mat[j][k], mat[k][i]) {
                        let mut p = vec![M::zero(); m];
                        p[x] = M::one();
                        p[y] = M::one();
                        p[z] = M::one();
                        solver.add_equation(&p, M::zero());
                    }
                }
            }
        }
        if let Some((c, _)) = solver.solve() {
            let c = c.iter().map(|c| c.0 + 1).collect::<Vec<_>>();
            println!("{}", join(&c, " "));
        } else {
            println!("-1");
        }
    }
}
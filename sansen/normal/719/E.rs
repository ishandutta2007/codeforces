// ---------- begin Matrix ----------
trait SemiRing: std::ops::Add<Output = Self> + std::ops::Mul<Output = Self> + Copy {
    fn zero() -> Self;
    fn one() -> Self;
}

#[derive(Clone)]
struct SquareMatrix<R> {
    buf: [[R; 2]; 2],
}

#[allow(dead_code)]
impl<R: SemiRing> SquareMatrix<R> {
    fn zero() -> Self {
        SquareMatrix {
            buf: [[R::zero(); 2]; 2],
        }
    }
    fn identity() -> Self {
        let mut e = Self::zero();
        for i in 0..2 {
            e.buf[i][i] = R::one();
        }
        e
    }
    fn set_at(&mut self, x: usize, y: usize, val: R) {
        self.buf[x][y] = val;
    }
    fn get_at(&self, x: usize, y: usize) -> R {
        self.buf[x][y]
    }
    fn matadd(&self, rhs: &Self) -> Self {
        let mut res = Self::zero();
        for (x, (a, b)) in res.buf.iter_mut().zip(self.buf.iter().zip(rhs.buf.iter())) {
            for (x, (a, b)) in x.iter_mut().zip(a.iter().zip(b.iter())) {
                *x = *a + *b;
            }
        }
        res
    }
    fn matmul(&self, rhs: &Self) -> Self {
        let mut res = Self::zero();
        res.buf[0][0] = self.buf[0][0] * rhs.buf[0][0] + self.buf[0][1] * rhs.buf[1][0];
        res.buf[0][1] = self.buf[0][0] * rhs.buf[0][1] + self.buf[0][1] * rhs.buf[1][1];
        res.buf[1][0] = self.buf[1][0] * rhs.buf[0][0] + self.buf[1][1] * rhs.buf[1][0];
        res.buf[1][1] = self.buf[1][0] * rhs.buf[0][1] + self.buf[1][1] * rhs.buf[1][1];
        /*
        for (x, a) in res.buf.iter_mut().zip(self.buf.iter()) {
            for (a, b) in a.iter().zip(rhs.buf.iter()) {
                for (x, b) in x.iter_mut().zip(b.iter()) {
                    *x = *x + *a * *b;
                }
            }
        }
        */
        res
    }
    fn mat_pow(&self, mut n: usize) -> Self {
        let mut t = Self::identity();
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
// ---------- end Matrix ----------
// ---------- begin Lazy Segment Tree ----------
mod segment_tree {
    pub struct Lazy<T, E, F, G, H> {
        size: usize,
        bit: usize,
        a: Vec<(Option<T>, Option<E>)>,
        fold: F,
        eval: G,
        merge: H,
    }
    #[allow(dead_code)]
    impl<T: Clone, E: Clone, F: Fn(&T, &T) -> T, G: Fn(&T, &E) -> T, H: Fn(&E, &E) -> E>
        Lazy<T, E, F, G, H>
    {
        pub fn new(n: usize, f: F, g: G, h: H) -> Lazy<T, E, F, G, H> {
            let mut k = 0;
            while (1 << k) < n {
                k += 1;
            }
            Lazy {
                size: 1 << k,
                bit: k,
                a: vec![(None, None); 2 << k],
                fold: f,
                eval: g,
                merge: h,
            }
        }
        fn fold_op(a: &Option<T>, b: &Option<T>, fold: &F) -> Option<T> {
            match (a.as_ref(), b.as_ref()) {
                (Some(a), Some(b)) => Some((fold)(a, b)),
                (Some(a), None) => Some(a.clone()),
                (None, Some(b)) => Some(b.clone()),
                (None, None) => None,
            }
        }
        fn eval_op(x: &Option<T>, f: &Option<E>, eval: &G) -> Option<T> {
            match (x.as_ref(), f.as_ref()) {
                (Some(x), Some(f)) => Some((eval)(x, f)),
                (Some(x), None) => Some(x.clone()),
                (None, _) => None,
            }
        }
        fn merge_op(g: &Option<E>, h: &Option<E>, merge: &H) -> Option<E> {
            match (g.as_ref(), h.as_ref()) {
                (Some(a), Some(b)) => Some((merge)(a, b)),
                (Some(a), None) => Some(a.clone()),
                (None, Some(b)) => Some(b.clone()),
                (None, None) => None,
            }
        }
        pub fn build_by(z: &Vec<T>, f: F, g: G, h: H) -> Lazy<T, E, F, G, H> {
            let mut seg = Self::new(z.len(), f, g, h);
            let a = &mut seg.a;
            for (i, z) in z.iter().enumerate() {
                a[i + seg.size].0 = Some(z.clone());
            }
            for i in (1..seg.size).rev() {
                a[i].0 = Self::fold_op(&a[2 * i].0, &a[2 * i + 1].0, &seg.fold);
            }
            seg
        }
        fn propagate(&mut self, mut x: usize) {
            x += self.size;
            let a = &mut self.a;
            for k in (1..(self.bit + 1)).rev() {
                let y = x >> k;
                a[y].0 = Self::eval_op(&a[y].0, &a[y].1, &self.eval);
                a[2 * y].1 = Self::merge_op(&a[2 * y].1, &a[y].1, &self.merge);
                a[2 * y + 1].1 = Self::merge_op(&a[2 * y + 1].1, &a[y].1, &self.merge);
                a[y].1 = None;
            }
        }
        fn save(&mut self, l: usize, r: usize) {
            let mut l = l + self.size;
            let mut r = r + self.size;
            let a = &mut self.a;
            let mut flag_l = l & 1 == 1;
            let mut flag_r = r & 1 == 1;
            l >>= 1;
            r >>= 1;
            while l < r {
                if flag_l {
                    let k = l;
                    let p = Self::eval_op(&a[2 * k].0, &a[2 * k].1, &self.eval);
                    let q = Self::eval_op(&a[2 * k + 1].0, &a[2 * k + 1].1, &self.eval);
                    a[k].0 = Self::fold_op(&p, &q, &self.fold);
                }
                flag_l |= (l & 1) == 1;
                if flag_r {
                    let k = r;
                    let p = Self::eval_op(&a[2 * k].0, &a[2 * k].1, &self.eval);
                    let q = Self::eval_op(&a[2 * k + 1].0, &a[2 * k + 1].1, &self.eval);
                    a[k].0 = Self::fold_op(&p, &q, &self.fold);
                }
                flag_r |= (r & 1) == 1;
                l >>= 1;
                r >>= 1;
            }
            let mut k = l;
            while k > 0 {
                let l = Self::eval_op(&a[2 * k].0, &a[2 * k].1, &self.eval);
                let r = Self::eval_op(&a[2 * k + 1].0, &a[2 * k + 1].1, &self.eval);
                a[k].0 = Self::fold_op(&l, &r, &self.fold);
                k >>= 1;
            }
        }
        pub fn update(&mut self, l: usize, r: usize, f: E) {
            //self.propagate(l);
            //self.propagate(r - 1);
            let mut x = l + self.size;
            let mut y = r + self.size;
            let f = Some(f);
            while x < y {
                let a = &mut self.a;
                if (x & 1) == 1 {
                    a[x].1 = Self::merge_op(&a[x].1, &f, &self.merge);
                    x += 1;
                }
                if (y & 1) == 1 {
                    y -= 1;
                    a[y].1 = Self::merge_op(&a[y].1, &f, &self.merge);
                }
                x >>= 1;
                y >>= 1;
            }
            self.save(l, r);
        }
        pub fn find(&mut self, l: usize, r: usize) -> Option<T> {
            self.propagate(l);
            self.propagate(r - 1);
            let mut p: Option<T> = None;
            let mut q: Option<T> = None;
            let mut x = l + self.size;
            let mut y = r + self.size;
            while x < y {
                if (x & 1) == 1 {
                    p = Self::fold_op(
                        &p,
                        &Self::eval_op(&self.a[x].0, &self.a[x].1, &self.eval),
                        &self.fold,
                    );
                    x += 1;
                }
                if (y & 1) == 1 {
                    y -= 1;
                    q = Self::fold_op(
                        &Self::eval_op(&self.a[y].0, &self.a[y].1, &self.eval),
                        &q,
                        &self.fold,
                    );
                }
                x >>= 1;
                y >>= 1;
            }
            Self::fold_op(&p, &q, &self.fold)
        }
    }
}
// ---------- end Lazy Segment Tree ----------
// ---------- begin ModInt ----------
const MOD: u32 = 1_000_000_007;

#[derive(Clone, Copy)]
struct ModInt(u32);

impl std::ops::Add for ModInt {
    type Output = ModInt;
    fn add(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::AddAssign for ModInt {
    fn add_assign(&mut self, rhs: ModInt) {
        *self = *self + rhs;
    }
}

impl std::ops::Sub for ModInt {
    type Output = ModInt;
    fn sub(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::SubAssign for ModInt {
    fn sub_assign(&mut self, rhs: ModInt) {
        *self = *self - rhs;
    }
}

impl std::ops::Mul for ModInt {
    type Output = ModInt;
    fn mul(self, rhs: ModInt) -> Self::Output {
        ModInt((self.0 as u64 * rhs.0 as u64 % MOD as u64) as u32)
    }
}

impl std::ops::MulAssign for ModInt {
    fn mul_assign(&mut self, rhs: ModInt) {
        *self = *self * rhs;
    }
}

impl std::ops::Neg for ModInt {
    type Output = ModInt;
    fn neg(self) -> Self::Output {
        ModInt(if self.0 == 0 { 0 } else { MOD - self.0 })
    }
}

impl std::fmt::Display for ModInt {
    fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

impl std::str::FromStr for ModInt {
    type Err = std::num::ParseIntError;
    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let val = s.parse::<u32>()?;
        Ok(ModInt::new(val))
    }
}

#[allow(dead_code)]
impl ModInt {
    pub fn new(n: u32) -> ModInt {
        ModInt(n % MOD)
    }
    pub fn zero() -> ModInt {
        ModInt(0)
    }
    pub fn one() -> ModInt {
        ModInt(1)
    }
    pub fn pow(self, mut n: u32) -> ModInt {
        let mut t = ModInt::one();
        let mut s = self;
        while n > 0 {
            if n & 1 == 1 {
                t *= s;
            }
            s *= s;
            n >>= 1;
        }
        t
    }
    pub fn inv(self) -> ModInt {
        self.pow(MOD - 2)
    }
}
// ---------- end ModInt ----------
// ---------- begin Precalc ----------
#[allow(dead_code)]
struct Precalc {
    inv: Vec<ModInt>,
    fact: Vec<ModInt>,
    ifact: Vec<ModInt>,
}

#[allow(dead_code)]
impl Precalc {
    pub fn new(n: usize) -> Precalc {
        let mut inv = vec![ModInt::one(); n + 1];
        let mut fact = vec![ModInt::one(); n + 1];
        let mut ifact = vec![ModInt::one(); n + 1];
        for i in 2..(n + 1) {
            inv[i] = -inv[MOD as usize % i] * ModInt(MOD / i as u32);
            fact[i] = fact[i - 1] * ModInt(i as u32);
            ifact[i] = ifact[i - 1] * inv[i];
        }
        Precalc {
            inv: inv,
            fact: fact,
            ifact: ifact,
        }
    }
    pub fn inv(&self, n: usize) -> ModInt {
        self.inv[n]
    }
    pub fn fact(&self, n: usize) -> ModInt {
        self.fact[n]
    }
    pub fn ifact(&self, n: usize) -> ModInt {
        self.ifact[n]
    }
    pub fn comb(&self, n: usize, k: usize) -> ModInt {
        if k > n {
            return ModInt::zero();
        }
        self.fact[n] * self.ifact[k] * self.ifact[n - k]
    }
}
// ---------- end Precalc ----------

impl SemiRing for ModInt {
    fn zero() -> Self {
        ModInt(0)
    }
    fn one() -> Self {
        ModInt(1)
    }
}

use std::io::Read;
use std::io::Write;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();
    type T = SquareMatrix<ModInt>;
    let mut ini = T::zero();
    ini.set_at(0, 0, ModInt::one());
    ini.set_at(1, 0, ModInt::one());
    ini.set_at(0, 1, ModInt::one());
    let mut pow = vec![ini];
    for _ in 1..30 {
        let v = pow.last().unwrap().matmul(pow.last().unwrap());
        pow.push(v);
    }
    let mat_pow = |n: usize| {
        let mut t = T::identity();
        for k in 0..30 {
            if (n >> k) & 1 == 1 {
                t = t.matmul(&pow[k]);
            }
        }
        t
    };
    let mut z = vec![];
    for _ in 0..n {
        let a: usize = it.next().unwrap().parse().unwrap();
        z.push(mat_pow(a));
    }
    let mut seg = segment_tree::Lazy::build_by(&z, T::matadd, T::matmul, T::matmul);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for _ in 0..m {
        let op: u8 = it.next().unwrap().parse().unwrap();
        let l: usize = it.next().unwrap().parse().unwrap();
        let r: usize = it.next().unwrap().parse().unwrap();
        if op == 1 {
            let x: usize = it.next().unwrap().parse().unwrap();
            seg.update(l - 1, r, mat_pow(x));
        } else {
            let ans = seg.find(l - 1, r).unwrap().get_at(0, 1);
            writeln!(out, "{}", ans).ok();
        }
    }
}

fn main() {
    run();
}
fn main() {
    input! {
        n: usize,
        k: usize,
        e: [(usize1, usize1); n - 1],
    }
    let pc = Precalc::new(n);
    let mut solver = Rerooting::new(n, R(k, &pc));
    for (a, b) in e {
        solver.add_edge(a, b, ());
    }
    let mut ans = M::zero();
    let res = solver.solve();
    for (sum, child_sum, _) in res {
        ans += sum + M::from(n) * (pc.binom(n, k) - child_sum);
    }
    println!("{}", ans);
}

struct R<'a>(usize, &'a Precalc<E>);
impl<'a> RerootingOperator for R<'a> {
    // sum, child_sum, size
    type Value = (M, M, usize);
    type Edge = ();
    fn init(&mut self, _v: usize) -> Self::Value {
        (M::zero(), M::zero(), 1)
    }
    fn merge(&mut self, p: &Self::Value, c: &Self::Value, _e: &Self::Edge) -> Self::Value {
        let sum = p.0 + c.0 + M::from(c.2) * (self.1.binom(c.2, self.0) - c.1);
        let child_sum = p.1 + self.1.binom(c.2, self.0);
        let size = p.2 + c.2;
        (sum, child_sum, size)
    }
}

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
// ---------- begin Rerooting ----------
pub trait RerootingOperator {
    type Value: Clone;
    type Edge: Clone;
    fn init(&mut self, v: usize) -> Self::Value;
    fn merge(&mut self, p: &Self::Value, c: &Self::Value, e: &Self::Edge) -> Self::Value;
}

pub struct Rerooting<R: RerootingOperator> {
    manager: R,
    size: usize,
    edge: Vec<(usize, usize, R::Edge, R::Edge)>,
}

impl<R: RerootingOperator> Rerooting<R> {
    pub fn new(size: usize, manager: R) -> Self {
        assert!(size > 0 && size < 10usize.pow(8));
        Rerooting {
            manager: manager,
            size: size,
            edge: vec![],
        }
    }
    pub fn add_edge(&mut self, a: usize, b: usize, cost: R::Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.add_edge_bi(a, b, cost.clone(), cost);
    }
    pub fn add_edge_bi(&mut self, a: usize, b: usize, ab: R::Edge, ba: R::Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b, ab, ba));
    }
    pub fn solve(&mut self) -> Vec<R::Value> {
        let size = self.size;
        let mut graph = vec![vec![]; size];
        for e in self.edge.iter() {
            graph[e.0].push((e.1, e.2.clone()));
            graph[e.1].push((e.0, e.3.clone()));
        }
        let root = 0;
        let mut topo = vec![root];
        let mut parent = vec![root; size];
        let mut parent_edge: Vec<Option<R::Edge>> = (0..size).map(|_| None).collect();
        for i in 0..size {
            let v = topo[i];
            let child = std::mem::take(&mut graph[v]);
            for &(u, _) in child.iter() {
                let k = graph[u].iter().position(|e| e.0 == v).unwrap();
                let c = graph[u].remove(k).1;
                parent_edge[u] = Some(c);
                parent[u] = v;
                topo.push(u);
            }
            graph[v] = child;
        }
        let manager = &mut self.manager;
        let mut down: Vec<_> = (0..size).map(|v| manager.init(v)).collect();
        for &v in topo.iter().rev() {
            for &(u, ref w) in graph[v].iter() {
                down[v] = manager.merge(&down[v], &down[u], w);
            }
        }
        let mut up: Vec<_> = (0..size).map(|v| manager.init(v)).collect();
        let mut stack = vec![];
        for &v in topo.iter() {
            if let Some(e) = parent_edge[v].take() {
                let ini = manager.init(v);
                up[v] = manager.merge(&ini, &up[v], &e);
            }
            if !graph[v].is_empty() {
                stack.push((graph[v].as_slice(), up[v].clone()));
                while let Some((g, val)) = stack.pop() {
                    if g.len() == 1 {
                        up[g[0].0] = val;
                    } else {
                        let m = g.len() / 2;
                        let (a, b) = g.split_at(m);
                        for a in [(a, b), (b, a)].iter() {
                            let mut p = val.clone();
                            for a in a.0.iter() {
                                p = manager.merge(&p, &down[a.0], &a.1);
                            }
                            stack.push((a.1, p));
                        }
                    }
                }
            }
            for e in graph[v].iter() {
                up[v] = manager.merge(&up[v], &down[e.0], &e.1);
            }
        }
        up
    }
}
// ---------- end Rerooting ----------
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

type E = ConstantModulo<1_000_000_007>;
type M = ModInt<E>;
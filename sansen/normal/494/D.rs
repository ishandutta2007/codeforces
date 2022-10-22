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
        pub fn inv(&self) -> Self {
            assert!(self.0 != 0);
            self.pow(T::modulo() as u64 - 2)
        }
    }

    #[allow(dead_code)]
    pub fn mod_pow(r: u64, mut n: u64, m: u64) -> u64 {
        let mut t = 1 % m;
        let mut s = r % m;
        while n > 0 {
            if n & 1 == 1 {
                t = t * s % m;
            }
            s = s * s % m;
            n >>= 1;
        }
        t
    }
}
// ---------- end ModInt ----------
// ---------- begin Lowest Common Ancestor ----------
struct LCA {
    graph: Vec<Vec<usize>>,
    parent: Vec<usize>,
    path_root: Vec<usize>,
    path_parent: Vec<usize>,
    index: Vec<usize>
}

#[allow(dead_code)]
impl LCA {
    fn new(n: usize) -> Self {
        LCA {
            graph: vec![vec![]; n],
            parent: vec![],
            path_root: vec![],
            path_parent: vec![],
            index: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a != b && a < self.graph.len() && b < self.graph.len());
        self.graph[a].push(b);
        self.graph[b].push(a);
    }
    fn build(&mut self, root: usize) {
        let n = self.graph.len();
        assert!(root < n);
        let mut parent = vec![root; n];
        let mut q = vec![root];
        let graph = &mut self.graph;
        for i in 0..n {
            let v = q[i];
            let p = parent[v];
            let child = &mut graph[v];
            if let Some(k) = child.iter().position(|u| *u == p) {
                child.swap_remove(k);
            }
            for &u in child.iter() {
                parent[u] = v;
                q.push(u);
            }
        }
        let mut size = vec![1; n];
        for &v in q.iter().rev() {
            if graph[v].is_empty() {
                continue;
            }
            let mut max = (0, 0);
            for (i, &u) in graph[v].iter().enumerate() {
                size[v] += size[u];
                if size[u] > max.0 {
                    max = (size[u], i);
                }
            }
            graph[v].swap(0, max.1);
        }
        let mut path_root = vec![root; n];
        let mut path_parent = vec![root; n];
        let mut index = vec![n; n];
        let mut stack = vec![root];
        let mut k = 0;
        while let Some(v) = stack.pop() {
            index[v] = k;
            k += 1;
            if graph[v].is_empty() {
                continue;
            }
            for &u in graph[v].iter().skip(1) {
                path_root[u] = u;
                path_parent[u] = v;
                stack.push(u);
            }
            let u = graph[v][0];
            path_root[u] = path_root[v];
            path_parent[u] = path_parent[v];
            stack.push(u);
        }
        self.parent = parent;
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.index = index;
    }
    fn query(&self, mut a: usize, mut b: usize) -> usize {
        let path = &self.path_root;
        let parent = &self.path_parent;
        let index = &self.index;
        while path[a] != path[b] {
            if index[a] < index[b] {
                b = parent[b];
            } else {
                a = parent[a];
            }
        }
        if index[a] < index[b] {a} else {b}
    }
    fn parent(&self, v: usize) -> Option<usize> {
        let p = self.parent[v];
        if p == v {
            None
        } else {
            Some(p)
        }
    }
}
// ---------- end Lowest Common Ancestor ----------
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

use modint::*;
type M = ModInt<Mod>;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        e: [(usize1, usize1, M); n - 1],
        q: usize,
        ask: [(usize1, usize1); q],
    }
    let root = 0;
    let mut g = vec![vec![]; n];
    let mut lca = LCA::new(n);
    for &(a, b, c) in e.iter() {
        g[a].push((b, c));
        g[b].push((a, c));
        lca.add_edge(a, b);
    }
    lca.build(root);
    let mut q = vec![root];
    let mut parent = vec![(0, M::zero()); n];
    let mut depth = vec![M::zero(); n];
    for i in 0..n {
        let v = q[i];
        let child = std::mem::take(&mut g[v]);
        for &(u, c) in child.iter() {
            let k = g[u].iter().position(|c| c.0 == v).unwrap();
            g[u].remove(k);
            parent[u] = (v, c);
            depth[u] = depth[v] + c;
            q.push(u);
        }
        g[v] = child;
    }
    // sum d, sum d^2
    let mut dp = vec![(M::zero(), M::zero(), M::zero()); n];
    for &v in q.iter().rev() {
        let mut val = (M::one(), M::zero(), M::zero());
        for &(u, w) in g[v].iter() {
            let (a, b, c) = dp[u];
            val.0 += a;
            val.1 += b + a * w;
            val.2 += w * w * a + M::new(2) * w * b + c;
        }
        dp[v] = val;
    }
    let down = dp;
    // sum d, sum d^2, 
    let mut dp = vec![(M::zero(), M::zero()); n];
    let all = M::from(n);
    for &v in q.iter() {
        let mut sum = (dp[v].0 + down[v].1, dp[v].1 + down[v].2);
        for &(u, w) in g[v].iter() {
            let (a, b, c) = down[u];
            sum.1 -= w * w * a + M::new(2) * w * b + c;
            sum.0 -= b + a * w;
            sum.1 += w * w * (all - a) + M::new(2) * w * sum.0;
            sum.0 += w * (all - a);
            dp[u] = sum;
            sum.0 -= w * (all - a);
            sum.1 -= w * w * (all - a) + M::new(2) * w * sum.0;
            sum.1 += w * w * a + M::new(2) * w * b + c;
            sum.0 += b + a * w;
        }
    }
    let up = dp;
    for (a, b) in ask {
        let p = lca.query(a, b);
        let d = depth[a] + depth[b] - M::new(2) * depth[p];
        let mut ans = -(up[a].1 + down[a].2);
        if b == 0 {
            ans = up[a].1 + down[a].2;
        } else if b == p {
            let (x, y) = up[b];
            let (p, _, _) = down[b];
            ans = up[a].1 + down[a].2;
            ans -= M::new(2) * (y + M::new(2) * d * x + (all - p) * d * d);
        } else {
            let (x, y, z) = down[b];
            ans += M::new(2) * (d * d * x + M::new(2) * d * y + z);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
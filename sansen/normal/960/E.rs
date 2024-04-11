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
        ModInt(if self.0 == 0 {0} else {MOD - self.0})
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
        assert!(self.0 > 0);
        self.pow(MOD - 2)
    }
}
// ---------- end ModInt ----------
// ---------- begin Rerooting ----------
struct Rerooting<Edge, Value, Func, Init> {
    size: usize,
    edge: Vec<(usize, usize, Edge, Edge)>,
    init: Init,
    merge: Func,
    phantom: std::marker::PhantomData<Value>,
}

impl<Edge, Value, Func, Init> Rerooting<Edge, Value, Func, Init>
where
    Edge: Clone,
    Value: Clone,
    Func: Fn(&Value, &Value, &Edge) -> Value,
    Init: Fn(usize) -> Value,
{
    fn new(size: usize, init: Init, func: Func) -> Self {
        Rerooting {
            size: size,
            edge: vec![],
            init: init,
            merge: func,
            phantom: std::marker::PhantomData,
        }
    }
    #[allow(dead_code)]
    fn add_edge(&mut self, a: usize, b: usize, cost: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b, cost.clone(), cost));
    }
    #[allow(dead_code)]
    fn add_edge_bi(&mut self, a: usize, b: usize, x: Edge, y: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b, x, y));
    }
    fn solve(&self) -> Vec<Value> {
        let mut graph = vec![vec![]; self.size];
        for e in self.edge.iter() {
            graph[e.0].push((e.1, e.2.clone()));
            graph[e.1].push((e.0, e.3.clone()));
        }
        let root = 0;
        let mut topo = Vec::with_capacity(self.size);
        let mut parent = vec![root; self.size];
        let mut parent_edge: Vec<Option<Edge>> = (0..self.size).map(|_| None).collect();
        let mut stack = vec![root];
        while let Some(v) = stack.pop() {
            topo.push(v);
            if let Some(k) = graph[v].iter().position(|e| e.0 == parent[v]) {
                let x = graph[v].remove(k);
                parent_edge[v] = Some(x.1);
            }
            for e in graph[v].iter() {
                parent[e.0] = v;
                stack.push(e.0);
            }
        }
        assert!(topo.len() == self.size);
        let mut down: Vec<Value> = (0..self.size).map(|k| (self.init)(k)).collect();
        for &v in topo.iter().rev() {
            for e in graph[v].iter() {
                down[v] = (self.merge)(&down[v], &down[e.0], &e.1);
            }
        }
        let mut up: Vec<Value> = (0..self.size).map(|k| (self.init)(k)).collect();
        let mut ans = up.clone();
        for &v in topo.iter() {
            if let Some(e) = parent_edge[v].take() {
                up[v] = (self.merge)(&ans[v], &up[v], &e);
            }
            ans[v] = up[v].clone();
            for e in graph[v].iter() {
                ans[v] = (self.merge)(&ans[v], &down[e.0], &e.1);
            }
            if graph[v].is_empty() {
                continue;
            }
            let mut stack = vec![(graph[v].as_slice(), up[v].clone())];
            while let Some((g, val)) = stack.pop() {
                if g.len() == 1 {
                    up[g[0].0] = val;
                } else {
                    let m = g.len() / 2;
                    let (a, b) = g.split_at(m);
                    let mut p = val.clone();
                    for e in a.iter() {
                        p = (self.merge)(&p, &down[e.0], &e.1);
                    }
                    let mut q = val;
                    for e in b.iter() {
                        q = (self.merge)(&q, &down[e.0], &e.1);
                    }
                    stack.push((b, p));
                    stack.push((a, q));
                }
            }
        }
        ans
    }
}
// ---------- end Rerooting ----------

use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let a: Vec<ModInt> = (0..n).map(|_| {
        let a: i64 = it.next().unwrap().parse().unwrap();
        ModInt::new((a + MOD as i64) as u32)
    }).collect();
    type T = (ModInt, ModInt, ModInt);
    type E = ();
    let init = |v: usize| -> T {
        (a[v], a[v], ModInt::one())
    };
    let merge = |a: &T, b: &T, _c: &E| -> T {
        let mut p = *a;
        p.0 += a.1 * b.2 - b.0;
        p.2 += b.2;
        p
    };
    let mut solver = Rerooting::new(n, init, merge);
    for _ in 1..n {
        let a: usize = it.next().unwrap().parse().unwrap();
        let b: usize = it.next().unwrap().parse().unwrap();
        solver.add_edge(a - 1, b - 1, ());
    }
    let ans = solver.solve().into_iter().fold(ModInt::zero(), |s, a| s + a.0);
    println!("{}", ans);
}

fn main() {
    run();
}
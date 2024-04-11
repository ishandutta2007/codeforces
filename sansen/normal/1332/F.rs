// ---------- begin ModInt ----------
const MOD: u32 = 998_244_353;

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
// ---------- begin Tree DP ----------
struct TreeDP<Edge, Value, Init, Merge> {
    size: usize,
    graph: Vec<Vec<(usize, Edge)>>,
    init: Init,
    merge: Merge,
    phantom: std::marker::PhantomData<Value>,
}

impl<Edge, Value, Init, Merge> TreeDP<Edge, Value, Init, Merge>
where Edge: Clone,
      Value: Clone,
      Init: Fn(usize) -> Value,
      Merge: Fn(Value, Value, &Edge) -> Value,
{
    fn new(size: usize, init: Init, merge: Merge) -> Self {
        TreeDP {
            size: size,
            graph: vec![vec![]; size],
            init: init,
            merge: merge,
            phantom: std::marker::PhantomData,
        }
    }
    fn add_edge(&mut self, a: usize, b: usize, c: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.graph[a].push((b, c.clone()));
        self.graph[b].push((a, c));
    }
    fn solve(&self, root: usize) -> Value {
        let size = self.size;
        let graph = &self.graph;
        let mut topo = vec![];
        let mut parent = vec![root; size];
        let mut stack = vec![root];
        while let Some(v) = stack.pop() {
            topo.push(v);
            for e in graph[v].iter() {
                if e.0 != parent[v] {
                    parent[e.0] = v;
                    stack.push(e.0);
                }
            }
        }
        assert!(topo.len() == size);
        let mut dp: Vec<Option<Value>> = (0..size).map(|_| None).collect();
        for &v in topo.iter().rev() {
            let mut now = (self.init)(v);
            for u in graph[v].iter() {
                if u.0 == parent[v] {
                    continue;
                }
                let b = dp[u.0].take().unwrap();
                now = (self.merge)(now, b, &u.1);
            }
            dp[v] = Some(now);
        }
        dp[root].take().unwrap()
    }
}
// ---------- end Tree DP ----------
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

// DP
// 
// 
// induced 
//
// 0: induced 
// 1: induced 
// 2: induced 

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    type Value = (ModInt, ModInt, ModInt);
    type Edge = ();
    let init = |_v: usize| -> Value {
        (ModInt::one(), ModInt::zero(), ModInt::zero())
    };
    let merge = |a: Value, b: Value, _c: &Edge| -> Value {
        let mut ans = (ModInt::zero(), ModInt::zero(), ModInt::zero());
        // 
        ans.0 += a.0 * (b.0 + b.1 + b.2);
        ans.1 += a.1 * (b.0 + b.1 + b.2);
        ans.2 += a.2 * (b.0 + b.1 + b.2);
        // 
        ans.1 += a.0 * (b.0 + b.2) + a.1 * (b.0 + b.2);
        ans.2 += a.0 * (ModInt(2) * b.0 + b.1 + b.2) + a.2 * (ModInt(2) * b.0 + b.1 + b.2);
//        println!("{} {} {}", ans.0, ans.1, ans.2);
        ans
    };
    let mut solver = TreeDP::new(n, init, merge);
    for (a, b) in e {
        solver.add_edge(a, b, ());
    }
    let ans = solver.solve(0);
    let ans = ans.2 + ans.1 + ans.0 - ModInt::one();
    println!("{}", ans);
}

fn main() {
    run();
}
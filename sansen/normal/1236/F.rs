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

// 
// () - () + ()
// V[X] = E[X^2] - E[X]^2
// 
// A = 
// B = 
// C = 
// X^2?
// X^2 = A^2 + B^2 + C^2 + 2 * (-AB - BC + CA)
// 
// A_i: 
// B_j: 
// C_k: 
// 
// P(A_i) = 1/2
// P(B_j) = 1/4
// P(C_k) = 1/2^len (len )
// 
// E[A_i * A_j] i=j 1/2, 1/4
// E[B_i * B_j] i=j 1/4, 1/8 1/16
// E[C_i * B_j] i=j P(C_i), 2P(C_i)P(C_j), P(C_i)P(C_j)
// E[A_i * B_j] 1/4, 1/8
// E[B_i * C_j] P(C_j), P(C_j)/2, P(C_j)/4
// E[C_j * A_i] P(C_j), P(C_j)/2
// ...
fn run() {
    input! {
        n: usize,
        m: usize,
        edge: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for &(a, b) in edge.iter() {
        g[a].push(b);
        g[b].push(a);
    }
    let root = 0;
    let mut depth = vec![n; n];
    let mut parent = vec![root; n];
    depth[root] = 0;
    let mut stack = vec![root];
    let mut q = vec![];
    let mut back = vec![];
    while let Some(v) = stack.pop() {
        q.push(v);
        for &u in g[v].iter() {
            if depth[u] == n {
                depth[u] = depth[v] + 1;
                parent[u] = v;
                stack.push(u);
            } else if u != parent[v] {
                back.push((std::cmp::min(u, v), std::cmp::max(u, v)));
            }
        }
    }
    back.sort();
    back.dedup();
    let mut cycle_len = vec![1; back.len()];
    let mut cycle = vec![vec![]; n];
    for (i, &(mut u, mut v)) in back.iter().enumerate() {
        while u != v {
            cycle_len[i] += 1;
            if depth[u] <= depth[v] {
                cycle[v].push(i);
                v = parent[v];
            } else {
                cycle[u].push(i);
                u = parent[u];
            }
        }
        cycle[u].push(i);
    }
    let len = n + m + 4;
    let mut pow = vec![ModInt::one(); len + 1];
    let inv2 = ModInt(2).inv();
    for i in 1..=len {
        pow[i] = pow[i - 1] * inv2;
    }
    let pow = pow;
    let mut ans = ModInt::zero();
    // E[X]^2
    ans -= {
        let mut e = ModInt::zero();
        e += pow[1] * ModInt(n as u32);
        e -= pow[2] * ModInt(m as u32);
        for len in cycle_len.iter() {
            e += pow[*len];
        }
        e * e
    };
    // A * A
    ans += {
        let x = ModInt(n as u32);
        x * x * pow[2] - x * pow[2] + x * pow[1]
    };
    // B * B
    ans += {
        let x = ModInt(m as u32);
        let mut b = pow[4] * x * x - pow[4] * x + pow[2] * x;
        for g in g.iter() {
            let len = g.len() as u32;
            if len >= 2 {
                b -= pow[4] * ModInt(len) * ModInt(len - 1);
                b += pow[3] * ModInt(len) * ModInt(len - 1);
            }
        }
        b
    };
    // C * C
    ans += {
        let s = cycle_len.iter().fold(ModInt::zero(), |s, a| s + pow[*a]);
        let mut c = s * s + s;
        for len in cycle_len.iter() {
            c -= pow[*len].pow(2);
        }
        for id in cycle.iter() {
            if id.len() > 1 {
                let mut s = ModInt::zero();
                let mut t = ModInt::zero();
                for k in id.iter() {
                    let x = pow[cycle_len[*k]];
                    s += x;
                    t += x * x;
                }
                c += s * s - t;
            }
        }
        c
    };
    // A * B
    ans -= ModInt(2) * {
        let v = ModInt(n as u32);
        let e = ModInt(m as u32);
        v * e * pow[3] - ModInt(2) * e * pow[3] + ModInt(2) * e * pow[2]
    };
    // A * C
    ans += ModInt(2) * {
        let mut res = ModInt::zero();
        res += ModInt(n as u32) * pow[1] * cycle_len.iter().fold(ModInt::zero(), |s, a| s + pow[*a]);
        for id in cycle.iter() {
            for &k in id.iter() {
                res -= pow[1] * pow[cycle_len[k]];
                res += pow[cycle_len[k]];
            }
        }
        res
    };
    // B * C
    ans -= ModInt(2) * {
        let e = ModInt(m as u32);
        let mut res = ModInt::zero();
        for i in 0..back.len() {
            let len = cycle_len[i];
            let (mut u, mut v) = back[i];
            res += e * pow[2] * pow[len];
            res -= ModInt(len as u32) * pow[2] * pow[len];
            res += ModInt(len as u32) * pow[len];
            let mut d = 0;
            while u != v {
                if depth[u] <= depth[v] {
                    d += g[v].len() - 2;
                    v = parent[v];
                } else {
                    d += g[u].len() - 2;
                    u = parent[u];
                }
            }
            d += g[u].len() - 2;
            res -= ModInt(d as u32) * pow[2] * pow[len];
            res += ModInt(d as u32) * pow[1] * pow[len];
        }
        res
    };
    println!("{}", ans);
}

fn main() {
    run();
}
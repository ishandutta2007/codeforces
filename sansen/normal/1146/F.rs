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

/* 
impl std::fmt::Display for ModInt {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}
*/

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

fn run() {
    input! {
        n: usize,
        p: [usize1; n - 1],
    }
    let mut g = vec![vec![]; n];
    for (i, &p) in p.iter().enumerate() {
        g[p].push(i + 1);
    }
    let mut dp1 = vec![ModInt::zero(); n];//
    let mut dp2 = vec![ModInt::zero(); n];//
    let mut dp3 = vec![ModInt::zero(); n];//
    for v in (0..n).rev() {
        if g[v].len() == 0 {
            dp2[v] = ModInt::one();
            continue;
        }
        dp1[v] = ModInt::one();
        let len = g[v].len();
        let mut left = vec![ModInt::one(); len + 2];
        let mut right = vec![ModInt::one(); len + 2];
        for (i, &u) in g[v].iter().enumerate() {
            let w = dp1[u] + dp2[u];
            left[i + 1] = w;
            right[i + 1] = w;
            dp1[v] *= w;
        }
        for i in 1..=len {
            left[i] = left[i] * left[i - 1];
        }
        for i in (1..=len).rev() {
            right[i] = right[i] * right[i + 1];
        }
        dp2[v] = ModInt::one();
        let mut sub = right[1];
        for (i, &u) in g[v].iter().enumerate() {
            dp3[v] = dp3[v] + (dp2[u] + dp3[u]) * left[i] * right[i + 2];
            dp2[v] = dp2[v] * (dp1[u] + ModInt(2) * dp2[u] + dp3[u]);
            sub += (dp2[u] + dp3[u]) * left[i] * right[i + 2];
        }
        dp2[v] -= sub;
    }
    let ans = dp1[0] + dp2[0];
    println!("{}", ans.0);
}

fn main() {
    run();
}
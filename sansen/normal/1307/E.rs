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

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        m: usize,
        s: [usize1; n],
        p: [(usize1, usize); m],
    }
    let mut s = s;
    s.push(n);
    s.reverse();
    let mut a = vec![vec![]; n + 1];
    a[n].push(1);
    for &(f, h) in p.iter() {
        a[f].push(h);
    }
    for a in a.iter_mut() {
        a.sort();
    }
    let mut left = vec![0; n + 1];
    let mut right = vec![0; n + 1];
    for &c in s.iter() {
        right[c] += 1;
    }
    let mut ans = (0, ModInt::one());
    for &c in s.iter() {
        left[c] += 1;
        right[c] -= 1;
        if a[c].binary_search(&left[c]).is_err() {
            continue;
        }
        let mut cnt = 0;
        let mut way = ModInt::one();
        for (i, (a, (&l, &r))) in a.iter().zip(left.iter().zip(right.iter())).enumerate() {
            if a.len() == 0 {
                continue;
            }
            match (i == c, a.len() == 1) {
                (true, true) => {
                    cnt += 1;
                },
                (true, false) => {
                    cnt += 1;
                    let mut j = 0;
                    while j < a.len() && a[j] <= r {
                        j += 1;
                    }
                    if j > 0 {
                        if a[j - 1] >= left[c] {
                            j -= 1;
                        }
                        if j > 0 {
                            cnt += 1;
                            way *= ModInt(j as u32);
                        }
                    }
                },
                (false, true) => {
                    let v = a[0];
                    let mut c = 0;
                    if v <= l {
                        c += 1;
                    }
                    if v <= r {
                        c += 1;
                    }
                    if c > 0 {
                        cnt += 1;
                        way *= ModInt(c as u32);
                    }
                },
                (false, false) => {
                    let mut i = 0;
                    while i < a.len() && a[i] <= max(l, r) {
                        i += 1;
                    }
                    if i == 0 {
                        continue;
                    }
                    let mut j = 0;
                    while j < a.len() && a[j] <= min(l, r) {
                        j += 1;
                    }
                    if j == 0 {
                        cnt += 1;
                        way *= ModInt(i as u32);
                    } else if i == 1 {
                        cnt += 1;
                        way *= ModInt(2);
                    } else {
                        cnt += 2;
                        way *= ModInt(j as u32);
                        way *= ModInt((i - 1) as u32);
                    }
                },
            }
        }
        if cnt > ans.0 {
            ans = (cnt, way);
        } else if cnt == ans.0 {
            ans.1 += way;
        }
    }
    println!("{} {}", ans.0 - 1, ans.1);
}

fn main() {
    run();
}
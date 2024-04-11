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
        assert!(self.0 > 0);
        self.pow(MOD - 2)
    }
}
// ---------- end ModInt ----------
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

fn fix(b: &mut Vec<usize>) -> bool {
    let mut ans = vec![];
    while !b.is_empty() {
        let mut local = (b[0], 0);
        for (i, b) in b.iter().enumerate().skip(1) {
            local = max(local, (*b, i));
        }
        if local.0 == 0 {
            return false;
        }
        ans.push(local.0);
        b.swap_remove(local.1);
        for b in b.iter_mut() {
            *b = min(*b, *b ^ local.0);
        }
    }
    for i in 1..ans.len() {
        for j in 0..i {
            ans[j] = min(ans[j], ans[i] ^ ans[j]);
        }
    }
    *b = ans;
    true
}

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1, usize); m],
    }
    let m = 32;
    let mut set = std::collections::BTreeSet::new();
    for e in 1..m {
        for d in 1..=e {
            for c in 1..=d {
                for b in 1..=c {
                    for a in 1..=b {
                        let mut x = vec![];
                        for &z in [a, b, c, d, e].iter() {
                            x.push(z);
                            if !fix(&mut x) {
                                break;
                            }
                            set.insert(x.clone());
                        }
                    }
                }
            }
        }
    }
    let mut p: Vec<Vec<usize>> = set.into_iter().collect();
    p.push(vec![]);
    p.sort();
    p.dedup();
    let size = p.len();
    let mut graph = vec![vec![None; size]; size];
    for i in 0..size {
        for j in 0..(i + 1) {
            let mut x = p[i].clone();
            x.extend_from_slice(&p[j]);
            if fix(&mut x) {
                let k = p.binary_search(&x).unwrap();
                graph[i][j] = Some(k);
                graph[j][i] = Some(k);
            }
        }
    }
    let mut g = vec![vec![]; n];
    for (a, b, c) in e {
        g[a].push((b, c));
        g[b].push((a, c));
    }
    let mut xor = vec![0; n];
    let mut ord = vec![0; n];
    ord[0] = 1;
    let mut id = 1;
    let mut dp = vec![ModInt::zero(); size];
    dp[p.binary_search(&vec![]).unwrap()] = ModInt::one();
    for &(v, c) in g[0].iter() {
        if ord[v] > 0 {
            continue;
        }
        xor[v] = c;
        id += 1;
        ord[v] = id;
        let mut b = vec![];
        let mut one = None;
        let mut stack = vec![(v, 0)];
        while let Some((v, p)) = stack.pop() {
            for &(u, c) in g[v].iter() {
                if u == p {
                    continue;
                }
                if u == 0 {
                    one = Some(xor[v] ^ c);
                } else if ord[u] == 0 {
                    xor[u] = xor[v] ^ c;
                    id += 1;
                    ord[u] = id;
                    stack.push((u, v));
                } else if ord[u] < ord[v] {
                    b.push(xor[u] ^ xor[v] ^ c);
                }
            }
        }
        if !fix(&mut b) {
            continue;
        }
        let s = p.binary_search(&b).expect("err");
        if let Some(c) = one {
            if let Ok(c) = p.binary_search(&vec![c]) {
                let mut next = dp.clone();
                for (k, v) in dp.into_iter().enumerate() {
                    if let Some(u) = graph[s][k] {
                        next[u] += v + v;
                        if let Some(u) = graph[u][c] {
                            next[u] += v;
                        }
                    }
                }
                dp = next;
            } else {
                let mut next = dp.clone();
                for (k, v) in dp.into_iter().enumerate() {
                    if let Some(u) = graph[s][k] {
                        next[u] += v + v;
                    }
                }
                dp = next;
            }
        } else {
            let mut next = dp.clone();
            for (k, v) in dp.into_iter().enumerate() {
                if let Some(u) = graph[s][k] {
                    next[u] += v;
                }
            }
            dp = next;
        }
    }
    let ans = dp.into_iter().fold(ModInt::zero(), |s, a| s + a);
    println!("{}", ans);
}

fn main() {
    run();
}
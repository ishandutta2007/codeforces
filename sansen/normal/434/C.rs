// ---------- begin Aho-Corasick ----------
const F: usize = 20;

struct ACTrieNode {
    elem: bool,
    fail: usize,
    depth: usize,
    next: [usize; F],
}

impl ACTrieNode {
    fn new() -> ACTrieNode {
        ACTrieNode {
            elem: false,
            fail: 0,
            depth: 0,
            next: [0; F],
        }
    }
}

struct AhoCorasick {
    node: Vec<ACTrieNode>,
}

#[allow(dead_code)]
impl AhoCorasick {
    fn new() -> Self {
        let root = ACTrieNode::new();
        AhoCorasick {
            node: vec![root],
        }
    }
    fn insert(&mut self, s: &Vec<usize>) -> usize {
        let node = &mut self.node;
        let mut v = 0;
        for &k in s {
            if node[v].next[k] == 0 {
                node[v].next[k] = node.len();
                let mut t = ACTrieNode::new();
                t.depth = node[v].depth + 1;
                node.push(t);
            }
            v = node[v].next[k];
        }
        node[v].elem = true;
        v
    }
    fn build(&mut self) {
        let mut q = std::collections::VecDeque::new();
        let node = &mut self.node;
        for i in 0..F {
            if node[0].next[i] != 0 {
                q.push_back(node[0].next[i]);
            }
        }
        while let Some(v) = q.pop_front() {
            for i in 0..F {
                let u = node[v].next[i];
                if u == 0 {
                    continue;
                }
                let mut fail = node[v].fail;
                while fail > 0 && node[fail].next[i] == 0 {
                    fail = node[fail].fail;
                }
                let f = node[fail].next[i];
                node[u].fail = f;
                q.push_back(u);
            }
        }
    }
    fn next(&self, v: usize, k: usize) -> usize {
        self.node[v].next[k]
    }
    fn trans(&self, mut v: usize, k: usize) -> usize {
        let node = &self.node;
        while v > 0 && node[v].next[k] == 0 {
            v = node[v].fail;
        }
        node[v].next[k]
    }
    fn elem(&self, k: usize) -> bool {
        self.node[k].elem
    }
    fn fail(&self, k: usize) -> usize {
        self.node[k].fail
    }
    fn depth(&self, k: usize) -> usize {
        self.node[k].depth
    }
    fn get_size(&self) -> usize {
        self.node.len()
    }
}
// ---------- end Aho-Corasick ----------
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

    impl<T> std::fmt::Debug for ModInt<T> {
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
}
// ---------- end ModInt ----------
// ---------- begin Precalc ----------
mod precalc {
    use super::modint::*;
    #[allow(dead_code)]
    pub struct Precalc<T> {
        inv: Vec<ModInt<T>>,
        fact: Vec<ModInt<T>>,
        ifact: Vec<ModInt<T>>,
    }
    #[allow(dead_code)]
    impl<T: Modulo> Precalc<T> {
        pub fn new(n: usize) -> Precalc<T> {
            let mut inv = vec![ModInt::one(); n + 1];
            let mut fact = vec![ModInt::one(); n + 1];
            let mut ifact = vec![ModInt::one(); n + 1];
            for i in 2..(n + 1) {
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
            Precalc {
                inv: inv,
                fact: fact,
                ifact: ifact,
            }
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
        pub fn comb(&self, n: usize, k: usize) -> ModInt<T> {
            if k > n {
                return ModInt::zero();
            }
            self.fact[n] * self.ifact[k] * self.ifact[n - k]
        }
    }
}
// ---------- end Precalc ----------
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

use modint::*;
type M = ModInt<Mod>;

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let k: usize = sc.next();
    let l: usize = sc.next();
    let l: Vec<usize> = sc.next_vec(l);
    let r: usize = sc.next();
    let r: Vec<usize> = sc.next_vec(r);
    let mut aho = AhoCorasick::new();
    let mut score = vec![0];
    for _ in 0..n {
        let l: usize = sc.next();
        let a: Vec<usize> = sc.next_vec(l);
        let v: usize = sc.next();
        let x = aho.insert(&a);
        if x >= score.len() {
            score.resize(x + 1, 0);
        }
        score[x] += v;
    }
    aho.build();
    {
        let mut q = std::collections::VecDeque::new();
        q.push_back(0);
        while let Some(v) = q.pop_front() {
            score[v] += score[aho.node[v].fail];
            for i in 0..F {
                let u = aho.node[v].next[i];
                if u == 0 {
                    continue;
                }
                q.push_back(u);
            }
        }
    }
    let calc = |s: &[usize]| -> M {
        let mut dp = vec![vec![M::zero(); score.len()]; k + 1];
        let mut sup = (0, 0);
        for (i, &s) in s.iter().enumerate() {
            let mut next = vec![vec![M::zero(); score.len()]; k + 1];
            for (i, dp) in dp.iter().enumerate() {
                for (v, &dp) in dp.iter().enumerate() {
                    if dp.is_zero() {
                        continue;
                    }
                    for d in 0..m {
                        let u = aho.trans(v, d);
                        let k = i + score[u];
                        next.get_mut(k).map(|next| next[u] += dp);
                    }
                }
            }
            if i > 0 {
                for d in 1..m {
                    let u = aho.trans(0, d);
                    let k = score[u];
                    next.get_mut(k).map(|next| next[u] += M::one());
                }
                for d in 0..s {
                    let u = aho.trans(sup.0, d);
                    let k = score[u] + sup.1;
                    next.get_mut(k).map(|next| next[u] += M::one());
                }
            } else {
                for d in 1..s {
                    let u = aho.trans(sup.0, d);
                    let k = score[u] + sup.1;
                    next.get_mut(k).map(|next| next[u] += M::one());
                }
            }
            let u = aho.trans(sup.0, s);
            sup = (u, sup.1 + score[u]);
            dp = next;
        }
        let mut ans = dp.iter().flatten().fold(M::zero(), |s, a| s + *a);
        if sup.1 <= k {
            ans += M::one();
        }
        ans
    };
    let mut ans = calc(&r) - calc(&l);
    let mut pos = 0;
    let mut s = 0;
    for l in l.iter() {
        pos = aho.trans(pos, *l);
        s += score[pos];
    }
    if s <= k {
        ans += M::one();
    }
    println!("{}",ans);
}
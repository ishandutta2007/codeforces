// ---------- begin mod vector ----------
mod modvector {
    const MOD: u64 = (1u64 << 61) - 1;

    #[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
    struct ModInt(u64);

    impl std::ops::Add for ModInt {
        type Output = Self;
        fn add(self, rhs: Self) -> Self::Output {
            assert!(self.0 < MOD && rhs.0 < MOD);
            let mut d = self.0 + rhs.0;
            if d >= MOD {
                d -= MOD;
            }
            ModInt(d)
        }
    }

    impl std::ops::Sub for ModInt {
        type Output = Self;
        fn sub(self, rhs: Self) -> Self::Output {
            assert!(self.0 < MOD && rhs.0 < MOD);
            let mut d = self.0 + MOD - rhs.0;
            if d >= MOD {
                d -= MOD;
            }
            ModInt(d)
        }
    }

    impl std::ops::Mul for ModInt {
        type Output = Self;
        fn mul(self, rhs: Self) -> Self::Output {
            assert!(self.0 < MOD && rhs.0 < MOD);
            const MASK31: u64 = (1u64 << 31) - 1;
            const MASK30: u64 = (1u64 << 30) - 1;
            let au = self.0 >> 31;
            let ad = self.0 & MASK31;
            let bu = rhs.0 >> 31;
            let bd = rhs.0 & MASK31;
            let mid = ad * bu + au * bd;
            let midu = mid >> 30;
            let midd = mid & MASK30;
            let sum = au * bu * 2 + midu + (midd << 31) + ad * bd;
            let mut ans = (sum >> 61) + (sum & MOD);
            if ans >= MOD {
                ans -= MOD;
            }
            ModInt(ans)
        }
    }

    impl ModInt {
        fn new(v: u64) -> Self {
            ModInt(v % MOD)
        }
        fn zero() -> Self {
            ModInt(0)
        }
        fn pow(&self, n: u64) -> Self {
            let mut t = ModInt(1);
            let mut s = *self;
            let mut n = n;
            while n > 0 {
                if n & 1 == 1 {
                    t = t * s;
                }
                s = s * s;
                n >>= 1;
            }
            t
        }
        fn inv(&self) -> Self {
            assert!(self.0 > 0);
            self.pow(MOD - 2)
        }
    }

    pub const BASE_NUM: usize = 2;

    #[derive(Clone, PartialEq, Eq, PartialOrd, Ord)]
    pub struct ModVector {
        val: [ModInt; BASE_NUM],
    }

    use std::hash::*;
    impl Hash for ModVector {
        fn hash<H: Hasher>(&self, state: &mut H) {
            self.val.iter().fold(0, |s, a| s ^ a.0).hash(state);
        }
    }

    #[allow(dead_code)]
    impl ModVector {
        pub fn zero() -> Self {
            ModVector {
                val: [ModInt::zero(); BASE_NUM],
            }
        }
        pub fn new(v: &[u64]) -> Self {
            assert!(v.len() >= BASE_NUM);
            let mut ans = ModVector::zero();
            for (x, a) in ans.val.iter_mut().zip(v.iter()) {
                *x = ModInt::new(*a);
            }
            ans
        }
        pub fn single(v: u64) -> Self {
            ModVector::new(&[v; BASE_NUM])
        }
        pub fn add(&self, rhs: &Self) -> Self {
            let mut ans = ModVector::zero();
            for (c, (a, b)) in ans.val.iter_mut().zip(self.val.iter().zip(rhs.val.iter())) {
                *c = *a + *b;
            }
            ans
        }
        pub fn sub(&self, rhs: &Self) -> Self {
            let mut ans = ModVector::zero();
            for (c, (a, b)) in ans.val.iter_mut().zip(self.val.iter().zip(rhs.val.iter())) {
                *c = *a - *b;
            }
            ans
        }
        pub fn mul(&self, rhs: &Self) -> Self {
            let mut ans = ModVector::zero();
            for (c, (a, b)) in ans.val.iter_mut().zip(self.val.iter().zip(rhs.val.iter())) {
                *c = *a * *b;
            }
            ans
        }
        pub fn inv(&self) -> Self {
            let mut ans = ModVector::zero();
            for (x, a) in ans.val.iter_mut().zip(self.val.iter()) {
                *x = a.inv();
            }
            ans
        }
    }

    pub fn rand_time() -> u32 {
        static mut X: u32 = 0;
        unsafe {
            if X == 0 {
                use std::time::{SystemTime, UNIX_EPOCH};
                X = SystemTime::now()
                    .duration_since(UNIX_EPOCH)
                    .unwrap()
                    .subsec_nanos();
            }
            X ^= X << 13;
            X ^= X >> 17;
            X ^= X << 5;
            X
        }
    }

    pub fn rand_memory() -> u32 {
        static mut X: u32 = 0;
        unsafe {
            if X == 0 {
                X = Box::into_raw(Box::new("I hope this is a random number")) as u32;
            }
            X ^= X << 13;
            X ^= X >> 17;
            X ^= X << 5;
            X
        }
    }

    pub fn generate_random_rad() -> ModVector {
        let mut rad = ModVector::zero();
        for (i, v) in rad.val.iter_mut().enumerate() {
            *v = ModInt::new(if i & 1 == 0 {
                rand_time() as u64 + 2
            } else {
                rand_memory() as u64 + 2
            });
        }
        rad
    }
}
// ---------- end mod vector ----------
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

use modvector::*;
type M = ModVector;
type Set = std::collections::HashSet<M>;

struct State {
    graph: Vec<Vec<usize>>,
    hash: Vec<M>,
}

impl State {
    fn dfs(&self, v: usize, diff: &mut [usize]) -> Set {
        let mut set = Set::new();
        set.insert(self.hash[v].clone());
        for &u in self.graph[v].iter() {
            let mut p = self.dfs(u, diff);
            if set.len() < p.len() {
                std::mem::swap(&mut set, &mut p);
            }
            for p in p {
                set.insert(p);
            }
        }
        diff[v] = set.len();
        set
    }
}

fn run() {
    input! {
        n: usize,
        c: [usize; n],
        s: bytes,
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let rad = generate_random_rad();
    let mut hash = vec![M::zero(); n];
    let mut topo = vec![0];
    for i in 0..n {
        let v = topo[i];
        hash[v] = hash[v].mul(&rad).add(&M::single((s[v] - b'a' + 1) as u64));
        for u in g[v].clone() {
            let x = g[u].iter().position(|p| *p == v).unwrap();
            g[u].remove(x);
            hash[u] = hash[v].clone();
            topo.push(u);
        }
    }
    let mut size = vec![1; n];
    for &v in topo.iter().rev() {
        g[v].sort_by_key(|u| !size[*u]);
        size[v] += g[v].iter().fold(0, |s, a| s + size[*a]);
    }
    let state = State {
        graph: g,
        hash: hash,
    };
    let mut diff = vec![0; n];
    state.dfs(0, &mut diff);
    let p = diff
        .iter()
        .zip(c.iter())
        .map(|p| *p.0 + *p.1)
        .collect::<Vec<_>>();
    let max = *p.iter().max().unwrap();
    let cnt = p.iter().filter(|p| **p == max).count();
    println!("{}\n{}", max, cnt);
}

fn main() {
    run();
}
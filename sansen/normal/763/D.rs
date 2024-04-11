mod modvector {
    const MOD: u64 = (1u64 << 61) - 1;

    #[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
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

    #[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
    pub struct ModVector {
        val: [ModInt; BASE_NUM],
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
        pub fn one(v: u64) -> Self {
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
        pub fn pow(&self, n: usize) -> Self {
            let mut ans = ModVector::zero();
            for (c, a) in ans.val.iter_mut().zip(self.val.iter()) {
                *c = a.pow(n as u64);
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
//            println!("{}", v.0);
        }
        rad
    }
}
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

//

use modvector::*;

struct MultiSet<K> {
    map: std::collections::BTreeMap<K, u32>,
}

impl<K> MultiSet<K>
where K: Ord
{
    fn new() -> Self {
        MultiSet {
            map: std::collections::BTreeMap::new(),
        }
    }
    fn len(&self) -> usize {
        self.map.len()
    }
    fn insert(&mut self, v: K) {
        *self.map.entry(v).or_insert(0) += 1;
    }
    fn remove(&mut self, v: &K) {
        assert!(self.map.get(v).map_or(false, |v| *v > 0));
        if let Some(x) = self.map.get_mut(v) {
            *x -= 1;
        }
        if self.map.get(v).map_or(false, |x| *x == 0) {
            self.map.remove(v);
        }
    }
}

fn dfs(v: usize, set: &mut MultiSet<ModVector>, dp: &[ModVector], dp2: &[ModVector], g: &[Vec<usize>]) -> (usize, usize) {
//    println!("{}: {}", v + 1, set.len());
    let mut ans = (set.len(), v);
    for &u in g[v].iter() {
        set.remove(&dp[u]);
        set.insert(dp2[u]);
        ans = std::cmp::max(ans, dfs(u, set, dp, dp2, g));
        set.remove(&dp2[u]);
        set.insert(dp[u]);
    }
    ans
}

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut rad = vec![];
    for _ in 0..n {
        rad.push(generate_random_rad());
    }
    let root = 0;
    let mut q = vec![];
    let mut stack = vec![(root, root)];
    while let Some((v, p)) = stack.pop() {
        q.push(v);
        if let Some(k) = g[v].iter().position(|u| *u == p) {
            g[v].remove(k);
        }
        for &u in g[v].iter() {
            stack.push((u, v));
        }
    }
    let one = ModVector::one(1);
    let mut dp = vec![one; n];
    let mut depth = vec![0; n];
    for &v in q.iter().rev() {
        let mut hash = one;
        for &u in g[v].iter() {
            hash = hash.mul(&dp[u]);
            depth[v] = std::cmp::max(depth[v], depth[u] + 1);
        }
        dp[v] = hash.add(&rad[depth[v]]);
    }
    let mut dp2 = vec![ModVector::zero(); n];
    let mut depth2 = vec![0; n];
    for &v in q.iter() {
        let mut a = vec![];
        for &u in g[v].iter() {
            a.push((dp[u], u, depth[u] + 1));
        }
        if v != root {
            a.push((dp2[v], v, depth2[v] + 1));
        }
        let mut left = vec![];
        let mut hash = one;
        let mut d = 0;
        for a in a.iter() {
            left.push((hash, d));
            hash = a.0.mul(&hash);
            d = std::cmp::max(d, a.2);
        }
        let mut right = one;
        let mut d = 0;
        for (a, left) in a.iter().zip(left.iter()).rev() {
            if a.1 != v {
                let hash = left.0.mul(&right);
                let d = std::cmp::max(d, left.1);
                dp2[a.1] = hash.add(&rad[d]);
                depth2[a.1] = d;
            }
            right = a.0.mul(&right);
            d = std::cmp::max(d, a.2);
        }
    }
    let mut set = MultiSet::new();
    for (i, dp) in dp.iter().enumerate() {
        if i != root {
            set.insert(*dp);
        }
    }
    let ans = dfs(root, &mut set, &dp, &dp2, &g);
    println!("{}", ans.1 + 1);
}

fn main() {
    run();
}
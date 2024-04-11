// ---------- begin mod vector ----------
mod modvector {
    const MOD: u64 = (1u64 << 61) - 1;

    #[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Debug, Hash)]
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

    #[allow(dead_code)]
    impl ModInt {
        fn new(v: u64) -> Self {
            ModInt(v % MOD)
        }
        fn zero() -> Self {
            ModInt(0)
        }
        fn one() -> Self {
            ModInt(1)
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

    #[derive(Clone, PartialEq, Eq, PartialOrd, Ord, Debug, Hash)]
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
        pub fn one() -> Self {
            ModVector {
                val: [ModInt::one(); BASE_NUM],
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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        s: bytes,
        ask: [(usize1, usize1, usize); m],
    }
    use modvector::*;
    type M = ModVector;
    let rad = generate_random_rad();
    let mut pow = vec![M::one(); n + 1];
    for i in 1..=n {
        pow[i] = pow[i - 1].mul(&rad);
    }
    let pow = pow;
    let mut sum = vec![vec![M::zero(); n + 1]; 26];
    for (i, sum) in sum.iter_mut().enumerate() {
        for (j, c) in s.iter().enumerate().rev() {
            let mut hash = sum[j + 1].mul(&rad);
            if *c == i as u8 + b'a' {
                hash = hash.add(&M::one());
            }
            sum[j] = hash;
        }
    }
    let sum = sum;
    let mut map = std::collections::HashMap::new();
    for (x, y, len) in ask {
        map.clear();
        for sum in sum.iter() {
            let key = sum[x].sub(&sum[x + len].mul(&pow[len]));
            *map.entry(key).or_insert(0i32) += 1;
        }
        let mut ans = "YES";
        for sum in sum.iter() {
            let key = sum[y].sub(&sum[y + len].mul(&pow[len]));
            match map.get_mut(&key) {
                Some(p) if *p > 0 => *p -= 1,
                _ => {
                    ans = "NO";
                    break;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
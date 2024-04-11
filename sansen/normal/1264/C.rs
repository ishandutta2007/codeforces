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
        self.pow(MOD - 2)
    }
}
// ---------- end ModInt ----------
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(T, T) -> T> {
        size: usize,
        a: Vec<Option<T>>,
        fold: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(T, T) -> T> PURQ<T, F> {
        pub fn new(len: usize, fold: F) -> PURQ<T, F> {
            let size = len.next_power_of_two();
            PURQ {
                size: size,
                a: vec![None; 2 * size],
                fold: fold,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.size + x;
            self.a[k] = Some(v);
            k >>= 1;
            while k > 0 {
                self.a[k] = self.merge(self.a[2 * k].clone(), self.a[2 * k + 1].clone());
                k >>= 1;
            }
        }
        fn merge(&self, a: Option<T>, b: Option<T>) -> Option<T> {
            match (a, b) {
                (Some(a), Some(b)) => Some((self.fold)(a, b)),
                (Some(a), None) => Some(a),
                (None, Some(b)) => Some(b),
                (None, None) => None,
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.size] = Some(v);
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.size)).rev() {
                self.a[k] = self.merge(self.a[2 * k].clone(), self.a[2 * k + 1].clone());
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p: Option<T> = None;
            let mut q: Option<T> = None;
            let a = &self.a;
            l += self.size;
            r += self.size;
            while l < r {
                if (l & 1) == 1 {
                    p = self.merge(p, a[l].clone());
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = self.merge(a[r].clone(), q);
                }
                l >>= 1;
                r >>= 1;
            }
            self.merge(p, q).unwrap()
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
// ---------- begin fenwick tree ----------
#[allow(dead_code)]
mod fenwick {
    type T = i32;
    const ZERO: T = 0;
    pub struct Tree {
        a: Vec<T>,
    }
    impl Tree {
        pub fn new(n: usize) -> Tree {
            Tree {
                a: vec![ZERO; n + 1],
            }
        }
        pub fn add(&mut self, mut x: usize, v: T) {
            while x < self.a.len() {
                self.a[x] += v;
                x += x & (!x + 1);
            }
        }
        pub fn sum(&self, mut x: usize) -> T {
            debug_assert!(x < self.a.len());
            let mut res = ZERO;
            while x > 0 {
                res += self.a[x];
                x -= x & (!x + 1);
            }
            res
        }
        pub fn search(&self, s: T) -> usize {
            debug_assert!(self.sum(self.a.len() - 1) >= s);
            let mut k = 1;
            while 2 * k < self.a.len() {
                k *= 2;
            }
            let mut x = 0;
            let mut w = ZERO;
            while k > 0 {
                if k + x < self.a.len() && w + self.a[x + k] < s {
                    w += self.a[x + k];
                    x += k;
                }
                k >>= 1;
            }
            x + 1
        }
    }
}
// ---------- end fenwick tree ----------
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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        q: usize,
        p: [u32; n],
        u: [usize; q],
    }
    type T = (ModInt, ModInt);
    let f = |a: T, b: T| (a.0 * b.1 + b.0, a.1 * b.1);
    let mut seg = segment_tree::PURQ::new(n, f);
    for i in 0..n {
        let p = ModInt(p[i]) * ModInt(100).inv();
        let ip = p.inv();
        seg.update_tmp(i, (ip, ip));
    }
    seg.update_all();
    let mut e = seg.find(0, n).0;
    let mut bit = fenwick::Tree::new(n + 1);
    let mut cond = vec![false; n + 1];
    bit.add(n + 1, 1);
    for u in u {
        if cond[u] {
            cond[u] = false;
            bit.add(u, -1);
            let sum = bit.sum(u);
            let l = bit.search(sum) - 1;
            let r = bit.search(sum + 1) - 1;
            e -= seg.find(l, u - 1).0;
            e -= seg.find(u - 1, r).0;
            e += seg.find(l, r).0;
        } else {
            cond[u] = true;
            let sum = bit.sum(u);
            let l = bit.search(sum) - 1;
            let r = bit.search(sum + 1) - 1;
            bit.add(u, 1);
            e += seg.find(l, u - 1).0;
            e += seg.find(u - 1, r).0;
            e -= seg.find(l, r).0;
        }
        writeln!(out, "{}", e).ok();
    }
}

fn main() {
    run();
}
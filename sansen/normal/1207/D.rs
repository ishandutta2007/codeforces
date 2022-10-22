// ---------- begin ModInt ----------
//https://github.com/kenkoooo/competitive-programming-rs/blob/master/src/math/mod_int.rs
//
#[allow(dead_code)]
mod modint {
    pub const MOD: u32 = 998_244_353;
    use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Neg, Sub, SubAssign};
    #[derive(Clone, Copy)]
    pub struct ModInt<T: Copy + Clone>(pub T);
    type Num = u32;
    impl Add<ModInt<Num>> for ModInt<Num> {
        type Output = ModInt<Num>;
        fn add(self, other: ModInt<Num>) -> ModInt<Num> {
            let mut d = self.0 + other.0;
            if d >= MOD {
                d -= MOD;
            }
            ModInt(d)
        }
    }
    impl AddAssign<ModInt<Num>> for ModInt<Num> {
        fn add_assign(&mut self, other: ModInt<Num>) {
            *self = *self + other;
        }
    }
    impl Sub<ModInt<Num>> for ModInt<Num> {
        type Output = ModInt<Num>;
        fn sub(self, other: ModInt<Num>) -> ModInt<Num> {
            let mut d = self.0 + MOD - other.0;
            if d >= MOD {
                d -= MOD;
            }
            ModInt(d)
        }
    }
    impl SubAssign<ModInt<Num>> for ModInt<Num> {
        fn sub_assign(&mut self, other: ModInt<Num>) {
            *self = *self - other;
        }
    }
    impl Mul<ModInt<Num>> for ModInt<Num> {
        type Output = ModInt<Num>;
        fn mul(self, other: ModInt<Num>) -> ModInt<Num> {
            ModInt(((self.0 as u64) * (other.0 as u64) % (MOD as u64)) as u32)
        }
    }
    impl MulAssign<ModInt<Num>> for ModInt<Num> {
        fn mul_assign(&mut self, other: ModInt<Num>) {
            *self = *self * other;
        }
    }
    impl Div<ModInt<Num>> for ModInt<Num> {
        type Output = ModInt<Num>;
        fn div(self, other: ModInt<Num>) -> ModInt<Num> {
            self * other.pow(MOD - 2)
        }
    }
    impl DivAssign<ModInt<Num>> for ModInt<Num> {
        fn div_assign(&mut self, other: ModInt<Num>) {
            *self = *self / other;
        }
    }
    impl Neg for ModInt<Num> {
        type Output = ModInt<Num>;
        fn neg(self) -> ModInt<Num> {
            ModInt(if self.0 == 0 { 0 } else { MOD - self.0 })
        }
    }
    impl ModInt<Num> {
        pub fn new(v: u32) -> ModInt<Num> {
            ModInt(v % MOD)
        }
        pub fn pow(self, mut n: u32) -> ModInt<Num> {
            let mut t = ModInt::new(1);
            let mut s = self;
            while n > 0 {
                if (n & 1) == 1 {
                    t *= s;
                }
                s *= s;
                n >>= 1;
            }
            t
        }
    }
    pub struct Precalc {
        n: usize,
        inv: Vec<ModInt<Num>>,
        fact: Vec<ModInt<Num>>,
        ifact: Vec<ModInt<Num>>,
    }
    impl Precalc {
        pub fn new(n: usize) -> Precalc {
            let mut inv = vec![ModInt(1); n + 1];
            let mut fact = vec![ModInt(1); n + 1];
            let mut ifact = vec![ModInt(1); n + 1];
            for i in 1..(n + 1) {
                if i >= 2 {
                    inv[i] = -inv[(MOD as usize) % i] * ModInt(MOD / (i as u32));
                }
                fact[i] = ModInt(i as u32) * fact[i - 1];
                ifact[i] = inv[i] * ifact[i - 1];
            }
            Precalc {
                n: n,
                inv: inv,
                fact: fact,
                ifact: ifact,
            }
        }
        pub fn fact(&self, n: usize) -> ModInt<Num> {
            self.fact[n]
        }
        pub fn inv(&self, x: usize) -> ModInt<Num> {
            self.inv[x]
        }
        pub fn ifact(&self, x: usize) -> ModInt<Num> {
            self.ifact[x]
        }
        pub fn comb(&self, n: usize, k: usize) -> ModInt<Num> {
            if !(k <= n) {
                return ModInt(0);
            }
            self.fact[n] * self.ifact[k] * self.ifact[n - k]
        }
    }
    use std;
    impl std::fmt::Display for ModInt<Num> {
        fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
            write!(f, "{}", self.0)
        }
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

use modint::*;

fn run() {
    input! {
        n: usize,
        p: [(u32, u32); n],
    }
    let pc = Precalc::new(n);
    let mut p = p;
    p.sort();
    let mut ans = pc.fact(n);
    let mut i = 0;
    let mut f = ModInt(1);
    while i < n {
        let mut j = i + 1;
        while j < n && p[i].0 == p[j].0 {
            j += 1;
        }
        let d = j - i;
        i = j;
        f *= pc.fact(d);
    }
    ans -= f;
    for p in p.iter_mut() {
        let (a, b) = *p;
        *p = (b, a);
    }
    p.sort();
    let mut i = 0;
    let mut f = ModInt(1);
    while i < n {
        let mut j = i + 1;
        while j < n && p[i].0 == p[j].0 {
            j += 1;
        }
        let d = j - i;
        i = j;
        f *= pc.fact(d);
    }
    ans -= f;
    let mut sorted = true;
    for i in 1..n {
        let (a, b) = p[i - 1];
        let (c, d) = p[i];
        if !(a <= c && b <= d) {
            sorted = false;
        }
    }
    if sorted {
        let mut i = 0;
        let mut f = ModInt(1);
        while i < n {
            let mut j = i + 1;
            while j < n && p[i] == p[j] {
                j += 1;
            }
            let d = j - i;
            i = j;
            f *= pc.fact(d);
        }
        ans += f;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
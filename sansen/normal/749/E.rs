// ---------- begin fenwick tree ----------
pub struct Fenwick<T> {
    zero: T,
    a: Box<[T]>,
}

impl<T> Fenwick<T>
where
    T: Copy + std::ops::Add<Output = T>,
{
    pub fn new(size: usize, zero: T) -> Fenwick<T> {
        Fenwick {
            zero: zero,
            a: vec![zero; size + 1].into_boxed_slice(),
        }
    }
    pub fn init(&mut self) {
        for a in self.a.iter_mut() {
            *a = self.zero;
        }
    }
    pub fn add(&mut self, mut x: usize, v: T) {
        assert!(x > 0);
        while let Some(a) = self.a.get_mut(x) {
            *a = *a + v;
            x += x & (!x + 1);
        }
    }
    pub fn sum(&self, mut x: usize) -> T {
        assert!(x < self.a.len());
        let mut res = self.zero;
        while x > 0 {
            res = res + self.a[x];
            x -= x & (!x + 1);
        }
        res
    }
}

impl<T> Fenwick<T>
where
    T: Copy + std::ops::Add<Output = T> + PartialOrd,
{
    pub fn search(&self, s: T) -> usize {
        debug_assert!(self.sum(self.a.len() - 1) >= s);
        let mut k = 1;
        while 2 * k < self.a.len() {
            k *= 2;
        }
        let mut x = 0;
        let mut w = self.zero;
        while k > 0 {
            self.a.get(x + k).map(|a| {
                if w + *a < s {
                    w = w + *a;
                    x += k;
                }
            });
            k >>= 1;
        }
        x + 1
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

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut inv = 0i64;
    let mut bit = Fenwick::new(n, 0);
    for a in a.iter().rev() {
        inv += bit.sum(*a);
        bit.add(*a, 1);
    }
    bit.init();
    let mut sum = 0i64;
    for (i, a) in a.iter().rev().enumerate() {
        sum -= 4 * bit.sum(*a) * (n - i) as i64;
        bit.add(*a, (i + 1) as i64);
    }
    for i in 2..=n {
        let k = i as i64;
        sum += k * (k - 1) * (n - i + 1) as i64;
    }
    let mut ans = inv as f64;
    let n = n as f64;
    ans += sum as f64 / 2.0 / n / (n + 1.0);
    println!("{:.10}", ans);
}

fn main() {
    run();
}
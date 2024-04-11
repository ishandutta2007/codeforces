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

fn calc(p: &[usize]) -> Vec<usize> {
    let mut bit = Fenwick::new(p.len(), 0);
    let mut ans = vec![];
    for p in p.iter() {
        let pre = bit.sum(*p + 1);
        ans.push(*p - pre);
        bit.add(*p + 1, 1);
    }
    ans
}

fn run() {
    input! {
        n: usize,
        p: [usize; n],
        q: [usize; n],
    }
    let mut a = calc(&p);
    let b = calc(&q);
    for (a, b) in a.iter_mut().zip(b.iter()) {
        *a += *b;
    }
    for i in (1..n).rev() {
        let carry = a[i] / (n - i);
        a[i] %= n - i;
        a[i - 1]+= carry;
    }
    a[0] %= n;
    let mut bit = Fenwick::new(n, 0);
    for i in 1..=n {
        bit.add(i, 1);
    }
    let mut ans = vec![];
    for a in a {
        let x = bit.search(a + 1);
        bit.add(x, !0);
        ans.push(x - 1);
    }
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        ask: [(u8, i64); n],
    }
    let mut z = vec![0];
    for &(_, p) in ask.iter() {
        if p > 0 {
            z.push(p);
        }
    }
    z.sort();
    z.dedup();
    let mut cnt = Fenwick::new(z.len(), 0usize);
    let mut sum = Fenwick::new(z.len(), 0i64);
    let mut light = 0;
    let mut fire = std::collections::BTreeSet::new();
    for (op, d) in ask {
        let k = z.binary_search(&d.abs()).unwrap();
        match (op, d > 0) {
            (0, true) => {
                fire.insert(d);
                cnt.add(k, 1);
                sum.add(k, d);
            },
            (0, false) => {
                fire.remove(&-d);
                cnt.add(k, !0);
                sum.add(k, d);
            },
            (1, true) => {
                light += 1;
                cnt.add(k, 1);
                sum.add(k, d);
            },
            (1, false) => {
                light -= 1;
                cnt.add(k, !0);
                sum.add(k, d);
            },
            _ => unreachable!(),
        };
        let ans = if light == 0 {
            sum.sum(z.len())
        } else if light == cnt.sum(z.len()) {
            let k = cnt.search(1);
            sum.sum(z.len()) * 2 - sum.sum(k)
        } else if light == 1 {
            sum.sum(z.len()) + *fire.iter().rev().next().unwrap()
        } else {
            let d = *fire.iter().rev().next().unwrap();
            let x = z.binary_search(&d).unwrap();
            sum.add(x, -d);
            cnt.add(x, !0);
            let mut ans = 2 * d;
            let all = cnt.sum(z.len());
            let y = cnt.search(all - (light - 1));
            ans += sum.sum(z.len());
            ans += sum.sum(z.len()) - sum.sum(y);
            sum.add(x, d);
            cnt.add(x, 1);
            ans
        };
        writeln!(out, "{}", ans).ok();
    }
}
fn naive() {
    input! {
        n: usize,
        ask: [(u8, i64); n],
    }
    let mut set = std::collections::BTreeSet::new();
    for (op, d) in ask {
        if d > 0 {
            set.insert((op, d));
        } else {
            set.remove(&(op, -d));
        }
        let mut a = vec![];
        let mut b = vec![];
        for &(op, v) in set.iter() {
            if op == 0 {
                a.push(v);
            } else {
                b.push(v);
            }
        }
        let ans = if a.is_empty() {
            let mut ans = 0;
            for (i, b) in b.iter().enumerate() {
                ans += if i > 0 {2} else {1} * *b;
            }
            ans
        } else if b.is_empty() {
            a.iter().sum::<i64>()
        } else {
            let mut sum = a.pop().unwrap() * 2;
            let mut c = b.len() - 1;
            a.append(&mut b);
            a.sort();
            while c > 0 {
                sum += a.pop().unwrap() * 2;
                c -= 1;
            }
            for a in a {
                sum += a;
            }
            sum
        };
        println!("{}", ans);
    }
}

fn main() {
    run();
}
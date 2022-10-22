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

use std::io::Write;

fn run() {
    input! {
        n: usize,
        m: usize,
        q: usize,
        a: [usize1; n],
        ask: [i64; q],
    }
    let mut cnt = vec![0; m];
    for a in a {
        cnt[a] += 1;
    }
    let mut map = std::collections::BTreeMap::new();
    for (i, c) in cnt.iter().enumerate() {
        map.entry(*c).or_insert(vec![]).push(i + 1);
    }
    let mut ans = vec![0; q];
    let mut a = map.into_iter().rev().collect::<Vec<_>>();
    let mut bit = Fenwick::new(m, 0i64);
    let (q, x) = a.pop().unwrap();
    let mut q = q as i64;
    for x in x {
        bit.add(x, 1);
    }
    let mut query = ask.iter().cloned().enumerate().collect::<Vec<_>>();
    query.sort_by_key(|p| p.1);
    let mut sum = n as i64;
    for (k, ask) in query {
        let ask = ask - 1;
        loop {
            let p = a.last().map_or(std::i64::MAX / m as i64 - 10, |p| p.0 as i64);
            if (p - q) * bit.sum(m) + sum <= ask {
                sum += (p - q) * bit.sum(m);
                q = p;
                let x = a.pop().unwrap().1;
                for x in x {
                    bit.add(x, 1);
                }
            } else {
                break;
            }
        }
        let c = bit.sum(m);
        let v = (ask - sum) / c;
        sum += v * c;
        q += v;
        ans[k] = bit.search((ask - sum) % c + 1);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
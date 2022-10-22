// ---------- begin next_permutation ----------
fn next_permutation<T: Ord>(a: &mut [T]) -> bool {
    a.windows(2).rposition(|a| a[0] < a[1]).map_or(false, |x| {
        let y = a.iter().rposition(|b| a[x] < *b).unwrap();
        a.swap(x, y);
        a[(x + 1)..].reverse();
        true
    })
}
// ---------- end next_permutation ----------
// 1-indexedBIT
// x[1,x], ([1,x])>=s x
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
        t: usize,
        s: [chars; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut op = "ANTON".chars().collect::<Vec<_>>();
    op.sort();
    op.dedup();
    let op = op;
    for s in s {
        let n = s.len();
        let mut x = (0..4).map(|k| (k, vec![])).collect::<Vec<_>>();
        for (i, c) in s.iter().enumerate() {
            let y = op.iter().position(|a| *a == *c).unwrap();
            x[y].1.push(i + 1);
        }
        let mut ans = (0, x.clone());
        while {
            let mut bit = Fenwick::new(n, 0u64);
            let mut val = 0;
            for x in x.iter() {
                for x in x.1.iter().rev() {
                    val += bit.sum(*x);
                    bit.add(*x, 1);
                }
            }
            if ans.0 < val {
                ans = (val, x.clone());
            }
            next_permutation(&mut x)
        } {}
        let mut p = String::new();
        for x in ans.1.iter().rev() {
            for x in x.1.iter() {
                p.push(s[*x - 1]);
            }
        }
        writeln!(out, "{}", p).ok();
    }
}

fn main() {
    run();
}
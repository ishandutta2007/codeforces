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
// ---------- begin super slice ----------
pub trait SuperSlice {
    type Item;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn lower_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn lower_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn upper_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn upper_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
}

impl<T> SuperSlice for [T] {
    type Item = T;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.lower_bound_by(|p| p.cmp(key))
    }
    fn lower_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Greater))
            .unwrap_err()
    }
    fn lower_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.lower_bound_by(|p| f(p).cmp(key))
    }
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.upper_bound_by(|p| p.cmp(key))
    }
    fn upper_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Less))
            .unwrap_err()
    }
    fn upper_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.upper_bound_by(|p| f(p).cmp(key))
    }
}
// ---------- end super slice ----------
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a = sc.next_vec::<usize>(n);
        let mut x = vec![vec![]; 2];
        for (i, a) in a.iter().enumerate() {
            x[*a & 1].push(i);
        }
        let calc = |x: Vec<usize>| -> u64 {
            let mut val = 0;
            let mut bit = Fenwick::new(n, 0u64);
            for x in x.iter().rev() {
                val += bit.sum(*x + 1);
                bit.add(*x + 1, 1);
            }
            val
        };
        let mut ans = std::u64::MAX;
        for _ in 0..2 {
            {
                let mut y = vec![];
                let mut x = x.clone();
                for i in 0..n {
                    if let Some(p) = x[i & 1].pop() {
                        y.push(p);
                    } else {
                        break;
                    }
                }
                if y.len() == n {
                    y.reverse();
                    ans = ans.min(calc(y));
                }
            }
            x.swap(0, 1);
        }
        if ans == std::u64::MAX {
            writeln!(out, "-1").ok();
        } else {
            writeln!(out, "{}", ans).ok();
        }
    }
}
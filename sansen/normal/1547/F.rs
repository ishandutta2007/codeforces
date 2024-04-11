// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u64, b: u64) -> u64 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
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
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

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
    let m = 1_000_000;
    let mut f = (0..=m).collect::<Vec<_>>();
    for i in (2..).take_while(|p| p * p <= m) {
        if i == f[i] {
            for j in i..=(m / i) {
                f[j * i] = i;
            }
        }
    }
    let f = f;
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<usize> = sc.next_vec(n);
        let g = a.iter().fold(0, |s, a| binary_gcd(s, *a as u64)) as usize;
        a.iter_mut().for_each(|a| *a /= g);
        let mut map = Map::new();
        for (i, a) in a.iter().enumerate() {
            let mut x = *a;
            while x > 1 {
                let p = f[x];
                map.entry(p).or_insert(vec![]).push(i);
                while x % p == 0 {
                    x /= p;
                }
            }
        }
        let mut ans = 0;
        for (_, x) in map {
            let mut x = x;
            x.sort();
            for i in 0..x.len() {
                let y = x[i] + n;
                x.push(y);
            }
            let mut pre = x[0];
            let mut len = 1;
            for i in 1..x.len() {
                if x[i] > pre + 1 {
                    ans.chmax(len);
                    len = 0;
                }
                pre = x[i];
                len += 1;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
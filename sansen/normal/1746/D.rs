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

use std::collections::*;
use std::io::Write;

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
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let k: u64 = sc.next();
        let mut child = vec![vec![]; n];
        for i in 1..n {
            let p = sc.next::<usize>() - 1;
            child[p].push(i);
        }
        let s = sc.next_vec::<u64>(n);
        let ans = calc(0, k, &child, &s, &mut Map::new());
        writeln!(out, "{}", ans).ok();
    }
}

fn calc(v: usize, k: u64, child: &[Vec<usize>], s: &[u64], dp: &mut Map<(usize, u64), u64>) -> u64 {
    if k == 0 {
        return 0;
    }
    if child[v].is_empty() {
        return s[v] * k;
    }
    if let Some(&w) = dp.get(&(v, k)) {
        return w;
    }
    let len = child[v].len() as u64;
    let q = k / len;
    let mut ans = s[v] * k;
    for &u in child[v].iter() {
        ans += calc(u, q, child, s, dp);
    }
    if q * len != k {
        let mut a = vec![];
        for &u in child[v].iter() {
            a.push(calc(u, q + 1, child, s, dp) - calc(u, q, child, s, dp));
        }
        a.sort();
        ans += a.iter().rev().take((k - q * len) as usize).sum::<u64>();
    }
    dp.insert((v, k), ans);
    ans
}
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
type Set<T> = BTreeSet<T>;

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
        let m: usize = sc.next();
        let mut cnt = Map::new();
        for a in sc.next_vec::<usize>(n) {
            *cnt.entry(a).or_insert(0) += 1;
        }
        let mut map = Map::new();
        for (x, c) in cnt {
            map.entry(c).or_insert(vec![]).push(x);
        }
        for v in map.values_mut() {
            v.sort_by_key(|v| !*v);
        }
        let mut ban = Set::new();
        for _ in 0..m {
            let x: usize = sc.next();
            let y: usize = sc.next();
            ban.insert((x, y));
        }
        let valid = |mut x: usize, mut y: usize| -> bool {
            if x > y {
                std::mem::swap(&mut x, &mut y);
            }
            x < y && !ban.contains(&(x, y))
        };
        let mut ans = 0;
        for (i, (&a, v)) in map.iter().enumerate() {
            for (&b, u) in map.iter().take(i + 1) {
                for &v in v.iter() {
                    if let Some(u) = u.iter().find(|u| valid(**u, v)) {
                        ans = ans.max((a + b) * (v + *u));
                    }
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
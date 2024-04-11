// ---------- begin Run Length Encoding ----------
fn run_length_encoding<T: Clone + Eq>(a: &[T]) -> Vec<(T, usize)> {
    let mut a = a.iter().map(|a| (a.clone(), 1)).collect::<Vec<_>>();
    a.dedup_by(|a, b| {
        a.0 == b.0 && {
            b.1 += a.1;
            true
        }
    });
    a
}
// ---------- end Run Length Encoding ----------
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std;
    use std::io::Read;
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error"),
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let sup = 1_000_000;
    let mut f = (0..=sup).collect::<Vec<_>>();
    for i in 2..=sup {
        if i == f[i] {
            for j in 2..=(sup / i) {
                f[j * i] = i;
            }
        }
    }
    let f = f;
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut map = std::collections::BTreeMap::new();
        for i in 0..n {
            let mut a: usize = sc.next();
            let mut key = vec![];
            while a > 1 {
                let p = f[a];
                a /= p;
                key.push(p);
            }
            key.sort();
            let key = run_length_encoding(&key)
                .into_iter()
                .filter(|p| p.1 % 2 != 0)
                .map(|p| p.0)
                .collect::<Vec<_>>();
            map.entry(key).or_insert(vec![]).push(i);
        }
        let mut empty = 0;
        let mut even = 0;
        let mut odd = 0;
        let mut even_max = 0;
        for (k, v) in map.iter() {
            if k.is_empty() {
                empty += v.len();
            } else if v.len() % 2 == 0 {
                even += v.len();
                even_max = even_max.max(v.len());
            } else {
                odd = odd.max(v.len());
            }
        }
        let q: usize = sc.next();
        for _ in 0..q {
            let w: u64 = sc.next();
            let ans = if w == 0 {
                even_max.max(empty).max(odd)
            } else {
                odd.max(empty + even)
            };
            writeln!(out, "{}", ans).ok();
        }
    }
}
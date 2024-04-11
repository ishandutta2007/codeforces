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

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let haha = "haha".chars().collect::<Vec<_>>();
        let mut state = Map::<String, (u64, Vec<char>, Vec<char>)>::new();
        let mut last = String::new();
        for _ in 0..n {
            let x = sc.next::<String>();
            last = x.clone();
            let op = sc.next::<String>();
            if op == ":=" {
                let y = sc.next::<String>().chars().collect::<Vec<_>>();
                let cnt = y.windows(4).filter(|y| y == &haha).count() as u64;
                let l = y.iter().take(3).cloned().collect::<Vec<_>>();
                let r = y.iter().rev().take(3).rev().cloned().collect::<Vec<_>>();
                state.insert(x, (cnt, l, r));
            } else {
                let lhs = sc.next::<String>();
                let _ = sc.next::<String>();
                let rhs = sc.next::<String>();
                let left = state.get(&lhs).unwrap().clone();
                let right = state.get(&rhs).unwrap().clone();
                let mut cnt = left.0 + right.0;
                let mid = left.2.iter().chain(&right.1).cloned().collect::<Vec<_>>();
                cnt += mid.windows(4).filter(|y| y == &haha).count() as u64;
                let mut l = left.1.iter().chain(&right.1).cloned().collect::<Vec<_>>();
                l.truncate(3);
                let mut r = left.2.iter().chain(&right.2).cloned().collect::<Vec<_>>();
                r.reverse();
                r.truncate(3);
                r.reverse();
                state.insert(x, (cnt, l, r));
            }
        }
        writeln!(out, "{}", state.get(&last).unwrap().0).ok();
    }
}
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
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
use std::collections::*;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    let mut map = BTreeMap::new();
    for _ in 0..q {
        let op: u8 = sc.next();
        let mut a: u64 = sc.next();
        let mut b: u64 = sc.next();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        if op == 1 {
            let w: u64 = sc.next();
            while a != b {
                *map.entry((a / 2, a)).or_insert(0) += w;
                a >>= 1;
                if a < b {
                    std::mem::swap(&mut a, &mut b);
                }
            }
        } else {
            let mut sum = 0;
            while a != b {
                sum += map.get(&(a / 2, a)).cloned().unwrap_or(0);
                a >>= 1;
                if a < b {
                    std::mem::swap(&mut a, &mut b);
                }
            }
            writeln!(out, "{}", sum).ok();
        }
    }
}
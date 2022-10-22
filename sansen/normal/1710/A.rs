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
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

// S = sum A
// HW 
// H, W >= 3
// 1
// 
// 
//

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let mut h: i64 = sc.next();
        let mut w: i64 = sc.next();
        let n: usize = sc.next();
        let a: Vec<i64> = sc.next_vec(n);
        let mut ans = "No";
        for _ in 0..2 {
            let mut a = a.clone();
            a.iter_mut().for_each(|a| *a /= w);
            a.retain(|a| *a >= 2);
            let sum = a.iter().sum::<i64>();
            if sum >= h {
                if a.iter().any(|a| *a > 2) || h % 2 == 0 {
                    ans = "Yes";
                }
            }
            std::mem::swap(&mut h, &mut w);
        }
        writeln!(out, "{}", ans).ok();
    }
}
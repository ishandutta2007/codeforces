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
        let mut a = sc.next_vec::<usize>(n);
        a.sort();
        let s = a.iter().sum::<usize>();
        let mut h = std::collections::BinaryHeap::new();
        h.push(s);
        let mut ans = "YES";
        let mut cnt = n - 1;
        for a in a.into_iter().rev() {
            while cnt > 0 && h.peek().map_or(false, |p| *p > a) {
                cnt -= 1;
                let v = h.pop().unwrap();
                h.push(v / 2);
                h.push((v + 1) / 2);
            }
            if h.pop().map_or(true, |p| p != a) {
                ans = "NO";
                break;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
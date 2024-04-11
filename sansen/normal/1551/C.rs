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
        let s = (0..n).map(|_| sc.next_bytes()).collect::<Vec<_>>();
        let mut ans = 0;
        for c in b'a'..=b'e' {
            let mut a = vec![];
            for s in s.iter() {
                let len = s.len() as i64;
                let cnt = s.iter().filter(|s| **s == c).count() as i64;
                a.push(cnt - (len - cnt));
            }
            a.sort();
            a.reverse();
            if a[0] <= 0 {
                continue;
            }
            let mut s = a[0];
            ans = ans.max(1);
            for j in 1..a.len() {
                s += a[j];
                if s > 0 {
                    ans = ans.max(j + 1);
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
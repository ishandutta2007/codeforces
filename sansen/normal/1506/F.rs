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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut p = vec![(0i64, 0i64); n];
        for p in p.iter_mut() {
            p.0 = sc.next();
        }
        for p in p.iter_mut() {
            p.1 = sc.next();
        }
        p.sort();
        let mut pos = (1, 1);
        let mut ans = 0;
        for &(x, y) in p.iter() {
            if pos.0 - pos.1 == x - y {
                if (x + y) % 2 == 0 {
                    ans += x - pos.0;
                }
            } else {
                if (pos.0 + pos.1) % 2 == 0 {
                    pos.0 += 1;
                }
                if pos.0 - pos.1 == x - y {
                } else {
                    pos.0 += y - pos.1;
                    pos.1 += y - pos.1;
                    ans += (x - pos.0 + 1) / 2;
                }
            }
            pos = (x, y);
        }
        writeln!(out, "{}", ans).ok();
    }
}
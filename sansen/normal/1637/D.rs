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
        let a: Vec<usize> = sc.next_vec(n);
        let b: Vec<usize> = sc.next_vec(n);
        let mut dp = vec![((0, 0), 0)];
        for (a, b) in a.iter().zip(&b) {
            let mut a = *a;
            let mut b = *b;
            let mut next = vec![];
            for _ in 0..2 {
                for &((x, y), c) in dp.iter() {
                    next.push(((x + a, y + b), c + a * x + b * y));
                }
                std::mem::swap(&mut a, &mut b);
            }
            dp = next;
            dp.sort_by_key(|p| p.0);
            dp.dedup_by(|a, b| {
                a.0 == b.0 && {
                    b.1 = a.1.min(b.1);
                    true
                }
            });
        }
        let mut ans = 0;
        ans += 2 * dp.iter().map(|p| p.1).min().unwrap();
        ans += a.iter().fold(0, |s, a| s + a.pow(2)) * (n - 1);
        ans += b.iter().fold(0, |s, a| s + a.pow(2)) * (n - 1);
        writeln!(out, "{}", ans).ok();
    }
}
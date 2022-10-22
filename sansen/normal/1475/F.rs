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
        let mut a = vec![vec![0u8; n]; n];
        for a in a.iter_mut() {
            let c = sc.next_bytes();
            for (a, c) in a.iter_mut().zip(c.iter()) {
                *a = *c - b'0';
            }
        }
        let mut b = vec![vec![0u8; n]; n];
        for a in b.iter_mut() {
            let c = sc.next_bytes();
            for (a, c) in a.iter_mut().zip(c.iter()) {
                *a = *c - b'0';
            }
        }
        for j in 0..n {
            if a[0][j] != b[0][j] {
                for i in 0..n {
                    a[i][j] ^= 1;
                }
            }
        }
        let mut ans = "YES";
        for (a, b) in a.iter().zip(b.iter()) {
            let xor = a[0] ^ b[0];
            if a.iter().zip(b.iter()).any(|(a, b)| *a^ *b != xor) {
                ans = "NO";
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
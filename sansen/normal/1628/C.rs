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
        let mut a = (0..n).map(|_| sc.next_vec(n)).collect::<Vec<Vec<u32>>>();
        let mut ans = 0;
            for _ in 0..2 {
                for i in 0..n {
                    for j in 0..n {
                        let s = i + j;
                        if s % 4 == 0 && i % 2 == j % 2 && i % 2 == 0 && s < n - 1 {
                            ans ^= a[i][j];
                        }
                        let x = n - 1 - i;
                        let y = n - 1 - j;
                        let s = x + y;
                        if s % 4 == 2 && x % 2 == y % 2 && x % 2 == 0 && s < n {
                            ans ^= a[i][j];
                        }
                    }
                }
                for a in a.iter_mut() {
                    a.reverse();
                }
        }
        writeln!(out, "{}", ans).ok();
    }
}
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
        let l: usize = sc.next();
        let r: usize = sc.next();
        let a: Vec<usize> = sc.next_vec(r - l + 1);
        let ans = solve(a, l, r);
        writeln!(out, "{}", ans).ok();
    }
}

fn solve(a: Vec<usize>, l: usize, r: usize) -> usize {
    let mut c = [0; 18];
    let mut ca = [0; 18];
    for i in 0..(r - l + 1) {
        for j in 0..17 {
            c[j] += (l + i) >> j & 1;
            ca[j] += a[i] >> j & 1;
        }
    }
    let mut xor = 0;
    for j in 0..18 {
        if c[j] != ca[j] {
            xor ^= 1 << j;
        }
    }
    xor
}
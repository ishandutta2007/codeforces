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
        let ans = if can(a, b) {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn can(a: Vec<usize>, b: Vec<usize>) -> bool {
    let n = a.len();
    if a[n - 1] != b[n - 1] {
        return false;
    }
    let mut need = vec![0; n + 1];
    let mut x = n - 1;
    for i in (0..(n - 1)).rev() {
        let last = b[i + 1];
        if b[i] == a[x - 1] {
            x -= 1;
            continue;
        }
        if b[i] == last {
            need[b[i]] += 1;
            continue;
        }
        while x > 0 && a[x - 1] != b[i] {
            if need[a[x - 1]] > 0 {
                need[a[x - 1]] -= 1;
                x -= 1;
            } else {
                return false;
            }
        }
        if !(x > 0 && a[x - 1] == b[i]) {
            return false;
        }
        x -= 1;
    }
    true
}
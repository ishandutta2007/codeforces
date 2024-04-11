// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
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

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let mut a = vec![vec![0usize; n]; n];
    for a in a.iter_mut().flatten() {
        *a = sc.next();
    }
    let mut b = vec![0usize; n];
    for (i, a) in a.iter().enumerate() {
        b[i] = a[i];
    }
    let mut xor = b.iter().fold(0, |s, a| s ^ *a);
    let q: usize = sc.next();
    let mut s = String::new();
    for _ in 0..q {
        let op: u8 = sc.next();
        if op == 3 {
            s.push_str(&format!("{}", xor));
        } else {
            let x = sc.next::<usize>() - 1;
            b[x] ^= 1;
            xor ^= 1;
        }
    }
    writeln!(out, "{}", s).ok();
}
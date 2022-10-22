//---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
            (0..n).map(|_| self.next()).collect::<Vec<T>>()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
//---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let out = std::io::BufWriter::new(out.lock());
    run(sc, out);
}

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    macro_rules! puts {
        ($($format:tt)*) => (write!(out, $($format)*).unwrap());
    }
    let q: usize = sc.next();
    for _ in 0..q {
        let n: usize = sc.next();
        let mut a = Vec::with_capacity(4 * n);
        for _ in 0..(4 * n) {
            let v: u32 = sc.next();
            a.push(v);
        }
        a.sort();
        let s = a[0] * a[4 * n - 1];
        let mut ok = true;
        for i in 0..n {
            if !(a[2 * i] == a[2 * i + 1] && a[4 * n - 2 * i - 1] == a[4 * n - 2 * i - 2] && a[2 * i] * a[4 * n - 2 * i - 1] == s) {
                ok = false;
            }
        }
        if ok {
            puts!("YES\n");
        } else {
            puts!("NO\n");
        }
    }
}
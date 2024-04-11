// ---------- begin scannner ----------
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
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<u32> = sc.next_vec(n);
        let b: Vec<u32> = sc.next_vec(n);
        let c: Vec<u32> = sc.next_vec(n);
        let mut p = vec![];
        p.push(a[0]);
        for i in 1..(n - 1) {
            let v = p[i - 1];
            if a[i] != v {
                p.push(a[i]);
            } else if b[i] != v {
                p.push(b[i]);
            } else {
                p.push(p[i]);
            }
        }
        let x = p[0];
        let y = p[n - 2];
        if a[n - 1] != x && a[n - 1] != y {
            p.push(a[n - 1]);
        } else if b[n - 1] != x && b[n - 1] != y {
            p.push(b[n - 1]);
        } else {
            p.push(c[n - 1]);
        }
        let mut s = String::new();
        for p in p {
            s.push_str(&format!("{} ", p));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
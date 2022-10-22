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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: Vec<u32> = (0..n).map(|_| sc.next()).collect();
        let mut ans = 0;
        let mut min = a[n - 1];
        for i in (0..(n - 1)).rev() {
            if a[i] > min {
                ans += 1;
            } else {
                min = a[i];
            }
        }
        writeln!(out, "{}", ans).unwrap();
    }
}
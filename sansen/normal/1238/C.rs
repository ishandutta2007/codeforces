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
    let q: usize = sc.next();
    for _ in 0..q {
        let _h: u32 = sc.next();
        let n: usize = sc.next();
        let mut p: Vec<u32> = (0..n).map(|_| sc.next()).collect();
        p.push(0);
        p.push(0);
        let mut ans = 0;
        let mut i = 0;
        while i < n {
            p[i] = p[i + 1] + 1;
            if i + 2 < p.len() && p[i + 2] + 1 >= p[i + 1] {
                i += 2;
            } else {
                i += 1;
                ans += 1;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
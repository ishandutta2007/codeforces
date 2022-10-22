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
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let s: u64 = sc.next();
        let p: Vec<(u64, u64)> = (0..n).map(|_| {
            let l: u64 = sc.next();
            let r: u64 = sc.next();
            (l, r)
        }).collect();
        let mut l = 1;
        let mut r = 1_000_000_000 + 1;
        while r - l > 1 {
            let m = (l + r) / 2;
            if can(m, s, &p) {
                l = m;
            } else {
                r = m;
            }
        }
        writeln!(out, "{}", l).ok();
    }
}

fn can(m: u64, s: u64, p: &[(u64, u64)]) -> bool {
    let mut b = vec![];
    let mut s = s;
    let n = p.len();
    let mut cnt = 0;
    for &(l, r) in p {
        if l >= m {
            s -= l;
            cnt += 1;
        } else if r < m {
            s -= l;
        } else {
            b.push(l);
        }
    }
    if cnt + b.len() <= n / 2 {
        return false;
    }
    if cnt > n / 2 {
        return true;
    }
    b.sort();
    b.reverse();
    while cnt + b.len() > n / 2 + 1 {
        let l = b.pop().unwrap();
        s -= l;
    }
    s >= (b.len() as u64) * m
}
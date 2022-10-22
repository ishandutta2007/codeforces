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
        let _n: usize = sc.next();
        let a: Vec<usize> = sc.next_chars().into_iter().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
        let ans = calc(&a, 0);
        writeln!(out, "{}", ans).ok();
    }
}

fn calc(a: &[usize], c: usize) -> usize {
    if a.len() == 1 {
        return if a[0] == c {
            0
        } else {
            1
        };
    }
    let m = a.len() / 2;
    let (l, r) = a.split_at(m);
    let x = calc(r, c + 1) + l.iter().filter(|p| **p != c).count();
    let y = calc(l, c + 1) + r.iter().filter(|p| **p != c).count();
    std::cmp::min(x, y)
}
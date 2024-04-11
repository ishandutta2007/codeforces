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
use std::cmp::*;

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
        let a: Vec<i64> = (0..n).map(|_| sc.next()).collect();
        let mut ng = -1;
        let mut ok = 1_000_000_000;
        while ok - ng > 1 {
            let m = (ng + ok) / 2;
            let mut val = 0;
            let mut l = 0;
            let mut r = 1_000_000_000;
            for i in 1..n {
                match (a[i - 1] == -1, a[i] == -1) {
                    (true, true) => (),
                    (false, false) => {
                        val = max(val, (a[i] - a[i - 1]).abs());
                    },
                    (true, false) => {
                        l = max(l, a[i] - m);
                        r = min(r, a[i] + m);
                    },
                    (false, true) => {
                        l = max(l, a[i - 1] - m);
                        r = min(r, a[i - 1] + m);
                    },
                }
            }
            if l <= r && val <= m {
                ok = m;
            } else {
                ng = m;
            }
        }
        let m = ok;
        let mut val = 0;
        let mut l = 0;
        let mut r = 1_000_000_000;
        for i in 1..n {
            match (a[i - 1] == -1, a[i] == -1) {
                (true, true) => (),
                (false, false) => {
                    val = max(val, (a[i - 1] - a[i]).abs());
                },
                (true, false) => {
                    l = max(l, a[i] - m);
                    r = min(r, a[i] + m);
                },
                (false, true) => {
                    l = max(l, a[i - 1] - m);
                    r = min(r, a[i - 1] + m);
                },
            }
        }
        writeln!(out, "{} {}", max(ok, val), l).ok();
    }
}
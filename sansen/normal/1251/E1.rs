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
use std::cmp::Reverse;

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
        let mut p: Vec<(usize, u64)> = (0..n).map(|_| {
            let m = sc.next();
            let p = sc.next();
            (m, p)
        }).collect();
        p.sort_by_key(|p| (p.0, 1_000_000_000 - p.1));
        let mut h = std::collections::BinaryHeap::new();
        let mut cnt = n - 1;
        let mut ans = 0;
        for &(m, p) in p.iter().rev() {
            h.push(Reverse(p));
            if m <= cnt {
                cnt -= 1;
            } else {
                let Reverse(v) = h.pop().unwrap();
                ans += v;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
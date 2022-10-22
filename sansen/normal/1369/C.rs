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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let k: usize = sc.next();
        let mut a: Vec<i64> = (0..n).map(|_| sc.next()).collect();
        a.sort();
        let mut w: Vec<usize> = (0..k).map(|_| sc.next()).collect();
        w.sort();
        w.reverse();
        let mut ans = 0;
        while w.last().map_or(false, |w| *w == 1) {
            ans += a.pop().unwrap() * 2;
            w.pop();
        }
        a.reverse();
        for w in w.iter_mut() {
            ans += a.pop().unwrap();
            *w -= 1;
            while *w > 1 {
                a.pop();
                *w -= 1;
            }
        }
        ans += a.iter().sum::<i64>();
        writeln!(out, "{}", ans).ok();
    }
}
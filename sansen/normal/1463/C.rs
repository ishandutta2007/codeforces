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
        let mut p = vec![(0i64, 0i64); n];
        for p in p.iter_mut() {
            p.0 = sc.next();
            p.1 = sc.next();
        }
        for i in (1..n).rev() {
            p[i].0 -= p[i - 1].0;
        }
        let inf = std::i64::MAX / 10;
        p.push((inf, inf));
        p.push((inf, inf));
        let mut ans = 0;
        let mut pos = 0;
        let mut dir = 0;
        let mut com = n + 1;
        for (i, &(t, x)) in p[..=n].iter().enumerate() {
            let mut ns = pos + dir * t;
            if (dir > 0 && ns > p[com].1) || (dir < 0 && ns < p[com].1) {
                ns = p[com].1;
            }
            if i > 0 {
                ans += (pos.min(ns) <= p[i - 1].1 && p[i - 1].1 <= pos.max(ns)) as u32;
            }
            pos = ns;
            if pos == p[com].1 {
                dir = 0;
                com = n + 1;
            }
            if dir == 0 {
                dir = (x - pos).signum();
                com = i;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
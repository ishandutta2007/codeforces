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
        let mut a: Vec<(i64, i64)> = (0..n).map(|_| {
            let a: i64 = sc.next();
            let b: i64 = sc.next();
            (a, b)
        }).collect();
        if n == 1 {
            writeln!(out, "{}", a[0].0).ok();
            continue;
        }
        let p = a[0];
        a.push(p);
        let mut ans = 0;
        let mut min = std::i64::MAX;
        for i in 1..=n {
            if a[i - 1].1 < a[i].0 {
                ans += a[i].0 - a[i - 1].1;
                a[i].0 = a[i - 1].1;
            }
            min = std::cmp::min(min, a[i].0);
        }
        ans += min;
        writeln!(out, "{}", ans).ok();
    }
}
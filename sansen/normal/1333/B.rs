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
        let a: Vec<i32> = (0..n).map(|_| sc.next()).collect();
        let b: Vec<i32> = (0..n).map(|_| sc.next()).collect();
        let mut cnt = vec![0; 3];
        for a in a.iter() {
            cnt[(*a + 1) as usize] += 1;
        }
        let mut ok = true;
        for (a, b) in a.iter().zip(b.iter()).rev() {
            cnt[(*a + 1) as usize] -= 1;
            if *a == *b {
                continue;
            }
            if *a < *b {
                ok = ok && cnt[2] > 0;
            } else {
                ok = ok && cnt[0] > 0;
            }
        }
        if ok {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
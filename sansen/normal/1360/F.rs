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
        let m: usize = sc.next();
        let a: Vec<Vec<char>> = (0..n).map(|_| sc.next_chars()).collect();
        let op: Vec<char> = "qwertyuiopasdfghjklzxcvbnm".chars().collect();
        assert!(op.len() == 26);
        let valid = |s: &[char]| -> bool {
            a.iter().all(|a| a.iter().zip(s.iter()).filter(|p| *p.0 != *p.1).count() <= 1)
        };
        let mut ans = vec![];
        for i in 0..m {
            let mut s = a[0].clone();
            for c in op.iter() {
                s[i] = *c;
                if valid(&s) {
                    ans = s.clone();
                    break;
                }
            }
        }
        if ans.len() > 0 {
            let ans: String = ans.into_iter().collect();
            writeln!(out, "{}", ans).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}
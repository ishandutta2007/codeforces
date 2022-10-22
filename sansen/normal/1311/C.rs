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
        let s: Vec<char> = sc.next_chars();
        let s: Vec<usize> = s.into_iter().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
        let mut imos = vec![0u64; n];
        imos[n - 1] = 1;
        for _ in 0..m {
            let p: usize = sc.next();
            imos[p - 1] += 1;
        }
        for i in (1..n).rev() {
            imos[i - 1] += imos[i];
        }
        let f = 26;
        let mut cnt = vec![0; f];
        for (s, c) in s.iter().zip(imos.iter()) {
            cnt[*s] += *c;
        }
        let mut s = String::new();
        for c in cnt {
            s.push_str(&format!("{} ", c));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
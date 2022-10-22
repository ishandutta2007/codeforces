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
        let a: usize = sc.next();
        let b: usize = sc.next();
        let q: usize = sc.next();
        let mut cnt = vec![0; (a * b) as usize + 1];
        for i in 0..(a * b) {
            cnt[i + 1] = cnt[i];
            if i % a % b != i % b % a {
                cnt[i + 1] += 1;
            }
        }
        let count = |n: u64| -> u64 {
            let q = n / (a * b) as u64;
            let ans = q * cnt[a * b];
            let rem = n % (a * b) as u64;
            ans + cnt[rem as usize + 1]
        };
        let mut ans = String::new();
        for _ in 0..q {
            let l: u64 = sc.next();
            let r: u64 = sc.next();
            let v = count(r) - count(l - 1);
            ans.push_str(&format!("{} ", v));
        }
        ans.pop();
        writeln!(out, "{}", ans).ok();
    }
}
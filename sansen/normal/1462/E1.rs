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
        let m = 3;
        let k = 2;
        let mut cnt = vec![0u64; n + 1 + m + k + 1];
        for _ in 0..n {
            let a: usize = sc.next();
            cnt[a] += 1;
        }
        for i in (1..=n).rev() {
            cnt[i] += cnt[i + 1];
        }
        let mut ans = 0;
        for i in 1..=n {
            if cnt[i] > 0 {
                let v = cnt[i] - cnt[i + k + 1];
                if v >= (m as u64)  {
                    ans += v * (v - 1) * (v - 2) / 6;
                    let c = cnt[i] - cnt[i + 1];
                    if v - c >= (m as u64) {
                        ans -= (v - c) * (v - c - 1) * (v - c - 2) / 6;
                    }
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
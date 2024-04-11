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

fn main() {
    let sc = scanner::read_string();
    let sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let out = std::io::BufWriter::new(out.lock());
    run(sc, out);
}

use std::cmp::min;

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    for _ in 0..q {
        let n: usize = sc.next();
        let mut a = vec![0i64; n];
        let mut b = vec![0i64; n];
        for (a, b) in a.iter_mut().zip(b.iter_mut()) {
            *a = sc.next();
            *b = sc.next();
        }
        let m = 5;
        let mut dp = vec![0; m];
        for i in 0..m {
            dp[i] = i as i64 * b[0];
        }
        for i in 1..n {
            let (p, q) = (a[i - 1] as usize, a[i] as usize);
            let mut next = vec![1_000_000_000_000_000_000 + 1; m];
            for j in 0..m {
                for k in 0..m {
                    if p + j == q + k {
                        continue;
                    }
                    let v = dp[j] + k as i64 * b[i];
                    next[k] = min(next[k], v);
                }
            }
            dp = next;
        }
        let ans = *dp.iter().min().unwrap();
        writeln!(out, "{}", ans).unwrap();
    }
}
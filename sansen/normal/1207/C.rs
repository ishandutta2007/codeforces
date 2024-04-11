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

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let a: u64 = sc.next();
        let b: u64 = sc.next();
        let mut s = sc.next_chars();
        s.push('0');
        let inf = (1 + 2 * a + 2 * b) * n as u64;
        let mut dp = vec![vec![inf; n + 1]; 2];
        dp[0][0] = b;
        for i in 0..n {
            dp[1][i + 1] = std::cmp::min(dp[1][i] + a + 2 * b, dp[0][i] + 2 * a + 2 * b);
            if s[i] == '0' && s[i + 1] == '0' {
                dp[0][i + 1] = std::cmp::min(dp[0][i] + a + b, dp[1][i] + 2 * a + b);
            }
        }
        writeln!(out, "{}", dp[0][n]).unwrap();
    }
}
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
    let q: usize = sc.next();
    for _ in 0..q {
        let n: usize = sc.next();
        let mut s = [sc.next_chars(), sc.next_chars()];
        for i in 0..2 {
            for j in 0..n {
                if '1' <= s[i][j] && s[i][j] <= '2' {
                    s[i][j] = '0';
                } else {
                    s[i][j] = '1';
                }
            }
        }
        let mut dp = [true, false];
        for i in 0..n {
            let mut next = [false, false];
            if s[0][i] == '0' {
                next[0] |= dp[0];
            }
            if s[0][i] == '1' && s[1][i] == '1' {
                next[0] |= dp[1];
                next[1] |= dp[0];
            }
            if s[1][i] == '0' {
                next[1] |= dp[1];
            }
            dp = next;
        }
        let ans = if dp[1] {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", ans).unwrap();
    }
}
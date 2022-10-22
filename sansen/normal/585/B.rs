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
        let w: usize = sc.next();
        let _k: usize = sc.next();
        let mut s: Vec<Vec<char>> = (0..3).map(|_| sc.next_chars()).collect();
        for s in s.iter_mut() {
            s.push('.');
            s.push('.');
            s.push('.');
        }
        let ans = || -> bool {
            let pos = s.iter().position(|s| s[0] == 's').unwrap();
            if s[pos][1] != '.' {
                return false;
            }
            let mut dp = vec![false; 3];
            dp[pos] = true;
            if pos + 1 < 3 && s[pos + 1][1] == '.' {
                dp[pos + 1] = true;
            }
            if pos >= 1 && s[pos - 1][1] == '.' {
                dp[pos - 1] = true;
            }
            let mut i = 1;
            while i < w {
                for (s, dp) in s.iter().zip(dp.iter_mut()) {
                    *dp &= s[i..=(i + 3)].iter().all(|c| *c == '.');
                }
                i += 3;
                let mut next = vec![false; 3];
                for (j, &v) in dp.iter().enumerate() {
                    next[j] |= v;
                    if j + 1 < 3 {
                        next[j + 1] |= v && s[j + 1][i] == '.';
                    }
                    if j >= 1 {
                        next[j - 1] |= v && s[j - 1][i] == '.';
                    }
                }
                dp = next;
            }
            dp.iter().any(|v| *v)
        }();
        if ans {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
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
        let h: usize = sc.next();
        let w: usize = sc.next();
        let x: u64 = sc.next();
        let y: u64 = sc.next();
        let s: Vec<Vec<char>> = (0..h).map(|_| sc.next_chars()).collect();
        let y = std::cmp::min(2 * x, y);
        let mut ans = 0;
        for mut s in s {
            for i in 0..w {
                if s[i] == '*' {
                    continue;
                }
                s[i] = '*';
                if i + 1 < w && s[i + 1] == '.' {
                    ans += y;
                    s[i + 1] = '*';
                } else {
                    ans += x;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
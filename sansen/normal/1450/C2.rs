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
        let mut s = vec![];
        for _ in 0..n {
            s.push(sc.next::<String>().bytes().collect::<Vec<_>>());
        }
        let mut cnt = [[0; 3]; 2];
        for (i, s) in s.iter().enumerate() {
            for (j, s) in s.iter().enumerate() {
                if *s != b'.' {
                    let x = (*s == b'X') as usize;
                    cnt[x][(i + j) % 3] += 1;
                }
            }
        }
        let mut p = (0, 1);
        for i in 0..3 {
            for j in 0..3 {
                if i == j {
                    continue;
                }
                if cnt[0][p.0] + cnt[1][p.1] > cnt[0][i] + cnt[1][j] {
                    p = (i, j);
                }
            }
        }
        for (i, s) in s.iter_mut().enumerate() {
            for (j, s) in s.iter_mut().enumerate() {
                if *s != b'.' {
                    let k = (i + j) % 3;
                    if *s == b'O' && k == p.0 {
                        *s = b'X';
                    } else if *s == b'X' && k == p.1 {
                        *s = b'O';
                    }
                }
                write!(out, "{}", *s as char).ok();
            }
            writeln!(out).ok();
        }
    }
}
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
        let s: Vec<Vec<char>> = (0..h).map(|_| sc.next_chars()).collect();
        if s.iter().all(|s| s.iter().all(|c| *c == 'P')) {
            writeln!(out, "MORTAL").ok();
            continue;
        }
        let mut ans = calc(&s);
        let mut ts = vec![vec!['0'; h]; w];
        for i in 0..h {
            for j in 0..w {
                ts[j][i] = s[i][j];
            }
        }
        ans = std::cmp::min(ans, calc(&ts));
        writeln!(out, "{}", ans).ok();
    }
}

fn calc(s: &[Vec<char>]) -> usize {
    if s.iter().all(|s| s.iter().all(|c| *c == 'A')) {
        return 0;
    }
    let h = s.len();
    let w = s[0].len();
    for &i in [0, h - 1].iter() {
        if s[i].iter().all(|c| *c == 'A') {
            return 1;
        }
    }
    if s[0][0] == 'A' || s[h - 1][0] == 'A' || s[0][w - 1] == 'A' || s[h - 1][w - 1] == 'A' {
        return 2;
    }
    for i in 0..h {
        if s[i].iter().all(|c| *c == 'A') {
            return 2;
        }
    }
    for &i in [0, h - 1].iter() {
        if s[i].iter().any(|c| *c == 'A') {
            return 3;
        }
    }
    4
}
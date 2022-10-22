// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let h: usize = sc.next();
        let w: usize = sc.next();
        let mut s = vec![vec!['.'; w]; h];
        for (i, s) in s.iter_mut().enumerate() {
            if i % 3 == 1 {
                *s = vec!['X'; w];
            }
        }
        let t = (0..h).map(|_| sc.next_chars()).collect::<Vec<_>>();
        for (i, t) in t.iter().enumerate() {
            for (j, t) in t.iter().enumerate() {
                if *t == '.' || s[i][j] == 'X' {
                    continue;
                }
                s[i][j] = 'X';
            }
        }
        for i in (2..(h - 1)).step_by(3) {
            if let Some(x) = s[i].iter().position(|p| *p == 'X') {
                s[i + 1][x] = 'X';
                continue;
            }
            if let Some(x) = s[i + 1].iter().position(|p| *p == 'X') {
                s[i][x] = 'X';
            } else {
                s[i][0] = 'X';
                s[i + 1][0] = 'X';
            }
        }
        if h > 1 && h % 3 == 1 {
            for j in 0..w {
                if s[h - 1][j] == 'X' {
                    s[h - 2][j] = 'X';
                }
            }
        } else if h == 1 {
            s[0] = vec!['X'; w];
        }
        for s in s {
            let s = s.into_iter().collect::<String>();
            writeln!(out, "{}", s).ok();
        }
    }
}
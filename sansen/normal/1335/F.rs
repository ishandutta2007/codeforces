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
        let color: Vec<_> = (0..h).map(|_| sc.next_chars()).collect();
        let mut next = vec![vec![(0, 0); w]; h];
        for (x, next) in next.iter_mut().enumerate() {
            let s = sc.next_chars();
            for (y, (v, c)) in next.iter_mut().zip(s.into_iter()).enumerate() {
                *v = match c {
                    'L' => (x, y - 1),
                    'R' => (x, y + 1),
                    'U' => (x - 1, y),
                    'D' => (x + 1, y),
                    _ => unreachable!(),
                }
            }
        }
        let mut tmp = vec![vec![(0, 0); w]; h];
        for _ in 0..20 {
            for (tmp, a) in tmp.iter_mut().zip(next.iter()) {
                for (t, a) in tmp.iter_mut().zip(a.iter()) {
                    let (p, q) = *a;
                    *t = next[p][q];
                }
            }
            next.clone_from(&tmp);
        }
        let mut ans = 0;
        let mut ans_black = 0;
        let mut used = vec![vec![false; w]; h];
        let mut black = vec![vec![false; w]; h];
        for (s, next) in color.into_iter().zip(next.into_iter()) {
            for (c, (x, y)) in s.into_iter().zip(next.into_iter()) {
                if !used[x][y] {
                    used[x][y] = true;
                    ans += 1;
                }
                if c == '0' && !black[x][y] {
                    black[x][y] = true;
                    ans_black += 1;
                }
            }
        }
        writeln!(out, "{} {}", ans, ans_black).ok();
    }
}
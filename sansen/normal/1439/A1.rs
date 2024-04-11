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
        let h: usize = sc.next();
        let w: usize = sc.next();
        let a: Vec<Vec<u8>> = (0..h).map(|_| sc.next::<String>().bytes().collect()).collect();
        let mut b = a.clone();
        let mut ans = vec![];
        for j in (2..w).rev() {
            for i in (0..h).rev() {
                if b[i][j] == b'1' {
                    let mut p = vec![(i, j), (i, j - 1)];
                    if i == 0 {
                        p.push((i + 1, j - 1));
                    } else {
                        p.push((i - 1, j - 1));
                    }
                    for &(x, y) in p.iter() {
                        b[x][y] ^= b'0' ^ b'1';
                    }
                    ans.push(p);
                }
            }
        }
        for i in (2..h).rev() {
            for j in 0..2 {
                if b[i][j] == b'1' {
                    let p = vec![(i, j), (i - 1, 0), (i - 1, 1)];
                    for &(x, y) in p.iter() {
                        b[x][y] ^= b'0' ^ b'1';
                    }
                    ans.push(p);
                }
            }
        }
        let p = [(0, 0), (0, 1), (1, 0), (1, 1)];
        for i in 0..(1 << 4) {
            let mut b = b.clone();
            let mut op = vec![];
            for j in 0..4 {
                let mut a = vec![];
                if i >> j & 1 == 1 {
                    for (k, p) in p.iter().enumerate() {
                        if k != j {
                            a.push(*p);
                            b[p.0][p.1] ^= b'0' ^ b'1';
                        }
                    }
                }
                if a.len() > 0 {
                    op.push(a);
                }
            }
            if b == vec![vec![b'0'; w]; h] {
                if op.len() > 0 {
                    ans.append(&mut op);
                }
                break;
            }
        }
        writeln!(out, "{}", ans.len()).ok();
        for a in ans {
            let (a, b, c) = (a[0], a[1], a[2]);
            writeln!(out, "{} {} {} {} {} {}", a.0 + 1, a.1 + 1, b.0 + 1, b.1 + 1, c.0 + 1, c.1 + 1).ok();
        }
    }
}
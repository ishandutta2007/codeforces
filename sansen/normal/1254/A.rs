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
        let cnt: usize = sc.next();
        let s: Vec<Vec<char>> = (0..h).map(|_| sc.next_chars()).collect();
        let mut rice = 0;
        for i in 0..h {
            for j in 0..w {
                if s[i][j] == 'R' {
                    rice += 1;
                }
            }
        }
        let op: Vec<char> = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890".chars().collect();
        assert!(op.len() == 62);
        let mut a = vec![0; cnt];
        while rice > 0 {
            for a in a.iter_mut() {
                if rice == 0 {
                    break;
                }
                *a += 1;
                rice -= 1;
            }
        }
        let mut ans = vec![vec!['\n'; w]; h];
        let mut p = (0, 0);
        let mut k = 0;
        while p.0 < h {
            let (x, y) = p;
            ans[x][y] = op[k];
            if s[x][y] == 'R' {
                a[k] -= 1;
            }
            if k < cnt - 1 && a[k] == 0 {
                k += 1;
            }
            if p.0 % 2 == 0 {
                if p.1 == w - 1 {
                    p.0 += 1;
                } else {
                    p.1 += 1;
                }
            } else {
                if p.1 == 0 {
                    p.0 += 1;
                } else {
                    p.1 -= 1;
                }
            }
        }
        let mut s = String::new();
        for i in 0..h {
            for j in 0..w {
                s.push(ans[i][j]);
            }
            s.push('\n');
        }
        write!(out, "{}", s).ok();
    }
}
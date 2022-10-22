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
        let mut a: Vec<Vec<u32>> = (0..h).map(|_| (0..w).map(|_| sc.next()).collect()).collect();
        let mut ok = true;
        for (i, a) in a.iter_mut().enumerate() {
            for (j, a) in a.iter_mut().enumerate() {
                let mut cnt = 0;
                for &(x, y) in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)].iter() {
                    if x < h && y < w {
                        cnt += 1;
                    }
                }
                if *a > cnt {
                    ok = false;
                } else {
                    *a = cnt;
                }
            }
        }
        if ok {
            writeln!(out, "YES").ok();
            for a in a {
                for a in a {
                    write!(out, "{} ", a).ok();
                }
                writeln!(out, "").ok();
            }
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
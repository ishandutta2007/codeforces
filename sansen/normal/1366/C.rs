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
        let a: Vec<Vec<usize>> = (0..h).map(|_| (0..w).map(|_| sc.next()).collect()).collect();
        let mut ans = 0;
        for x in 0.. {
            let y = h - 1 + w - 1 - x;
            if y <= x {
                break;
            }
            let mut cnt = vec![0; 2];
            for i in 0..=x {
                if i < h && x - i < w {
                    cnt[a[i][x - i]] += 1;
                }
            }
            for i in 0..=y {
                if i < h && y - i < w {
                    cnt[a[i][y - i]] += 1;
                }
            }
            ans += cnt.into_iter().min().unwrap();
        }
        writeln!(out, "{}", ans).ok();
    }
}
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
        let n: usize = sc.next();
        let p: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let mut ans = vec![p[0]];
        if n > 2 {
            for p in p.windows(3) {
                if p[0] < p[1] && p[1] < p[2] {
                    continue;
                }
                if p[0] > p[1] && p[1] > p[2] {
                    continue;
                }
                ans.push(p[1]);
            }
        }
        ans.push(p[n - 1]);
        let mut s = String::new();
        s.push_str(&format!("{}\n", ans.len()));
        for a in ans {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
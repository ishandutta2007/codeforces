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
        let prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31];
        let mut c = vec![vec![]; 11];
        for i in 0..n {
            let a: usize = sc.next();
            for (j, p) in prime.iter().enumerate() {
                if a % *p == 0 {
                    c[j].push(i);
                    break;
                }
            }
        }
        let mut ans = vec![0; n];
        let mut id = 0;
        for c in c {
            if c.is_empty() {
                continue;
            }
            id += 1;
            for c in c {
                ans[c] = id;
            }
        }
        let mut s = String::new();
        s.push_str(&format!("{}\n", id));
        for a in ans {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
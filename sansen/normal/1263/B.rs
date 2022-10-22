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
        let mut s: Vec<Vec<char>> = (0..n).map(|_| sc.next_chars()).collect();
        let mut ans = 0;
        for i in 0..n {
            let mut same = false;
            for j in 0..n {
                if i != j && s[i] == s[j] {
                    same = true;
                }
            }
            if same {
                ans += 1;
                'outer: for k in 0..4 {
                    let save = s[i][k];
                    for c in 0..10 {
                        let c = (c + '0' as u8) as char;
                        s[i][k] = c;
                        let mut same = false;
                        for j in 0..n {
                            if i != j && s[i] == s[j] {
                                same = true;
                            }
                        }
                        if !same {
                            break 'outer;
                        }
                    }
                    s[i][k] = save;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
        for s in s {
            let s: String = s.into_iter().collect();
            writeln!(out, "{}", s).ok();
        }
    }
}
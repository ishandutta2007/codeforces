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
    let t: u32 = sc.next();
    for _ in 0..t {
        let k: usize = sc.next();
        let n: usize = sc.next();
        let m: usize = sc.next();
        let mut a: Vec<usize> = sc.next_vec(n);
        let mut b: Vec<usize> = sc.next_vec(m);
        let mut len = k;
        let mut ans = vec![];
        while a.len() > 0 || b.len() > 0 {
            if a.len() > 0 && a[0] <= len {
                let v = a.remove(0);
                ans.push(v);
                if v == 0 {
                    len += 1;
                }
            } else if b.len() > 0 && b[0] <= len {
                let v = b.remove(0);
                ans.push(v);
                if v == 0 {
                    len += 1;
                }
            } else {
                ans = vec![];
                break;
            }
        }
        if ans.is_empty() {
            writeln!(out, "-1").ok();
        } else {
            let s = ans.iter().map(|a| a.to_string()).collect::<Vec<_>>().join(" ");
            writeln!(out, "{}", s).ok();
        }
    }
}
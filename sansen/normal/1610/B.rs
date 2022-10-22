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
        let n: usize = sc.next();
        let a: Vec<u32> = sc.next_vec(n);
        let mut f = 0;
        let mut t = n;
        while f < t {
            if a[f] == a[t - 1] {
                f += 1;
                t -= 1;
            } else {
                break;
            }
        }
        let mut ans = "NO";
        if f < t {
            let a = Vec::from(&a[f..t]);
            let b = [a[0], *a.last().unwrap()];
            for b in b.iter() {
                let mut a = a.clone();
                a.retain(|a| *a != *b);
                if a.iter().zip(a.iter().rev()).all(|p| *p.0 == *p.1) {
                    ans = "YES";
                }
            }
        } else {
            ans = "YES";
        }
        writeln!(out, "{}", ans).ok();
    }
}
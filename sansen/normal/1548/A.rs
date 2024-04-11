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
    let n: usize = sc.next();
    let m: usize = sc.next();
    let mut cnt = vec![0; n];
    let mut ans = n;
    for _ in 0..m {
        let mut a: usize = sc.next::<usize>() - 1;
        let mut b: usize = sc.next::<usize>() - 1;
        if a > b {
            std::mem::swap(&mut a, &mut b);
        }
        if cnt[a] == 0 {
            ans -= 1;
        }
        cnt[a] += 1;
    }
    let q: usize = sc.next();
    for _ in 0..q {
        let op = sc.next::<u8>();
        if op == 3 {
            writeln!(out, "{}", ans).ok();
        } else {
            let mut a: usize = sc.next::<usize>() - 1;
            let mut b: usize = sc.next::<usize>() - 1;
            if a > b {
                std::mem::swap(&mut a, &mut b);
            }
            if op == 1 {
                if cnt[a] == 0 {
                    ans -= 1;
                }
                cnt[a] += 1;
            } else {
                if cnt[a] == 1 {
                    ans += 1;
                }
                cnt[a] -= 1;
            }
        }
    }
}
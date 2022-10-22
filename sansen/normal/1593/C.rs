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
        let n: u64 = sc.next();
        let k: usize = sc.next();
        let mut x = vec![0u64; k];
        for x in x.iter_mut() {
            *x = n - sc.next::<u64>();
        }
        x.sort();
        let valid = |m: usize| -> bool {
            let mut pos = n;
            for &x in x[..m].iter().rev() {
                if x >= pos {
                    return false;
                }
                pos -= x;
            }
            true
        };
        let mut ok = 0;
        let mut ng = k + 1;
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            if valid(mid) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        writeln!(out, "{}", ok).ok();
    }
}
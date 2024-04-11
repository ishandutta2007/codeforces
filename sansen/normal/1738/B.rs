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
        let k: usize = sc.next();
        let s: Vec<i64> = sc.next_vec(k);
        let ans = if solve(s, n) { "Yes" } else { "No" };
        writeln!(out, "{}", ans).ok();
    }
}

fn solve(s: Vec<i64>, n: usize) -> bool {
    let mut a = s.windows(2).map(|s| s[1] - s[0]).collect::<Vec<_>>();
    let k = n - a.len();
    let d = s[0].div_euclid(k as i64);
    a.splice(0..0, (0..k).map(|_| d));
    let r = s[0].rem_euclid(k as i64) as usize;
    for a in a[(k - r)..k].iter_mut() {
        *a += 1;
    }
    a.windows(2).all(|a| a[0] <= a[1])
}
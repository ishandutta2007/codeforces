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
        let m: u64 = sc.next();
        let mut a = vec![];
        for _ in 0..n {
            let mut x: u64 = sc.next();
            let mut cnt = 1;
            while x % m == 0 {
                x /= m;
                cnt *= m;
            }
            a.push((x, cnt));
        }
        a.dedup_by(|a, b| {
            a.0 == b.0 && {
                b.1 += a.1;
                true
            }
        });
        let len: usize = sc.next();
        let b: Vec<u64> = sc.next_vec(len);
        let mut ans = "Yes";
        if b.iter().sum::<u64>() != a.iter().fold(0, |s, a| s + a.0 * a.1) {
            ans = "No";
        } else {
            let mut x = 0;
            for b in b {
                let (q, c) = a[x];
                let mut k = 1;
                while k * q < b {
                    k *= m;
                }
                if k * q != b || k > c {
                    ans = "No";
                    break;
                }
                a[x].1 -= k;
                if a[x].1 == 0 {
                    x += 1;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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
        let h: usize = sc.next();
        let w: usize = sc.next();
        let mut s = vec![];
        for _ in 0..h {
            let t = sc.next_bytes();
            let mut a = vec![];
            for t in t {
                a.push((t - b'0') as usize);
            }
            s.push(a);
        }
        let s = s;
        let mut sum = vec![vec![0; w + 1]; h + 1];
        for (i, s) in s.iter().enumerate().rev() {
            for (j, s) in s.iter().enumerate().rev() {
                sum[i][j] = *s + sum[i + 1][j];
            }
        }
        let sum = sum;
        let mut ans = 16;
        for i in 5..=h {
            for d in i..=h {
                let mut dp = (16, 16, 16);
                let (a, b, c, d) = (&sum[d - i + 1], &sum[d - 1], &s[d - i], &s[d - 1]);
                for j in 0..w {
                    let v = c[j] + d[j];
                    let c = a[j] - b[j];
                    ans.chmin(dp.2 + i - 2 - c);
                    dp.2 = (dp.2 + 2 - v + c).min(dp.1 + 2 - v + c);
                    dp.1 = dp.0 + 2 - v + c;
                    dp.0 = i - 2 - c;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
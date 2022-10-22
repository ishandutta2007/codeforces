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
        let x: i64 = sc.next();
        let a: Vec<i64> = sc.next_vec(n);
        let geta = a.windows(2).map(|a| (a[1] - a[0]).abs()).sum::<i64>();
        let ans = if n == 1 {
            x.max(a[0]) - 1
        } else {
            let p = a
                .windows(2)
                .map(|a| -(a[1] - a[0]).abs() + (a[0] - 1).abs() + (a[1] - 1).abs())
                .min()
                .unwrap();
            let q = a
                .windows(2)
                .map(|a| -(a[1] - a[0]).abs() + (a[0] - x).abs() + (a[1] - x).abs())
                .min()
                .unwrap();
            let mut ans = geta + p + q;
            let mut a = a;
            for _ in 0..2 {
                ans = ans.min(geta + (a[0] - 1).abs() + q);
                ans = ans.min(geta + (a[0] - x).abs() + p);
                ans = ans.min(geta + (a[0] - 1).abs() + (a[n - 1] - x).abs());
                ans = ans.min(geta + (a[0] - x).abs() + (a[n - 1] - 1).abs());
                ans = ans.min(geta + (a[0] - 1).abs() + x - 1);
                ans = ans.min(geta + (a[0] - x).abs() + x - 1);
                ans = ans.min(
                    geta + a
                        .windows(2)
                        .map(|a| -(a[0] - a[1]).abs() + (a[0] - 1).abs() + x - 1 + (a[1] - x).abs())
                        .min()
                        .unwrap(),
                );
                a.reverse();
            }
            ans
        };
        writeln!(out, "{}", ans).ok();
    }
}
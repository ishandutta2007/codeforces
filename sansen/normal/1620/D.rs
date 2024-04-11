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
        let a: Vec<i64> = sc.next_vec(n);
        let q = *a.iter().max().unwrap() / 3;
        let mut ans = std::i64::MAX;
        for i in -3..=3 {
            if q + i < 0 {
                continue;
            }
            let three = q + i;
            for one in 0..3 {
                for two in 0..3 {
                    let ok = a.iter().all(|&a| {
                        for i in 0..=two {
                            if i * 2 > a {
                                break;
                            }
                            let a = a - i * 2;
                            let q = (a / 3).min(three);
                            let a = a - 3 * q;
                            if a <= one {
                                return true;
                            }
                        }
                        false
                    });
                    if ok {
                        ans = ans.min(one + two + three);
                    }
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
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
        let a = sc.next_vec::<i32>(n);
        let compress = |a: &mut Vec<(i32, u32)>| {
            a.sort();
            a.dedup_by(|a, b| {
                a.0 == b.0 && {
                    b.1 += a.1;
                    true
                }
            });
        };
        let mut a = a.into_iter().map(|a| (a, 1)).collect::<Vec<_>>();
        compress(&mut a);
        for _ in 1..n {
            let mut b = vec![];
            b.extend(a.iter().filter(|a| a.1 > 1).map(|a| (0, a.1 - 1)));
            b.extend(a.windows(2).map(|a| (a[1].0 - a[0].0, 1)));
            a = b;
            compress(&mut a);
        }
        writeln!(out, "{}", a[0].0).ok();
    }
}
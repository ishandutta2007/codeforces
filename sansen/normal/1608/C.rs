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
        let n: usize = sc.next();
        let a: Vec<u32> = sc.next_vec(n);
        let b: Vec<u32> = sc.next_vec(n);
        let mut x = a.iter().cloned().enumerate().collect::<Vec<_>>();
        let mut y = b.iter().cloned().enumerate().collect::<Vec<_>>();
        x.sort_by_key(|p| p.1);
        y.sort_by_key(|p| p.1);
        let mut s = vec!['0'; n];
        let mut xmin = a[x[n - 1].0];
        let mut ymin = b[x[n - 1].0];
        let mut i = n;
        let mut j = n;
        while i > 0 || j > 0 {
            if i > 0 && x[i - 1].1 >= xmin {
                i -= 1;
                s[x[i].0] = '1';
                ymin.chmin(b[x[i].0]);
            } else if j > 0 && y[j - 1].1 >= ymin {
                j -= 1;
                s[y[j].0] = '1';
                xmin.chmin(a[y[j].0]);
            } else {
                break;
            }
        }
        let mut xmin = a[y[n - 1].0];
        let mut ymin = b[y[n - 1].0];
        let mut i = n;
        let mut j = n;
        while i > 0 || j > 0 {
            if i > 0 && x[i - 1].1 >= xmin {
                i -= 1;
                s[x[i].0] = '1';
                ymin.chmin(b[x[i].0]);
            } else if j > 0 && y[j - 1].1 >= ymin {
                j -= 1;
                s[y[j].0] = '1';
                xmin.chmin(a[y[j].0]);
            } else {
                break;
            }
        }
        let s = s.into_iter().collect::<String>();
        writeln!(out, "{}", s).ok();
    }
}
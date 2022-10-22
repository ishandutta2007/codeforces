//---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
//---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let out = std::io::BufWriter::new(out.lock());
    run(sc, out);
}

fn gcd(a: u64, b: u64) -> u64 {
    if b == 0 {a} else {gcd(b, a % b)}
}

fn eval(p: &[u64], x: u64, a: u64, y: u64, b: u64) -> u64 {
    assert!(x >= y);
    let n = p.len() as u64;
    let mut sum = 0;
    let k = n / (a * b / gcd(a, b));
    for i in 0..k {
        sum += p[i as usize] / 100 * (x + y);
    }
    let m = n / a;
    for i in k..m {
        sum += p[i as usize] / 100 * x;
    }
    let l = n / b + m - k;
    for i in m..l {
        sum += p[i as usize] / 100 * y;
    }
    sum
}

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    for _ in 0..q {
        let n: usize = sc.next();
        let mut p: Vec<u64> = (0..n).map(|_| sc.next()).collect();
        p.sort();
        p.reverse();
        let x: u64 = sc.next();
        let a: u64 = sc.next();
        let y: u64 = sc.next();
        let b: u64 = sc.next();
        let (x, a, y, b) = if x >= y {(x, a, y, b)} else {(y, b, x, a)};
        let m: u64 = sc.next();
        if eval(&p, x, a, y, b) < m {
            writeln!(out, "-1").unwrap();
            continue;
        }
        let mut l = 0;
        let mut r = n;
        while r - l > 1 {
            let mid = (l + r) / 2;
            if eval(&p[..mid], x, a, y, b) >= m {
                r = mid;
            } else {
                l = mid;
            }
        }
        writeln!(out, "{}", r).unwrap();
    }
}
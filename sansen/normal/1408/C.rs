// ---------- begin scannner ----------
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
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let l: f64 = sc.next();
        let mut a: Vec<f64> = sc.next_vec(n);
        a.insert(0, 0f64);
        a.push(l);
        let a: Vec<f64> = a.windows(2).map(|a| a[1] - a[0]).collect();
        let mut ng = 0f64;
        let mut ok = l;
        for _ in 0..100 {
            let mid = (ok + ng) * 0.5;
            let mut sum = 0f64;
            let mut rem = mid;
            for (i, a) in a.iter().enumerate() {
                let v = (i + 1) as f64;
                let t = *a / v;
                if t < rem {
                    rem -= t;
                    sum += *a;
                } else {
                    sum += rem * v;
                    break;
                }
            }
            let mut rem = mid;
            for (i, a) in a.iter().rev().enumerate() {
                let v = (i + 1) as f64;
                let t = *a / v;
                if t < rem {
                    rem -= t;
                    sum += *a;
                } else {
                    sum += rem * v;
                    break;
                }
            }
            if sum > l {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        writeln!(out, "{:.7}", ok).ok();
    }
}
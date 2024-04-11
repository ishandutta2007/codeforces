// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std;
    use std::io::Read;
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error"),
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
    let q: usize = sc.next();
    let mut x = vec![];
    let mut sum = 0f64;
    let mut k = 0;
    for _ in 0..q {
        let op: usize = sc.next();
        if op == 1 {
            let v: f64 = sc.next();
            x.push(v);
        } else {
            let p = *x.last().unwrap();
            let mut ans = p - (sum + p) / (k + 1) as f64;
            while k < x.len() {
                let q = p - (sum + x[k] + p) / (k + 2) as f64;
                if ans < q {
                    ans = q;
                    sum += x[k];
                    k += 1;
                } else {
                    break;
                }
            }
            writeln!(out, "{:.8}", ans).ok();
        }
    }
}
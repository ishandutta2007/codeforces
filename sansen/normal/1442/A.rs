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
        let mut a: Vec<i64> = sc.next_vec(n);
        let mut b = vec![0; a.len() + 1];
        b[0] = a[0];
        for i in 1..n {
            b[i] = a[i] - a[i - 1];
        }
        b[n] = -a[n - 1];
        for i in 1..n {
            let v = b[i].abs();
            if b[i] < 0 {
                b[i] += v;
                b[0] -= v;
            } else {
                b[i] -= v;
                b[n] += v;
            }
        }
        let ans = if b[0] >= 0 && b[n] <= 0 {"YES"} else {"NO"};
        writeln!(out, "{}", ans).ok();
    }
}
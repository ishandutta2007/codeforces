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
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    for _ in 0..q {
        let n: usize = sc.next();
        let mut s: Vec<char> = sc.next_chars();
        let mut t: Vec<char> = sc.next_chars();
        let v = inversion(&mut s) ^ inversion(&mut t);
        let mut cond = false;
        for i in 1..n {
            if s[i] == s[i - 1] {
                cond = true;
            }
        }
        let ans = if s == t && (cond || v == 0) {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn inversion(a: &mut [char]) -> usize {
    if a.len() <= 1 {
        return 0;
    }
    let n = a.len();
    let m = n / 2;
    let mut ans = inversion(&mut a[..m]);
    ans ^= inversion(&mut a[m..]);
    let mut b = vec![];
    let mut i = 0;
    let mut j = m;
    while i < m && j < n {
        if a[i] <= a[j] {
            b.push(a[i]);
            i += 1;
        } else {
            b.push(a[j]);
            ans ^= m - i;
            j += 1;
        }
    }
    while i < m {
        b.push(a[i]);
        i += 1;
    }
    for k in 0..b.len() {
        a[k] = b[k];
    }
    ans & 1
}
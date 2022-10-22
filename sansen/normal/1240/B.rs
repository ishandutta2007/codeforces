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
    for _ in 0..q {
        let n: usize = sc.next();
        let mut a: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let mut b = a.clone();
        b.sort();
        b.dedup();
        let len = b.len();
        let mut left = vec![n; len];
        let mut right = vec![0; len];
        for (i, a) in a.iter_mut().enumerate() {
            *a = b.binary_search(&a).unwrap();
            left[*a] = std::cmp::min(left[*a], i);
            right[*a] = i;
        }
        let mut dp = vec![1; len];
        for i in 1..len {
            if right[i - 1] < left[i] {
                dp[i] = dp[i - 1] + 1;
            }
        }
        let ans = len - dp.into_iter().max().unwrap();
        writeln!(out, "{}", ans).ok();
    }
}
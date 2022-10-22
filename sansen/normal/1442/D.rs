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
    let n: usize = sc.next();
    let k: usize = sc.next();
    let mut a = vec![];
    for _ in 0..n {
        let t: usize = sc.next();
        let mut b: Vec<u64> = sc.next_vec(t);
        b.truncate(k);
        let sum = b.iter().sum::<u64>();
        a.push((sum, b));
    }
    let ans = calc(&a, &vec![0; k + 1]);
    writeln!(out, "{}", ans).ok();
}

fn calc(a: &[(u64, Vec<u64>)], dp: &Vec<u64>) -> u64 {
    if a.len() <= 1 {
        let mut ans = *dp.last().unwrap();
        let mut sum = 0;
        for (dp, a) in dp.iter().rev().skip(1).zip(a[0].1.iter()) {
            sum += *a;
            ans = std::cmp::max(ans, sum + *dp);
        }
        return ans;
    }
    let m = a.len() / 2;
    let (l, r) = a.split_at(m);
    let mut ans = 0;
    for (l, r) in [(l, r), (r, l)].iter() {
        let mut dp = dp.clone();
        for a in l.iter() {
            let b = a.1.len();
            let a = a.0;
            let w = dp.len();
            for i in (b..w).rev() {
                dp[i] = std::cmp::max(dp[i], dp[i - b] + a);
            }
        }
        ans = std::cmp::max(ans, calc(r, &dp));
    }
    ans
}
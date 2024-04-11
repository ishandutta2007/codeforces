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
        let n: i64 = sc.next();
        let m: usize = sc.next();
        let mut p = vec![(0i64, 0i64); m];
        let mut a = vec![];
        for (k, p) in p.iter_mut().enumerate() {
            p.0 = sc.next();
            p.1 = sc.next();
            a.push((p.0, 0, k));
            a.push((p.1, 1, k));
        }
        a.sort();
        let mut ans = 0i64;
        let mut cnt = 0;
        let mut sum = 0;
        let mut used = vec![false; m];
        for &(v, op, x) in a.iter().rev() {
            if op == 0 {
                used[x] = true;
                cnt += 1;
                if cnt <= n {
                    sum += v;
                }
                ans = std::cmp::max(ans, sum);
            } else {
                let val = if used[x] {
                    (n - cnt) * v + sum
                } else if cnt + 1 <= n {
                    (n - cnt - 1) * v + sum + p[x].0
                } else {
                    0
                };
                ans = std::cmp::max(ans, val);
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
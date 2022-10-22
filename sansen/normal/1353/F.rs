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
    let t: usize = sc.next();
    for _ in 0..t {
        let h: usize = sc.next();
        let w: usize = sc.next();
        let a: Vec<Vec<i64>> = (0..h).map(|_| (0..w).map(|_| sc.next()).collect()).collect();
        let mut z = vec![];
        for (i, a) in a.iter().enumerate() {
            for (j, &a) in a.iter().enumerate() {
                let d = (i + j) as i64;
                z.push(a - d);
            }
        }
        z.sort();
        z.dedup();
        let inf = 10i64.pow(18);
        let mut ans = inf;
        for s in z.iter() {
            let mut dp = vec![inf; w];
            let mut next = vec![inf; w];
            dp[0] = 0;
            for (i, a) in a.iter().enumerate() {
                next.clear();
                next.resize(w, inf);
                for (j, (&a, (next, dp))) in a.iter().zip(next.iter_mut().zip(dp.iter())).enumerate() {
                    let x = s + (i + j) as i64;
                    if x <= a {
                        *next = std::cmp::min(*next, *dp + a - x);
                    }
                }
                let mut prev = inf;
                for (j, (&a, next)) in a.iter().zip(next.iter_mut()).enumerate() {
                    let x = s + (i + j) as i64;
                    if x <= a {
                        *next = std::cmp::min(*next, prev + a - x);
                    }
                    prev =*next;
                }
                std::mem::swap(&mut dp, &mut next);
            }
            ans = std::cmp::min(ans, dp[w - 1]);
        }
        writeln!(out, "{}", ans).ok();
    }
}
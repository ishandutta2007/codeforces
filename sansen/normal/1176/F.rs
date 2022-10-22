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
use std::cmp::max;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let m = 10;
    let mut dp = vec![std::i64::MIN / 2; m];
    dp[0] = 0;
    for _ in 0..n {
        let k: usize = sc.next();
        let mut a = vec![vec![]; 4];
        for _ in 0..k {
            let c: usize = sc.next();
            let d: i64 = sc.next();
            a[c].push(d);
        }
        let mut way = vec![];
        let mut cnt = 0;
        for i in 1..=3 {
            a[i].sort();
            a[i].reverse();
            while a[i].len() > 3 / i {
                a[i].pop();
            }
            while let Some(v) = a[i].pop() {
                way.push((v, i, cnt));
                cnt += 1;
            }
        }
        let f = |a: (i64, usize), b: i64| if a.1 == m - 1 {(a.0 + 2 * b, 0)} else {(a.0 + b, a.1 + 1)};
        let mut next = dp.clone();
        for s in 0..m {
            let state = (dp[s], s);
            for &x in way.iter() {
                let (v, k) = f(state, x.0);
                next[k] = max(next[k], v);
                for &y in way.iter() {
                    if x == y || x.1 + y.1 > 3 {
                        continue;
                    }
                    let (v, k) = f(f(state, x.0), y.0);
                    next[k] = max(next[k], v);
                    for &z in way.iter() {
                        if z == x || z == y || x.1 + y.1 + z.1 > 3 {
                            continue;
                        }
                        let (v, k) = f(f(f(state, x.0), y.0), z.0);
                        next[k] = max(next[k], v);
                    }
                }
            }
        }
        dp = next;
    }
    let ans = dp.into_iter().max().unwrap();
    writeln!(out, "{}", ans).ok();
}
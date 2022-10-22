// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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
    let h: usize = sc.next();
    let w: usize = sc.next();
    let mut memo = vec![vec![(0, 0); w]; h];
    for memo in memo.iter_mut() {
        let k: usize = sc.next();
        for _ in 0..k {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            for p in memo[l..r].iter_mut() {
                *p = (l, r);
            }
        }
    }
    let mut dp = vec![vec![0; w + 1]; w + 1];
    for r in 1..=w {
        for l in (0..r).rev() {
            let mut v = 0;
            for k in l..r {
                let mut cnt = 0;
                for memo in memo.iter() {
                    let (x, y) = memo[k];
                    if l <= x && y <= r {
                        cnt += 1;
                    }
                }
                v.chmax(dp[l][k] + cnt * cnt + dp[k + 1][r]);
            }
            dp[l][r] = v;
        }
    }
    let ans = dp[0][w];
    writeln!(out, "{}", ans).ok();
}
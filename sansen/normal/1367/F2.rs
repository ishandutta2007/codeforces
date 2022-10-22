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

use std::cmp::*;
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
        let mut map = std::collections::BTreeMap::new();
        for i in 0..n {
            let v: u32 = sc.next();
            map.entry(v).or_insert(vec![]).push(i);
        }
        let mut a = map.into_iter().map(|a| a.1).collect::<Vec<_>>();
        let mut len = a.iter().map(|a| a.len()).max().unwrap();
        for a in a.windows(2) {
            let mut dp = [0; 2];
            let x = &a[0];
            let y = &a[1];
            let mut i = 0;
            let mut j = 0;
            while i < x.len() && j < y.len() {
                if x[i] < y[j] {
                    dp[0] += 1;
                    i += 1;
                } else {
                    dp[1] = max(dp[0], dp[1]) + 1;
                    j += 1;
                }
            }
            dp[1] = max(dp[0], dp[1]) + y.len() - j;
            dp[0] += x.len() - i;
            len = max(len, *dp.iter().max().unwrap());
        }
        for _ in 0..2 {
            let mut i = 0;
            while i + 1 < a.len() {
                let mut stack = a[i].clone();
                let mut j = i + 1;
                while let Some(&k) = stack.last() {
                    if k < a[j][0] {
                        break;
                    } else {
                        stack.pop();
                    }
                }
                let mut prev = *a[j].last().unwrap();
                let mut cnt = stack.len() + a[j].len();
                j += 1;
                while j < a.len() && prev < a[j][0] {
                    prev = *a[j].last().unwrap();
                    cnt += a[j].len();
                    j += 1;
                }
                if j < a.len() {
                    for a in a[j].iter().rev() {
                        if prev < *a {
                            cnt += 1;
                        } else {
                            break;
                        }
                    }
                }
                len = max(len, cnt);
                i = j - 1;
            }
            for a in a.iter_mut() {
                for a in a.iter_mut() {
                    *a = n - 1 - *a;
                }
                a.reverse();
            }
            a.reverse();
        }
        writeln!(out, "{}", n - len).ok();
    }
}
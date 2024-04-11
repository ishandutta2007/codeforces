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
        let mut s: Vec<Vec<char>> = (0..n).map(|_| sc.next_chars()).collect();
        s.sort_by_key(|s| s.len());
        let mut cnt = vec![0; 2];
        for s in &s {
            for &c in s {
                let k = c as usize - '0' as usize;
                cnt[k] += 1;
            }
        }
        let mut pair = cnt[0] / 2 + cnt[1] / 2;
        let mut one = cnt[0] % 2 + cnt[1] % 2;
        let mut ans = 0;
        for s in &s {
            let n = s.len();
            if n % 2 == 0 {
                if 2 * pair >= n {
                    ans += 1;
                    pair -= n / 2;
                }
            } else {
                if one > 0 && 2 * pair + 1 >= n {
                    one -= 1;
                    pair -= n / 2;
                    ans += 1;
                } else if one == 0 && 2 * pair >= n {
                    pair -= 1;
                    one += 2;
                    if 2 * pair + 1 >= n {
                        ans += 1;
                        pair -= n / 2;
                        one -= 1;
                    }
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
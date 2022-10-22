//---------- begin scanner ----------
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
//---------- end scanner ----------

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
        let a: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let mut dp = vec![vec![false; n]; 2];
        dp[0][0] = true;
        for i in 1..n {
            for j in 0..2 {
                if dp[j][i - 1] {
                    dp[j ^ 1][i] = true;
                    if a[i] == a[i - 1] {
                        dp[j][i] = true;
                    }
                }
            }
        }
        let mut last = if dp[0][n - 1] && a[0] == a[n - 1] {
            0
        } else if dp[1][n - 1] {
            1
        } else {
            2
        };
        let mut color = vec![];
        for i in (1..n).rev() {
            color.push(last);
            if a[i - 1] == a[i] {
                for j in 0..2 {
                    if dp[j][i - 1] {
                        last = j;
                        break;
                    }
                }
            } else {
                for j in 0..2 {
                    if dp[j][i - 1] && last != j {
                        last = j;
                        break;
                    }
                }
            }
        }
        color.push(last);
        let c = *color.iter().max().unwrap();
        let mut s = String::from(&format!("{}\n", c + 1));
        for c in color.into_iter().rev() {
            s.push_str(&format!("{} ", c + 1));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
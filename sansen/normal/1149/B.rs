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
    let n: usize = sc.next();
    let q: usize = sc.next();
    let s: Vec<char> = sc.next_chars();
    let s: Vec<usize> = s.into_iter().map(|c| convert(c)).collect();
    let f = 26;
    let mut next = vec![vec![n + 1; n + 2]; f];
    for i in (0..n).rev() {
        for j in 0..f {
            next[j][i] = next[j][i + 1];
        }
        next[s[i]][i] = i + 1;
    }
    let m = 250;
    let mut dp = vec![vec![vec![n + 1; m + 1]; m + 1]; m + 1];
    dp[0][0][0] = 0;
    let mut a = vec![vec![]; 3];
    for _ in 0..q {
        let op: Vec<char> = sc.next_chars();
        let v: usize = sc.next::<usize>() - 1;
        if op[0] == '+' {
            let c: usize = convert(sc.next_chars()[0]);
            a[v].push(c);
            let mut begin = [0, 0, 0];
            begin[v] = a[v].len();
            for i in begin[0]..=a[0].len() {
                for j in begin[1]..=a[1].len() {
                    for k in begin[2]..=a[2].len() {
                        let mut local = n + 1;
                        if i > 0 {
                            local = std::cmp::min(local, next[a[0][i - 1]][dp[i - 1][j][k]]);
                        }
                        if j > 0 {
                            local = std::cmp::min(local, next[a[1][j - 1]][dp[i][j - 1][k]]);
                        }
                        if k > 0 {
                            local = std::cmp::min(local, next[a[2][k - 1]][dp[i][j][k - 1]]);
                        }
                        dp[i][j][k] = local;
                    }
                }
            }
        } else {
            a[v].pop();
        }
        let ans = if dp[a[0].len()][a[1].len()][a[2].len()] <= n {"YES"} else {"NO"};
        writeln!(out, "{}", ans).ok();
    }
}

fn convert(c: char) -> usize {
    (c.to_digit(36).unwrap() - 10) as usize
}
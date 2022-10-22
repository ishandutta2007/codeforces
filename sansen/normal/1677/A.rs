// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let p: Vec<u32> = sc.next_vec(n);
        let mut dp = vec![vec![0; n + 1]; n + 1];
        for (i, a) in p.iter().enumerate() {
            for (j, b) in p.iter().enumerate().take(i) {
                if *b > *a {
                    dp[j][i] += 1u32;
                }
            }
        }
        for i in (0..n).rev() {
            for j in (0..n).rev() {
                dp[i][j] += dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
            }
        }
        let eval = |l: usize, r: usize, d: usize, u: usize| -> u64 {
            (dp[l][d] - dp[r][d] - dp[l][u] + dp[r][u]) as u64
        };
        let mut ans = 0u64;
        for (i, a) in p.iter().enumerate() {
            for (j, b) in p.iter().enumerate().take(i) {
                if *b < *a {
                    ans += eval(j + 1, i, i + 1, n);
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
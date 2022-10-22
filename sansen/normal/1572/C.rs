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
        let mut a = sc.next_vec::<usize>(n);
        a.dedup();
        let mut pos = vec![vec![]; n];
        for (i, a) in a.iter_mut().enumerate() {
            *a -= 1;
            pos[*a].push(i);
        }
        let n = a.len();
        let mut dp = vec![vec![0u16; n + 1]; n + 1];
        for (l, a) in a.iter().enumerate().rev() {
            let pos = &pos[*a];
            for r in (l + 1)..n {
                let mut val = 1 + dp[l + 1][r];
                for &x in pos.iter() {
                    if l < x && x <= r {
                        val = val.min(dp[l + 1][x - 1] + 1 + dp[x][r]);
                    }
                }
                dp[l][r] = val;
            }
        }
        writeln!(out, "{}", dp[0][n - 1]).ok();
    }
}
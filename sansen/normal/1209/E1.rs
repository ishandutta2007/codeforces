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
    let sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let out = std::io::BufWriter::new(out.lock());
    run(sc, out);
}

use std::cmp::max;

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let a: Vec<Vec<u32>> = (0..n).map(|_| (0..m).map(|_| sc.next()).collect()).collect();
        let a: Vec<Vec<u32>> = (0..m).map(|j| (0..n).map(|i| a[i][j]).collect()).collect();
        let mut b = a;
        b.sort_by_cached_key(|b| *b.iter().max().unwrap());
        b.reverse();
        if m > n {
            b.split_off(n);
        }
        let mut dp = vec![0; 1 << n];
        for b in b {
            let mut score = vec![0; 1 << n];
            let mut d = b;
            for _ in 0..n {
                for bit in 1..(1 << n) {
                    let mut sum = 0;
                    for k in 0..n {
                        if (bit >> k) & 1 == 1 {
                            sum += d[k];
                        }
                    }
                    score[bit] = max(score[bit], sum);
                }
                d.rotate_left(1);
            }
            for i in (1..(1 << n)).rev() {
                let mut j = i;
                while j > 0 {
                    dp[i] = max(dp[i], dp[i ^ j] + score[j]);
                    j = (j - 1) & i;
                }
            }
        }
        writeln!(out, "{}", dp[(1 << n) - 1]).unwrap();
    }
}
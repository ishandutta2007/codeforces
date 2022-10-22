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
    let n: usize = sc.next();
    let m: usize = sc.next();
    let d: usize = sc.next();
    let mut a = vec![];
    for i in 0..m {
        let k: usize = sc.next();
        let mut b = sc.next_vec::<usize>(k);
        b.sort();
        a.push(b);
    }
    let mut dp = vec![0; 1 << m];
    for i in 0..(1 << m) {
        let mut v = dp[i];
        loop {
            let mut update = false;
            for (j, a) in a.iter().enumerate() {
                if i >> j & 1 == 1 {
                    let x = a
                        .binary_search_by_key(&(v + d, 1), |p| (*p, 0))
                        .unwrap_err();
                    if x > 0 && a[x - 1] > v {
                        v = a[x - 1];
                        update = true;
                    }
                }
            }
            if !update {
                break;
            }
        }
        dp[i] = v;
        for j in 0..m {
            if i >> j & 1 == 0 {
                dp[i | (1 << j)] = v.max(dp[i | (1 << j)]);
            }
        }
    }
    let mut ans = m;
    for (i, dp) in dp.iter().enumerate() {
        if i > 0 && *dp + d > n {
            ans = ans.min(i.count_ones() as usize);
        }
    }
    println!("{}", ans);
}
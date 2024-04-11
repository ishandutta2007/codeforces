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
    let m = 10usize.pow(7);
    let mut factor = (0..=m).collect::<Vec<_>>();
    for i in (2..=m).take_while(|p| p.pow(2) <= m) {
        if i == factor[i] {
            for j in i..=(m / i) {
                factor[i * j] = i;
            }
        }
    }
    let normalize = |mut a: usize| -> usize {
        let mut res = 1;
        while a > 1 {
            let p = factor[a];
            let mut cnt = 0;
            while a % p == 0 {
                a /= p;
                cnt += 1;
            }
            if cnt & 1 == 1 {
                res *= p;
            }
        }
        res
    };
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let k: usize = sc.next();
        let mut a = vec![0; n];
        for a in a.iter_mut() {
            *a = normalize(sc.next());
        }
        let mut z = a.clone();
        z.sort();
        z.dedup();
        for a in a.iter_mut() {
            *a = z.binary_search(a).unwrap();
        }
        let mut right = vec![];
        for i in 0..=k {
            let mut cnt = vec![0; z.len()];
            let mut rem = i;
            let mut r = 0;
            let mut next = vec![0; n];
            for (j, next) in next.iter_mut().enumerate() {
                while r < n && (cnt[a[r]] == 0 || rem > 0) {
                    let po = &mut cnt[a[r]];
                    if *po > 0 {
                        rem -= 1;
                    }
                    *po += 1;
                    r += 1;
                }
                *next = r;
                let po = &mut cnt[a[j]];
                if *po > 1 {
                    rem += 1;
                }
                *po -= 1;
            }
            right.push(next);
        }
        let inf = n + 1;
        let mut dp = vec![vec![inf; n + 1]; k + 1];
        dp[0][0] = 0;
        let mut ans = inf;
        for i in 0..=k {
            for j in 0..n {
                let v = dp[i][j];
                if v == inf {
                    continue;
                }
                for (r, dp) in right.iter().zip(dp[i..].iter_mut()) {
                    let po = &mut dp[r[j]];
                    *po = (v + 1).min(*po);
                }
            }
            ans = ans.min(dp[i][n]);
        }
        writeln!(out, "{}", ans).ok();
    }
}
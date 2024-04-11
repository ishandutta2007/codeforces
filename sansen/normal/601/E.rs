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
    let w: usize = sc.next();
    let mut p: Vec<(u64, usize)> = (0..n).map(|_| {
        let v: u64 = sc.next();
        let w: usize = sc.next();
        (v, w)
    }).collect::<Vec<_>>();
    let inf = 1000000;
    let mut range = vec![(0, inf); n];
    let q: usize = sc.next();
    let mut len = 0;
    for _ in 0..q {
        let op: u8 = sc.next();
        if op == 1 {
            let v: u64 = sc.next();
            let w: usize = sc.next();
            p.push((v, w));
            range.push((len, inf));
        } else if op == 2 {
            let x = sc.next::<usize>() - 1;
            range[x].1 = len;
        } else {
            len += 1;
        }
    }
    for range in range.iter_mut() {
        if range.1 == inf {
            range.1 = len;
        }
    }
    let mut item = vec![];
    for i in 0..p.len() {
        let (v, w) = p[i];
        let (l, r) = range[i];
        if l < r {
            item.push((l, r, v, w));
        }
    }
    let mut ans = vec![0; len];
    dfs(0, len, &mut ans, item, vec![0; w + 1]);
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn dfs(l: usize, r: usize, ans: &mut [u64], item: Vec<(usize, usize, u64, usize)>, mut dp: Vec<u64>) {
    let m = (l + r) / 2;
    let mut left = vec![];
    let mut right = vec![];
    for (s, t, v, w) in item {
        if s <= l && r <= t {
            for i in (w..dp.len()).rev() {
                dp[i] = dp[i].max(dp[i - w] + v);
            }
            continue;
        }
        if s < m {
            left.push((s, t, v, w));
        }
        if m < t {
            right.push((s, t, v, w));
        }
    }
    if r - l > 1 {
        dfs(l, m, ans, left, dp.clone());
        dfs(m, r, ans, right, dp.clone());
    } else {
        let q = 1_000_000_007u64;
        let p = 10_000_000 + 19;
        let mut val = 0;
        for i in (1..dp.len()).rev() {
            val = (p * val + dp[i]) % q;
        }
        ans[l] = val;
    }
}
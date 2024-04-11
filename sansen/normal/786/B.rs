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

fn run(mut sc: scanner::Scanner, mut out: std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let q: usize = sc.next();
    let s: usize = sc.next::<usize>() - 1;
    let mut k = 1;
    while k < n {
        k *= 2;
    }
    let mut g = vec![vec![]; n + 2 * 2 * k];
    for i in 0..n {
        g[i].push((n + k + i, 0));
        g[n + 2 * k + k + i].push((i, 0));
    }
    for i in 1..k {
        g[n + 2 * i].push((n + i, 0));
        g[n + 2 * i + 1].push((n + i, 0));
        g[n + 2 * k + i].push((n + 2 * k + 2 * i, 0));
        g[n + 2 * k + i].push((n + 2 * k + 2 * i + 1, 0));
    }
    for _ in 0..q {
        let t: usize = sc.next();
        let v = sc.next::<usize>() - 1;
        if t == 1 {
            let u = sc.next::<usize>() - 1;
            let w: i64 = sc.next();
            g[v].push((u, w));
        } else if t == 2 {
            let mut l: usize = sc.next::<usize>() - 1;
            let mut r: usize = sc.next::<usize>();
            let w: i64 = sc.next();
            l += k;
            r += k;
            while l < r {
                if l & 1 == 1 {
                    g[v].push((n + 2 * k + l, w));
                    l += 1;
                }
                if r & 1 == 1 {
                    r -= 1;
                    g[v].push((n + 2 * k + r, w));
                }
                l >>= 1;
                r >>= 1;
            }
        } else {
            let mut l: usize = sc.next::<usize>() - 1;
            let mut r: usize = sc.next::<usize>();
            let w: i64 = sc.next();
            l += k;
            r += k;
            while l < r {
                if l & 1 == 1 {
                    g[n + l].push((v, w));
                    l += 1;
                }
                if r & 1 == 1 {
                    r -= 1;
                    g[n + r].push((v, w));
                }
                l >>= 1;
                r >>= 1;
            }
        }
    }
    let inf = 1_000_000_000_000_000 + 1;
    let mut dp = vec![inf; n + 4 * k];
    dp[s] = 0;
    let mut h = std::collections::BinaryHeap::new();
    h.push((0, s));
    while let Some((d, v)) = h.pop() {
        let d = -d;
        if dp[v] < d {
            continue;
        }
        for &(u, w) in &g[v] {
            let c = d + w;
            if c < dp[u] {
                dp[u] = c;
                h.push((-c, u));
            }
        }
    }
    for i in 0..n {
        write!(out, "{}{}", if dp[i] == inf {-1} else {dp[i]},if i == n - 1 {'\n'} else {' '}).unwrap();
    }
}
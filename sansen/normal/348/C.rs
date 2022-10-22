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
    let q: usize = sc.next();
    let a: Vec<i64> = sc.next_vec(n);
    let mut g = vec![];
    for _ in 0..m {
        let len = sc.next::<usize>();
        let mut s = vec![];
        let mut sum = 0;
        for _ in 0..len {
            let x = sc.next::<usize>() - 1;
            s.push(x);
            sum += a[x];
        }
        s.sort();
        g.push((s, sum));
    }
    let batch = 300;
    let mut large = vec![];
    let mut index = vec![m + 1; m];
    for (i, (s, _)) in g.iter().enumerate() {
        if s.len() <= batch {
            continue;
        }
        index[i] = large.len();
        let mut cnt = vec![0i64; n];
        for s in s.iter() {
            cnt[*s] += 1;
        }
        let mut p = vec![0i64; n];
        for (p, g) in p.iter_mut().zip(&g) {
            for &u in g.0.iter() {
                *p += cnt[u];
            }
        }
        large.push((i, p));
    }
    let mut a = vec![0; n];
    let mut memo = vec![0; m];
    let mut small_large = vec![0; large.len()];
    let mut large_large = vec![0; large.len()];
    for _ in 0..q {
        let op = sc.next::<String>();
        if op == "?" {
            let x = sc.next::<usize>() - 1;
            let mut ans = g[x].1;
            if g[x].0.len() <= batch {
                for &u in g[x].0.iter() {
                    ans += a[u];
                }
                for &(y, ref p) in large.iter() {
                    ans += p[x] * memo[y]
                }
            } else {
                ans += small_large[index[x]];
                ans += large_large[index[x]];
            }
            writeln!(out, "{}", ans).ok();
        } else {
            let x = sc.next::<usize>() - 1;
            let v = sc.next::<i64>();
            if g[x].0.len() <= batch {
                for &u in g[x].0.iter() {
                    a[u] += v;
                }
                for (dp, large) in small_large.iter_mut().zip(&large) {
                    *dp += large.1[x] * v;
                }
            } else {
                memo[x] += v;
                for &(y, ref p) in large.iter() {
                    large_large[index[y]] += p[x] * v;
                }
            }
        }
    }
}
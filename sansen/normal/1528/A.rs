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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut p = vec![(0i64, 0i64); n];
        for p in p.iter_mut() {
            p.0 = sc.next();
            p.1 = sc.next();
        }
        let mut g = vec![vec![]; n];
        for _ in 1..n {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            g[a].push(b);
            g[b].push(a);
        }
        let mut topo = vec![0];
        for i in 0..n {
            let v = topo[i];
            for u in g[v].clone() {
                let x = g[u].iter().position(|p| *p == v).unwrap();
                g[u].remove(x);
                topo.push(u);
            }
        }
        let mut dp = vec![(0i64, 0i64); n];
        for &v in topo.iter().rev() {
            let (l, r) = p[v];
            let mut a = 0i64;
            let mut b = 0i64;
            for &u in g[v].iter() {
                let (s, t) = p[u];
                let (x, y) = dp[u];
                a += ((s - l).abs() + x).max((t - l).abs() + y);
                b += ((s - r).abs() + x).max((t - r).abs() + y);
            }
            dp[v] = (a, b);
        }
        let ans = dp[0].0.max(dp[0].1);
        writeln!(out, "{}", ans).ok();
    }
}
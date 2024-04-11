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
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: i64 = sc.next();
        let mut p = vec![0i64; n];
        let mut h = vec![0i64; n];
        for p in p.iter_mut().chain(h.iter_mut()) {
            *p = sc.next();
        }
        let mut g = vec![vec![]; n];
        for _ in 1..n {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            g[a].push(b);
            g[b].push(a);
        }
        let mut q = vec![(0, 0)];
        for i in 0..n {
            let (v, p) = q[i];
            if let Some(k) = g[v].iter().position(|u| *u == p) {
                g[v].remove(k);
            }
            for &u in g[v].iter() {
                q.push((u, v));
            }
        }
        let mut happy = vec![0; n];
        let mut ans = "YES";
        for &(v, _) in q.iter().rev() {
            for &u in g[v].iter() {
                happy[v] += happy[u];
                p[v] += p[u];
            }
            if h[v].abs() > p[v] {
                ans = "NO";
            }
            if (p[v] - h[v]) % 2 != 0 {
                ans = "NO";
            }
            if happy[v] - (p[v] - happy[v]) > h[v] {
                ans = "NO";
            }
            happy[v] = (h[v] + p[v]) / 2;
        }
        assert!(p[0] == m);
        writeln!(out, "{}", ans).ok();
    }
}
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
        let sup = 200_000 + 2;
        let mut a = vec![(0, sup)];
        let mut z = vec![0, sup, std::usize::MAX];
        for _ in 0..n {
            let l: usize = sc.next();
            let r: usize = sc.next();
            a.push((l, r + 1));
            z.push(l);
            z.push(r + 1);
        }
        z.sort();
        z.dedup();
        for a in a.iter_mut() {
            a.0 = z.binary_search(&a.0).unwrap();
            a.1 = z.binary_search(&a.1).unwrap();
        }
        a.sort_by_key(|p| (p.0, !p.1));
        let mut dp = vec![0; a.len()];
        let mut g = vec![vec![]; z.len()];
        for (i, &(l, r)) in a.iter().enumerate().rev() {
            for (&v, &(x, y)) in dp.iter().zip(a.iter()).skip(i + 1) {
                if l <= x && y <= r {
                    g[x].push((y, v));
                }
            }
            let mut b = vec![0; z.len()];
            for i in l..r {
                b[i + 1] = std::cmp::max(b[i], b[i + 1]);
                for &(u, v) in g[i].iter() {
                    b[u] = std::cmp::max(b[u], b[i] + v);
                }
            }
            dp[i] = b[r] + 1;
            for g in g.iter_mut() {
                g.clear();
            }
        }
        let ans = dp[0] - 1;
        writeln!(out, "{}", ans).ok();
    }
}
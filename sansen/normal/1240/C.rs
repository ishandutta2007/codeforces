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
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;
use std::cmp::max;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    for _ in 0..q {
        let n: usize = sc.next();
        let k: usize = sc.next();
        let mut g = vec![vec![]; n];
        for _ in 1..n {
            let a: usize = sc.next::<usize>() - 1;
            let b: usize = sc.next::<usize>() - 1;
            let c: i64 = sc.next();
            g[a].push((b, c));
            g[b].push((a, c));
        }
        let mut q = vec![];
        let mut stack = vec![(0, 0)];
        while let Some((v, p)) = stack.pop() {
            q.push(v);
            for i in 0..g[v].len() {
                if g[v][i].0 == p {
                    g[v].remove(i);
                    break;
                }
            }
            for &(u, _) in g[v].iter() {
                stack.push((u, v));
            }
        }
        let mut dp0 = vec![0i64; n];
        let mut dp1 = vec![0i64; n];
        for &v in q.iter().rev() {
            let mut a = vec![];
            let mut sum = 0;
            for &(u, c) in g[v].iter() {
                sum += dp0[u];
                let val = dp1[u] + c - dp0[u];
                if val > 0 {
                    a.push(val);
                }
            }
            if a.len() < k {
                dp1[v] = sum + a.iter().fold(0, |s, a| s + *a);
                dp0[v] = dp1[v];
            } else {
                a.sort();
                a.reverse();
                a.resize(k, 0);
                let add = a.iter().fold(0, |s, a| s + *a);
                dp0[v] = sum + add;
                dp1[v] = sum + add - *a.last().unwrap();
            }
        }
        let ans = max(dp0[0], dp1[0]);
        writeln!(out, "{}", ans).ok();
    }
}
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
        let m: usize = sc.next();
        let a = sc.next::<usize>() - 1;
        let b = sc.next::<usize>() - 1;
        let c = sc.next::<usize>() - 1;
        let mut p: Vec<u64> = (0..m).map(|_| sc.next()).collect();
        let mut g = vec![vec![]; n];
        for _ in 0..m {
            let x = sc.next::<usize>() - 1;
            let y = sc.next::<usize>() - 1;
            g[x].push(y);
            g[y].push(x);
        }
        let from_a = bfs(&g, a);
        let from_b = bfs(&g, b);
        let from_c = bfs(&g, c);
        p.sort();
        p.reverse();
        p.push(0);
        for i in (0..m).rev() {
            p[i] += p[i + 1];
        }
        let mut ans = std::u64::MAX;
        for r in 0..n {
            let x = from_a[r];
            let y = from_b[r];
            let z = from_c[r];
            if y + x + z <= m {
                ans = std::cmp::min(ans, 2 * p[m - y] + p[m - x - y - z] - p[m - y]);
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn bfs(g: &[Vec<usize>], a: usize) -> Vec<usize> {
    let mut dp = vec![1_000_000; g.len()];
    dp[a] = 0;
    let mut q = std::collections::VecDeque::new();
    q.push_back(a);
    while let Some(v) = q.pop_front() {
        for &u in g[v].iter() {
            let d = dp[v] + 1;
            if d < dp[u] {
                dp[u] = d;
                q.push_back(u);
            }
        }
    }
    dp
}
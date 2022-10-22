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
        let mut g = vec![vec![]; 2 * n];
        for _ in 1..(2 * n) {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            let c: u64 = sc.next();
            g[a].push((b, c));
            g[b].push((a, c));
        }
        let mut parent = vec![0; 2 * n];
        let mut p_d = vec![0; 2 * n];
        let mut stack = vec![0];
        let mut q = vec![];
        while let Some(v) = stack.pop() {
            q.push(v);
            for &(u, c) in g[v].iter() {
                if u == parent[v] {
                    p_d[v] = c;
                } else {
                    parent[u] = v;
                    stack.push(u);
                }
            }
        }
        let mut size = vec![1; 2 * n];
        let mut min = 0;
        let mut max = 0;
        for &v in q.iter().rev() {
            for &(u, _) in g[v].iter() {
                if u != parent[v] {
                    size[v] += size[u];
                }
            }
            if size[v] % 2 != 0 {
                min += p_d[v];
            }
            max += std::cmp::min(size[v], 2 * n - size[v]) as u64 * p_d[v];
        }
        writeln!(out, "{} {}", min, max).ok();
    }
}
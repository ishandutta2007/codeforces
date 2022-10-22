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
        let a: usize = sc.next::<usize>() - 1;
        let b: usize = sc.next::<usize>() - 1;
        let mut g = vec![vec![]; n];
        for _ in 0..m {
            let x: usize = sc.next::<usize>() - 1;
            let y: usize = sc.next::<usize>() - 1;
            g[x].push(y);
            g[y].push(x);
        }
        let mut t = vec![0; n];
        let mut stack = vec![a];
        while let Some(v) = stack.pop() {
            t[v] |= 1;
            for &u in &g[v] {
                if u != b && (t[u] & 1) == 0 {
                    t[u] |= 1;
                    stack.push(u);
                }
            }
        }
        let mut stack = vec![b];
        while let Some(v) = stack.pop() {
            t[v] |= 2;
            for &u in &g[v] {
                if u != a && (t[u] & 2) == 0 {
                    t[u] |= 2;
                    stack.push(u);
                }
            }
        }
        let mut cnt = vec![0u64; 4];
        for t in t {
            cnt[t] += 1;
        }
        let ans = (cnt[1] - 1) * (cnt[2] - 1);
        writeln!(out, "{}", ans).ok();
    }
}
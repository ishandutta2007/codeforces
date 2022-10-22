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
        let m: usize = sc.next();
        let mut edge = vec![];
        let mut g = vec![vec![]; n];
        let mut deg = vec![0; n];
        for _ in 0..m {
            let op: u8 = sc.next();
            let s = sc.next::<usize>() - 1;
            let t = sc.next::<usize>() - 1;
            if op == 1 {
                g[s].push(t);
                deg[t] += 1;
            } else {
                edge.push((s, t));
            }
        }
        let mut q = std::collections::VecDeque::new();
        for i in 0..n {
            if deg[i] == 0 {
                q.push_back(i);
            }
        }
        let mut topo = vec![None; n];
        let mut id = 0;
        while let Some(v) = q.pop_front() {
            topo[v] = Some(id);
            id += 1;
            for &u in g[v].iter() {
                deg[u] -= 1;
                if deg[u] == 0 {
                    q.push_back(u);
                }
            }
        }
        if deg.iter().any(|d| *d > 0) {
            writeln!(out, "NO").ok();
            continue;
        }
        let mut ans = vec![];
        for (a, b) in edge {
            let x = topo[a].unwrap();
            let y = topo[b].unwrap();
            if x < y {
                ans.push((a, b));
            } else {
                ans.push((b, a));
            }
        }
        writeln!(out, "YES").ok();
        for (a, b) in ans {
            writeln!(out, "{} {}", a + 1, b + 1).ok();
        }
        for s in 0..n {
            for t in g[s].iter() {
                writeln!(out, "{} {}", s + 1, t + 1).ok();
            }
        }

    }
}
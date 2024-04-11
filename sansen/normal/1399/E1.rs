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
        let s: i64 = sc.next();
        let mut g = vec![vec![]; n];
        for _ in 1..n {
            let mut a: usize = sc.next();
            let mut b: usize = sc.next();
            let w: i64 = sc.next();
            a -= 1;
            b -= 1;
            g[a].push((b, w));
            g[b].push((a, w));
        }
        let mut q = vec![(0, 0)];
        for i in 0..n {
            let (v, p) = q[i];
            let g = &mut g[v];
            if let Some(k) = g.iter().position(|e| e.0 == p) {
                g.remove(k);
            }
            for &(u, _) in g.iter() {
                q.push((u, v));
            }
        }
        let mut size = vec![0; n];
        let mut a = vec![];
        for &(v, _) in q.iter().rev() {
            if g[v].is_empty() {
                size[v] = 1;
                continue;
            }
            for &(u, w) in g[v].iter() {
                let mut w = w;
                let mut b = vec![];
                while w > 0 {
                    b.push(w);
                    w /= 2;
                }
                b.push(0);
                for b in b.windows(2) {
                    a.push((b[0] - b[1]) * size[u]);
                }
                size[v] += size[u];
            }
        }
        a.sort();
        let mut i = 0;
        let mut sum = 0;
        while i < a.len() && sum + a[i] <= s {
            sum += a[i];
            i += 1;
        }
        writeln!(out, "{}", a.len() - i).ok();
    }
}
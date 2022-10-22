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
        let mut g = vec![vec![]; n];
        for _ in 1..n {
            let a: usize = sc.next();
            let b: usize = sc.next();
            g[a].push(b);
            g[b].push(a);
        }
        let mut topo = vec![0];
        let mut parent = vec![n; n];
        for i in 0..n {
            let v = topo[i];
            for u in g[v].clone() {
                let x = g[u].iter().position(|p| *p == v).unwrap();
                g[u].remove(x);
                parent[u] = v;
                topo.push(u);
            }
        }
        let mut size = vec![1; n];
        for &v in topo.iter().rev() {
            for &u in g[v].iter() {
                size[v] += size[u];
            }
        }
        let mut cnt = vec![0; n + 1];
        let m = n as u64;
        cnt[0] = m * (m - 1) / 2;
        cnt[1] = cnt[0];
        for &u in g[0].iter() {
            cnt[1] -= size[u] * (size[u] - 1) / 2;
        }
        let mut s = 0;
        let mut t = 0;
        let mut f = n;
        let mut path = vec![false; n];
        path[0] = true;
        for v in 1..n {
            if !path[v] {
                let mut pos = v;
                while !path[pos] {
                    path[pos] = true;
                    if v == 1 {
                        f = pos;
                    }
                    pos = parent[pos];
                }
                if pos == t {
                    t = v;
                } else if pos == s {
                    s = v;
                } else {
                    break;
                }
            }
            let a = if s == 0 {
                m - size[f]
            } else {
                size[s]
            };
            let b = size[t];
            cnt[v + 1] = a * b;
        }
        for i in 1..=n {
            cnt[i - 1] -= cnt[i];
        }
        let mut s = String::new();
        for c in cnt {
            s.push_str(&format!("{} ", c));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
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
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let k: usize = sc.next();
        let x: Vec<usize> = (0..k).map(|_| sc.next::<usize>() - 1).collect::<Vec<_>>();
        let mut g = vec![vec![]; n];
        for _ in 1..n {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            g[a].push(b);
            g[b].push(a);
        }
        let mut parent = vec![0; n];
        let mut depth = vec![0; n];
        let mut dfs = vec![0];
        while let Some(v) = dfs.pop() {
            for u in g[v].clone() {
                g[u].retain(|p| *p != v);
                parent[u] = v;
                depth[u] = depth[v] + 1;
                dfs.push(u);
            }
        }
        let mut table = vec![];
        while parent.iter().any(|p| *p != 0) {
            let mut next = vec![0; n];
            for (next, p) in next.iter_mut().zip(&parent) {
                *next = parent[*p];
            }
            table.push(parent);
            parent = next;
        }
        let mut ban = vec![false; n];
        for mut x in x {
            let d = depth[x] / 2;
            for (i, p) in table.iter().enumerate() {
                if d >> i & 1 == 1 {
                    x = p[x];
                }
            }
            ban[x] = true;
        }
        let mut dfs = vec![0];
        let mut elem = false;
        while let Some(v) = dfs.pop() {
            elem |= g[v].is_empty();
            for &u in g[v].iter() {
                if ban[u] {
                } else {
                    dfs.push(u);
                }
            }
        }
        let ans = if !elem {
            "NO"
        } else {
            "YES"
        };
        writeln!(out, "{}", ans).ok();
    }
}
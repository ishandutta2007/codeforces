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
        let mut g = vec![vec![]; n];
        for _ in 1..n {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            g[a].push(b);
            g[b].push(a);
        }
        let mut depth = vec![0; n];
        let mut vertex = vec![vec![]; 2];
        let mut topo = vec![0];
        for i in 0..n {
            let v = topo[i];
            vertex[depth[v]].push(v);
            for u in g[v].clone() {
                g[u].retain(|p| *p != v);
                depth[u] = depth[v] ^ 1;
                topo.push(u);
            }
        }
        let mut p = vec![vec![]; 18];
        for i in 1..=n {
            let mut k = 0;
            while i >> k > 1 {
                k += 1;
            }
            p[k].push(i);
        }
        p.sort_by_key(|p| p.len());
        let mut ans = vec![0; n];
        for p in p.drain(..).rev() {
            let len = p.len();
            let pos = (vertex[0].len() <= vertex[1].len()) as usize;
            for (v, p) in vertex[pos].drain(..len).zip(p) {
                ans[v] = p;
            }
        }
        let s = ans.iter().map(|a| a.to_string()).collect::<Vec<_>>().join(" ");
        writeln!(out, "{}", s).ok();
    }
}
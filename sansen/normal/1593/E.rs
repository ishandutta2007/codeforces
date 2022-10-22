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
        let mut g = vec![vec![]; n];
        let mut deg = vec![0; n];
        for _ in 1..n {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            deg[a] += 1;
            deg[b] += 1;
            g[a].push(b);
            g[b].push(a);
        }
        let mut dfs = vec![];
        for i in 0..n {
            if deg[i] <= 1 {
                dfs.push(i);
            }
        }
        let mut ban = vec![false; n];
        for _ in 0..k {
            if dfs.is_empty() {
                break;
            }
            let mut next = vec![];
            for v in dfs {
                ban[v] = true;
                for &u in g[v].iter() {
                    deg[u] -= 1;
                    if deg[u] == 1 {
                        next.push(u);
                    }
                }
            }
            dfs = next;
        }
        let ans = ban.into_iter().filter(|p| !*p).count();
        writeln!(out, "{}", ans).ok();
    }
}
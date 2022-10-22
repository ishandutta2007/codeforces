mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
}
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
        let p: usize = sc.next();
        let n: usize = 1 << p;
        let mut g = vec![vec![]; n];
        for i in 0..(n - 1) {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            g[a].push((b, i));
            g[b].push((a, i));
        }
        let mut vertex = vec![0; n];
        let mut edge = vec![0; n - 1];
        vertex[0] = n;
        let mut val = 1;
        let mut dfs = vec![(0, 1)];
        while let Some((v, k)) = dfs.pop() {
            for (u, pos) in g[v].clone() {
                g[u].retain(|p| p.0 != v);
                dfs.push((u, k ^ 1));
                edge[pos] = val;
                vertex[u] = val;
                if k == 1 {
                    edge[pos] ^= 1 << p;
                } else {
                    vertex[u] ^= 1 << p;
                }
                val += 1;
            }
        }
        use util::*;
        writeln!(out, "1").ok();
        writeln!(out, "{}", vertex.iter().join(" ")).ok();
        writeln!(out, "{}", edge.iter().join(" ")).ok();
    }
}
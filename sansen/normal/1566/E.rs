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
        let mut topo = vec![0];
        for i in 0..n {
            let v = topo[i];
            topo.extend(&g[v]);
            for u in g[v].clone() {
                let x = g[u].iter().position(|p| *p == v).unwrap();
                g[u].remove(x);
            }
        }
        let mut a = vec![];
        let mut leaf = vec![false; n];
        for &v in topo[1..].iter().rev() {
            let c = g[v].iter().filter(|u| leaf[**u]).count();
            if c == 0 {
                leaf[v] = true;
            } else {
                a.push(c);
                for &u in g[v].iter() {
                    leaf[u] = false;
                }
            }
        }
        let mut ans = leaf.iter().filter(|l| **l).count();
        if ans == 0 {
            ans += 1;
        }
        if a.len() > 0 {
            ans += a.iter().sum::<usize>();
            ans -= a.len();
        }
        writeln!(out, "{}", ans).ok();
    }
}
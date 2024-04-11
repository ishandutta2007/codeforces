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
        let mut child = vec![vec![]; n];
        let mut deg = vec![0; n];
        for i in 0..n {
            let k: usize = sc.next();
            deg[i] = k;
            for _ in 0..k {
                let u: usize = sc.next::<usize>() - 1;
                child[u].push(i);
            }
        }
        let mut set = std::collections::BTreeSet::new();
        for i in 0..n {
            if deg[i] == 0 {
                set.insert(i);
            }
        }
        let mut ans = 1;
        let mut last = 0;
        while set.len() > 0 {
            let v = if let Some(&v) = set.range(last..).next() {
                v
            } else {
                *set.iter().next().unwrap()
            };
            set.remove(&v);
            if last > v {
                ans += 1;
            }
            last = v;
            for &u in child[v].iter() {
                deg[u] -= 1;
                if deg[u] == 0 {
                    set.insert(u);
                }
            }
        }
        if deg.iter().any(|d| *d > 0) {
            writeln!(out, "-1").ok();
        } else {
            writeln!(out, "{}", ans).ok();
        }
    }
}
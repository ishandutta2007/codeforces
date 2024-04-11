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
        let mut parent: Vec<usize> = sc.next_vec(n);
        let mut child = vec![vec![]; n];
        for (i, p) in parent.iter_mut().enumerate() {
            *p -= 1;
            if *p != i {
                child[*p].push(i);
            }
        }
        let root = parent.iter().enumerate().position(|p| p.0 == *p.1).unwrap();
        let mut ord: Vec<usize> = sc.next_vec(n);
        ord.iter_mut().for_each(|p| *p -= 1);
        let mut set = std::collections::BTreeSet::new();
        let mut depth = vec![0usize; n];
        let mut ok = true;
        set.insert(root);
        for (i, v) in ord.iter().enumerate() {
            ok &= set.remove(v);
            depth[*v] = i;
            for c in child[*v].iter() {
                set.insert(*c);
            }
        }
        if ok {
            for i in 0..n {
                if i > 0 {
                    write!(out, " ").ok();
                }
                let d = depth[i] - depth[parent[i]];
                write!(out, "{}", d).ok();
            }
            writeln!(out).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}
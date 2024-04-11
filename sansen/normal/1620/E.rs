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
    let q: usize = sc.next();
    let m = 500_000;
    let mut index = vec![vec![]; m + 1];
    let mut x = 0usize;
    for _ in 0..q {
        let op = sc.next::<u8>();
        if op == 1 {
            let v: usize = sc.next();
            index[v].push(x);
            x += 1;
        } else {
            let a: usize = sc.next();
            let b: usize = sc.next();
            if a != b {
                let mut p = std::mem::take(&mut index[a]);
                let mut q = std::mem::take(&mut index[b]);
                if p.len() <= q.len() {
                    q.append(&mut p);
                } else {
                    p.append(&mut q);
                    std::mem::swap(&mut p, &mut q);
                }
                index[b] = q;
                index[a] = p;
            }
        }
    }
    let mut ans = vec![0; x];
    for (i, x) in index.iter().enumerate() {
        for x in x.iter() {
            ans[*x] = i;
        }
    }
    for (i, ans) in ans.iter().enumerate() {
        if i > 0 {
            write!(out, " ").ok();
        }
        write!(out, "{}", *ans).ok();
    }
    writeln!(out).ok();
}
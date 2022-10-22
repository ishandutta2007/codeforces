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
        let mut a = vec![(0, 0); n];
        for (i, a) in a.iter_mut().enumerate() {
            a.0 = sc.next::<i32>();
            a.1 = i;
        }
        let mut depth = vec![0; n];
        let mut dfs = vec![(0, n, 0)];
        while let Some((l, r, d)) = dfs.pop() {
            if r <= l {
                continue;
            }
            let p = *a[l..r].iter().max().unwrap();
            depth[p.1] = d;
            dfs.push((l, p.1, d + 1));
            dfs.push((p.1 + 1, r, d + 1));
        }
        let mut s = String::new();
        for d in depth {
            s.push_str(&format!("{} ", d));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
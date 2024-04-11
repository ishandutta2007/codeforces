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
        let mut p = vec![(0u32, 0u32); n];
        for p in p.iter_mut() {
            p.0 = sc.next();
        }
        for p in p.iter_mut() {
            p.1 = sc.next();
        }
        let mut ord = (0..n).collect::<Vec<_>>();
        ord.sort_by_key(|v| p[*v]);
        if !ord.windows(2).all(|v| p[v[0]].1 <= p[v[1]].1) {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut p = (0..n).collect::<Vec<_>>();
        let mut ans = vec![];
        for i in 0..n {
            if p[i] != ord[i] {
                let k = (i..n).find(|k| p[*k] == ord[i]).unwrap();
                ans.push((i, k));
                p.swap(i, k);
            }
        }
        writeln!(out, "{}", ans.len()).ok();
        for (a, b) in ans {
            writeln!(out, "{} {}", a + 1, b + 1).ok();
        }
    }
}
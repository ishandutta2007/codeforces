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
        let m: usize = sc.next();
        let mut b: Vec<Vec<u64>> = (0..n).map(|_| sc.next_vec(m)).collect();
        for b in b.iter_mut() {
            b.sort();
            b.reverse();
        }
        let mut ans = vec![vec![0; m]; n];
        let inf = 1000000000 + 1;
        for i in 0..m {
            let mut x = (inf, 0);
            for j in 0..n {
                if let Some(b) = b[j].last() {
                    if *b < x.0 {
                        x = (*b, j);
                    }
                }
            }
            b[x.1].pop();
            ans[x.1][i] = x.0;
        }
        for (ans, b) in ans.iter_mut().zip(b.iter_mut()) {
            for a in ans.iter_mut() {
                if *a == 0 {
                    *a = b.pop().unwrap();
                }
            }
        }
        let mut s = String::new();
        for a in ans {
            for a in a {
                s.push_str(&format!("{} ", a));
            }
            s.pop();
            s.push('\n');
        }
        write!(out, "{}", s).ok();
    }
}
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
        let u: Vec<usize> = sc.next_vec(n);
        let mut a = vec![vec![]; n];
        for u in u {
            let s: i64 = sc.next();
            a[u - 1].push(s);
        }
        let mut ans = vec![0; n + 1];
        for mut a in a {
            a.sort_by_key(|a| !a);
            for i in 1..a.len() {
                a[i] += a[i - 1];
            }
            for k in 1..=a.len() {
                let q = a.len() / k * k;
                ans[k] += a[q - 1];
            }
        }
        let mut s = String::new();
        for a in ans[1..].iter() {
            s.push_str(&format!("{} ", *a));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
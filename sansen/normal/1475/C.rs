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
        let a: usize = sc.next();
        let b: usize = sc.next();
        let k: usize = sc.next();
        let x: Vec<usize> = (0..k).map(|_| sc.next::<usize>() - 1).collect();
        let y: Vec<usize> = (0..k).map(|_| sc.next::<usize>() - 1).collect();
        let mut ans = 0u64;
        let mut cnt = vec![0; a + b];
        let mut sum = 0;
        for (&x, &y) in x.iter().zip(y.iter()) {
            ans += sum - cnt[x] - cnt[y + a];
            cnt[x] += 1;
            cnt[y + a] += 1;
            sum += 1;
        }
        writeln!(out, "{}", ans).ok();
    }
}
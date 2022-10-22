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
        let c: Vec<u64> = sc.next_vec(n);
        let m = n as u64;
        let mut ans = c[0] * m + c[1] * m;
        let mut sum = [c[0], c[1]];
        let mut min = [c[0], c[1]];
        let mut cnt = [0, 0];
        for (i, c) in c[2..].iter().enumerate() {
            let p = i & 1;
            sum[p] += *c;
            min[p] = min[p].min(*c);
            cnt[p] += 1;
            let mut val = 0;
            val += sum[0] - min[0] + (m - cnt[0]) * min[0];
            val += sum[1] - min[1] + (m - cnt[1]) * min[1];
            ans = ans.min(val);
        }
        writeln!(out, "{}", ans).ok();
    }
}
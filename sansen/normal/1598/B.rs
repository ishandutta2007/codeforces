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
        let n: u32 = sc.next();
        let m = 5;
        let mut cnt = vec![0; 1 << 5];
        for _ in 0..n {
            let mut x = 0;
            for _ in 0..m {
                let a: usize = sc.next();
                x = 2 * x + a;
            }
            cnt[x] += 1;
        }
        let mut ans = "NO";
        for i in 0..m {
            for j in 0..i {
                let mut c = [[0; 2]; 2];
                for (x, cnt) in cnt.iter().enumerate() {
                    c[x >> i & 1][x >> j & 1] += *cnt;
                }
                if c[0][0] == 0 && c[1][0] <= n / 2 && c[0][1] <= n / 2 {
                    ans = "YES";
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
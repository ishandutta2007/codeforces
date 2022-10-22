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
        let s = sc.next_bytes();
        let mut cnt = vec![[0i32; 2]; s.len() + 1];
        for (i, s) in s.iter().enumerate().rev() {
            cnt[i] = cnt[i + 1];
            if *s == b'(' || *s == b')' {
                cnt[i][i & 1] += 1;
            }
        }
        let q: usize = sc.next();
        for _ in 0..q {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let a = cnt[l][0] - cnt[r][0];
            let b = cnt[l][1] - cnt[r][1];
            writeln!(out, "{}", (a - b).abs()).ok();
        }
    }
}
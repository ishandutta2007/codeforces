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
    let s = sc.next_bytes();
    let t = sc.next_bytes();
    let n = s.len();
    let p: Vec<usize> = sc.next_vec(n);
    let valid = |m: usize| -> bool {
        let mut ban = vec![false; n];
        for p in p.iter().take(m) {
            ban[*p - 1] = true;
        }
        let mut x = 0;
        for (s, ban) in s.iter().zip(ban) {
            if ban {
                continue;
            }
            if x < t.len() && t[x] == *s {
                x += 1;
            }
        }
        x == t.len()
    };
    let mut ok = 0;
    let mut ng = n;
    while ng - ok > 1 {
        let m = (ok + ng) / 2;
        if valid(m) {
            ok = m;
        } else {
            ng = m;
        }
    }
    println!("{}", ok);
}
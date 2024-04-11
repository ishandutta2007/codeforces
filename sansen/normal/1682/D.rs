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
        let _n: usize = sc.next();
        let s = sc.next_bytes();
        if let Some(ans) = solve(s) {
            writeln!(out, "YES").ok();
            for (a, b) in ans {
                writeln!(out, "{} {}", a + 1, b + 1).ok();
            }
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn solve(s: Vec<u8>) -> Option<Vec<(usize, usize)>> {
    let s = s.iter().map(|s| (*s - b'0') as usize).collect::<Vec<_>>();
    if s.iter().sum::<usize>() % 2 != 0 || s.iter().all(|s| *s == 0) {
        return None;
    }
    let n = s.len();
    let mut ans = vec![];
    let l = (0..n).find(|p| s[*p] == 1).unwrap();
    let r = ((l + 1)..n).find(|p| s[*p] == 1).unwrap();
    for i in (l + 2)..=r {
        ans.push((i - 1, i));
    }
    let root = l + 1;
    let mut v = (r + 1) % n;
    let mut left: Option<usize> = None;
    loop {
        if s[v] == 0 {
            if let Some(u) = left {
                ans.push((v, u));
            } else {
                ans.push((root, v));
            }
            left = Some(v);
        } else {
            if let Some(u) = left {
                ans.push((v, u));
                left = None;
            } else {
                ans.push((root, v));
            }
        }
        if v == l {
            break;
        }
        v = (v + 1) % n;
    }
    Some(ans)
}
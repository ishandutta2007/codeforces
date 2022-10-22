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
        let b: Vec<i64> = sc.next_vec(n);
        if let Some(ans) = solve(b) {
            writeln!(out, "YES").ok();
            for (i, a) in ans.iter().enumerate() {
                if i > 0 {
                    write!(out, " ").ok();
                }
                write!(out, "{}", *a).ok();
            }
            writeln!(out).ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn solve(b: Vec<i64>) -> Option<Vec<i64>> {
    let sum = b.iter().sum::<i64>();
    let n = b.len() as i64;
    if sum % (n * (n + 1) / 2) != 0 {
        return None;
    }
    let all = sum / (n * (n + 1) / 2);
    let mut ans = vec![0; b.len()];
    for i in 0..b.len() {
        let v = b[(i + b.len() - 1) % b.len()] + all - b[i];
        if v % n != 0 {
            return None;
        }
        ans[i] = v / n;
    }
    if !ans.iter().all(|a| 1 <= *a && *a <= 1000000000) {
        return None;
    }
    Some(ans)
}
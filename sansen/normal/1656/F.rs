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
        let n = sc.next::<usize>();
        let a: Vec<i64> = sc.next_vec(n);
        if let Some(ans) = solve(a) {
            writeln!(out, "{}", ans).ok();
        } else {
            writeln!(out, "INF").ok();
        }
    }
}

fn solve(mut a: Vec<i64>) -> Option<i64> {
    a.sort();
    let n = a.len();
    if a[0] * (n - 1) as i64 + a[1..].iter().sum::<i64>() > 0 {
        return None;
    }
    if a[n - 1] * (n - 1) as i64 + a[..(n - 1)].iter().sum::<i64>() < 0 {
        return None;
    }
    let min = a[0];
    let max = a[n - 1];
    let a = &a[1..(n - 1)];
    let mut x = min + max;
    let mut y = min * max;
    let mut e = vec![];
    for (i, &a) in a.iter().enumerate() {
        x += a + max;
        y += a * max;
        e.push((-a, i));
    }
    e.sort();
    let mut ans = std::i64::MIN;
    if x == 0 {
        ans = ans.max(y);
    }
    for (t, k) in e {
        x += min - max;
        y += a[k] * (min - max);
        ans = ans.max(t * x + y);
    }
    if x == 0 {
        ans = ans.max(y);
    }
    Some(ans)
}
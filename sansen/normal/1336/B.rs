// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let len: Vec<usize> = (0..3).map(|_| sc.next()).collect();
        let mut a: Vec<Vec<i64>> = len.iter().map(|n| (0..*n).map(|_| sc.next()).collect()).collect();
        for a in a.iter_mut() {
            a.sort();
            a.dedup()
        }
        let mut ans = std::i64::MAX;
        ans = std::cmp::min(ans, eval(&a[0], &a[1], &a[2]));
        ans = std::cmp::min(ans, eval(&a[0], &a[2], &a[1]));
        ans = std::cmp::min(ans, eval(&a[1], &a[0], &a[2]));
        ans = std::cmp::min(ans, eval(&a[1], &a[2], &a[0]));
        ans = std::cmp::min(ans, eval(&a[2], &a[0], &a[1]));
        ans = std::cmp::min(ans, eval(&a[2], &a[1], &a[0]));
        writeln!(out, "{}", ans).ok();
    }
}

fn eval(a: &[i64], b: &[i64], c: &[i64]) -> i64 {
    let mut l = 0;
    let mut r = 0;
    let mut k = 0;
    let mut res = std::i64::MAX;
    for &a in a.iter() {
        while l < b.len() && b[l] < a {
            l += 1;
        }
        if l >= b.len() {
            return res;
        }
        while k < c.len() && c[k] < b[l] {
            k += 1;
        }
        if k >= c.len() {
            return res;
        }
        while r < b.len() && b[r] <= c[k] {
            r += 1;
        }
        let func = |b: i64| {
            let x = a - b;
            let y = b - c[k];
            let z = c[k] - a;
            x * x + y * y + z * z
        };
        let mut l = l;
        let mut r = r;
        while r - l > 2 {
            let ll = (2 * l + r) / 3;
            let rr = (l + 2 * r) / 3;
            if func(b[ll]) >= func(b[rr]) {
                l = ll;
            } else {
                r = rr;
            }
        }
        for b in b[l..r].iter() {
            res = std::cmp::min(res, func(*b));
        }
    }
    res
}
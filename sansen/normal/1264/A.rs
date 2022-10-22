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
        let n: usize = sc.next();
        let p: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let a = run_length_encoding(&p);
        let g = a[0].1;
        let mut s = 0;
        let mut i = 1;
        while i < a.len() && s <= g {
            s += a[i].1;
            i += 1;
        }
        let mut b = 0;
        while i < a.len() && b <= g {
            b += a[i].1;
            i += 1;
        }
        while i < a.len() && 2 * (g + s + b + a[i].1) <= n {
            b += a[i].1;
            i += 1;
        }
        if g < s && g < b && 2 * (g + s + b) <= n {
            writeln!(out, "{} {} {}", g, s, b).ok();
        } else {
            writeln!(out, "0 0 0").ok();
        }
    }
}

fn run_length_encoding<T: Clone + Eq>(a: &[T]) -> Vec<(T, usize)> {
    if a.len() == 0 {
        return vec![];
    }
    let mut x = a[0].clone();
    let mut cnt = 1;
    let mut ans = vec![];
    for y in &a[1..] {
        if x == *y {
            cnt += 1;
        } else {
            ans.push((x, cnt));
            x = y.clone();
            cnt = 1;
        }
    }
    ans.push((x, cnt));
    ans
}
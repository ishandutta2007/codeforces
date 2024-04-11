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
        let m: usize = sc.next();
        let mut a = vec![];
        for _ in 0..n {
            let s: Vec<char> = sc.next_chars();
            let mut p = 0i64;
            for s in s {
                p = 2 * p + s.to_digit(10).unwrap() as i64;
            }
            a.push(p);
        }
        a.sort();
        let k = 2i64.pow(m as u32) - n as i64;
        let t = (k - 1) / 2;
        let mut ok = -1;
        let mut ng = 2i64.pow(m as u32);
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            let mut cnt = mid;
            for a in a.iter() {
                if *a <= mid {
                    cnt -= 1;
                }
            }
            if cnt >= t {
                ng = mid;
            } else {
                ok = mid;
            }
        }
        let mut ans = String::new();
        ok += 1;
        for j in (0..m).rev() {
            ans.push_str(&format!("{}", (ok >> j as i64) & 1));
        }
        writeln!(out, "{}", ans).ok();
    }
}
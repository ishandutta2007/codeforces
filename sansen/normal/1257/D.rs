//---------- begin scannner ----------
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
//---------- end scannner ----------

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
        let a: Vec<u32> = (0..n).map(|_| sc.next()).collect();
        let m: usize = sc.next();
        let mut way = vec![0; n + 1];
        for _ in 0..m {
            let p: u32 = sc.next();
            let s: usize = sc.next();
            way[s] = std::cmp::max(way[s], p);
        }
        for i in (0..n).rev() {
            way[i] = std::cmp::max(way[i], way[i + 1]);
        }
        let mut now = 0;
        let mut ans = 0;
        while now < n && a[now] <= way[1] {
            ans += 1;
            let mut j = 0;
            let mut v = a[now];
            while now + j < n && std::cmp::max(v, a[now + j]) <= way[j + 1] {
                v = std::cmp::max(v, a[now + j]);
                j += 1;
            }
            now += j;
        }
        if now >= n {
            writeln!(out, "{}", ans).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}
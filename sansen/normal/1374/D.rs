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
        let k: u64 = sc.next();
        let mut map = std::collections::BTreeMap::new();
        for _ in 0..n {
            let a = sc.next::<u64>() % k;
            if a != 0 {
                *map.entry(k - a).or_insert(0) += 1;
            }
        }
        let mut q = 0;
        for v in map.values() {
            q = std::cmp::max(q, *v);
        }
        let mut ans = 0;
        if q > 0 {
            ans += (q - 1) * k;
        }
        let mut rem = 0;
        for (k, v) in map {
            if v == q {
                rem = std::cmp::max(rem, k + 1);
            }
        }
        ans += rem;
        writeln!(out, "{}", ans).ok();
    }
}
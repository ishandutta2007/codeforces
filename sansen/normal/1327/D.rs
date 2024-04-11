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
        let p: Vec<usize> = (0..n).map(|_| sc.next::<usize>() - 1).collect();
        let c: Vec<usize> = (0..n).map(|_| sc.next::<usize>() - 1).collect();
        let mut used = vec![false; n];
        let mut ans = n;
        for i in 0..n {
            if used[i] {
                continue;
            }
            let mut a = vec![c[i]];
            let mut pos = p[i];
            used[i] = true;
            while pos != i {
                a.push(c[pos]);
                used[pos] = true;
                pos = p[pos];
            }
            ans = std::cmp::min(a.len(), ans);
            for k in 1.. {
                if k * k > a.len() {
                    break;
                }
                if a.len() % k == 0 {
                    if valid(&a, k) {
                        ans = std::cmp::min(ans, k);
                    }
                    if valid(&a, a.len() / k) {
                        ans = std::cmp::min(ans, a.len() / k);
                    }
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn valid(a: &[usize], k: usize) -> bool {
    for i in 0..k {
        let v = a[i];
        let mut j = i + k;
        while j < a.len() {
            if a[j] != v {
                break;
            } else {
                j += k;
            }
        }
        if j >= a.len() {
            return true;
        }
    }
    false
}
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
        let k: usize = sc.next();
        let k = k - 1;
        let mut s: Vec<char> = sc.next_chars();
        let m = n / 2;
        let mut ans = vec!['\n'; n];
        for i in 0..(m - k) {
            ans[i] = '(';
        }
        for i in (m - k)..(2 * (m - k)) {
            ans[i] = ')';
        }
        for i in 0..k {
            ans[n - 1 - 2 * i] = ')';
            ans[n - 1 - 2 * i - 1] = '(';
        }
        let b = ans;
        let mut ans = vec![];
        for i in 0..n {
            if s[i] == b[i] {
                continue;
            }
            let l = i;
            let mut r = i + 1;
            while s[r] != b[l] {
                r += 1;
            }
            ans.push((l + 1, r + 1));
            s[l..(r + 1)].reverse();
        }
        let mut cnt = 0i32;
        let mut x = 0;
        for i in 0..n {
            if s[i] == '(' {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            assert!(cnt >= 0);
            if cnt == 0 {
                x += 1;
            }
        }
        assert!(x - 1 == k);
        writeln!(out, "{}", ans.len()).ok();
        for (l, r) in ans {
            writeln!(out, "{} {}", l, r).ok();
        }
    }
}
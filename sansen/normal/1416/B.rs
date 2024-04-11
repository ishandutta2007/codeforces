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
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
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
        let mut a: Vec<i64> = sc.next_vec(n);
        a.insert(0, 0);
        let mut b = a.clone();
        let sum = a.iter().sum::<i64>();
        if sum % n as i64 != 0 {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut ans = vec![];
        for i in 2..=n {
            let k = i as i64;
            if a[i] % k != 0 {
                let req = k - a[i] % k;
                ans.push((1, i, req));
                a[1] -= req;
                a[i] += req;
                assert!(a[1] >= 0);
            }
            assert!(a[i] % k == 0);
            let v = a[i] / k;
            ans.push((i, 1, v));
            a[i] -= k * v;
            a[1] += k * v;
        }
        let ave = sum / n as i64;
        for i in 2..=n {
            ans.push((1, i, ave));
            a[1] -= ave;
            a[i] += ave;
        }
        writeln!(out, "{}", ans.len()).ok();
        for (i, j, x) in ans {
            b[i] -= x * i as i64;
            b[j] += x * i as i64;
            assert!(b[i] >= 0 && b[j] >= 0);
            writeln!(out, "{} {} {}", i, j, x).ok();
        }
        assert!(b.iter().skip(1).all(|a| *a == ave));
    }
}
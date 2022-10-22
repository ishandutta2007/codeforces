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
        let mut a: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let mut cnt = vec![0; n + 1];
        for a in a.iter() {
            cnt[*a] += 1;
        }
        let mut op = vec![];
        let mut l = 0;
        let mut r = n;
        while !a.windows(2).all(|a| a[0] <= a[1]) && op.len() <= 2 * n {
            let mex = cnt.iter().position(|c| *c == 0).unwrap();
            assert!(l <= mex && mex <= r);
            if mex == l {
                cnt[a[l]] -= 1;
                a[l] = mex;
                cnt[mex] += 1;
                op.push(l);
                l += 1;
            } else if mex == r {
                r -= 1;
                cnt[a[r]] -= 1;
                a[r] = mex;
                cnt[mex] += 1;
                op.push(r);
            } else {
                cnt[a[mex]] -= 1;
                a[mex] = mex;
                cnt[mex] += 1;
                op.push(mex);
            }
        }
        assert!(op.len() <= 2 * n);
        let mut s = String::new();
        s.push_str(&format!("{}\n", op.len()));
        for k in op {
            s.push_str(&format!("{} ", k + 1));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
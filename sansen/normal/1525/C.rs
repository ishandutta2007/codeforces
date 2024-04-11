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
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: i64 = sc.next();
        let mut x = (0..n).map(|k| (0i64, false, k)).collect::<Vec<_>>();
        for x in x.iter_mut() {
            x.0 = sc.next();
        }
        for x in x.iter_mut() {
            let s = sc.next_bytes();
            x.1 = s[0] == b'L';
        }
        x.sort();
        let mut ans = vec![-1; n];
        let mut stack = vec![vec![]; 2];
        for &(x, dir, k) in x.iter() {
            let p = (x % 2) as usize;
            if dir {
                if let Some((pos, j)) = stack[p].pop() {
                    let t = (x - pos) / 2;
                    ans[j] = t;
                    ans[k] = t;
                } else {
                    stack[p].push((-x, k));
                }
            } else {
                stack[p].push((x, k));
            }
        }
        for s in stack.iter_mut() {
            while s.len() >= 2 {
                let a = s.pop().unwrap();
                let b = s.pop().unwrap();
                let r = m + (m - b.0);
                let l = a.0;
                let t = (r - l) / 2;
                ans[a.1] = t;
                ans[b.1] = t;
            }
        }
        let mut s = String::new();
        for a in ans {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
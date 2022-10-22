// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std;
    use std::io::Read;
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error"),
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
        let mut a = vec![vec![]; 2];
        for _ in 0..n {
            let x: i64 = sc.next();
            a[(x & 1) as usize].push(x);
        }
        a.iter_mut().for_each(|a| a.sort());
        let mut ans = 0;
        let mut x = 0;
        for _ in 0..n {
            let y = if a[0].is_empty() {
                1
            } else if a[1].is_empty() {
                0
            } else {
                let p = *a[0].last().unwrap();
                let q = *a[1].last().unwrap();
                if p > q {
                    0
                } else {
                    1
                }
            };
            let v = a[y].pop().unwrap();
            if x == y {
                if x == 0 {
                    ans += v;
                } else {
                    ans -= v;
                }
            }
            x ^= 1;
        }
        let s = match ans {
            0 => "Tie",
            v if v > 0 => "Alice",
            _ => "Bob",
        };
        writeln!(out, "{}", s).ok();
    }
}
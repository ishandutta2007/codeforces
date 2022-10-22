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

// k
// a_i, b_i 
// a_i + b_i + 1 < K 
// 0 <= x < k
// xk-1-x
// x <= a_i && k - 1 - x <= b_i
// k - 1 - b_i <= x <= a_i
//

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut p = vec![(0i32, 0i32); n];
        for p in p.iter_mut() {
            p.0 = sc.next();
            p.1 = sc.next();
        }
        let valid = |k: i32| -> bool {
            let mut x = 0;
            for &(a, b) in p.iter().rev() {
                if x <= a && k - 1 - b <= x {
                    x += 1;
                }
            }
            x >= k
        };
        let mut ok = 1;
        let mut ng = n as i32 + 1;
        while ng - ok > 1 {
            let m = (ok + ng) / 2;
            if valid(m) {
                ok = m;
            } else {
                ng = m;
            }
        }
        writeln!(out, "{}", ok).ok();
    }
}
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
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let d: i32 = sc.next();
        let a: Vec<i32> = sc.next_vec(n);
        let valid = |m: i32| -> bool {
            let mut last = 0;
            let mut used = false;
            let mut fill = false;
            for &a in a.iter() {
                if last + m < a {
                    if used && !fill && last + 2 * m + 1 < a {
                        fill = true;
                    }
                    last = a;
                } else if used {
                    return false;
                } else {
                    used = true;
                }
            }
            if used && !fill && last + m < d {
                fill = true;
            }
            if !used || fill {
                return true;
            }
            let mut used = false;
            let mut fill = false;
            let mut last = d + m + 1;
            for &a in a.iter().rev() {
                if a < last - m && a > m {
                    if used && !fill && a < last - m - 1 - m {
                        fill = true;
                    }
                    last = a;
                } else if used {
                    return false;
                } else {
                    used = true;
                }
            }
            if used && !fill && m + 1 < last - m {
                fill = true;
            }
            !used || fill
        };
        let mut ok = 0;
        let mut ng = d + 1;
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            if valid(mid) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        writeln!(out, "{}", ok).ok();
    }
}
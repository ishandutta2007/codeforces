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
        let n = sc.next::<usize>();
        let h: Vec<i64> = sc.next_vec(n);
        let max = *h.iter().max().unwrap();
        let valid = |m: i64| -> bool {
            let two = m / 2;
            let one = m - two;
            (0..=1).any(|add| {
                let v = max + add;
                let mut two = two;
                let mut one = one;
                h.iter().all(|h| {
                    let mut h = *h;
                    let q = two.min((v - h) / 2);
                    two -= q;
                    h += 2 * q;
                    let q = one.min(v - h);
                    one -= q;
                    h += q;
                    h == v
                })
            })
        };
        let mut ok = (max * n as i64 - h.iter().sum::<i64>()) * 2;
        let mut ng = -1;
        while ok - ng > 1 {
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
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
    let n: usize = sc.next();
    let m: usize = sc.next();
    let mut a = 0;
    let mut b = 0;
    let mut map = std::collections::BTreeMap::new();
    for _ in 0..m {
        let op: String = sc.next();
        if op == "+" {
            let x: usize = sc.next();
            let y: usize = sc.next();
            let c = sc.next::<String>().chars().next().unwrap();
            map.insert((x, y), c);
            if let Some(&p) = map.get(&(y, x)) {
                b += 1;
                if p == c {
                    a += 1;
                }
            }
        } else if op == "-" {
            let x: usize = sc.next();
            let y: usize = sc.next();
            let c = map.remove(&(x, y)).unwrap();
            if let Some(&p) = map.get(&(y, x)) {
                b -= 1;
                if p == c {
                    a -= 1;
                }
            }
        } else {
            let k = sc.next::<usize>();
            let ans = if a > 0 || (b > 0 && k % 2 == 1) {
                "YES"
            } else {
                "NO"
            };
            writeln!(out, "{}", ans).ok();
        }
    }
}
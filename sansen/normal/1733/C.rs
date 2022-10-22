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

// parity0
// 
//

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<u32> = sc.next_vec(n);
        let mut ans = vec![];
        let mut op = |x: usize, y: usize, a: &mut [u32]| {
            assert!(x < y && y < a.len());
            ans.push((x, y));
            let v = (a[x] + a[y]) % 2;
            if v == 1 {
                a[y] = a[x];
            } else {
                a[x] = a[y];
            }
        };
        if n > 1 {
        op(0, n - 1, &mut a);
        for i in 1..(n - 1) {
            if a[0] & 1 != a[i] & 1 {
                op(0, i, &mut a);
            } else {
                op(i, n - 1, &mut a);
            }
        }
        }
        assert!(a.windows(2).all(|a| a[0] <= a[1]));
        writeln!(out, "{}", ans.len()).ok();
        for (x, y) in ans {
            writeln!(out, "{} {}", x + 1, y + 1).ok();
        }
    }
}
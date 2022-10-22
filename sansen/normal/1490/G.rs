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
        let m: usize = sc.next();
        let a: Vec<i64> = sc.next_vec(n);
        let mut stack: Vec<(i64, usize)> = vec![];
        let mut sum = 0;
        for (i, a) in a.iter().enumerate() {
            sum += *a;
            if stack.last().map_or(true, |p| p.0 < sum) {
                stack.push((sum, i));
            }
        }
        let stack = stack;
        let sum = sum;
        let ask: Vec<i64> = sc.next_vec(m);
        let mut s = String::new();
        for x in ask {
            if stack.last().unwrap().0 < x && sum <= 0 {
                s.push_str("-1 ");
                continue;
            }
            if stack.last().unwrap().0 >= x {
                let po = stack.binary_search_by_key(&(x, 0), |p| (p.0, 1)).unwrap_err();
                s.push_str(&format!("{} ", stack[po].1));
            } else {
                assert!(sum > 0);
                let q = (x - stack.last().unwrap().0 + sum - 1) / sum;
                let x = x - sum * q as i64;
                let po = stack.binary_search_by_key(&(x, 0), |p| (p.0, 1)).unwrap_err();
                s.push_str(&format!("{} ", q as u64 * n as u64 + stack[po].1 as u64)); 
            }
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
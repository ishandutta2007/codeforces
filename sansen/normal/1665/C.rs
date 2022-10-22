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
        let mut deg = vec![0; n];
        for _ in 1..n {
            let p = sc.next::<usize>() - 1;
            deg[p] += 1;
        }
        deg.sort();
        deg.retain(|d| *d > 0);
        let mut ans = 0;
        let mut f = vec![0i32];
        for d in deg.into_iter().rev() {
            f.iter_mut().for_each(|f| *f -= 1);
            f.retain(|f| *f > 0);
            f.push(d - 1);
            ans += 1;
        }
        loop {
            f.iter_mut().for_each(|f| *f -= 1);
            f.retain(|f| *f > 0);
            ans += 1;
            let len = f.len();
            if let Some(v) = f.iter_mut().max() {
                if len == 1 && *v <= 1 {
                    ans += 1;
                    break;
                }
                *v -= 1;
            } else {
                break;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
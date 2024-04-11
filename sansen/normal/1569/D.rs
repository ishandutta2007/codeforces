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
        let h: usize = sc.next();
        let w: usize = sc.next();
        let m: usize = sc.next();
        let mut x = vec![0u32; h];
        for x in x.iter_mut() {
            *x = sc.next();
        }
        let mut y = vec![0u32; w];
        for y in y.iter_mut() {
            *y = sc.next();
        }
        let mut row = vec![0u64; h];
        let mut col = vec![0u64; w];
        let mut map = std::collections::BTreeMap::new();
        let mut ans = 0;
        for _ in 0..m {
            let a: u32 = sc.next();
            let b: u32 = sc.next();
            match (x.binary_search(&a), y.binary_search(&b)) {
                (Err(a), Ok(b)) => {
                    let po = map.entry((a, b, 0)).or_insert(0);
                    ans += row[a] - *po;
                    row[a] += 1;
                    *po += 1;
                },
                (Ok(a), Err(b)) => {
                    let po = map.entry((a, b, 1)).or_insert(0);
                    ans += col[b] - *po;
                    col[b] += 1;
                    *po += 1;
                },
                _ => (),
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
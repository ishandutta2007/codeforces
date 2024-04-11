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
        let k: usize = sc.next();
        let mut used = vec![false; 2 * n];
        let mut range = vec![];
        for _ in 0..k {
            let x = sc.next::<usize>() - 1;
            let y = sc.next::<usize>() - 1;
            used[x] = true;
            used[y] = true;
            range.push((x.min(y), x.max(y)));
        }
        let mut p = vec![];
        for (i, u) in used.iter().enumerate() {
            if !*u {
                p.push(i);
            }
        }
        if p.len() > 0 {
            let m = p.len() / 2;
            let (l, r) = p.split_at(m);
            for (l, r) in l.iter().zip(r.iter()) {
                range.push((*l, *r));
            }
        }
        range.sort();
        let mut ans = n * (n - 1) / 2;
        for (i, &(a, b)) in range.iter().enumerate() {
            for &(c, d) in range.iter().skip(i + 1) {
                if (a <= c && d <= b) || b <= c {
                    ans -= 1;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
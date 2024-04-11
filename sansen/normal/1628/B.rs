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

// yes
// 
// |X| = 2
// Y = c + rev X
// yes
// x, rev x yes

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut s = vec![];
        for _ in 0..n {
            s.push(sc.next_bytes());
        }
        let ans = if valid(s) { "YES" } else { "NO" };
        writeln!(out, "{}", ans).ok();
    }
}

fn valid(s: Vec<Vec<u8>>) -> bool {
    if s.iter()
        .any(|s| s.iter().zip(s.iter().rev()).all(|p| *p.0 == *p.1))
    {
        return true;
    }
    type Set<T> = std::collections::BTreeSet<T>;
    let mut set = Set::new();
    for a in s.iter() {
        if set.contains(a) {
            return true;
        }
        let mut b = a.clone();
        b.reverse();
        set.insert(b);
    }
    let mut set = Set::new();
    for a in s.iter() {
        if a.len() == 3 {
            let mut b = a.clone();
            b.pop();
            b.reverse();
            set.insert(b);
        } else if a.len() == 2 && set.contains(a) {
            return true;
        }
    }
    let mut set = Set::new();
    for a in s.iter() {
        if a.len() == 2 {
            let mut b = a.clone();
            b.reverse();
            set.insert(b);
        } else if a.len() == 3 {
            let mut b = a.clone();
            b.remove(0);
            if set.contains(&b) {
                return true;
            }
        }
    }
    false
}
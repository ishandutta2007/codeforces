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
use std::collections::*;

type Set<T> = BTreeSet<T>;

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
    let mut val = vec![];
    for _ in 0..n {
        let c: usize = sc.next();
        let a: Vec<u64> = sc.next_vec(c);
        val.push(a);
    }
    let m: usize = sc.next();
    let mut ban = Set::new();
    for _ in 0..m {
        let mut b: Vec<usize> = sc.next_vec(n);
        for b in b.iter_mut() {
            *b -= 1;
        }
        ban.insert(b);
    }
    let calc = |p: &[usize]| -> u64 {
        val.iter().zip(p).map(|p| p.0[*p.1]).sum::<u64>()
    };
    let mut used = Set::new();
    let ini = val.iter().map(|p| p.len() - 1).collect::<Vec<_>>();
    let mut h = BinaryHeap::new();
    h.push((calc(&ini), ini.clone()));
    used.insert(ini);
    while let Some((_, pos)) = h.pop() {
        if !ban.contains(&pos) {
            let s = pos.iter().map(|p| (*p + 1).to_string()).collect::<Vec<_>>().join(" ");
            println!("{}", s);
            return;
        }
        for i in 0..n {
            if pos[i] > 0 {
                let mut pos = pos.clone();
                pos[i] -= 1;
                if used.insert(pos.clone()) {
                    h.push((calc(&pos), pos));
                }
            }
        }
    }
}
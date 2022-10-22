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
        let q: Vec<usize> = sc.next_vec(n);
        let mut set = (1..=n).collect::<std::collections::BTreeSet<_>>();
        let mut min = vec![];
        let mut last = 0;
        for &q in q.iter() {
            if q != last {
                set.remove(&q);
                min.push(q);
                last = q;
            } else {
                let v = *set.iter().next().unwrap();
                set.remove(&v);
                min.push(v);
            }
        }
        let mut set = (1..=n).collect::<std::collections::BTreeSet<_>>();
        let mut max = vec![];
        let mut last = 0;
        for &q in q.iter() {
            if q != last {
                set.remove(&q);
                max.push(q);
                last = q;
            } else {
                let v = *set.range(..=q).next_back().unwrap();
                set.remove(&v);
                max.push(v);
            }
        }
        let mut s = String::new();
        for v in min {
            s.push_str(&format!("{} ", v));
        }
        s.pop();
        s.push('\n');
        for v in max {
            s.push_str(&format!("{} ", v));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}
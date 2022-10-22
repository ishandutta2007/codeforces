pub fn join<T: std::fmt::Display>(a: &[T], sep: &str) -> String {
    use std::fmt::Write;
    let mut s = String::new();
    for (i, a) in a.iter().enumerate() {
        if i > 0 {
            write!(&mut s, "{}", sep).ok();
        }
        write!(&mut s, "{}", a).ok();
    }
    s
}
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
        let mut a: Vec<u32> = sc.next_vec(n);
        let mut z = a.clone();
        z.sort();
        if z.chunks(2).any(|z| z.len() == 1 || z[0] != z[1]) {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut op = vec![];
        let mut insert = |x: usize, c: u32, a: &mut Vec<u32>| {
            assert!(x <= a.len());
            op.push((x, c));
            a.splice(x..x, [c, c]);
        };
        let mut len = vec![];
        let mut l = 0;
        while l < a.len() {
            let v = a[l];
            let r = l + 1 + a[(l + 1)..].iter().position(|a| *a == v).unwrap();
            let d = Vec::from(&a[(l + 1)..r]);
            for (i, d) in d.iter().enumerate() {
                insert(r + 1 + i, *d, &mut a);
            }
            len.push(2 + 2 * d.len());
            l += 2 + 2 * d.len();
        }
        writeln!(out, "{}", op.len()).ok();
        for (x, c) in op {
            writeln!(out, "{} {}", x, c).ok();
        }
        writeln!(out, "{}", len.len()).ok();
        writeln!(out, "{}", join(&len, " ")).ok();
    }
}
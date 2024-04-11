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
        let l: usize = sc.next();
        let r: usize = sc.next();
        let c: Vec<usize> = sc.next_vec(n);
        let mut cnt = vec![(0, 0); n + 1];
        for i in 0..n {
            let c = c[i];
            if i < l {
                cnt[c].0 += 1;
            } else {
                cnt[c].1 += 1;
            }
        }
        let mut l = vec![];
        let mut r = vec![];
        for (a, b) in cnt {
            let v = a.min(b);
            if a > v {
                l.push(a - v);
            }
            if b > v {
                r.push(b - v);
            }
        }
        let ls = l.iter().sum::<i32>();
        let rs = r.iter().sum::<i32>();
        let d = (ls - rs).abs() / 2;
        let mut ans = d + (ls + rs) / 2;
        if ls >= rs {
            l.sort();
            let mut rem = d;
            for mut l in l {
                while rem > 0 && l > 1 {
                    l -= 2;
                    rem -= 1;
                    ans -= 1;
                }
            }
        } else {
            r.sort();
            let mut rem = d;
            for mut l in r {
                while rem > 0 && l > 1 {
                    l -= 2;
                    rem -= 1;
                    ans -= 1;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
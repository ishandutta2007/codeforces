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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

// 
// inf 1
// 0 1 2 4 7 inf*100
// 7
// mex
// 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut k: usize = sc.next();
        let a: Vec<usize> = sc.next_vec(n);
        let mut cnt = vec![0; n + 1];
        let mut b = vec![];
        for a in a {
            if a < n {
                cnt[a] += 1;
            } else {
                b.push((a, 1));
            }
        }
        let mut mex = 0;
        {
            let mut k = k;
            while mex < n && (cnt[mex] > 0 || k > 0) {
                if cnt[mex] == 0 {
                    k -= 1;
                    cnt[mex] += 1;
                } else {
                    mex += 1;
                }
            }
        }
        let mut s = 0;
        for i in 0..mex {
            s += cnt[i] - 1;
        }
        for i in mex..n {
            if cnt[i] > 0 {
                b.push((i, cnt[i]));
            }
        }
        b.sort();
        b.dedup_by(|a, b| {
            a.0 == b.0 && {
                b.1 += a.1;
                true
            }
        });
        b.sort_by_key(|p| !p.1);
        let mut k = k;
        while k > 0 && b.len() > 0 {
            let (x, mut y) = b.pop().unwrap();
            if k >= y {
                k -= y;
            } else {
                y -= k;
                b.push((x, y));
                k = 0;
            }
        }
        let ans = b.len();
        writeln!(out, "{}", ans).ok();
    }
}
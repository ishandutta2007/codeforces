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

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: i32 = sc.next();
        let m: usize = sc.next();
        let mut a = sc.next_vec::<i32>(m);
        a.sort();
        let mut d = a.windows(2).map(|a| a[1] - a[0] - 1).collect::<Vec<_>>();
        d.push(a[0] + n - a[m - 1] - 1);
        d.sort();
        let mut ans = 0;
        for (i, d) in d.iter().rev().enumerate() {
            let mut d = *d - 4 * i as i32;
            if d > 0 {
                ans += 1;
                d -= 1;
            }
            d -= 1;
            if d > 0 {
                ans += 1;
                d -= 1;
            }
            ans += d.max(0);
        }
        ans = n - ans;
        writeln!(out, "{}", ans).ok();
    }
}
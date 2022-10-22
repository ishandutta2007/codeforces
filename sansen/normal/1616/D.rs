// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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
    let t: u32 = sc.next();
    for _ in 0..t {
        run(&mut sc, &mut out);
    }
}

// N
// 
// x 
// 1, 2
// x
//
// 2
// 2, 3
// 42, 3
// 
//

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let mut a: Vec<i64> = sc.next_vec(n);
    let x: i64 = sc.next();
    a.push(1000000);
    a.push(1000000);
    // 21
    let mut dp = [[0; 2]; 2];
    for i in (0..n).rev() {
        let mut next = [[0; 2]; 2];
        for (p, dp) in dp.iter().enumerate() {
            for (q, &dp) in dp.iter().enumerate() {
                next[0][p].chmax(dp);
                if (p == 0 || a[i] + a[i + 1] >= 2 * x) && (p == 0 || q == 0 || a[i] + a[i + 1] + a[i + 2] >= 3 * x) {
                    next[1][p].chmax(dp + 1);
                }
            }
        }
        dp = next;
    }
    let ans = *dp.iter().flatten().max().unwrap();
    writeln!(out, "{}", ans).ok();
}
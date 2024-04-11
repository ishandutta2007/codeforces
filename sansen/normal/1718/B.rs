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

// 
// 
//
// 
// 
// 
// 
// 
//

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<u64> = sc.next_vec(n);
        if n == 1 {
            let ans = if a[0] == 1 {
                "YES"
            } else {
                "NO"
            };
            writeln!(out, "{}", ans).ok();
            continue;
        }
        let sum = a.iter().sum::<u64>();
        let mut fib = vec![(1, 1), (1, 1)];
        let mut s = 2;
        while s < sum {
            let len = fib.len();
            let a = fib[len - 2].0 + fib[len - 1].0;
            let b = fib[len - 2].1 + a;
            fib.push((a, b));
            s += a;
        }
        if s != sum {
            writeln!(out, "NO").ok();
            continue;
        }
        if dfs(&mut a, n, &mut fib) {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn dfs(a: &mut [u64], pre: usize, fib: &mut Vec<(u64, u64)>) -> bool {
    if fib.is_empty() {
        return true;
    }
    let last = *fib.last().unwrap();
    if a.iter().any(|a| *a > last.1) {
        return false;
    }
    fib.pop();
    for i in 0..a.len() {
        if i != pre && a[i] >= last.0 {
            a[i] -= last.0;
            if dfs(a, i, fib) {
                return true;
            }
            a[i] += last.0;
        }
    }
    fib.push(last);
    false
}
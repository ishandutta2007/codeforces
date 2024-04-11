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

//  a_i = b_i (l <= i < r) 
//  a_i = b_i 
//
// 
// 
// 
// a_i = b_i 
// 
// 
//
// 
// 
// 
// ...
// c_i = a_i - b_i 
// 0
// 00
// 
// 
// b_i
//
// 
// 
// ...
//
// 
// 
// 0
//

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let a: Vec<i64> = sc.next_vec(n);
        let b: Vec<i64> = sc.next_vec(n);
        let mut c = vec![0; n];
        let mut sum = vec![0; n + 1];
        for (i, ((c, a), b)) in c.iter_mut().zip(a.iter()).zip(b.iter()).enumerate() {
            *c = *a - *b;
            sum[i + 1] = sum[i] + *c;
        }
        let mut p = vec![];
        for _ in 0..m {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            p.push((l, r));
        }
        let mut ban = Set::new();
        for i in 0..=n {
            if sum[i] != 0 {
                ban.insert(i);
            }
        }
        let mut dfs = vec![];
        let mut memo = vec![vec![]; n + 1];
        for (l, r) in p {
            if !ban.contains(&l) && !ban.contains(&r) {
                dfs.push((l, r));
            } else {
                memo[l].push((l, r));
                memo[r].push((l, r));
            }
        }
        while let Some((l, r)) = dfs.pop() {
            let d = ban.range(l..=r).cloned().collect::<Vec<_>>();
            for v in d.iter() {
                ban.remove(v);
            }
            for &v in d.iter() {
                for (l, r) in memo[v].drain(..) {
                    if !ban.contains(&l) && !ban.contains(&r) {
                        dfs.push((l, r));
                    }
                }
            }
        }
        let ans = if ban.is_empty() {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", ans).ok();
    }
}
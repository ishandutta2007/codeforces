// ---------- begin multiset ----------
struct MultiSet<T> {
    size: usize,
    map: std::collections::BTreeMap<T, u32>,
}

impl<T> MultiSet<T> where T: Ord {
    fn new() -> Self {
        MultiSet {
            size: 0,
            map: std::collections::BTreeMap::new(),
        }
    }
    fn len(&self) -> usize {
        self.map.len()
    }
    fn insert(&mut self, val: T) {
        self.size += 1;
        *self.map.entry(val).or_insert(0) += 1;
    }
    fn remove(&mut self, val: &T) {
        assert!(self.map.contains_key(val));
        let cnt = self.map.get_mut(val).unwrap();
        *cnt -= 1;
        self.size -= 1;
        if *cnt == 0 {
            self.map.remove(val);
        }
    }
}
// ---------- end multiset ----------
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
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

// max 
// max
// 1
// second max?
//  or 
//
// 

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a: Vec<usize> = sc.next_vec(2 * n);
        a.sort();
        let mut x = 0;
        let mut ans = vec![];
        for i in 0..(2 * n - 1) {
            x = a[i] + a[2 * n - 1];
            let mut set = MultiSet::new();
            for j in 0..(2 * n) {
                if j != i && j != 2 * n - 1 {
                    set.insert(a[j]);
                }
            }
            let mut op = vec![(a[i], a[2 * n - 1])];
            let mut y = a[2 * n - 1];
            for _ in 1..n {
                let p = *set.map.keys().next_back().unwrap();
                set.remove(&p);
                if set.map.contains_key(&(y - p)) {
                    op.push((p, y - p));
                    set.remove(&(y - p));
                    y = p;
                } else {
                    break;
                }
            }
            if op.len() == n {
                ans = op;
                break;
            }
        }
        if ans.len() == n {
            writeln!(out, "YES").ok();
            writeln!(out, "{}", x).ok();
            for (a, b) in ans {
                writeln!(out, "{} {}", a, b).ok();
            }
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
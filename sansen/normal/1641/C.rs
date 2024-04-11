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

// , 
// 
//  
//  

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let q: usize = sc.next();
    let mut map = Map::<usize, usize>::new();
    let mut free = (0..n).collect::<Set<_>>();
    let mut ban = Set::new();
    for _ in 0..q {
        let op: u8 = sc.next();
        if op == 0 {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let v: u8 = sc.next();
            if v == 0 {
                let del = free.range(l..r).cloned().collect::<Vec<_>>();
                for d in del {
                    free.remove(&d);
                }
            } else if ban.range(l..r).next().is_some() {
                continue;
            } else if map.range(l..).next().map_or(true, |(_, p)| r < *p) {
                while let Some((&k, &v)) = map.range(..=l).next_back() {
                    if r <= v {
                        map.remove(&k);
                    } else {
                        break;
                    }
                }
                map.insert(l, r);
            }
            let mut range = vec![];
            if v == 1 {
                range.push((l, r));
            } else {
                if let Some(p) = map.range(..l).next_back() {
                    range.push((*p.0, *p.1));
                }
                if let Some(p) = map.range(..r).next_back() {
                    range.push((*p.0, *p.1));
                }
            }
            for (l, r) in range {
                if free.range(l..r).take(2).count() == 1 {
                    let x = *free.range(l..r).next().unwrap();
                    free.remove(&x);
                    ban.insert(x);
                    while let Some((&k, &v)) = map.range(..=x).next_back() {
                        if v > x {
                            map.remove(&k);
                        } else {
                            break;
                        }
                    }
                }
            }
        } else {
            let x = sc.next::<usize>() - 1;
            let mut ans = "NO";
            if free.contains(&x) {
                ans = "N/A";
            } else if ban.contains(&x) {
                ans = "YES";
            }
            writeln!(out, "{}", ans).ok();
        }
    }
}
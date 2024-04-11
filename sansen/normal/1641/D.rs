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

type Map<K, V> = HashMap<K, V>;

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
    let n: usize = sc.next();
    let m: usize = sc.next();
    let mut a = vec![vec![0usize; m]; n];
    let mut z = vec![];
    let mut w = vec![];
    for a in a.iter_mut() {
        for a in a.iter_mut() {
            *a = sc.next();
        }
        w.push(sc.next::<i32>());
        z.extend(a.iter().cloned());
    }
    z.sort();
    z.dedup();
    for a in a.iter_mut() {
        for a in a.iter_mut() {
            *a = z.binary_search(a).unwrap();
        }
        a.sort();
    }
    let gen = |a: &[usize], res: &mut Vec<Vec<usize>>| {
        res.clear();
        for i in 0..(1 << m) {
            let mut key = vec![];
            for (j, a) in a.iter().enumerate() {
                if i >> j & 1 == 1 {
                    key.push(*a);
                }
            }
            res.push(key);
        }
    };
    let mut ord = (0..n).collect::<Vec<_>>();
    ord.sort_by_key(|x| w[*x]);
    let mut cnt = Map::new();
    let mut ans = std::i32::MAX;
    let mut stack = vec![];
    let mut key = vec![];
    for x in ord {
        gen(&a[x], &mut key);
        let mut c = 0;
        for (j, key) in key.drain(..).enumerate() {
            let po = cnt.entry(key).or_insert(0);
            if j.count_ones() % 2 == 0 {
                c += *po;
            } else {
                c -= *po;
            }
            *po += 1;
        }
        stack.push(x);
        while c > 0 {
            let y = stack.pop().unwrap();
            if a[y].iter().all(|y| !a[x].contains(&y)) {
                ans = ans.min(w[x] + w[y]);
                c -= 1;
            }
            gen(&a[y], &mut key);
            for key in key.iter() {
                *cnt.get_mut(key).unwrap() -= 1;
            }
        }
    }
    if ans == std::i32::MAX {
        ans = -1;
    }
    writeln!(out, "{}", ans).ok();
}
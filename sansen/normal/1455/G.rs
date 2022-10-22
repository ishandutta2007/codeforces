// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

use std::collections::*;

struct MultiSet {
    map: BTreeMap<i64, u32>,
}

impl MultiSet {
    fn new() -> Self {
        MultiSet {
            map: BTreeMap::new(),
        }
    }
    fn insert(&mut self, v: i64) {
        *self.map.entry(v).or_insert(0) += 1;
    }
    fn remove(&mut self, v: i64) {
        self.map.get_mut(&v).map(|p| *p -= 1);
        if self.map.get(&v).map_or(false, |p| *p == 0) {
            self.map.remove(&v);
        }
    }
}

struct DP {
    map: BTreeMap<usize, i64>,
    set: MultiSet,
    add: i64,
}

impl DP {
    fn new(s: usize, v: i64) -> Self {
        let mut dp = DP {
            map: BTreeMap::new(),
            set: MultiSet::new(),
            add: 0,
        };
        dp.map.insert(s, v);
        dp.set.insert(v);
        dp
    }
    fn find(&self, s: usize) -> Option<i64> {
        self.map.get(&s).map(|v| *v + self.add)
    }
    fn update(&mut self, s: usize, v: i64) {
        if let Some(p) = self.map.get_mut(&s) {
            if *p + self.add > v {
                self.set.remove(*p);
                self.set.insert(v - self.add);
                *p = v - self.add;
            }
        } else {
            self.set.insert(v - self.add);
            self.map.insert(s, v - self.add);
        }
    }
    fn update_add(&mut self, v: i64) {
        self.add += v;
    }
    fn remove(&mut self, s: usize) {
        if let Some(p) = self.map.remove(&s) {
            self.set.remove(p);
        }
    }
    fn min(&self) -> i64 {
        *self.set.map.keys().next().unwrap() + self.add
    }
    fn merge(&mut self, rhs: &mut Self) {
        if self.map.len() < rhs.map.len() {
            std::mem::swap(self, rhs);
        }
        let add = rhs.add;
        for (&x, &v) in rhs.map.iter() {
            self.update(x, v + add);
        }
    }
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let s: usize = sc.next();
    let mut op = vec![];
    for _ in 0..n {
        let s = sc.next::<String>();
        if s == "set" {
            let y: usize = sc.next();
            let c: i64 = sc.next();
            op.push(("set", y, c));
        } else if s == "if" {
            let y: usize = sc.next();
            op.push(("if", y, 0));
        } else {
            op.push(("end", 0, 0));
        }
    }
    op.push(("end", 0, 0));
    let mut dp = DP::new(0, 0);
    calc(&mut 0, s, &op, &mut dp);
    writeln!(out, "{}", dp.min()).ok();
}

fn calc(k: &mut usize, s: usize, op: &[(&str, usize, i64)], dp: &mut DP) {
    loop {
        let x = *k;
        *k += 1;
        match op[x].0 {
            "end" => return,
            "set" => {
                let y = op[x].1;
                let c = op[x].2;
                let val = dp.min();
                dp.update_add(c);
                if y != s {
                    dp.update(y, val);
                }
            },
            "if" => {
                let y = op[x].1;
                if let Some(v) = dp.find(y) {
                    dp.remove(y);
                    let mut tmp = DP::new(y, v);
                    calc(k, s, op, &mut tmp);
                    dp.merge(&mut tmp);
                } else {
                    let mut c = 1;
                    while c > 0 {
                        if op[*k].0 == "if" {
                            c += 1;
                        } else if op[*k].0 == "end" {
                            c -= 1;
                        }
                        *k += 1;
                    }
                }
            },
            _ => (),
        }
    }
}
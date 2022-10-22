//---------- begin union_find ----------
pub struct DSU {
    p: Vec<i32>,
}
impl DSU {
    pub fn new(n: usize) -> DSU {
        assert!(n < std::i32::MAX as usize);
        DSU { p: vec![-1; n] }
    }
    pub fn init(&mut self) {
        self.p.iter_mut().for_each(|p| *p = -1);
    }
    pub fn root(&self, mut x: usize) -> usize {
        assert!(x < self.p.len());
        while self.p[x] >= 0 {
            x = self.p[x] as usize;
        }
        x
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.p.len() && y < self.p.len());
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.p.len() && y < self.p.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            return None;
        }
        if self.p[x] > self.p[y] {
            std::mem::swap(&mut x, &mut y);
        }
        self.p[x] += self.p[y];
        self.p[y] = x as i32;
        Some((x, y))
    }
    pub fn parent(&self, x: usize) -> Option<usize> {
        assert!(x < self.p.len());
        let p = self.p[x];
        if p >= 0 {
            Some(p as usize)
        } else {
            None
        }
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.p.len());
        let r = self.root(x);
        (-self.p[r]) as usize
    }
}
//---------- end union_find ----------
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

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    let mut dsu = DSU::new(2 * q + 1);
    let mut dp = vec![0; 2 * q + 1];
    let mut id = 0;
    let mut map = std::collections::BTreeMap::new();
    let mut last = 0;
    for _ in 0..q {
        let op: usize = sc.next();
        let mut l = sc.next::<usize>() ^ last;
        let mut r = sc.next::<usize>() ^ last;
        if r < l {
            std::mem::swap(&mut l, &mut r);
        }
        r += 1;
        if op == 1 {
            let diff = sc.next::<usize>() ^ last;
            for x in [l, r].iter() {
                map.entry(*x).or_insert_with(|| {
                    id += 1;
                    id
                });
            }
            let mut l = *map.get(&l).unwrap();
            let mut r = *map.get(&r).unwrap();
            let mut xor = 0;
            while let Some(p) = dsu.parent(l) {
                xor ^= dp[l];
                l = p;
            }
            while let Some(p) = dsu.parent(r) {
                xor ^= dp[r];
                r = p;
            }
            if l != r {
                let (_, b) = dsu.unite(l, r).unwrap();
                dp[b] = xor ^ diff;
            }
        } else {
            if !(map.contains_key(&l) && map.contains_key(&r)) {
                writeln!(out, "-1").ok();
                last = 1;
                continue;
            }
            let mut l = *map.get(&l).unwrap();
            let mut r = *map.get(&r).unwrap();
            let mut xor = 0;
            while let Some(p) = dsu.parent(l) {
                xor ^= dp[l];
                l = p;
            }
            while let Some(p) = dsu.parent(r) {
                xor ^= dp[r];
                r = p;
            }
            if l == r {
                writeln!(out, "{}", xor).ok();
                last = xor;
            } else {
                writeln!(out, "-1").ok();
                last = 1;
            }
        }
    }
}
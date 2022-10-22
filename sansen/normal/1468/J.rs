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
    pub fn sum<F>(&self, mut x: usize, mut f: F) -> usize
    where F: FnMut(usize),
    {
        while let Some(p) = self.parent(x) {
            f(x);
            x = p;
        }
        x
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.p.len());
        let r = self.root(x);
        (-self.p[r]) as usize
    }
}
//---------- end union_find ----------

use std::io::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();
        let k: i64 = it.next().unwrap().parse().unwrap();
        let mut less = vec![];
        let mut over = vec![];
        for _ in 0..m {
            let x = it.next().unwrap().parse::<usize>().unwrap() - 1;
            let y = it.next().unwrap().parse::<usize>().unwrap() - 1;
            let s = it.next().unwrap().parse::<i64>().unwrap();
            if s <= k {
                less.push((x, y, s));
            } else {
                over.push((x, y, s));
            }
        }
        less.sort_by_key(|e| e.2);
        over.sort_by_key(|e| e.2);
        let mut ans = std::i64::MAX;
        let mut dsu = DSU::new(n);
        for &(x, y, _) in less.iter() {
            dsu.unite(x, y);
        }
        if dsu.size(0) == n {
            ans = ans.min(k - less.last().unwrap().2);
            if !over.is_empty() {
                ans = ans.min(over[0].2 - k);
            }
        } else {
            let mut sum = 0;
            for &(x, y, s) in over.iter() {
                if dsu.unite(x, y).is_some() {
                    sum += s - k;
                }
            }
            ans = sum;
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
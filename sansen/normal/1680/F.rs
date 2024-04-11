mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
}
// ---------- begin quick find ----------
pub struct QuickFind {
    size: usize,
    id: Vec<usize>,
    list: Vec<Vec<usize>>,
}

impl QuickFind {
    pub fn new(size: usize) -> Self {
        let id = (0..size).collect::<Vec<_>>();
        let list = (0..size).map(|x| vec![x]).collect::<Vec<_>>();
        QuickFind { size, id, list }
    }
    pub fn root(&self, x: usize) -> usize {
        assert!(x < self.size);
        self.id[x]
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.size);
        assert!(y < self.size);
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.size);
        assert!(y < self.size);
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            return None;
        }
        if (self.list[x].len(), x) < (self.list[y].len(), y) {
            std::mem::swap(&mut x, &mut y);
        }
        let mut z = std::mem::take(&mut self.list[y]);
        z.iter().for_each(|y| self.id[*y] = x);
        self.list[x].append(&mut z);
        Some((x, y))
    }
    pub fn enumerate(&self, x: usize) -> &[usize] {
        assert!(x < self.size);
        &self.list[self.root(x)]
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.size);
        self.enumerate(x).len()
    }
}
// ---------- end quick find ----------
//---------- begin union_find ----------
pub struct DSU {
    parent: Vec<u32>,
    size: Vec<u32>,
    stack: Vec<Option<(u32, u32)>>,
}

impl DSU {
    pub fn new(n: usize) -> DSU {
        assert!(n < std::u32::MAX as usize);
        let mut res = DSU {
            parent: vec![0; n],
            size: vec![1; n],
            stack: vec![],
        };
        res.init();
        res
    }
    pub fn init(&mut self) {
        self.stack.clear();
        for (i, (parent, size)) in self.parent.iter_mut().zip(self.size.iter_mut()).enumerate() {
            *parent = i as u32;
            *size = 1;
        }
    }
    pub fn root(&self, mut x: usize) -> usize {
        assert!(x < self.parent.len());
        while self.parent[x] != x as u32 {
            x = self.parent[x] as usize;
        }
        x
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            self.stack.push(None);
            return None;
        }
        if (self.size[x], x) < (self.size[y], y) {
            std::mem::swap(&mut x, &mut y);
        }
        self.size[x] += self.size[y];
        self.parent[y] = x as u32;
        self.stack.push(Some((x as u32, y as u32)));
        Some((x, y))
    }
    pub fn parent(&self, x: usize) -> Option<usize> {
        assert!(x < self.parent.len());
        let p = self.parent[x];
        if p != x as u32 {
            Some(p as usize)
        } else {
            None
        }
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.parent.len());
        let r = self.root(x);
        self.size[r] as usize
    }
    pub fn undo(&mut self) -> Option<(usize, usize)> {
        self.stack.pop().unwrap().map(|(x, y)| {
            let x = x as usize;
            let y = y as usize;
            self.size[x] -= self.size[y];
            self.parent[y] = y as u32;
            (x, y)
        })
    }
    pub fn snap(&mut self) {
        self.stack.clear();
    }
    pub fn rollback(&mut self) {
        while !self.stack.is_empty() {
            self.undo();
        }
    }
}
//---------- end union_find ----------
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
    use util::*;
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let mut edge = vec![(0, 0); m];
        for e in edge.iter_mut() {
            e.0 = sc.next::<usize>() - 1;
            e.1 = sc.next::<usize>() - 1;
        }
        let mut dsu = DSU::new(2 * n);
        let mut cond = true;
        for &(a, b) in edge.iter() {
            dsu.unite(a, b + n);
            dsu.unite(b, a + n);
            cond &= !dsu.same(a, a + n);
        }
        if cond {
            writeln!(out, "YES").ok();
            writeln!(out, "{}", (0..n).map(|v| dsu.same(0, v) as u8).join("")).ok();
            continue;
        }
        if let Some(e) = solve(&edge, true, n, &mut DSU::new(2 * n)) {
            dsu.init();
            for &(x, y) in edge.iter() {
                if (x, y) != e {
                    dsu.unite(x, y + n);
                    dsu.unite(y, x + n);
                }
            }
            writeln!(out, "YES").ok();
            writeln!(out, "{}", (0..n).map(|v| dsu.same(e.0, v) as u8).join("")).ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn solve(e: &[(usize, usize)], bipartite: bool, n: usize, dsu: &mut DSU) -> Option<(usize, usize)> {
    if !bipartite {
        return None;
    }
    if e.len() == 1 {
        return Some(e[0]);
    }
    let m = e.len() / 2;
    let (mut l, mut r) = e.split_at(m);
    for _ in 0..2 {
        let mut bipartite = bipartite;
        for &(a, b) in l.iter() {
            for &(a, b) in [(a, b + n), (b, a + n)].iter() {
                dsu.unite(a, b);
                bipartite &= !dsu.same(a, a + n);
            }
        }
        if let Some(ans) = solve(r, bipartite, n, dsu) {
            return Some(ans);
        }
        for _ in 0..(2 * l.len()) {
            dsu.undo();
        }
        std::mem::swap(&mut l, &mut r);
    }
    None
}
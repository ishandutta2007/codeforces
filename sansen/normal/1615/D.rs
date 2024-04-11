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
    where
        F: FnMut(usize),
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
    let t: u32 = sc.next();
    for _ in 0..t {
        run(&mut sc, &mut out);
    }
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let mut ans = vec![];
    let mut edge = vec![];
    let mut dsu = DSU::new(2 * n);
    for _ in 1..n {
        let a = sc.next::<usize>() - 1;
        let b = sc.next::<usize>() - 1;
        let x = sc.next::<i32>();
        if x == -1 {
            edge.push((a, b));
        } else {
            ans.push((a, b, x));
            let c = x.count_ones();
            if c % 2 == 0 {
                dsu.unite(a, b);
                dsu.unite(a + n, b + n);
            } else {
                dsu.unite(a, b + n);
                dsu.unite(b, a + n);
            }
        }
    }
    for _ in 0..m {
        let a = sc.next::<usize>() - 1;
        let b = sc.next::<usize>() - 1;
        let x = sc.next::<i32>();
        if x == 0 {
            dsu.unite(a, b);
            dsu.unite(a + n, b + n);
        } else {
            dsu.unite(a, b + n);
            dsu.unite(b, a + n);
        }
    }
    if (0..n).any(|p| dsu.same(p, p + n)) {
        writeln!(out, "NO").ok();
        return;
    }
    for (a, b) in edge {
        if !(dsu.same(a, b) || dsu.same(a, b + n)) {
            dsu.unite(a, b);
            dsu.unite(a + n, b + n);
        }
        if dsu.same(a, b) {
            ans.push((a, b, 0));
        } else if dsu.same(a, b + n) {
            ans.push((a, b, 1));
        }
    }
    writeln!(out, "YES").ok();
    for (a, b, x) in ans {
        writeln!(out, "{} {} {}", a + 1, b + 1, x).ok();
    }
}
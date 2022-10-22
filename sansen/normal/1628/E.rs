// undo uniteRE
// snap unite 
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

// path max 
// l, r 
//
// 
// 
// 
// 
// 
// log Q 
// log N 
// log N path max 
// beats 3*10^5 
//

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let q: usize = sc.next();
    let mut e = vec![];
    for _ in 1..n {
        let a = sc.next::<usize>() - 1;
        let b = sc.next::<usize>() - 1;
        let w = sc.next::<i32>();
        e.push((w, a, b));
    }
    e.sort();
    let mut dsu = DSU::new(n);
    let mut dp = vec![std::i32::MAX; n];
    for (w, a, b) in e {
        let (_, b) = dsu.unite(a, b).unwrap();
        dp[b] = w;
    }
    let path_max = |mut a: usize, mut b: usize| -> i32 {
        let mut res = -1;
        while a != b {
            if dp[a] > dp[b] {
                res = dp[b];
                b = dsu.parent(b).unwrap();
            } else {
                res = dp[a];
                a = dsu.parent(a).unwrap();
            }
        }
        res
    };
    let size = n.next_power_of_two();
    let mut seg = vec![(-1, n); 2 * size];
    for i in 0..n {
        seg[i + size] = (-1, i);
    }
    for i in (1..size).rev() {
        if seg[2 * i + 1].1 < n {
            let (a, x) = seg[2 * i];
            let (b, y) = seg[2 * i + 1];
            seg[i] = (a.max(b).max(path_max(x, y)), x);
        }
    }
    let memo = seg;
    let info = Info {
        dsu, dp, memo, n,
    };
    let mut seg = vec![(-1, n, false); 2 * size];
    for _ in 0..q {
        let op: u8 = sc.next();
        if op == 3 {
            let x = sc.next::<usize>() - 1;
            let (a, v, _) = seg[1];
            let ans = a.max(info.path_max(v, x));
            writeln!(out, "{}", ans).ok();
        } else {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            if op == 1 {
                add(1, 0, size, l, r, &mut seg, &info);
            } else {
                del(1, 0, size, l, r, &mut seg, &info);
            }
        }
    }
}

struct Info {
    dsu: DSU,
    dp: Vec<i32>,
    memo: Vec<(i32, usize)>,
    n: usize,
}

impl Info {
    fn path_max(&self, mut a: usize, mut b: usize) -> i32 {
        let n = self.n;
        if a >= n || b >= n {
            return -1;
        }
        let dsu = &self.dsu;
        let dp = &self.dp;
        let mut res = -1;
        while a != b {
            if dp[a] >= dp[b] {
                res = dp[b];
                b = dsu.parent(b).unwrap();
            } else {
                res = dp[a];
                a = dsu.parent(a).unwrap();
            }
        }
        res
    }
}

fn add(v: usize, l: usize, r: usize, s: usize, t: usize, seg: &mut [(i32, usize, bool)], info: &Info) {
    if t <= l || r <= s {
        return;
    }
    if s <= l && r <= t {
        seg[v].0 = info.memo[v].0;
        seg[v].1 = info.memo[v].1;
        seg[v].2 = true;
        return;
    }
    let n = info.n;
    let ini = (-1, info.n, false);
    if seg[v].2 {
        if seg[v].1 == n {
            seg[2 * v] = ini;
            seg[2 * v].2 = true;
            seg[2 * v + 1] = ini;
            seg[2 * v + 1].2 = true;
        } else {
            seg[2 * v].0 = info.memo[2 * v].0;
            seg[2 * v].1 = info.memo[2 * v].1;
            seg[2 * v].2 = true;
            seg[2 * v + 1].0 = info.memo[2 * v + 1].0;
            seg[2 * v + 1].1 = info.memo[2 * v + 1].1;
            seg[2 * v + 1].2 = true;
        }
    }
    seg[v] = ini;
    let m = (l + r) / 2;
    add(2 * v, l, m, s, t, seg, info);
    add(2 * v + 1, m, r, s, t, seg, info);
    let (a, x, _) = seg[2 * v];
    let (b, y, _) = seg[2 * v + 1];
    seg[v] = (a.max(b).max(info.path_max(x, y)), x.min(y), false);
}

fn del(v: usize, l: usize, r: usize, s: usize, t: usize, seg: &mut [(i32, usize, bool)], info: &Info) {
    if t <= l || r <= s {
        return;
    }
    if s <= l && r <= t {
        seg[v] = (-1, info.n, true);
        return;
    }
    let n = info.n;
    let ini = (-1, info.n, false);
    if seg[v].2 {
        if seg[v].1 == n {
            seg[2 * v] = ini;
            seg[2 * v].2 = true;
            seg[2 * v + 1] = ini;
            seg[2 * v + 1].2 = true;
        } else {
            seg[2 * v].0 = info.memo[2 * v].0;
            seg[2 * v].1 = info.memo[2 * v].1;
            seg[2 * v].2 = true;
            seg[2 * v + 1].0 = info.memo[2 * v + 1].0;
            seg[2 * v + 1].1 = info.memo[2 * v + 1].1;
            seg[2 * v + 1].2 = true;
        }
    }
    seg[v] = ini;
    let m = (l + r) / 2;
    del(2 * v, l, m, s, t, seg, info);
    del(2 * v + 1, m, r, s, t, seg, info);
    let (a, x, _) = seg[2 * v];
    let (b, y, _) = seg[2 * v + 1];
    seg[v] = (a.max(b).max(info.path_max(x, y)), x.min(y), false);
}
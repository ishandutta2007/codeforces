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
    run(&mut sc, &mut out);
}

// https://yukicoder.me/problems/no/806
// 
// 
// Note the graph can be unconnected after a certain operation.
// 
// (?)
// 3
// dfs 
// 3

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut g = vec![vec![]; n];
        let mut edge = vec![];
        for i in 0..(n - 1) {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            g[a].push((b, i));
            g[b].push((a, i));
            edge.push((a, b));
        }
        // v, 
        let mut topo = vec![(0, n)];
        for i in 0..n {
            let v = topo[i].0;
            for (u, k) in g[v].clone() {
                let x = g[u].iter().position(|e| e.0 == v).unwrap();
                g[u].remove(x);
                topo.push((u, k));
            }
        }
        let mut del = vec![false; n - 1];
        for &(v, k) in topo.iter().rev() {
            let mut cnt = 0;
            for &(_, k) in g[v].iter() {
                if !del[k] {
                    cnt += 1;
                }
            }
            if v > 0 {
                cnt += 1;
            }
            if cnt > 2 {
                if v > 0 {
                    del[k] = true;
                    cnt -= 1;
                }
                for &(_, k) in g[v].iter() {
                    if cnt > 2 && !del[k] {
                        del[k] = true;
                        cnt -= 1;
                    }
                }
            }
        }
        let mut dsu = DSU::new(n);
        let mut v = (0..n).map(|v| vec![v]).collect::<Vec<_>>();
        let mut deg = vec![0; n];
        let mut remove_edge = vec![];
        for i in 0..(n - 1) {
            let (a, b) = edge[i];
            if !del[i] {
                deg[a] += 1;
                deg[b] += 1;
                if let Some((a, b)) = dsu.unite(a, b) {
                    let mut p = std::mem::take(&mut v[b]);
                    v[a].append(&mut p);
                }
            } else {
                remove_edge.push((a, b));
            }
        }
        let mut pair = vec![];
        for i in 0..n {
            if dsu.root(i) == i {
                if dsu.size(i) == 1 {
                    pair.push((i, i));
                } else {
                    let mut a = vec![];
                    for &v in v[i].iter() {
                        if deg[v] == 1 {
                            a.push(v);
                        }
                    }
                    pair.push((a[0], a[1]));
                }
            }
        }
        writeln!(out, "{}", remove_edge.len()).ok();
        for (&(x, y), a) in remove_edge.iter().zip(pair.windows(2)) {
            let x = x + 1;
            let y = y + 1;
            let p = a[0].1 + 1;
            let q = a[1].0 + 1;
            writeln!(out, "{} {} {} {}", x, y, p, q).ok();
        }
    }
}
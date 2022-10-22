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
        if (self.list[x].len(), x) > (self.list[y].len(), y) {
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
    for _ in 0..t {
        let n: usize = sc.next();
        let mut p = vec![vec![0; n]; 2 * n];
        for p in p.iter_mut().flatten() {
            *p = sc.next::<usize>() - 1;
        }
        let mut ban = vec![vec![false; n]; n];
        let mut used = vec![false; 2 * n];
        let mut fix = vec![];
        let mut index = vec![vec![vec![]; n]; n];
        while {
            for (i, p) in p.iter().enumerate() {
                if used[i] {
                    continue;
                }
                let mut ok = true;
                for (ban, &p) in ban.iter().zip(p) {
                    ok &= !ban[p];
                }
                if !ok {
                    used[i] = true;
                    continue;
                }
                for (index, p) in index.iter_mut().zip(p) {
                    index[*p].push(i);
                }
            }
            let mut update = false;
            for index in index.iter().flatten() {
                if index.len() != 1 {
                    continue;
                }
                let v = index[0];
                if used[v] {
                    continue;
                }
                update = true;
                used[v] = true;
                fix.push(v);
                for (ban, p) in ban.iter_mut().zip(&p[v]) {
                    ban[*p] = true;
                }
            }
            index.iter_mut().flatten().for_each(|p| p.clear());
            update
        } {}
        for (i, p) in p.iter().enumerate() {
            if used[i] {
                continue;
            }
            for (j, p) in p.iter().enumerate() {
                index[j][*p].push(i);
            }
        }
        let mut dsu = QuickFind::new(4 * n);
        for index in index.into_iter().flatten() {
            if index.len() == 2 {
                let a = index[0];
                let b = index[1];
                dsu.unite(a, b + 2 * n);
                dsu.unite(b, a + 2 * n);
            }
        }
        let mut ans = 1;
        for i in 0..(4 * n) {
            if !used[i % (2 * n)] && i == dsu.root(i) && dsu.size(i) > 1 {
                for &v in dsu.enumerate(i) {
                    if v >= 2 * n {
                        used[v - 2 * n] = true;
                    } else {
                        used[v] = true;
                        fix.push(v);
                    }
                }
                ans = ans * 2 % 998_244_353;
            }
        }
        fix.sort();
        let p = fix
            .iter()
            .map(|p| (*p + 1).to_string())
            .collect::<Vec<_>>()
            .join(" ");
        writeln!(out, "{}", ans).ok();
        writeln!(out, "{}", p).ok();
    }
}
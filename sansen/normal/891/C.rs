//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    use std;
    pub struct UF {
        parent: Vec<usize>,
        size: Vec<usize>,
        stack: Vec<Option<(usize, usize)>>,
    }
    impl UF {
        pub fn new(n: usize) -> UF {
            let mut u = UF {
                parent: vec![0; n],
                size: vec![1; n],
                stack: vec![],
            };
            u.init();
            u
        }
        pub fn init(&mut self) {
            for (i, p) in self.parent.iter_mut().enumerate() {
                *p = i;
            }
            self.size.clear();
            self.size.resize(self.parent.len(), 1);
            self.stack.clear();
        }
        pub fn root(&mut self, mut x: usize) -> usize {
            while self.parent[x] != x {
                x = self.parent[x];
            }
            x
        }
        pub fn same(&mut self, x: usize, y: usize) -> bool {
            self.root(x) == self.root(y)
        }
        pub fn unite(&mut self, mut x: usize, mut y: usize) -> Option<(usize, usize)> {
            x = self.root(x);
            y = self.root(y);
            if x == y {
                self.stack.push(None);
                return None;
            }
            if self.size[x] < self.size[y] {
                std::mem::swap(&mut x, &mut y);
            }
            self.size[x] += self.size[y];
            self.parent[y] = x;
            self.stack.push(Some((x, y)));
            Some((x, y))
        }
        pub fn undo(&mut self) -> Option<(usize, usize)> {
            self.stack
                .pop()
                .expect("union find undo error: stack is empty")
                .map(|(x, y)| {
                    self.size[x] -= self.size[y];
                    self.parent[y] = y;
                    (x, y)
                })
        }
        pub fn get_size(&mut self, x: usize) -> usize {
            let r = self.root(x);
            self.size[r]
        }
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
    let n: usize = sc.next();
    let m: usize = sc.next();
    let w = 500_000;
    let mut edge = vec![vec![]; w + 1];
    let mut e = vec![];
    for _ in 0..m {
        let a = sc.next::<usize>() - 1;
        let b = sc.next::<usize>() - 1;
        let c: usize = sc.next();
        edge[c].push((a, b));
        e.push((a, b, c));
    }
    let q: usize = sc.next();
    let mut ask = vec![vec![]; w + 1];
    for i in 0..q {
        let k: usize = sc.next();
        let mut map = std::collections::BTreeMap::new();
        for _ in 0..k {
            let x = sc.next::<usize>() - 1;
            let (a, b, c) = e[x];
            map.entry(c).or_insert(vec![]).push((a, b));
        }
        for (c, a) in map {
            ask[c].push((i, a));
        }
    }
    let mut ans = vec![true; q];
    let mut u = union_find::UF::new(n);
    for (edge, ask) in edge.into_iter().zip(ask.into_iter()) {
        for (k, ask) in ask {
            for &(a, b) in ask.iter() {
                if u.unite(a, b).is_none() {
                    ans[k] = false;
                }
            }
            for _ in ask.iter() {
                u.undo();
            }
        }
        for (a, b) in edge {
            u.unite(a, b);
        }
    }
    for a in ans {
        let ans = if a {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", ans).ok();
    }
}
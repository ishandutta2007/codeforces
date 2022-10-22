// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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

// 3path
// 12
// T 2
// 1
//
// 
// 
// 2
// 3
// 
// 
// chmin
// stackrollback
// (l, r) 
// (a, b) 
// (a, hoge)2(hoge, b)21

const INF: u64 = 10_000_000_000;

#[derive(Clone)]
struct State {
    edge: Vec<(usize, usize, u64)>,
}

impl State {
    fn new() -> Self {
        State {
            edge: (0..10).map(|k| (k, (k + 1) % 4, INF)).collect()
        }
    }
    fn add(&mut self, a: usize, b: usize, w: u64) {
        if let Some(x) = self.edge.iter().position(|e| w < e.2) {
            self.edge.insert(x, (a, b, w));
            let mut po = x;
            while po < self.edge.len() {
                let (a, b, _) = self.edge[po];
                let mut x = 0;
                let mut y = 0;
                for e in self.edge[..po].iter() {
                    if e.0 == a || e.1 == a {
                        x += 1;
                    }
                    if e.0 == b || e.1 == b {
                        y += 1;
                    }
                }
                if x.max(y) >= 3 {
                    self.edge.remove(po);
                } else {
                    po += 1;
                }
            }
            self.edge.truncate(10);
        }
    }
    fn find(&self, a: usize, b: usize) -> u64 {
        for &(x, y, w) in self.edge.iter() {
            if a != x && b != x && a != y && b != y {
                return w;
            }
        }
        unreachable!()
    }
}

#[derive(Clone)]
struct Top3([u64; 3]);

impl Top3 {
    fn new() -> Self {
        Top3([INF; 3])
    }
    fn add(&mut self, v: u64) {
        if let Some(x) = self.0.iter().position(|p| v < *p) {
            self.0[x..].rotate_right(1);
            self.0[x] = v;
        }
    }
    fn find(&self) -> u64 {
        self.0.iter().sum()
    }
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let mut map = std::collections::BTreeMap::new();
    for _ in 0..m {
        let a = sc.next::<usize>() - 1;
        let b = sc.next::<usize>() - 1;
        let (a, b) = (a.min(b), a.max(b));
        let w: u64 = sc.next();
        map.insert((a, b), (w, 0));
    }
    let q: usize = sc.next();
    let mut edge = vec![];
    for i in 1..=q {
        let op: u8 = sc.next();
        let a = sc.next::<usize>() - 1;
        let b = sc.next::<usize>() - 1;
        let (a, b) = (a.min(b), a.max(b));
        if op == 0 {
            let (w, s) = map.remove(&(a, b)).unwrap();
            edge.push((s, i, a, b, w));
        } else {
            let w: u64 = sc.next();
            map.insert((a, b), (w, i));
        }
    }
    for ((a, b), (w, s)) in map {
        edge.push((s, q + 1, a, b, w));
    }
    let mut res = vec![0; q + 1];
    let mut top3 = vec![Top3::new(); n];
    let mut dfs = vec![(0, q + 1, INF, State::new(), edge, vec![])];
    while let Some((l, r, mut ans, mut state, edge, memo)) = dfs.pop() {
        if l < r {
            let m = (l + r) / 2;
            let mut memo = vec![];
            let mut e = vec![];
            let mut left = vec![];
            let mut right = vec![];
            for (s, t, a, b, w) in edge {
                if s <= l && r <= t {
                    e.push((s, t, a, b, w));
                    ans.chmin(state.find(a, b) + w);
                    state.add(a, b, w);
                    for &x in [a, b].iter() {
                        memo.push((x, top3[x].clone()));
                        top3[x].add(w);
                        ans.chmin(top3[x].find());
                    }
                    continue;
                }
                if s < m {
                    left.push((s, t, a, b, w));
                }
                if m < t {
                    right.push((s, t, a, b, w));
                }
            }
            dfs.push((1, 0, ans, state.clone(), e, memo));
            if l + 1 == r {
                res[l] = ans;
            } else {
                dfs.push((m, r, ans, state.clone(), right, vec![]));
                dfs.push((l, m, ans, state.clone(), left, vec![]));
            }
        } else {
            for (pos, val) in memo.into_iter().rev() {
                top3[pos] = val;
            }
        }
    }
    for a in res {
        writeln!(out, "{}", a).ok();
    }
}
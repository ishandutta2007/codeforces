// ---------- begin super slice ----------
pub trait SuperSlice {
    type Item;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn lower_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn lower_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn upper_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn upper_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
}

impl<T> SuperSlice for [T] {
    type Item = T;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.lower_bound_by(|p| p.cmp(key))
    }
    fn lower_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Greater))
            .unwrap_err()
    }
    fn lower_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.lower_bound_by(|p| f(p).cmp(key))
    }
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.upper_bound_by(|p| p.cmp(key))
    }
    fn upper_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Less))
            .unwrap_err()
    }
    fn upper_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.upper_bound_by(|p| f(p).cmp(key))
    }
}
// ---------- end super slice ----------
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
        let m: usize = sc.next();
        let mut a: Vec<u64> = sc.next_vec(n - 1);
        let mut b: Vec<u64> = sc.next_vec(n - 1);
        a.insert(0, 0);
        b.insert(0, 0);
        let mut edge = vec![(0, 0); m];
        for e in edge.iter_mut() {
            e.0 = sc.next::<usize>() - 1;
            e.1 = sc.next::<usize>() - 1;
        }
        let mut edge = edge.iter().cloned().chain(edge.iter().map(|p| (p.1, p.0))).collect::<Vec<_>>();
        edge.sort();
        let valid = |mut m: u64| -> bool {
            let mut edge = edge.clone();
            let mut elem = vec![false; n];
            elem[0] = true;
            while elem.iter().any(|e| !*e) {
                edge = edge.into_iter().filter(|&(a, b)| !elem[a] || !elem[b]).collect();
                let mut g = Vec::with_capacity(n);
                for i in 0..n {
                    let s = edge.lower_bound(&(i, 0));
                    let t = edge.lower_bound(&(i + 1, 0));
                    g.push(&edge[s..t]);
                }
                let mut parent = vec![None; n];
                let (x, y) = || -> (usize, usize) {
                    for root in 0..n {
                        if !elem[root] {
                            continue;
                        }
                        let mut dfs = vec![(root, n, m)];
                        while let Some((v, p, power)) = dfs.pop() {
                            for &(_, u) in g[v].iter() {
                                if u == p {
                                    continue;
                                }
                                if elem[u] {
                                    return (u, v);
                                }
                                if a[u] < power {
                                    if parent[u].is_some() {
                                        return (u, v);
                                    }
                                    parent[u] = Some(v);
                                    dfs.push((u, v, power + b[u]));
                                }
                            }
                        }
                    }
                    (n, n)
                }();
                if (x, y) == (n, n) {
                    return false;
                }
                for v in [x, y].iter() {
                    let mut v = *v;
                    while !elem[v] {
                        elem[v] = true;
                        m += b[v];
                        v = parent[v].unwrap();
                    }
                }
            }
            true
        };
        let mut ng = 0;
        let mut ok = 1_000_000_000 + 1;
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            if valid(mid) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        writeln!(out, "{}", ok).ok();
    }
}
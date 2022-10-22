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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

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
        let k: usize = sc.next();
        let e = (0..m)
            .map(|_| {
                let a = sc.next::<usize>() - 1;
                let b = sc.next::<usize>() - 1;
                (a, b)
            })
            .collect::<Vec<_>>();
        if let Some((op, ans)) = solve(n, k, e) {
            if op == 1 {
                writeln!(out, "1 {}", ans.len()).ok();
            } else {
                writeln!(out, "2").ok();
            }
            use util::*;
            writeln!(out, "{}", ans.iter().map(|a| *a + 1).join(" ")).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn solve(n: usize, k: usize, e: Vec<(usize, usize)>) -> Option<(u8, Vec<usize>)> {
    let mut g = vec![Set::new(); n];
    for &(a, b) in e.iter() {
        g[a].insert(b);
        g[b].insert(a);
    }
    let mut h = BinaryHeap::new();
    for (i, g) in g.iter().enumerate() {
        if g.len() < k {
            h.push((!g.len(), i));
        }
    }
    let mut used = vec![false; n];
    while let Some((_, v)) = h.pop() {
        if used[v] {
            continue;
        }
        used[v] = true;
        if g[v].len() + 1 == k {
            let a = g[v]
                .iter()
                .cloned()
                .chain(std::iter::once(v))
                .collect::<Vec<_>>();
            let ok = a
                .iter()
                .enumerate()
                .all(|(i, &v)| a[..i].iter().all(|u| g[v].contains(u)));
            if ok {
                return Some((2, a));
            }
        }
        for u in std::mem::take(&mut g[v]) {
            g[u].remove(&v);
            if !used[u] && g[u].len() < k {
                h.push((!g[u].len(), u));
            }
        }
    }
    let v = used
        .iter()
        .enumerate()
        .filter(|p| !*p.1)
        .map(|p| p.0)
        .collect::<Vec<_>>();
    if v.len() > 0 {
        Some((1, v))
    } else {
        None
    }
}
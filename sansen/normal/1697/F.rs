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

// 
// 1. a_i <= a_{i + 1}
// 2. a_i != x_p
// 3. a_i + a_j <= x_p
// 4. a_i + a_j >= x_p
// 5. 1 <= a_i <= k
//
// N <= 2*10^4
// M <= 2*10^4
// k <= 10
//
// KSAT
// k^2N + k^2M closure
// 
// SAT
// X_{i, j}: A_i >= j 
// 
// X_{i, j} => X_{i, j - 1}
// X_{i, j} => X_{i + 1, j}
// 
// 
// X_{i, v} && !X_{i, v + 1}  A_i = v
// 
// a_i != v
// !(X_{i, v} && !X_{i, v + 1})
// a_i + a_j >= v
// for p
//   X_{i, p} => X_{j, v - p}
//
// a_i + a_j <= v
//   X_{i, p} => !X_{j, v - p + 1}
//
// 
// 
// >= 
//   !X_{i, p} => X_{j, v - p + 1}
// 

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: u32 = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let m: usize = sc.next();
        let k: i32 = sc.next();
        let pos = |x, y| -> usize {
            assert!(x < n && 0 <= y && y <= k + 1, "{} {}", x, y);
            x * (k + 2) as usize + y as usize
        };
        let mut sat = SAT2::new(n * (k + 2) as usize);
        for i in 0..n {
            sat.either(pos(i, 1), pos(i, 1));
            sat.either(!pos(i, k + 1), !pos(i, k + 1));
            for j in 1..=(k + 1) {
                if j > 0 {
                    sat.either(!pos(i, j), pos(i, j - 1));
                }
                if i + 1 < n {
                    sat.either(!pos(i, j), pos(i + 1, j));
                }
            }
        }
        let mut cond = vec![];
        for _ in 0..m {
            let op: u8 = sc.next();
            let i: usize = sc.next::<usize>() - 1;
            if op == 1 {
                let v: i32 = sc.next();
                sat.either(!pos(i, v), pos(i, v + 1));
                cond.push((op, i, 0, v));
            } else {
                let j: usize = sc.next::<usize>() - 1;
                let v: i32 = sc.next();
                for p in 0..=k {
                    let q = v - p;
                    if 0 <= q && q <= k {
                        if op == 2 {
                            sat.either(!pos(i, p), !pos(j, q + 1));
                            sat.either(!pos(j, p), !pos(i, q + 1));
                        } else {
                            sat.either(pos(i, p), pos(j, q + 1));
                            sat.either(pos(j, p), pos(i, q + 1));
                        }
                    }
                }
                cond.push((op, i, j, v));
            }
        }
        if let Some(ans) = sat.solve() {
            let mut a = vec![];
            for i in 0..n {
                let mut v = k;
                for j in 1..=k {
                    if !ans[pos(i, j)] {
                        v = j - 1;
                        break;
                    }
                }
                a.push(v);
            }
            assert!(a.windows(2).all(|a| a[0] <= a[1]));
            for (op, x, y, v) in cond {
                if op == 1 {
                    assert!(a[x] != v);
                } else if op == 2 {
                    assert!(a[x] + a[y] <= v);
                } else {
                    assert!(a[x] + a[y] >= v);
                }
            }
            use util::*;
            writeln!(out, "{}", a.iter().join(" ")).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

// ---------- begin 2-SAT ----------
pub struct SAT2 {
    size: usize,
    clause: Vec<(usize, usize)>,
}

impl SAT2 {
    pub fn new(size: usize) -> Self {
        SAT2 {
            size: size,
            clause: vec![],
        }
    }
    pub fn either(&mut self, a: usize, b: usize) {
        assert!(a.min(!a) < self.size && b.min(!b) < self.size);
        self.clause.push((a, b));
    }
    pub fn add_variable(&mut self) -> usize {
        let v = self.size;
        self.size += 1;
        v
    }
    pub fn at_most_one<V>(&mut self, mut list: V)
    where
        V: Iterator<Item = usize> + Clone,
    {
        let size = list.clone().count();
        if size <= 1 {
            return;
        }
        let mut cur = !list.next().unwrap();
        for v in list.clone().skip(1) {
            let next = self.add_variable();
            self.either(cur, !v);
            self.either(cur, next);
            self.either(!v, next);
            cur = !next;
        }
        self.either(cur, !list.next().unwrap());
    }
    pub fn solve(&self) -> Option<Vec<bool>> {
        let size = self.size;
        let g = CSR::new(
            2 * size,
            self.clause.iter().flat_map(|&(a, b)| {
                let (x, ix) = if a >= size {
                    (!a + size, !a)
                } else {
                    (a, a + size)
                };
                let (y, iy) = if b >= size {
                    (!b + size, !b)
                } else {
                    (b, b + size)
                };
                assert!(x.max(ix).max(y).max(iy) < 2 * size);
                [(ix, y), (iy, x)]
            }),
        );
        let (_, id) = strongly_connected_components(2 * size, |v| g.list(v));
        let mut ans = Vec::with_capacity(size);
        for (a, b) in id.iter().zip(id[size..].iter()) {
            if *a == *b {
                return None;
            } else {
                ans.push(*a > *b);
            }
        }
        Some(ans)
    }
}
// ---------- end 2-SAT ----------
// ---------- begin CSR ----------
pub struct CSR {
    size: usize,
    pos: Vec<u32>,
    list: Vec<u32>,
}

impl CSR {
    pub fn new<I>(size: usize, it: I) -> Self
    where
        I: Iterator<Item = (usize, usize)> + Clone,
    {
        let mut pos = vec![0; size + 1];
        for (s, t) in it.clone() {
            assert!(s < size && t < size);
            pos[s + 1] += 1;
        }
        for i in 1..=size {
            pos[i] += pos[i - 1];
        }
        let mut x = pos[..size].to_vec();
        let mut list = vec![0; pos[size] as usize];
        for (s, t) in it {
            let x = &mut x[s];
            list[*x as usize] = t as u32;
            *x += 1;
        }
        CSR { size, pos, list }
    }
    pub fn list(&self, v: usize) -> impl Iterator<Item = usize> + '_ {
        assert!(v < self.size);
        let s = self.pos[v] as usize;
        let t = self.pos[v + 1] as usize;
        self.list[s..t].iter().map(|p| *p as usize)
    }
}
// ---------- end CSR ----------
// ---------- begin strongry connected components ----------
pub fn strongly_connected_components<G, I>(size: usize, graph: G) -> (usize, Vec<usize>)
where
    G: Fn(usize) -> I,
    I: Iterator<Item = usize>,
{
    let mut ord = vec![0; size];
    let mut res = vec![0; size];
    let mut vertex = vec![];
    let mut dfs = vec![];
    let mut id = 0;
    for s in 0..size {
        if ord[s] > 0 {
            continue;
        }
        vertex.push(s);
        ord[s] = vertex.len();
        dfs.push((s, graph(s)));
        while let Some((v, mut it)) = dfs.pop() {
            (|| {
                while let Some(u) = it.next() {
                    if ord[u] == 0 {
                        vertex.push(u);
                        ord[u] = vertex.len();
                        dfs.push((v, it));
                        dfs.push((u, graph(u)));
                        return;
                    }
                }
                let low = graph(v).map(|u| ord[u]).min().unwrap_or(ord[v]);
                if low < ord[v] {
                    ord[v] = low;
                    return;
                }
                while let Some(u) = vertex.pop() {
                    ord[u] = !0;
                    res[u] = id;
                    if u == v {
                        break;
                    }
                }
                id += 1;
            })();
        }
    }
    res.iter_mut().for_each(|p| *p = id - 1 - *p);
    (id, res)
}
// ---------- end strongry connected components ----------
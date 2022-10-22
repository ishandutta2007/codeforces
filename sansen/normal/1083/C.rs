// ---------- begin segment tree Point Update Range Query ----------
pub struct SegmentTreePURQ<T, F> {
    n: usize,
    size: usize,
    data: Vec<T>,
    e: T,
    op: F,
}

impl<T, F> SegmentTreePURQ<T, F>
where
    T: Clone,
    F: Fn(&T, &T) -> T,
{
    pub fn new(n: usize, e: T, op: F) -> Self {
        assert!(n > 0);
        let size = n.next_power_of_two();
        let data = vec![e.clone(); 2 * size];
        SegmentTreePURQ {
            n,
            size,
            data,
            e,
            op,
        }
    }
    pub fn update_tmp(&mut self, x: usize, v: T) {
        assert!(x < self.n);
        self.data[x + self.size] = v;
    }
    pub fn update_all(&mut self) {
        for i in (1..self.size).rev() {
            self.data[i] = (self.op)(&self.data[2 * i], &self.data[2 * i + 1]);
        }
    }
    pub fn update(&mut self, x: usize, v: T) {
        assert!(x < self.n);
        let mut x = x + self.size;
        self.data[x] = v;
        x >>= 1;
        while x > 0 {
            self.data[x] = (self.op)(&self.data[2 * x], &self.data[2 * x + 1]);
            x >>= 1;
        }
    }
    pub fn find(&self, l: usize, r: usize) -> T {
        assert!(l <= r && r <= self.n);
        if l == r {
            return self.e.clone();
        }
        let mut l = self.size + l;
        let mut r = self.size + r;
        let mut x = self.e.clone();
        let mut y = self.e.clone();
        while l < r {
            if l & 1 == 1 {
                x = (self.op)(&x, &self.data[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                y = (self.op)(&self.data[r], &y);
            }
            l >>= 1;
            r >>= 1;
        }
        (self.op)(&x, &y)
    }
    pub fn max_right<P>(&self, l: usize, op: P) -> usize
    where
        P: Fn(&T) -> bool,
    {
        assert!(l <= self.n);
        if l == self.n {
            return l;
        }
        let mut l = l + self.size;
        let mut sum = self.e.clone();
        while {
            l >>= l.trailing_zeros();
            let sm = (self.op)(&sum, &self.data[l]);
            if !op(&sm) {
                while l < self.size {
                    l = 2 * l;
                    let sm = (self.op)(&sum, &self.data[l]);
                    if op(&sm) {
                        l += 1;
                        sum = sm;
                    }
                }
                return l - self.size;
            }
            sum = sm;
            l += 1;
            l & (!l + 1) != l
        } {}
        self.n
    }
}
// ---------- end segment tree Point Update Range Query ----------
// ---------- begin sparse table ----------
pub struct SparseTable<T, F> {
    table: Vec<Vec<T>>,
    size: usize,
    op: F,
}

impl<T, F> SparseTable<T, F>
where
    F: Fn(&T, &T) -> T,
{
    pub fn new(mut a: Vec<T>, op: F) -> Self {
        assert!(a.len() > 0);
        let size = a.len();
        let mut table = vec![];
        let mut w = 1;
        while w + 1 <= a.len() {
            let next = a
                .windows(w + 1)
                .map(|a| op(&a[0], &a[w]))
                .collect::<Vec<_>>();
            table.push(a);
            a = next;
            w <<= 1;
        }
        table.push(a);
        SparseTable {
            table: table,
            size: size,
            op: op,
        }
    }
    pub fn find(&self, l: usize, r: usize) -> T {
        assert!(l < r && r <= self.size);
        let k = (r - l + 1).next_power_of_two().trailing_zeros() as usize - 1;
        let table = &self.table[k];
        (self.op)(&table[l], &table[r - (1 << k)])
    }
}
// ---------- end sparse table ----------
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

// N
// vp_v
// 0..n
// 
// 1. p_u, p_v 
// 2. mex
//
// 
// [l, r] 
// [l, r] 
// 
// 
// 
// 2
// 
// 2
// 
// s, t, lca(s, t) 
// (l, r) 
// L(v), R(v)
// v (=(x, y)) 
// L(lca(s, t)) <= L(v) && R(v) <= R(lca(s, t))
// 
//  L(v) <= L(s) && R(s) <= R(v)
//  or
//  L(v) <= L(t) && R(t) <= R(v)
// 
//
// 

fn dfs(
    v: usize,
    d: u32,
    range: &mut [(usize, usize)],
    data: &mut Vec<(u32, u32)>,
    child: &[Vec<usize>],
) {
    range[v].0 = data.len();
    data.push((d, v as u32));
    for &u in child[v].iter() {
        dfs(u, d + 1, range, data, child);
        data.push((d, v as u32));
    }
    range[v].1 = data.len();
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let mut p = sc.next_vec::<usize>(n);
    let mut child = vec![vec![]; n];
    for i in 1..n {
        let x = sc.next::<usize>() - 1;
        child[x].push(i);
    }
    let mut data = vec![];
    let mut range = vec![(0, 0); n];
    dfs(0, 0, &mut range, &mut data, &child);
    let table = SparseTable::new(data, |a, b| std::cmp::min(*a, *b));
    let lca = |a: usize, b: usize| -> usize {
        let a = range[a];
        let b = range[b];
        table.find(a.0.min(b.0), a.1.max(b.1)).1 as usize
    };
    let on_path_pc = |p: usize, c: usize, v: usize| -> bool {
        let p = range[p];
        let c = range[c];
        let v = range[v];
        assert!(p.0 <= c.0 && c.1 <= p.1);
        p.0 <= v.0 && v.1 <= p.1 && v.0 <= c.0 && c.1 <= v.1
    };
    let on_path = |a: usize, b: usize, v: usize| -> bool {
        let lca = lca(a, b);
        on_path_pc(lca, a, v) || on_path_pc(lca, b, v)
    };
    // None
    // Some(Some((a, b)))
    type T = Option<Option<(usize, usize)>>;
    let merge = |a: &T, b: &T| -> T {
        if a.is_none() || b.is_none() {
            return a.clone().or(b.clone());
        }
        match (a.clone(), b.clone()) {
            (Some(Some(a)), Some(Some(b))) => {
                let v = [a.0, a.1, b.0, b.1];
                for s in v.iter() {
                    for t in v.iter() {
                        if v.iter()
                            .all(|v| *v == *s || *v == *t || on_path(*s, *t, *v))
                        {
                            return Some(Some((*s, *t)));
                        }
                    }
                }
                Some(None)
            }
            _ => Some(None),
        }
    };
    let mut seg = SegmentTreePURQ::new(n, None, merge);
    for (i, p) in p.iter().enumerate() {
        seg.update_tmp(*p, Some(Some((i, i))));
    }
    seg.update_all();
    let q: u32 = sc.next();
    for _ in 0..q {
        let op: u8 = sc.next();
        if op == 1 {
            let x = sc.next::<usize>() - 1;
            let y = sc.next::<usize>() - 1;
            p.swap(x, y);
            seg.update(p[x], Some(Some((x, x))));
            seg.update(p[y], Some(Some((y, y))));
        } else {
            let ans = seg.max_right(0, |s| {
                match s.clone() {
                    None | Some(Some(_)) => true,
                    _ => false,
                }
            });
            writeln!(out, "{}", ans).ok();
        }
    }
}
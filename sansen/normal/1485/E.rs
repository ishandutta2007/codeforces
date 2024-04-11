// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T, F> {
        size: usize,
        data: Vec<T>,
        e: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T, F> PURQ<T, F>
    where
        T: Clone,
        F: Fn(&T, &T) -> T,
    {
        pub fn new(size: usize, e: T, op: F) -> PURQ<T, F> {
            let size = size.next_power_of_two();
            PURQ {
                size,
                data: vec![e.clone(); 2 * size],
                e: e,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            assert!(x < self.size);
            let mut x = x + self.size;
            let data = &mut self.data;
            data[x] = v;
            x >>= 1;
            while x > 0 {
                data[x] = (self.op)(&data[2 * x], &data[2 * x + 1]);
                x >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            assert!(x < self.size);
            self.data[x + self.size] = v;
        }
        pub fn update_all(&mut self) {
            let data = &mut self.data;
            for k in (1..self.size).rev() {
                data[k] = (self.op)(&data[2 * k], &data[2 * k + 1]);
            }
        }
        pub fn find(&self, l: usize, r: usize) -> T {
            assert!(l <= r && r <= self.size);
            if l == r {
                return self.e.clone();
            }
            let mut p = self.e.clone();
            let mut q = self.e.clone();
            let mut l = l + self.size;
            let mut r = r + self.size;
            let data = &self.data;
            while l < r {
                if l & 1 == 1 {
                    p = (self.op)(&p, &data[l]);
                    l += 1;
                }
                if r & 1 == 1 {
                    r -= 1;
                    q = (self.op)(&data[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
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

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut g = vec![vec![]; n];
        for i in 1..n {
            let v = sc.next::<usize>() - 1;
            g[i].push(v);
            g[v].push(i);
        }
        let mut a = vec![0i64; n];
        for a in a[1..].iter_mut() {
            *a = sc.next();
        }
        let mut dfs = vec![0];
        while let Some(v) = dfs.pop() {
            for u in g[v].clone() {
                let x = g[u].iter().position(|p| *p == v).unwrap();
                g[u].remove(x);
                dfs.push(u);
            }
        }
        let mut dp = vec![0; n];
        let mut v = vec![0];
        let inf = 1_000_000_000_000_000_000i64 + 1;
        let mut b = a.iter().cloned().enumerate().map(|p| (p.1, p.0)).collect::<Vec<_>>();
        b.sort();
        let mut seg = segment_tree::PURQ::new(n, (-inf, -inf), |a, b| (a.0.max(b.0), a.1.max(b.1)));
        while !g[v[0]].is_empty() {
            let mut c = vec![];
            for v in v.iter() {
                c.extend_from_slice(&g[*v]);
            }
            let a_max = c.iter().map(|c| a[*c]).max().unwrap();
            let a_min = c.iter().map(|c| a[*c]).min().unwrap();
            for _ in 0..2 {
                for &v in v.iter() {
                    let val = dp[v];
                    for &u in g[v].iter() {
                        dp[u].chmax(val + (a_max - a[u]).max(a[u] - a_min));
                        let x = b.binary_search(&(a[u], u)).unwrap();
                        dp[u].chmax(seg.find(0, x).0 + a[u]);
                        dp[u].chmax(seg.find(x, n).1 - a[u]);
                        seg.update(x, (dp[v] - a[u], dp[v] + a[u]));
                    }
                    g[v].reverse();
                }
                for &v in v.iter() {
                    for &u in g[v].iter() {
                        let x = b.binary_search(&(a[u], u)).unwrap();
                        seg.update(x, (-inf, -inf));
                    }
                }
                v.reverse();
            }
            v = c;
        }
        let ans = dp.into_iter().max().unwrap();
        writeln!(out, "{}", ans).ok();
    }
}
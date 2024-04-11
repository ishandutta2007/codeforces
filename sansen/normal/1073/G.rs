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
// O(N (log N)^2)
// 
// O(N log N) log2
// ---------- begin Suffix Array ----------
fn suffix_array<T: Ord>(s: &[T]) -> Vec<usize> {
    let n = s.len();
    let mut z = s.iter().collect::<Vec<_>>();
    z.sort();
    z.dedup();
    let mut ord = Vec::with_capacity(n);
    for s in s.iter() {
        ord.push(z.binary_search(&s).unwrap() as u32 + 1);
    }
    let mut z = (0..n).map(|p| ((ord[p], 0), p)).collect::<Vec<_>>();
    z.sort_by_key(|p| p.0);
    let mut len = 1;
    while len < n {
        for z in z.iter_mut() {
            z.0 = (ord[z.1], ord.get(z.1 + len).map_or(0, |p| *p));
        }
        z.sort_by_key(|p| p.0);
        let mut id = 1;
        let mut prev = z[0].0;
        for z in z.iter_mut() {
            if z.0 != prev {
                id += 1;
                prev = z.0;
            }
            ord[z.1] = id;
        }
        len <<= 1;
    }
    z.into_iter().map(|p| p.1).collect()
}
// ---------- end Suffix Array ----------
// ---------- begin lcp array ----------
fn lcp_array<T: Ord>(s: &[T], sa: &[usize]) -> Vec<usize> {
    let mut isa = vec![0; s.len()];
    for (i, sa) in sa.iter().enumerate() {
        isa[*sa] = i;
    }
    let mut lcp = vec![0; s.len()];
    let mut h = 0;
    for i in 0..sa.len() {
        if isa[i] + 1 < sa.len() {
            let j = sa[isa[i] + 1];
            while i.max(j) + h < sa.len() && s[i + h] == s[j + h] {
                h += 1;
            }
            lcp[isa[i] + 1] = h;
            if h > 0 {
                h -= 1;
            }
        }
    }
    lcp
}
// ---------- end lcp array ----------
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
    let n: usize = sc.next();
    let q: usize = sc.next();
    let s = sc.next_bytes();
    let sa = suffix_array(&s);
    let lcp = lcp_array(&s, &sa);
    let mut isa = vec![0; n];
    for (i, sa) in sa.iter().enumerate() {
        isa[*sa] = i;
    }
    let isa = isa;
    let mut seg = segment_tree::PURQ::new(n, std::usize::MAX, |a, b| std::cmp::min(*a, *b));
    for (i, lcp) in lcp.iter().enumerate() {
        seg.update_tmp(i, *lcp);
    }
    seg.update_all();
    let seg = seg;
    for _ in 0..q {
        let a: usize = sc.next();
        let b: usize = sc.next();
        let mut e = vec![];
        for _ in 0..a {
            let x = sc.next::<usize>() - 1;
            e.push((isa[x], 0));
        }
        for _ in 0..b {
            let x = sc.next::<usize>() - 1;
            e.push((isa[x], 1));
        }
        e.sort();
        let mut ans = 0u64;
        let mut last = 0;
        let mut stack = vec![vec![(0, 0, 0)]; 2];
        for (pos, op) in e {
            if last < pos {
                let h = seg.find(last + 1, pos + 1) as u64;
                for stack in stack.iter_mut() {
                    let mut w = 0;
                    while stack.last().unwrap().0 > h {
                        w += stack.pop().unwrap().1;
                    }
                    if w > 0 {
                        let v = stack.last().unwrap().2;
                        stack.push((h, w, v + h * w));
                    }
                }
                last = pos;
            }
            ans += stack[op ^ 1].last().unwrap().2;
            let h = (n - sa[pos]) as u64;
            let v = stack[op].last().unwrap().2;
            stack[op].push((h, 1, v + h));
        }
        writeln!(out, "{}", ans).ok();
    }
}
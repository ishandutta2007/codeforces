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
use std::collections::*;

type Set<T> = BTreeSet<T>;

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
        let mut a: Vec<usize> = sc.next_vec(n);
        let mut p = vec![(0, 0); m];
        for p in p.iter_mut() {
            p.0 = sc.next::<usize>() - 1;
            p.1 = sc.next::<usize>();
        }
        let mut z = a.clone();
        z.sort();
        z.dedup();
        let mut pos = vec![vec![]; z.len()];
        let mut inv = vec![0; n];
        for (i, a) in a.iter_mut().enumerate() {
            *a = z.binary_search(a).unwrap();
            inv[i] = pos[*a].len();
            pos[*a].push(i);
        }
        p.sort_by_key(|p| (p.0, !p.1));
        p.dedup_by(|a, b| b.1 >= a.1);
        let mut cond = vec![];
        let mut seg = segment_tree::PURQ::new(n, (n, n), |a, b| std::cmp::min(*a, *b));
        let mut x = p.len();
        for i in (0..n).rev() {
            let k = inv[i];
            if k + 1 < pos[a[i]].len() {
                seg.update(i, (pos[a[i]][k + 1], i));
            }
            if x > 0 && p[x - 1].0 == i {
                let (_, r) = p[x - 1];
                x -= 1;
                let mut used = Set::new();
                while seg.find(i, r).0 < r {
                    let (_, k) = seg.find(i, r);
                    seg.update(k, (n, n));
                    if !used.insert(a[k]) {
                        continue;
                    }
                    let pos = &pos[a[k]];
                    let l1 = k;
                    let l2 = pos[inv[k] + 1];
                    let y = pos.lower_bound(&r);
                    let r2 = pos[y - 2];
                    let r1 = pos[y - 1];
                    cond.push((l1, l2, r2, r1));
                }
            }
        }
        if cond.is_empty() {
            writeln!(out, "0").ok();
            continue;
        }
        let mut ban = vec![false; n];
        let mut update = vec![vec![]; n];
        let mut set = Set::new();
        for (i, &(l1, l2, r2, r1)) in cond.iter().enumerate() {
            ban[l2] = true;
            update[l1].push((r2, r1, i));
            set.insert((r2, i));
        }
        let mut ans = n;
        for i in 0..n {
            ans = ans.min(set.iter().next_back().unwrap().0 + 1 - i);
            if ban[i] {
                break;
            }
            for &(r2, r1, k) in update[i].iter() {
                set.remove(&(r2, k));
                set.insert((r1, k));
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
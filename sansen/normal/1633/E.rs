fn main() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1, i64); m],
        p: usize,
        k: usize,
        a: i64,
        b: i64,
        c: i64,
        q: [i64; p],
    }
    let mut e = e;
    e.sort_by_key(|e| e.2);
    let mut range = vec![(0, 10i64.pow(10)); m];
    let mut g = vec![vec![]; n];
    for (i, &(a, b, w)) in e.iter().enumerate() {
        let mut parent = vec![(n, 0); n];
        let mut dfs = vec![a];
        while let Some(v) = dfs.pop() {
            for &(u, i) in g[v].iter() {
                if u != parent[v].0 {
                    parent[u] = (v, i);
                    dfs.push(u);
                }
            }
        }
        if parent[b].0 == n {
            range[i].0 = 0;
        } else {
            let mut weight = std::i64::MAX;
            let mut index = 0;
            let mut pos = b;
            while pos != a {
                let (p, k) = parent[pos];
                let w = e[k].2;
                if w < weight {
                    weight = w;
                    index = k;
                }
                pos = p;
            }
            let (s, t, v) = e[index];
            let mid = (v + w) / 2;
            range[index].1 = mid;
            range[i].0 = mid + 1;
            g[s].retain(|e| e.0 != t);
            g[t].retain(|e| e.0 != s);
        }
        g[a].push((b, i));
        g[b].push((a, i));
    }
    let mut z = vec![];
    z.extend(range.iter().map(|p| p.0));
    z.extend(range.iter().map(|p| p.1));
    z.extend(e.iter().map(|p| p.2));
    z.sort();
    z.dedup();
    let mut imos = vec![(0i64, 0i64); z.len() + 1];
    for (&(l, r), w) in range.iter().zip(e.iter().map(|e| e.2)) {
        if l > r {
            continue;
        }
        let a = z.binary_search(&l).unwrap();
        let b = z.binary_search(&w).unwrap();
        let c = z.binary_search(&r).unwrap();
        imos[a].0 -= 1;
        imos[a].1 += w;
        imos[b].0 += 1;
        imos[b].1 -= w;
        imos[b].0 += 1;
        imos[b].1 -= w;
        imos[c + 1].0 -= 1;
        imos[c + 1].1 += w;
    }
    for i in 1..imos.len() {
        imos[i].0 += imos[i - 1].0;
        imos[i].1 += imos[i - 1].1;
    }
    let mut xor = 0;
    for &q in q.iter() {
        let x = z.upper_bound(&q) - 1;
        let (a, b) = imos[x];
        xor ^= a * q + b;
    }
    let mut q = q[p - 1];
    for _ in p..k {
        q = (q * a + b) % c;
        let x = z.upper_bound(&q) - 1;
        let (a, b) = imos[x];
        xor ^= a * q + b;
    }
    println!("{}", xor);
}

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
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------
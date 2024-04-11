// ---------- begin sparse table ----------
pub struct SparseTable<T, F> {
    table: Vec<Vec<T>>,
    size: usize,
    op: F,
}

impl<T, F> SparseTable<T, F>
where
    F: Fn(&T, &T) -> T
{
    pub fn new(mut a: Vec<T>, op: F) -> Self {
        assert!(a.len() > 0);
        let size = a.len();
        let mut table = vec![];
        let mut w = 1;
        while w + 1 <= a.len() {
            let next = a.windows(w + 1).map(|a| op(&a[0], &a[w])).collect::<Vec<_>>();
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
//---------- begin union_find ----------
pub struct DSU {
    p: Vec<i32>,
}
impl DSU {
    pub fn new(n: usize) -> DSU {
        assert!(n < std::i32::MAX as usize);
        DSU { p: vec![-1; n] }
    }
    pub fn init(&mut self) {
        self.p.iter_mut().for_each(|p| *p = -1);
    }
    pub fn root(&self, mut x: usize) -> usize {
        assert!(x < self.p.len());
        while self.p[x] >= 0 {
            x = self.p[x] as usize;
        }
        x
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.p.len() && y < self.p.len());
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.p.len() && y < self.p.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            return None;
        }
        if self.p[x] > self.p[y] {
            std::mem::swap(&mut x, &mut y);
        }
        self.p[x] += self.p[y];
        self.p[y] = x as i32;
        Some((x, y))
    }
    pub fn parent(&self, x: usize) -> Option<usize> {
        assert!(x < self.p.len());
        let p = self.p[x];
        if p >= 0 {
            Some(p as usize)
        } else {
            None
        }
    }
    pub fn sum<F>(&self, mut x: usize, mut f: F) -> usize
    where
        F: FnMut(usize),
    {
        while let Some(p) = self.parent(x) {
            f(x);
            x = p;
        }
        x
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.p.len());
        let r = self.root(x);
        (-self.p[r]) as usize
    }
}
//---------- end union_find ----------
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 
// 2
// 
//
// 
// 
// 
// 
// 
// 
// 
// 
// /2
//
//

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); 2 * n],
    }
    let mut g = vec![vec![]; 2 * n];
    let mut dsu = DSU::new(2 * n);
    for &(a, b) in e.iter() {
        g[a].push(b);
        g[b].push(a);
        dsu.unite(a, b);
    }
    let mut ans = 0usize;
    for root in 0..(2 * n) {
        if root != dsu.root(root) {
            continue;
        }
        let size = dsu.size(root);
        let mut edge = vec![];
        let mut pos = root;
        let mut parent = root;
        for _ in 0..size {
            let v = *g[pos].iter().find(|&v| *v != parent).unwrap();
            edge.push((pos, v));
            parent = pos;
            pos = v;
        }
        let mut left = vec![(0, 0); 2 * size];
        let mut right = vec![(0, 0); 2 * size];
        for (i, e) in edge.iter().enumerate() {
            let mut x = e.0;
            let mut y = e.1;
            if x > y {
                std::mem::swap(&mut x, &mut y);
            }
            left[i] = (x, x);
            left[i + size] = (x, x);
            right[i] = (y, y);
            right[i + size] = (y, y);
        }
        let left = SparseTable::new(left, |a, b| (a.0.min(b.0), a.1.max(b.1)));
        let right = SparseTable::new(right, |a, b| (a.0.min(b.0), a.1.max(b.1)));
        for len in 1..=size {
            for s in 0..size {
                let l = left.find(s, s + len);
                let r = right.find(s, s + len);
                if len % 2 == 1 {
                    ans += (l.0 + 1) * (n - l.1) * (r.0 - n + 1) * (2 * n - r.1);
                } else {
                    ans -= (l.0 + 1) * (n - l.1) * (r.0 - n + 1) * (2 * n - r.1);
                }
                if len == size && s + 1 == size / 2 {
                    break;
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
//---------- begin union_find ----------
pub struct DSU {
    parent: Vec<u32>,
    size: Vec<u32>,
    stack: Vec<Option<(u32, u32)>>,
}

impl DSU {
    pub fn new(n: usize) -> DSU {
        assert!(n < std::u32::MAX as usize);
        let mut res = DSU {
            parent: vec![0; n],
            size: vec![1; n],
            stack: vec![],
        };
        res.init();
        res
    }
    pub fn init(&mut self) {
        self.stack.clear();
        for (i, (parent, size)) in self.parent.iter_mut().zip(self.size.iter_mut()).enumerate() {
            *parent = i as u32;
            *size = 1;
        }
    }
    pub fn root(&self, mut x: usize) -> usize {
        assert!(x < self.parent.len());
        while self.parent[x] != x as u32 {
            x = self.parent[x] as usize;
        }
        x
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            self.stack.push(None);
            return None;
        }
        if (self.size[x], x) < (self.size[y], y) {
            std::mem::swap(&mut x, &mut y);
        }
        self.size[x] += self.size[y];
        self.parent[y] = x as u32;
        self.stack.push(Some((x as u32, y as u32)));
        Some((x, y))
    }
    pub fn parent(&self, x: usize) -> Option<usize> {
        assert!(x < self.parent.len());
        let p = self.parent[x];
        if p != x as u32 {
            Some(p as usize)
        } else {
            None
        }
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.parent.len());
        let r = self.root(x);
        self.size[r] as usize
    }
    pub fn undo(&mut self) -> Option<(usize, usize)> {
        self.stack.pop().unwrap().map(|(x, y)| {
            let x = x as usize;
            let y = y as usize;
            self.size[x] -= self.size[y];
            self.parent[y] = y as u32;
            (x, y)
        })
    }
}
//---------- end union_find ----------
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T, F> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(&T, &T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            let a = &mut self.a;
            for k in (1..(self.n)).rev() {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            let a = &self.a;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(&p, &a[l]);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(&a[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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

//

// N <= 2 * 10^5, Q <= 5 * 10^5
// TL
// 
// 
// 
// 
// 
// 
// 

use std::io::Write;

fn run() {
    input! {
        n: usize,
        m: usize,
        q: usize,
        val: [u32; n],
        e: [(usize1, usize1); m],
        ask: [(u8, usize1); q],
    }
    let mut dsu = DSU::new(n);
    let mut del = vec![false; m];
    for &(op, k) in ask.iter() {
        if op == 2 {
            del[k] = true;
        }
    }
    let mut offset = vec![0; n];
    for (&(a, b), del) in e.iter().zip(del.iter()) {
        if !*del {
            if let Some((a, b)) = dsu.unite(a, b) {
                dsu.undo();
                offset[b] = dsu.size(a);
                dsu.unite(a, b);
            }
        }
    }
    let mut width = vec![0; q];
    for (width, &(op, k)) in width.iter_mut().zip(ask.iter()).rev() {
        if op == 2 {
            let (a, b) = e[k];
            if let Some((a, b)) = dsu.unite(a, b) {
                dsu.undo();
                offset[b] = dsu.size(a);
                dsu.unite(a, b);
            }
        } else {
            *width = dsu.size(k);
        }
    }
    let mut r = vec![];
    for i in 0..n {
        if i == dsu.root(i) {
            r.push(i);
        }
    }
    for r in r.windows(2) {
        let (a, b) = (r[0], r[1]);
        if let Some((a, b)) = dsu.unite(a, b) {
            dsu.undo();
            offset[b] = dsu.size(a);
            dsu.unite(a, b);
        }
    }
    let mut index = vec![0; n];
    for i in 0..n {
        let mut pos = i;
        let mut sum = offset[pos];
        while let Some(p) = dsu.parent(pos) {
            pos = p;
            sum += offset[pos];
        }
        index[i] = sum;
    }
    for _ in r.windows(2) {
        dsu.undo();
    }
    let mut seg = segment_tree::PURQ::new(n, (0, n), |a, b| std::cmp::max(*a, *b));
    for (i, &val) in val.iter().enumerate() {
        let k = index[i];
        seg.update_tmp(k, (val, k));
    }
    seg.update_all();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (&(op, k), &width) in ask.iter().zip(width.iter()) {
        if op == 1 {
            let l = index[dsu.root(k)];
            let r = l + width;
            let (val, k) = seg.find(l, r);
            if k < n {
                seg.update(k, (0, n));
            }
            writeln!(out, "{}", val).ok();
        } else {
            dsu.undo();
        }
    }
}

fn main() {
    run();
}
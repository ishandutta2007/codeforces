// ---------- begin Heavy-Light decomposition ----------
pub struct HLD {
    size: usize,
    edge: Vec<(usize, usize)>,
    child: Vec<Vec<usize>>,
    path_root: Vec<usize>,
    parent: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
    inverse: Vec<usize>,
}

impl HLD {
    pub fn new(size: usize) -> Self {
        assert!(size <= 10usize.pow(8));
        HLD {
            size: size,
            edge: Vec::with_capacity(size - 1),
            child: Vec::new(),
            path_root: Vec::new(),
            parent: Vec::new(),
            left: Vec::new(),
            right: Vec::new(),
            inverse: Vec::new(),
        }
    }
    pub fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a != b && a < self.size && b < self.size);
        self.edge.push((a, b));
    }
    pub fn build(&mut self, root: usize) {
        assert!(self.edge.len() + 1 == self.size);
        let size = self.size;
        let mut cnt = vec![0; size];
        for &(a, b) in self.edge.iter() {
            cnt[a] += 1;
            cnt[b] += 1;
        }
        let mut child = cnt
            .into_iter()
            .map(|c| Vec::with_capacity(c))
            .collect::<Vec<_>>();
        for &(a, b) in self.edge.iter() {
            child[a].push(b);
            child[b].push(a);
        }
        let mut parent = vec![size; size];
        let mut q = Vec::with_capacity(size);
        q.push(root);
        parent[root] = root;
        for i in 0..size {
            let v = q[i];
            for u in child[v].clone() {
                assert!(parent[u] == size);
                parent[u] = v;
                let k = child[u].iter().position(|e| *e == v).unwrap();
                child[u].remove(k);
                q.push(u);
            }
        }
        let mut sum = vec![1; size];
        for &v in q.iter().rev() {
            let child = &mut child[v];
            if !child.is_empty() {
                let mut max = (0, 0);
                for (i, &u) in child.iter().enumerate() {
                    sum[v] += sum[u];
                    max = std::cmp::max(max, (sum[u], i));
                }
                child.swap(0, max.1);
            }
        }
        let mut path_root = (0..size).collect::<Vec<_>>();
        let mut left = vec![0; size];
        let mut right = vec![0; size];
        let mut dfs = vec![(root, false)];
        let mut id = 0;
        while let Some((v, end)) = dfs.pop() {
            if end {
                right[v] = id;
                continue;
            }
            left[v] = id;
            id += 1;
            dfs.push((v, true));
            let child = &child[v];
            if !child.is_empty() {
                for &u in child.iter().skip(1) {
                    path_root[u] = u;
                    dfs.push((u, false));
                }
                let u = child[0];
                path_root[u] = path_root[v];
                dfs.push((u, false));
            }
        }
        let mut inverse = vec![size; size];
        for (i, l) in left.iter().enumerate() {
            inverse[*l] = i;
        }
        self.child = child;
        self.parent = parent;
        self.left = left;
        self.right = right;
        self.path_root = path_root;
        self.inverse = inverse;
    }
    pub fn lca(&self, mut a: usize, mut b: usize) -> usize {
        assert!(a < self.size && b < self.size);
        let path = &self.path_root;
        let parent = &self.parent;
        let index = &self.left;
        while path[a] != path[b] {
            if index[a] > index[b] {
                a = parent[path[a]];
            } else {
                b = parent[path[b]];
            }
        }
        (index[a], a).min((index[b], b)).1
    }
    pub fn path(
        &self,
        src: usize,
        dst: usize,
        up: &mut Vec<(usize, usize)>,
        down: &mut Vec<(usize, usize)>,
    ) {
        assert!(src < self.size && dst < self.size);
        up.clear();
        down.clear();
        let path = &self.path_root;
        let parent = &self.parent;
        let index = &self.left;
        let mut x = src;
        let mut y = dst;
        while path[x] != path[y] {
            if index[x] > index[y] {
                let p = path[x];
                assert!(p == path[p]);
                up.push((index[p], index[x] + 1));
                x = parent[p];
            } else {
                let p = path[y];
                assert!(p == path[p]);
                down.push((index[p], index[y] + 1));
                y = parent[p];
            }
        }
        if index[x] <= index[y] {
            down.push((index[x], index[y] + 1));
        } else {
            up.push((index[y], index[x] + 1));
        }
        down.reverse();
    }
    pub fn sub_tree(&self, v: usize) -> (usize, usize) {
        assert!(v < self.size);
        (self.left[v], self.right[v])
    }
    pub fn parent(&self, v: usize) -> Option<usize> {
        assert!(v < self.size);
        let p = self.parent[v];
        if p == v {
            None
        } else {
            Some(p)
        }
    }
    // s -> t 2
    pub fn next(&self, s: usize, t: usize) -> usize {
        assert!(s < self.size && t < self.size && s != t);
        let (a, b) = self.sub_tree(s);
        let (c, d) = self.sub_tree(t);
        if !(a <= c && d <= b) {
            return self.parent[s];
        }
        let mut pos = t;
        let mut pre = t;
        while self.path_root[s] != self.path_root[pos] {
            pre = self.path_root[pos];
            pos = self.parent[pre];
        }
        if s == pos {
            pre
        } else {
            self.child[s][0]
        }
    }
    pub fn vertex(&self, x: usize) -> usize {
        assert!(x < self.size);
        self.inverse[x]
    }
}
// ---------- end Heavy-Light decomposition ----------

mod wavelet_matrix {
    pub struct BitVector {
        size: usize,
        array: Vec<usize>,
        sum: Vec<usize>,
    }

    impl BitVector {
        const WIDTH: usize = std::mem::size_of::<usize>() * 8;
        const SHIFT: usize = BitVector::WIDTH.trailing_zeros() as usize;
        pub fn new(array: &[bool]) -> Self {
            const W: usize = BitVector::WIDTH;
            let size = array.len();
            let mut buf = vec![0usize; array.len() / W + 1];
            for (buf, a) in buf.iter_mut().zip(array.chunks(W)) {
                for (i, a) in a.iter().enumerate() {
                    *buf |= (*a as usize) << i;
                }
            }
            let mut sum = vec![0usize; array.len() / W + 1];
            let mut acc = 0;
            for (sum, buf) in sum.iter_mut().skip(1).zip(buf.iter()) {
                acc += buf.count_ones() as usize;
                *sum = acc;
            }
            BitVector {
                size,
                array: buf,
                sum,
            }
        }
        pub fn rank(&self, k: usize) -> usize {
            assert!(k <= self.size);
            const S: usize = BitVector::SHIFT;
            let q = k >> S;
            let r = k & ((1 << S) - 1);
            self.sum[q] + (self.array[q] & ((1 << r) - 1)).count_ones() as usize
        }
        pub fn select(&self, _k: usize) -> Option<usize> {
            unimplemented!();
        }
        pub fn at(&self, k: usize) -> bool {
            assert!(k < self.size);
            const S: usize = BitVector::SHIFT;
            self.array[k >> S] >> (k & ((1 << S) - 1)) & 1 == 1
        }
    }

    pub struct WaveletMatrix {
        size: usize,
        mat: Vec<BitVector>,
        zeros: Vec<usize>,
    }

    impl WaveletMatrix {
        pub fn new(array: &[u64], bits: usize) -> Self {
            assert!(0 < bits && bits <= 64);
            assert!(bits == 64 || array.iter().all(|p| *p < (1 << bits)));
            let size = array.len();
            let mut buf = vec![false; size];
            let mut front = Vec::with_capacity(size);
            let mut back = Vec::with_capacity(size);
            let mut array = array.to_vec();
            let mut mat = Vec::with_capacity(bits);
            let mut zeros = Vec::with_capacity(bits);
            for i in (0..bits).rev() {
                for (buf, a) in buf.iter_mut().zip(array.iter()) {
                    let x = ((*a >> i) & 1) == 1;
                    *buf = x;
                    if x {
                        back.push(*a);
                    } else {
                        front.push(*a);
                    }
                }
                mat.push(BitVector::new(&buf));
                zeros.push(front.len());
                array.clear();
                array.extend(front.drain(..));
                array.extend(back.drain(..));
            }
            mat.reverse();
            zeros.reverse();
            WaveletMatrix { size, mat, zeros }
        }

        // k 
        pub fn access(&self, mut k: usize) -> u64 {
            assert!(k < self.size);
            let mut ans = 0;
            for (bits, zero) in self.mat.iter().zip(self.zeros.iter()).rev() {
                let x = bits.at(k);
                let c = bits.rank(k);
                ans = (ans << 1) | x as u64;
                if x {
                    k = *zero + c;
                } else {
                    k -= c;
                }
            }
            ans
        }

        // [0..k) val
        pub fn rank(&self, mut k: usize, val: u64) -> usize {
            assert!(k <= self.size);
            assert!(val < (1 << self.mat.len() as u64));
            let mut l = 0;
            for (i, (bits, zero)) in self.mat.iter().zip(self.zeros.iter()).enumerate().rev() {
                let l_cnt = bits.rank(l);
                let k_cnt = bits.rank(k);
                if (val >> i) & 1 == 1 {
                    l = *zero + l_cnt;
                    k = *zero + k_cnt;
                } else {
                    l = l - l_cnt;
                    k = k - k_cnt;
                }
            }
            k - l
        }

        // k val
        pub fn select(&self, _k: usize, _val: u64) -> Option<usize> {
            unimplemented!();
        }

        // [l..r) k
        pub fn quantile(&self, mut l: usize, mut r: usize, mut k: usize) -> u64 {
            assert!(r <= self.size);
            assert!(l < r);
            assert!(k < r - l);
            let mut ans = 0;
            for (i, (bits, zero)) in self.mat.iter().zip(self.zeros.iter()).enumerate().rev() {
                let l_cnt = bits.rank(l);
                let r_cnt = bits.rank(r);
                let z_cnt = (r - l) - (r_cnt - l_cnt);
                if k >= z_cnt {
                    l = *zero + l_cnt;
                    r = *zero + r_cnt;
                    ans |= 1 << i as u64;
                    k -= z_cnt;
                } else {
                    l = l - l_cnt;
                    r = r - r_cnt;
                }
            }
            ans
        }

        // [s, e)  low <= x x
        pub fn next_value(&self, s: usize, e: usize, low: u64) -> Option<u64> {
            assert!(s <= e);
            assert!(e <= self.size);
            if low >= (1 << self.mat.len()) {
                return None;
            }
            let c = self.range_freq(s, e, low);
            if c < e - s {
                Some(self.quantile(s, e, c))
            } else {
                None
            }
        }

        // [s, e)  x <= up x
        pub fn prev_value(&self, s: usize, e: usize, up: u64) -> Option<u64> {
            assert!(s <= e);
            assert!(e <= self.size);
            if s == e {
                return None;
            }
            if up >= (1 << self.mat.len()) {
                return Some(self.quantile(s, e, e - s - 1));
            }
            let c = self.range_freq(s, e, up + 1);
            if c > 0 {
                Some(self.quantile(s, e, c - 1))
            } else {
                None
            }
        }

        // [s, e)  v < y v
        pub fn range_freq(&self, mut l: usize, mut r: usize, x: u64) -> usize {
            assert!(l <= r);
            assert!(r <= self.size);
            assert!(x <= (1 << self.mat.len()));
            if x == 1 << self.mat.len() {
                return r - l;
            }
            let mut ans = 0;
            for (i, (bits, zero)) in self.mat.iter().zip(self.zeros.iter()).enumerate().rev() {
                let l_cnt = bits.rank(l);
                let r_cnt = bits.rank(r);
                let z_cnt = (r - l) - (r_cnt - l_cnt);
                if x >> i & 1 == 1 {
                    l = *zero + l_cnt;
                    r = *zero + r_cnt;
                    ans += z_cnt;
                } else {
                    l = l - l_cnt;
                    r = r - r_cnt;
                }
            }
            ans
        }
    }
}
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

use std::io::Write;

// N <= 10^5
// 2sec
//
// 
// 
// k(1 <= k <= N)
//  1
//  
//
// a_1, a_2, ..., a_k 
// 
// 
// max top2top1
// top1top1-top2 (?)
// 
// mintop2
// min
// top2-min OK
// 3
// 2 (max - min)/2 
//
// 
//
// 
// 
// 
// ...
//
// 
// WM + HLD 
// 
// 
// 
// 
// 

fn run() {
    input! {
        n: usize,
        e: [(usize, usize); n],
    }
    if n == 1 {
        println!("0");
        return;
    }
    let mut root = 0;
    let mut hld = HLD::new(n);
    for (a, b) in e {
        if a == 0 {
            root = b - 1;
        } else {
            hld.add_edge(a - 1, b - 1);
        }
    }
    let root = root;
    hld.build(root);
    let hld = hld;
    let mut size = vec![1; n];
    let mut array = vec![0; n];
    for i in (0..n).rev() {
        let v = hld.vertex(i);
        let (l, r) = hld.sub_tree(v);
        size[v] = (r - l) as u64;
        array[i] = size[v] as u64;
    }
    let wm = wavelet_matrix::WaveletMatrix::new(&array, 17);
    let mut up = vec![];
    let mut down = vec![];
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for v in 0..n {
        let mut a = vec![];
        if v != root {
            a.push((n as u64 - size[v], 1));
        }
        for &u in hld.child[v].iter() {
            a.push((size[u], 0));
        }
        a.sort();
        let (max, op) = a.pop().unwrap();
        let ans = if a.len() == 0 {
            max
        } else {
            let min = a[0].0;
            let top2 = a.last().unwrap().0;
            let find = |l: usize, r: usize, sub: u64| -> u64 {
                let mut ans = max;
                if let Some(x) = wm.prev_value(l, r, (max - min) / 2 + sub) {
                    if x >= sub {
                        let x = x - sub;
                        ans.chmin(top2.max(min + x).max(max - x));
                    }
                }
                if let Some(x) = wm.next_value(l, r, (max - min + 1) / 2 + sub) {
                    if x >= sub {
                        let x = x - sub;
                        ans.chmin(top2.max(min + x).max(max - x));
                    }
                }
                ans
            };
            if op == 1 {
                let sub = size[v];
                hld.path(root, v, &mut up, &mut down);
                assert!(up.is_empty());
                let mut ans = max;
                for &(l, r) in down.iter() {
                    ans.chmin(find(l, r, sub));
                }
                for p in down.windows(2) {
                    let (l, r) = (p[0].1, p[1].0);
                    ans.chmin(find(l, r, 0));
                }
                if hld.sub_tree(v).1 < n {
                    let (l, r) = (hld.sub_tree(v).1, n);
                    ans.chmin(find(l, r, 0));
                }
                ans
            } else {
                let mut ans = max;
                let u = hld.child[v][0];
                let (l, r) = hld.sub_tree(u);
                ans.chmin(find(l, r, 0));
                ans
            }
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
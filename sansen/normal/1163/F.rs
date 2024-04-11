// ---------- begin SegmentTree Range update Point query ----------
mod segment_tree {
    pub struct RUPQ<T, F> {
        size: usize,
        bit: usize,
        data: Vec<T>,
        e: T,
        op: F,
    }
    impl<T, F> RUPQ<T, F>
    where
        T: Clone,
        F: Fn(&T, &T) -> T,
    {
        pub fn new(size: usize, e: T, op: F) -> Self {
            let size = size.next_power_of_two();
            let bit = size.trailing_zeros() as usize;
            Self {
                size,
                bit,
                data: vec![e.clone(); 2 * size],
                e,
                op,
            }
        }
        pub fn find(&self, x: usize) -> T {
            assert!(x < self.size);
            let mut x = x + self.size;
            let mut ans = self.data[x].clone();
            while x > 1 {
                x >>= 1;
                ans = (self.op)(&ans, &self.data[x]);
            }
            ans
        }
        fn propagate(&mut self, x: usize) {
            let f = std::mem::replace(&mut self.data[x], self.e.clone());
            self.data[2 * x] = (self.op)(&self.data[2 * x], &f);
            self.data[2 * x + 1] = (self.op)(&self.data[2 * x + 1], &f);
        }
        pub fn update(&mut self, l: usize, r: usize, f: T) {
            assert!(l <= r && r <= self.size);
            if l == r {
                return;
            }
            let mut l = l + self.size;
            let mut r = r + self.size;
            for i in (1..=self.bit).rev() {
                if (l >> i) << i != l {
                    self.propagate(l >> i);
                }
                if (r >> i) << i != r {
                    self.propagate((r - 1) >> i);
                }
            }
            while l < r {
                if l & 1 == 1 {
                    self.data[l] = (self.op)(&self.data[l], &f);
                    l += 1;
                }
                if r & 1 == 1 {
                    r -= 1;
                    self.data[r] = (self.op)(&self.data[r], &f);
                }
                l >>= 1;
                r >>= 1;
            }
        }
    }
}
// ---------- end SegmentTree Range update Point query ----------
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

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        m: usize,
        q: usize,
        e: [(usize1, usize1, u64); m],
        ask: [(usize1, u64); q],
    }
    let mut g = vec![vec![]; n];
    for (i, &(a, b, c)) in e.iter().enumerate() {
        g[a].push((b, c, i));
        g[b].push((a, c, i));
    }
    let inf = std::u64::MAX / 10;
    let dijkstra = |src: usize| -> Vec<u64> {
        let mut dp = vec![inf; n];
        dp[src] = 0;
        let mut h = std::collections::BinaryHeap::new();
        h.push(Reverse((0, src)));
        while let Some(Reverse((d, v))) = h.pop() {
            if d > dp[v] {
                continue;
            }
            for &(u, w, _) in g[v].iter() {
                let d = d + w;
                if dp[u].chmin(d) {
                    h.push(Reverse((d, u)));
                }
            }
        }
        dp
    };
    let dp_s = dijkstra(0);
    let dp_t = dijkstra(n - 1);
    let mut path = vec![None; m];
    let mut index = vec![None; n];
    let mut pos = 0;
    let mut id = 0;
    index[0] = Some(0);
    while pos != n - 1 {
        let (u, _, k) = *g[pos]
            .iter()
            .find(|e| dp_t[pos] == dp_t[e.0] + e.1)
            .unwrap();
        path[k] = Some(id);
        id += 1;
        pos = u;
        index[pos] = Some(id);
    }
    let (path, index) = (path, index);
    let left = {
        let mut h = std::collections::BinaryHeap::new();
        let mut left = vec![(inf, n); n];
        for i in 0..n {
            if let Some(k) = index[i] {
                left[i] = (dp_s[i], k);
                h.push(Reverse((dp_s[i], k, i)));
            }
        }
        while let Some(Reverse((d, k, v))) = h.pop() {
            if (d, k) > left[v] {
                continue;
            }
            for &(u, w, _) in g[v].iter() {
                let d = d + w;
                if index[u].is_none() && left[u].chmin((d, k)) {
                    h.push(Reverse((d, k, u)));
                }
            }
        }
        left
    };
    let right = {
        let mut h = std::collections::BinaryHeap::new();
        let mut right = vec![(inf, !0); n];
        for i in 0..n {
            if let Some(k) = index[i] {
                right[i] = (dp_t[i], !k);
                h.push(Reverse((dp_t[i], !k, i)));
            }
        }
        while let Some(Reverse((d, k, v))) = h.pop() {
            if (d, k) > right[v] {
                continue;
            }
            for &(u, w, _) in g[v].iter() {
                let d = d + w;
                if index[u].is_none() && right[u].chmin((d, k)) {
                    h.push(Reverse((d, k, u)));
                }
            }
        }
        right
    };
    let mut seg = segment_tree::RUPQ::new(n, inf, |a, b| std::cmp::min(*a, *b));
    for i in 0..m {
        if path[i].is_some() {
            continue;
        }
        let (a, b, c) = e[i];
        for &(a, b) in [(a, b), (b, a)].iter() {
            let (p, q) = left[a];
            let (r, s) = right[b];
            let s = !s;
            if q < s {
                seg.update(q, s, p + r + c);
            }
        }
    }
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (t, x) in ask {
        let (a, b, _) = e[t];
        let mut ans = (dp_s[a] + dp_t[b]).min(dp_t[a] + dp_s[b]) + x;
        if let Some(k) = path[t] {
            ans = ans.min(seg.find(k));
        } else {
            ans = ans.min(dp_s[n - 1]);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
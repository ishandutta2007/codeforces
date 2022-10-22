// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
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
//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    pub struct UF {
        p: Vec<i32>,
    }
    impl UF {
        pub fn new(n: usize) -> UF {
            UF { p: vec![-1; n] }
        }
        pub fn init(&mut self) {
            for p in self.p.iter_mut() {
                *p = -1;
            }
        }
        pub fn root(&self, mut x: usize) -> usize {
            while self.p[x] >= 0 {
                x = self.p[x] as usize;
            }
            x
        }
        pub fn same(&self, x: usize, y: usize) -> bool {
            self.root(x) == self.root(y)
        }
        pub fn unite(&mut self, mut x: usize, mut y: usize) -> Option<(usize, usize)> {
            x = self.root(x);
            y = self.root(y);
            if x == y {
                return None;
            }
            if self.p[x] > self.p[y] {
                let s = x;
                x = y;
                y = s;
            }
            self.p[x] += self.p[y];
            self.p[y] = x as i32;
            Some((x, y))
        }
        pub fn parent(&self, x: usize) -> Option<usize> {
            let p = self.p[x];
            if p >= 0 {
                Some(p as usize)
            } else {
                None
            }
        }
        pub fn get_size(&self, x: usize) -> usize {
            let r = self.root(x);
            (-self.p[r]) as usize
        }
    }
}
//---------- end union_find ----------
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

use std::cmp::*;

// 0
// 
// s->t 1
// 
// st-1
// N, 2(N - 1) 
// 1s-t
// O(N^2 + M)

fn dfs(v: usize, prev: usize, g: &[Vec<(usize, i64, usize)>], ord: &mut [usize], low: &mut [usize], id: &mut usize, parent: &mut [(usize, i64, usize)]) {
    ord[v] = *id;
    low[v] = *id;
    *id += 1;
    for &(u, c, k) in g[v].iter() {
        if k == prev {
            continue;
        }
        if ord[u] == g.len() {
            parent[u] = (v, c, k);
            dfs(u, k, g, ord, low, id, parent);
            low[v].chmin(low[u]);
        } else {
            low[v].chmin(ord[u]);
        }
    }
}

fn run() {
    input! {
        n: usize,
        m: usize,
        s: usize1,
        t: usize1,
        e: [(usize1, usize1, i64); m],
    }
    let e: Vec<_> = e
        .into_iter()
        .enumerate()
        .map(|(k, (a, b, c))| (a, b, c, k))
        .collect();
    let mut u = union_find::UF::new(n);
    for &(a, b, _, _) in e.iter() {
        u.unite(a, b);
    }
    if !u.same(s, t) {
        println!("0\n0");
        return;
    }
    // s 
    let mut v = vec![];
    for i in 0..n {
        if u.same(s, i) {
            v.push(i);
        }
    }
    let n = v.len();
    let s = v.binary_search(&s).unwrap();
    let t = v.binary_search(&t).unwrap();
    let e: Vec<_> = e
        .into_iter()
        .filter(|&(a, _, _, _)| v.binary_search(&a).is_ok())
        .map(|(a, b, c, k)| {
            let a = v.binary_search(&a).unwrap();
            let b = v.binary_search(&b).unwrap();
            (a, b, c, k)
        })
        .collect();
    // 
    let mut g = vec![vec![]; n];
    for &(a, b, c, k) in e.iter() {
        g[a].push((b, c, k));
        g[b].push((a, c, k));
    }
    let mut parent = vec![(n, m); n];
    parent[s] = (s, m);
    let mut q = std::collections::VecDeque::new();
    q.push_back(s);
    while let Some(v) = q.pop_front() {
        for &(u, _, k) in g[v].iter() {
            if parent[u].0 == n {
                parent[u] = (v, k);
                q.push_back(u);
            }
        }
    }
    let mut path = std::collections::BTreeSet::new();
    let mut pos = t;
    while pos != s {
        let (p, k) = parent[pos];
        path.insert(k);
        pos = p;
    }
    // 
    g.iter_mut().for_each(|g| g.clear());
    for &(a, b, c, k) in e.iter() {
        if !path.contains(&k) {
            g[a].push((b, c, k));
            g[b].push((a, c, k));
        }
    }
    let mut ord = vec![n; n];
    let mut low = vec![n; n];
    let mut id = 0;
    let mut parent = vec![(n, 0, 0); n];
    dfs(s, m, &g, &mut ord, &mut low, &mut id, &mut parent);
    for i in 0..n {
        if ord[i] == n {
            dfs(i, m, &g, &mut ord, &mut low, &mut id, &mut parent);
        }
    }
    // 
    let mut u = union_find::UF::new(n);
    let mut edge = vec![];
    for &(a, b, c, k) in e.iter() {
        if path.contains(&k) || ord[a] < low[b] || ord[b] < low[a] {
            edge.push((a, b, c, k));
        } else {
            u.unite(a, b);
        }
    }
    if u.same(s, t) {
        println!("-1");
        return;
    }
    let mut v = vec![];
    for i in 0..n {
        if i == u.root(i) {
            v.push(i);
        }
    }
    let n = v.len();
    let s = v.binary_search(&u.root(s)).unwrap();
    let t = v.binary_search(&u.root(t)).unwrap();
    let e: Vec<_> = e
        .into_iter()
        .filter(|&(a, b, _, _)| !u.same(a, b))
        .map(|(a, b, c, k)| {
            let a = v.binary_search(&u.root(a)).unwrap();
            let b = v.binary_search(&u.root(b)).unwrap();
            assert!(a != b);
            (a, b, c, k)
        })
        .collect();
    // 
    let mut ans = (std::i64::MAX, m, m);
    for (i, &(_, _, c, k)) in e.iter().enumerate() {
        let mut g = vec![vec![]; n];
        for (_, &(a, b, c, k)) in e.iter().enumerate().filter(|p| p.0 != i) {
            g[a].push((b, c, k));
            g[b].push((a, c, k));
        }
        let mut ord = vec![n; n];
        let mut low = vec![n; n];
        let mut id = 0;
        let mut parent = vec![(s, 0, 0); n];
        dfs(s, m, &g, &mut ord, &mut low, &mut id, &mut parent);
        if ord[t] == n {
            ans.chmin((c, k, m));
            continue;
        }
        let mut pos = t;
        while pos != s {
            let (p, d, x) = parent[pos];
            if ord[p] < low[pos] {
                ans.chmin((c + d, k, x));
            }
            pos = p;
        }
    }
    if ans.2 < m {
        println!("{}\n2\n{} {}", ans.0, ans.1 + 1, ans.2 + 1);
    } else {
        println!("{}\n1\n{}", ans.0, ans.1 + 1);
    }
}

fn main() {
    run();
}
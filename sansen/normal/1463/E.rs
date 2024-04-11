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
    where F: FnMut(usize),
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

fn cond(b: bool) {
    if !b {
        println!("0");
        std::process::exit(0);
    }
}

fn run() {
    input! {
        n: usize,
        k: usize,
        p: [usize; n],
        e: [(usize, usize); k],
    }
    let mut dsu = DSU::new(n + 1);
    let mut edge = vec![vec![]; n + 1];
    for &(x, y) in e.iter() {
        if let Some((a, b)) = dsu.unite(x, y) {
            let mut p = std::mem::take(&mut edge[b]);
            edge[a].append(&mut p);
            edge[a].push((x, y));
        } else {
            cond(false);
        }
    }
    let mut ord = vec![vec![]; n + 1];
    for i in 1..=n {
        if i != dsu.root(i) {
            continue;
        }
        let edge = &mut edge[i];
        if edge.is_empty() {
            ord[i].push(i);
            continue;
        }
        edge.sort();
        let mut to = std::collections::BTreeSet::new();
        for &(_, t) in edge.iter() {
            to.insert(t);
        }
        let mut s = 0;
        for &(a, _) in edge.iter() {
            if !to.contains(&a) {
                s = a;
                break;
            }
        }
        let mut v = vec![s];
        let mut p = s;
        loop {
            let x = edge.binary_search(&(p, 0)).unwrap_err();
            if edge.get(x).map_or(true, |e| e.0 != p) {
                break;
            }
            p = edge[x].1;
            v.push(p);
        }
        ord[i] = v;
    }
    let root = p.iter().position(|p| *p == 0).unwrap() + 1;
    cond(ord[dsu.root(root)][0] == root);
    let mut g = vec![vec![]; n + 1];
    let mut deg = vec![0; n + 1];
    for (i, &p) in p.iter().enumerate() {
        if p == 0 {
            continue;
        }
        let p = dsu.root(p);
        let i = dsu.root(i + 1);
        if p != i {
            g[p].push(i);
            deg[i] += 1;
        }
    }
    let mut topo = vec![dsu.root(root)];
    for i in 0.. {
        if i >= topo.len() {
            break;
        }
        let v = topo[i];
        for &u in g[v].iter() {
            deg[u] -= 1;
            if deg[u] == 0 {
                topo.push(u);
            }
        }
    }
    let mut ans = vec![];
    for v in topo {
        ans.append(&mut ord[v]);
    }
    cond(ans.len() == n);
    let mut index = vec![0; n + 1];
    for (i, a) in ans.iter().enumerate() {
        index[*a] = i;
    }
    for (i, &p) in p.iter().enumerate() {
        if p != 0 {
            cond(index[p] < index[i + 1]);
        }
    }
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
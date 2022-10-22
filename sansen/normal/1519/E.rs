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
// ---------- begin binary_gcd ----------
pub fn binary_gcd(a: u64, b: u64) -> u64 {
    if a == 0 || b == 0 {
        return a + b;
    }
    let x = a.trailing_zeros();
    let y = b.trailing_zeros();
    let mut a = a >> x;
    let mut b = b >> y;
    while a != b {
        let x = (a ^ b).trailing_zeros();
        if a < b {
            std::mem::swap(&mut a, &mut b);
        }
        a = (a - b) >> x;
    }
    a << x.min(y)
}
// ---------- end binary_gcd ----------
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

fn dfs(
    v: usize,
    p: usize,
    state: &mut [usize],
    used: &mut [bool],
    elem: &mut [bool],
    ans: &mut Vec<(usize, usize)>,
    g: &[Vec<(usize, usize)>],
    edge: &[(usize, usize)]
) {
    elem[v] = true;
    for &(u, i) in g[v].iter() {
        if used[i] {
            continue;
        }
        used[i] = true;
        if elem[u] {
            state[i] = v;
        } else {
            dfs(u, i, state, used, elem, ans, g, edge);
        }
    }
    let mut come = vec![];
    for &(_, i) in g[v].iter() {
        if state[i] == v {
            come.push(i);
        }
    }
    while come.len() > 1 {
        let a = come.pop().unwrap();
        let b = come.pop().unwrap();
        ans.push((a, b));
    }
    if come.len() > 0 && p != used.len() {
        let a = come.pop().unwrap();
        state[p] = v;
        ans.push((a, p));
    } else if p != used.len() {
        let e = edge[p];
        state[p] = e.0 ^ e.1 ^ v;
    }
}

fn run() {
    input! {
        n: usize,
        p: [(u64, u64, u64, u64); n],
    }
    let mut id = 0;
    let mut map = std::collections::BTreeMap::new();
    let mut get_id = |x: u64, y: u64| -> usize {
        *map.entry((x, y)).or_insert_with(|| {
            let v = id;
            id += 1;
            v
        })
    };
    let mut edge = vec![];
    for &(a, b, c, d) in p.iter() {
        let l = {
            let (x, y) = ((a + b) * d, c * b);
            let g = binary_gcd(x, y);
            get_id(x / g, y / g)
        };
        let r = {
            let (x, y) = (a * d, (c + d) * b);
            let g = binary_gcd(x, y);
            get_id(x / g, y / g)
        };
        edge.push((l, r));
    }
    let mut dsu = DSU::new(id);
    let mut g = vec![vec![]; id];
    for (k, &(a, b)) in edge.iter().enumerate() {
        g[a].push((b, k));
        g[b].push((a, k));
        dsu.unite(a, b);
    }
    let mut state = vec![id; n + 1];
    let mut used = vec![false; n];
    let mut elem = vec![false; id];
    let mut ans = vec![];
    for i in 0..id {
        if i == dsu.root(i) {
            dfs(i, n, &mut state, &mut used, &mut elem, &mut ans, &g, &edge);
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", ans.len()).ok();
    for (a, b) in ans {
        writeln!(out, "{} {}", a + 1, b + 1).ok();
    }
}

fn main() {
    run();
}
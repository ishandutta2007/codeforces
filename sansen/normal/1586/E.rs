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

// nq <= 3*10^5
// ...
// 
// 2
// 
// 
// 
//

use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
        q: usize,
        ask: [(usize1, usize1); q],
    }
    let mut g = vec![vec![]; n];
    let mut dsu = DSU::new(n);
    for &(a, b) in e.iter() {
        if dsu.unite(a, b).is_some() {
            g[a].push(b);
            g[b].push(a);
        }
    }
    let mut state = vec![0; n];
    let mut ans = vec![];
    for &(a, b) in ask.iter() {
        state[a] ^= 1;
        state[b] ^= 1;
        let mut topo = vec![(b, b, 0)];
        for i in 0..n {
            let (v, p, _) = topo[i];
            for &u in g[v].iter() {
                if u != p {
                    topo.push((u, v, i));
                }
            }
        }
        let mut pos = topo.iter().position(|p| p.0 == a).unwrap();
        let mut v = vec![a];
        while topo[pos].0 != b {
            pos = topo[pos].2;
            v.push(topo[pos].0);
        }
        ans.push(v);
    }
    let sum = state.iter().sum::<usize>();
    if sum == 0 {
        let out = std::io::stdout();
        let mut out = std::io::BufWriter::new(out.lock());
        writeln!(out, "YES").ok();
        for ans in ans {
            writeln!(out, "{}", ans.len()).ok();
            let s = ans.iter().map(|a| (*a + 1).to_string()).collect::<Vec<_>>().join(" ");
            writeln!(out, "{}", s).ok();
        }
    } else {
        println!("NO");
        println!("{}", sum / 2);
    }
}

fn main() {
    run();
}
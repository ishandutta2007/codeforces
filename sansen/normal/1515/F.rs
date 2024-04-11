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

use std::io::Write;

// 
// 
//  sum a >= (dsu.size(u) - 1) * d && sum a >= (dsu.size(v) - 1) * d
// 
// a -= d -d 
// a >= -d  0
// 0
//
// 
//

fn run() {
    input! {
        n: usize,
        m: usize,
        d: i64,
        a: [i64; n],
        e: [(usize1, usize1); m],
    }
    let mut a = a;
    a.iter_mut().for_each(|a| *a -= d);
    if a.iter().sum::<i64>() < -d {
        println!("NO");
        return;
    }
    let mut dsu = DSU::new(n);
    let mut g = vec![vec![]; n];
    for (i, &(a, b)) in e.iter().enumerate() {
        if dsu.unite(a, b).is_some() {
            g[a].push((a, b, i));
            g[b].push((b, a, i));
        }
    }
    dsu.init();
    let mut dp = a.clone();
    let mut h = std::collections::BinaryHeap::new();
    for i in 0..n {
        h.push((dp[i], i));
    }
    let ban = std::i64::MIN / 10;
    let mut ans = vec![];
    while let Some((x, r)) = h.pop() {
        if r != dsu.root(r) || x != dp[r] {
            continue;
        }
        if dsu.size(r) == n || dp[r] <= 0 {
            break;
        }
        let mut p = std::mem::take(&mut g[dsu.root(r)]);
        while let Some((a, b, k)) = p.pop() {
            if dsu.same(a, b) {
                continue;
            }
            let (a, b) = dsu.unite(a, b).unwrap();
            assert!(dp[a] + dp[b] >= -d);
            dp[a] += dp[b];
            dp[b] = ban;
            ans.push(k + 1);
            for &b in [a, b].iter() {
                if p.len() < g[b].len() {
                    std::mem::swap(&mut p, &mut g[b]);
                }
                for q in g[b].drain(..) {
                    p.push(q);
                }
            }
            break;
        }
        let r = dsu.root(r);
        g[r] = p;
        h.push((dp[r], r));
    }
    for (i, &(a, b)) in e.iter().enumerate() {
        if dsu.unite(a, b).is_some() {
            ans.push(i + 1);
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "YES").ok();
    for k in ans {
        writeln!(out, "{}", k).ok();
    }
}

fn main() {
    run();
}
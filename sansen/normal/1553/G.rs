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

// renketu 0
// 222
// 1
// 
//

fn run() {
    input! {
        n: usize,
        q: usize,
        a: [usize; n],
        ask: [(usize1, usize1); q],
    }
    let m = 1000001;
    let mut f = (0..=m).collect::<Vec<_>>();
    for i in 2..=m {
        if i == f[i] {
            for j in 1..=(m / i) {
                f[j * i] = i;
            }
        }
    }
    let f = f;
    let mut zero = DSU::new(m + 1 + n + 100);
    for (i, a) in a.iter().enumerate() {
        let mut x = *a;
        while x > 1 {
            let p = f[x];
            zero.unite(i, n + p);
            while x % p == 0 {
                x /= p;
            }
        }
    }
    let mut edge = vec![];
    for (i, &a) in a.iter().enumerate() {
        let mut v = vec![zero.root(i)];
        let mut x = a + 1;
        while x > 1 {
            let p = f[x];
            v.push(zero.root(n + p));
            while x % p == 0 {
                x /= p;
            }
        }
        v.sort();
        v.dedup();
        for (i, a) in v.iter().enumerate() {
            for b in v.iter().take(i) {
                edge.push((*b, *a));
            }
        }
    }
    edge.sort();
    edge.dedup();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (a, b) in ask {
        let mut a = zero.root(a);
        let mut b = zero.root(b);
        if a > b {
            std::mem::swap(&mut a, &mut b);
        }
        let ans = if zero.same(a, b) {
            0
        } else if edge.binary_search(&(a, b)).is_ok() {
            1
        } else {
            2
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
// ---------- begin quick find ----------
pub struct QuickFind {
    size: usize,
    id: Vec<usize>,
    list: Vec<Vec<usize>>,
}

impl QuickFind {
    pub fn new(size: usize) -> Self {
        let id = (0..size).collect::<Vec<_>>();
        let list = (0..size).map(|x| vec![x]).collect::<Vec<_>>();
        QuickFind { size, id, list }
    }
    pub fn root(&self, x: usize) -> usize {
        assert!(x < self.size);
        self.id[x]
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.size);
        assert!(y < self.size);
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.size);
        assert!(y < self.size);
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            return None;
        }
        if (self.list[x].len(), x) < (self.list[y].len(), y) {
            std::mem::swap(&mut x, &mut y);
        }
        let mut z = std::mem::take(&mut self.list[y]);
        z.iter().for_each(|y| self.id[*y] = x);
        self.list[x].append(&mut z);
        Some((x, y))
    }
    pub fn enumerate(&self, x: usize) -> &[usize] {
        assert!(x < self.size);
        &self.list[self.root(x)]
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.size);
        self.enumerate(x).len()
    }
}
// ---------- end quick find ----------
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

type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        a: usize,
        b: usize,
        ea: [(usize1, usize1); a],
        eb: [(usize1, usize1); b],
    }
    let mut x = QuickFind::new(n);
    let mut y = QuickFind::new(n);
    for (a, b) in ea {
        x.unite(a, b);
    }
    for (a, b) in eb {
        y.unite(a, b);
    }
    let mut ans = vec![];
    let mut q = (0..n).collect::<Deque<_>>();
    while let Some(v) = q.pop_front() {
        if ans.len() + a.max(b) + 1 == n {
            break;
        }
        let mut dfs = vec![v];
        while let Some(v) = dfs.pop() {
            if ans.len() + a.max(b) + 1 == n {
                break;
            }
            let len = q.len();
            for _ in 0..len {
                let (a, b) = (x.root(v), y.root(v));
                let u = q.pop_front().unwrap();
                let (c, d) = (x.root(u), y.root(u));
                if (a, b) == (c, d) {
                } else if a != c && b != d {
                    x.unite(v, u);
                    y.unite(v, u);
                    ans.push((v + 1, u + 1));
                } else if a == c {
                    dfs.push(u);
                } else {
                    q.push_back(u);
                }
            }
        }
    }
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", ans.len()).ok();
    for (a, b) in ans {
        writeln!(out, "{} {}", a, b).ok();
    }
}

fn main() {
    run();
}
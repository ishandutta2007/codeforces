//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    pub struct UF {
        parent: Vec<usize>,
        size: Vec<usize>,
        stack: Vec<Option<(usize, usize)>>,
    }
    impl UF {
        pub fn new(size: usize) -> UF {
            let mut u = UF {
                parent: vec![0; size],
                size: vec![1; size],
                stack: vec![],
            };
            u.init();
            u
        }
        pub fn init(&mut self) {
            for (i, p) in self.parent.iter_mut().enumerate() {
                *p = i;
            }
            self.size.clear();
            self.size.resize(self.parent.len(), 1);
            self.stack.clear();
        }
        pub fn root(&self, mut x: usize) -> usize {
            while self.parent[x] != x {
                x = self.parent[x];
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
                self.stack.push(None);
                return None;
            }
            if self.size[x] < self.size[y] {
                std::mem::swap(&mut x, &mut y);
            }
            self.size[x] += self.size[y];
            self.parent[y] = x;
            self.stack.push(Some((x, y)));
            Some((x, y))
        }
        pub fn undo(&mut self) -> Option<(usize, usize)> {
            self.stack
                .pop()
                .expect("union find undo error: stack is empty")
                .map(|(x, y)| {
                    self.size[x] -= self.size[y];
                    self.parent[y] = y;
                    (x, y)
                })
        }
        pub fn get_size(&self, x: usize) -> usize {
            let r = self.root(x);
            self.size[r]
        }
        pub fn parent(&self, x: usize) -> Option<usize> {
            let p = self.parent[x];
            if p == x {
                None
            } else {
                Some(p)
            }
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

use std::io::Write;

fn run() {
    input! {
        n: usize,
        q: usize,
        ask: [(usize1, usize1); q],
    }
    let mut edge = vec![];
    let mut map = std::collections::BTreeMap::new();
    for (i, (a, b)) in ask.into_iter().enumerate() {
        if let Some(&k) = map.get(&(a, b)) {
            edge.push((a, b, k, i));
            map.remove(&(a, b));
        } else {
            map.insert((a, b), i);
        }
    }
    for ((a, b), k) in map {
        edge.push((a, b, k, q));
    }
    let mut ans = vec![true; q];
    let mut u = union_find::UF::new(2 * n);
    let mut dfs = vec![(0, q, true, edge)];
    while let Some((l, r, mut v, e)) = dfs.pop() {
        if l == q {
            for _ in 0..r {
                u.undo();
            }
            continue;
        }
        let mut left = vec![];
        let mut right = vec![];
        let mut cnt = 0;
        let mid = (l + r) / 2;
        for (a, b, s, t) in e {
            if s <= l && r <= t {
                u.unite(a, b + n);
                u.unite(b, a + n);
                v &= !u.same(a, b);
                cnt += 2;
                continue;
            }
            if s < mid {
                left.push((a, b, s, t));
            }
            if mid < t {
                right.push((a, b, s, t));
            }
        }
        dfs.push((q, cnt, false, vec![]));
        if l + 1 == r {
            ans[l] = v;
        } else {
            dfs.push((l, mid, v, left));
            dfs.push((mid, r, v, right));
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        let s = if a {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", s).ok();
    }
}

fn main() {
    run();
}
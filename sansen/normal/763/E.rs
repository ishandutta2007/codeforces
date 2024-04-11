//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    use std;
    pub struct UF {
        parent: Vec<usize>,
        size: Vec<usize>,
        stack: Vec<Option<(usize, usize)>>,
    }
    impl UF {
        pub fn new(n: usize) -> UF {
            let mut u = UF {
                parent: vec![0; n],
                size: vec![1; n],
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
        pub fn root(&mut self, mut x: usize) -> usize {
            while self.parent[x] != x {
                x = self.parent[x];
            }
            x
        }
        pub fn same(&mut self, x: usize, y: usize) -> bool {
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
        pub fn get_size(&mut self, x: usize) -> usize {
            let r = self.root(x);
            self.size[r]
        }
        pub fn parent(&self, x: usize) -> Option<usize> {
            if self.parent[x] == x {
                None
            } else {
                Some(self.parent[x])
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
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        k: usize,
        m: usize,
        e: [(usize1, usize1); m],
        q: usize,
        ask: [(usize1, usize); q],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let batch = 300;
    let mut ans = vec![0; q];
    let mut query = vec![vec![]; n / batch + 1];
    let mut u = union_find::UF::new(n);
    for (i, (l, r)) in ask.into_iter().enumerate() {
        if r - l <= 2 * batch {
            let mut op = 0;
            let mut cnt = 0;
            for i in (l + 1)..r {
                for &b in g[i].iter() {
                    if l <= b && b < i {
                        op += 1;
                        if u.unite(i, b).is_some() {
                            cnt += 1;
                        }
                    }
                }
            }
            ans[i] = r - l - cnt;
            for _ in 0..op {
                u.undo();
            }
        } else {
            query[l / batch].push((r, l, i));
        }
    }
    for (i, query) in query.iter_mut().enumerate() {
        query.sort();
        let mut u = union_find::UF::new(n);
        let mut cnt = 0;
        let mut p = (i + 1) * batch;
        for &(r, l, index) in query.iter() {
            while p < r {
                for &b in g[p].iter() {
                    if (i + 1) * batch <= b && b < p && u.unite(b, p).is_some() {
                        cnt += 1;
                    }
                }
                p += 1;
            }
            let snap = cnt;
            let mut op = 0;
            for k in (l..((i + 1) * batch)).rev() {
                for &b in g[k].iter() {
                    if b > k && b < r {
                        op += 1;
                        if u.unite(k, b).is_some() {
                            cnt += 1;
                        }
                    }
                }
            }
            ans[index] = r - l - cnt;
            cnt = snap;
            for _ in 0..op {
                u.undo();
            }
        }
    }
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
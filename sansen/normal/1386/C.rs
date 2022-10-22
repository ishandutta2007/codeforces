// ---------- begin queue-like undoing ds ----------
// reference: https://codeforces.com/blog/entry/83467?#comment-711760
pub trait UndoDS {
    type Arg;
    fn update(&mut self, arg: Self::Arg);
    fn undo(&mut self) -> Self::Arg;
}

pub struct QueueLikeUndoDS<DS> {
    data: DS,
    memo: Vec<u8>,
    rem: usize,
}

impl<DS> QueueLikeUndoDS<DS>
where
    DS: UndoDS,
{
    pub fn new(data: DS) -> Self {
        Self {
            data: data,
            memo: vec![],
            rem: 0,
        }
    }
    pub fn enqueue(&mut self, arg: DS::Arg) {
        self.data.update(arg);
        self.memo.push(0);
    }
    pub fn dequeue(&mut self) {
        assert!(!self.memo.is_empty());
        let mut args = vec![];
        if self.rem == 0 {
            for _ in self.memo.drain(..) {
                args.push((self.data.undo(), 1));
            }
            self.rem = args.len();
            args.reverse();
        } else {
            while *self.memo.last().unwrap() == 0 {
                args.push((self.data.undo(), self.memo.pop().unwrap()));
            }
            let c = self.rem & (!self.rem + 1);
            for _ in 0..c {
                let p = self.memo.pop().unwrap();
                assert!(p == 1);
                args.push((self.data.undo(), p));
            }
            args.rotate_right(c);
        }
        for (arg, p) in args.drain(..).rev() {
            self.data.update(arg);
            self.memo.push(p);
        }
        self.data.undo();
        self.memo.pop();
        self.rem -= 1;
    }
}

impl<DS: UndoDS> std::ops::Deref for QueueLikeUndoDS<DS> {
    type Target = DS;
    fn deref(&self) -> &Self::Target {
        &self.data
    }
}
// ---------- end queue-like undoing ds ----------
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

struct DSU {
    n: usize,
    parent: Vec<usize>,
    size: Vec<usize>,
    stack: Vec<(usize, usize, Option<(usize, usize)>, Option<(usize, usize)>)>,
    cnt: usize,
}

impl DSU {
    pub fn new(size: usize) -> Self {
        Self {
            n: size,
            parent: (0..(2 * size)).collect::<Vec<_>>(),
            size: vec![1; 2 * size],
            stack: vec![],
            cnt: 0,
        }
    }
    pub fn root(&self, mut x: usize) -> usize {
        while self.parent[x] != x {
            x = self.parent[x];
        }
        x
    }
    pub fn unite(&mut self, mut a: usize, mut b: usize) -> Option<(usize, usize)> {
        a = self.root(a);
        b = self.root(b);
        if a == b {
            return None;
        }
        if self.size[a] < self.size[b] {
            std::mem::swap(&mut a, &mut b);
        }
        self.size[a] += self.size[b];
        self.parent[b] = a;
        Some((a, b))
    }
    pub fn is_bipartite(&self) -> bool {
        self.cnt == 0
    }
}

impl UndoDS for DSU {
    type Arg = (usize, usize);
    fn update(&mut self, (a, b): Self::Arg) {
        let x = self.unite(a, self.n + b);
        let y = self.unite(b, self.n + a);
        self.stack.push((a, b, x, y));
        self.cnt += (self.root(a) == self.root(a + self.n)) as usize;
    }
    fn undo(&mut self) -> Self::Arg {
        let (a, b, x, y) = self.stack.pop().unwrap();
        self.cnt -= (self.root(a) == self.root(a + self.n)) as usize;
        for p in [y, x].iter() {
            if let Some((a, b)) = *p {
                self.size[a] -= self.size[b];
                self.parent[b] = b;
            }
        }
        (a, b)
    }
}

use std::io::Write;

fn run() {
    input! {
        n: usize,
        m: usize,
        q: usize,
        e: [(usize1, usize1); m],
        ask: [(usize1, usize); q],
    }
    let dsu = DSU::new(n);
    let mut q = QueueLikeUndoDS::new(dsu);
    for &(a, b) in e.iter() {
        q.enqueue((a, b));
    }
    let mut ans = vec![0; m];
    let mut po = 0;
    for (i, ans) in ans.iter_mut().enumerate() {
        while po < m && !q.is_bipartite() {
            q.dequeue();
            po += 1;
        }
        if !q.is_bipartite() {
            po = m + 1;
        }
        *ans = po;
        let (a, b) = e[i];
        q.enqueue((a, b));
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r) in ask {
        let mut res = "NO";
        if ans[l] > r {
            res = "YES";
        }
        writeln!(out, "{}", res).ok();
    }
}

fn main() {
    run();
}
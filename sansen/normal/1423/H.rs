// 

// ---------- begin queue-like undoing ds ----------
// reference: https://codeforces.com/blog/entry/83467?#comment-711760
pub trait UndoDS {
    type Arg;
    fn update(&mut self, arg: Self::Arg);
    fn undo(&mut self);
}

pub struct QueueLikeUndoDS<DS: UndoDS> {
    data: DS,
    memo: Vec<(DS::Arg, u8)>,
    rem: usize,
}

impl<DS> QueueLikeUndoDS<DS>
where
    DS: UndoDS,
    DS::Arg: Clone,
{
    pub fn new(data: DS) -> Self {
        Self {
            data: data,
            memo: vec![],
            rem: 0,
        }
    }
    pub fn enqueue(&mut self, arg: DS::Arg) {
        self.data.update(arg.clone());
        self.memo.push((arg, 0));
    }
    pub fn dequeue(&mut self) {
        assert!(!self.memo.is_empty());
        let mut args = vec![];
        if self.rem == 0 {
            for (a, _) in self.memo.drain(..) {
                self.data.undo();
                args.push((a, 1));
            }
            self.rem = args.len();
        } else {
            while self.memo.last().unwrap().1 == 0 {
                self.data.undo();
                args.push(self.memo.pop().unwrap());
            }
            let c = self.rem & (!self.rem + 1);
            for _ in 0..c {
                let p = self.memo.pop().unwrap();
                assert!(p .1== 1);
                self.data.undo();
                args.push(p);
            }
            args.rotate_right(c);
        }
        for (arg, p) in args.drain(..).rev() {
            self.data.update(arg.clone());
            self.memo.push((arg, p));
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
// undo uniteRE
// snap unite 
//---------- begin union_find ----------
pub struct DSU {
    parent: Vec<u32>,
    size: Vec<u32>,
    stack: Vec<Option<(u32, u32)>>,
}

impl DSU {
    pub fn new(n: usize) -> DSU {
        assert!(n < std::u32::MAX as usize);
        let mut res = DSU {
            parent: vec![0; n],
            size: vec![1; n],
            stack: vec![],
        };
        res.init();
        res
    }
    pub fn init(&mut self) {
        self.stack.clear();
        for (i, (parent, size)) in self.parent.iter_mut().zip(self.size.iter_mut()).enumerate() {
            *parent = i as u32;
            *size = 1;
        }
    }
    pub fn root(&self, mut x: usize) -> usize {
        assert!(x < self.parent.len());
        while self.parent[x] != x as u32 {
            x = self.parent[x] as usize;
        }
        x
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            self.stack.push(None);
            return None;
        }
        if (self.size[x], x) < (self.size[y], y) {
            std::mem::swap(&mut x, &mut y);
        }
        self.size[x] += self.size[y];
        self.parent[y] = x as u32;
        self.stack.push(Some((x as u32, y as u32)));
        Some((x, y))
    }
    pub fn parent(&self, x: usize) -> Option<usize> {
        assert!(x < self.parent.len());
        let p = self.parent[x];
        if p != x as u32 {
            Some(p as usize)
        } else {
            None
        }
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.parent.len());
        let r = self.root(x);
        self.size[r] as usize
    }
    pub fn undo(&mut self) -> Option<(usize, usize)> {
        self.stack.pop().unwrap().map(|(x, y)| {
            let x = x as usize;
            let y = y as usize;
            self.size[x] -= self.size[y];
            self.parent[y] = y as u32;
            (x, y)
        })
    }
    pub fn snap(&mut self) {
        self.stack.clear();
    }
    pub fn rollback(&mut self) {
        while !self.stack.is_empty() {
            self.undo();
        }
    }
}
//---------- end union_find ----------

impl UndoDS for DSU {
    type Arg = (usize, usize);
    fn update(&mut self, (a, b): Self::Arg) {
        self.unite(a, b);
    }
    fn undo(&mut self) {
        self.undo();
    }
}

enum Query {
    ADD(usize, usize),
    QUERY(usize),
    NEXT,
}

fn read() -> (usize, usize, Vec<Query>) {
    let mut s = String::new();
    use std::io::Read;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace().flat_map(|s| s.parse::<usize>());
    let mut next = || it.next().unwrap();
    let n = next();
    let q = next();
    let k = next();
    let mut query = Vec::with_capacity(q);
    for _ in 0..q {
        let op = next();
        let v = if op == 1 {
            let a = next() - 1;
            let b = next() - 1;
            Query::ADD(a, b)
        } else if op == 2 {
            let a = next() - 1;
            Query::QUERY(a)
        } else {
            Query::NEXT
        };
        query.push(v);
    }
    (n, k, query)
}

fn run() {
    let (n, k, ask) = read();
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut q = QueueLikeUndoDS::new(DSU::new(n));
    let mut cnt = vec![0; ask.len()];
    let mut now = 0;
    for ask in ask {
        match ask {
            Query::ADD(a, b) => {
                q.enqueue((a, b));
                cnt[now] += 1;
            },
            Query::QUERY(z) => {
                writeln!(out, "{}", q.size(z)).ok();
            },
            Query::NEXT => {
                now += 1;
                if now >= k {
                    for _ in 0..cnt[now - k] {
                        q.dequeue();
                    }
                }
            },
        }
    }
}

fn main() {
    run();
}
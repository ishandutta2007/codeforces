fn run() {
    input! {
        n: usize,
        k: usize,
        b: [u64; n],
    }
    let mut seg = SegmentTree::new(vec![Node::new(0, 1); n]);
    let mut ans = 0;
    for (i, b) in b.iter().enumerate().rev() {
        let mut v = 0;
        seg.query(i, i + 1, |node| v += node.sum);
        if v < *b {
            let l = i.saturating_sub(k - 1);
            let m = (i + 1 - l) as u64;
            let need = (*b - v + m - 1) / m;
            ans += need;
            let mut add = 0;
            seg.update(l, l + k, |node| {
                node.apply(add * need, need);
                add += node.len;
            });
        }
    }
    println!("{}", ans);
}

#[derive(Clone)]
pub struct Node {
    sum: u64,
    add: u64,
    tri: u64,
    len: u64,
}

impl Node {
    fn new(val: u64, len: u64) -> Node {
        Node {
            sum: val,
            add: 0,
            tri: 0,
            len: len,
        }
    }
    fn apply(&mut self, add: u64, tri: u64) {
        self.sum += add * self.len + tri * self.len * (self.len + 1) / 2;
        self.add += add;
        self.tri += tri;
    }
}

impl DFSTest for Node {
    fn merge(&mut self, lhs: &Self, rhs: &Self) {
        self.sum = lhs.sum + rhs.sum;
        self.len = lhs.len + rhs.len;
    }
    fn propagate(&mut self, c: &mut [Self]) {
        let mut add = std::mem::take(&mut self.add);
        let tri = std::mem::take(&mut self.tri);
        for c in c.iter_mut() {
            c.apply(add, tri);
            add += tri * c.len;
        }
    }
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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

pub trait DFSTest: Clone {
    fn merge(&mut self, lhs: &Self, rhs: &Self);
    fn propagate(&mut self, c: &mut [Self]);
}

pub struct SegmentTree<T> {
    data: Vec<T>,
    n: usize,
    size: usize,
    stack: Vec<(usize, usize, usize)>,
}

impl<T> SegmentTree<T>
where
    T: DFSTest,
{
    pub fn new(ini: Vec<T>) -> Self {
        assert!(!ini.is_empty());
        let n = ini.len();
        let size = n.next_power_of_two();
        let mut data = vec![ini[0].clone(); 2 * size];
        for (data, ini) in data[size..].iter_mut().zip(ini) {
            *data = ini;
        }
        for i in (1..size).rev() {
            let (f, t) = data.split_at_mut(2 * i);
            f[i].merge(&t[0], &t[1]);
        }
        SegmentTree {
            data,
            n,
            size,
            stack: vec![],
        }
    }
    pub fn update_bool<F>(&mut self, l: usize, r: usize, mut f: F)
    where
        F: FnMut(&mut T) -> bool,
    {
        assert!(l < r && r <= self.n);
        self.stack.clear();
        self.stack.push((1, 0, self.size));
        while let Some((v, x, y)) = self.stack.pop() {
            if v >= 2 * self.size {
                if y <= self.n {
                    let v = !v;
                    let (f, t) = self.data.split_at_mut(2 * v);
                    f[v].merge(&t[0], &t[1]);
                }
                continue;
            }
            if l <= x && y <= r && f(&mut self.data[v]) {
                continue;
            }
            assert!(v < self.size);
            if y <= self.n {
                let (f, t) = self.data.split_at_mut(2 * v);
                f[v].propagate(&mut t[..2]);
            }
            let mid = (x + y) / 2;
            self.stack.push((!v, x, y));
            if mid < r {
                self.stack.push((2 * v + 1, mid, y));
            }
            if l < mid {
                self.stack.push((2 * v, x, mid));
            }
        }
    }
    pub fn update<F>(&mut self, l: usize, r: usize, mut f: F)
    where
        F: FnMut(&mut T),
    {
        self.update_bool(l, r, |node| {
            f(node);
            true
        });
    }
    fn query_bool<F>(&mut self, l: usize, r: usize, mut f: F)
    where
        F: FnMut(&mut T) -> bool,
    {
        assert!(l < r && r <= self.n);
        self.stack.clear();
        self.stack.push((1, 0, self.size));
        while let Some((v, x, y)) = self.stack.pop() {
            if v >= 2 * self.size {
                if y <= self.n {
                    let v = !v;
                    let (f, t) = self.data.split_at_mut(2 * v);
                    f[v].merge(&t[0], &t[1]);
                }
                continue;
            }
            if l <= x && y <= r && f(&mut self.data[v]) {
                continue;
            }
            assert!(v < self.size);
            if y <= self.n {
                let (f, t) = self.data.split_at_mut(2 * v);
                f[v].propagate(&mut t[..2]);
            }
            let mid = (x + y) / 2;
            self.stack.push((!v, x, y));
            if mid < r {
                self.stack.push((2 * v + 1, mid, y));
            }
            if l < mid {
                self.stack.push((2 * v, x, mid));
            }
        }
    }
    pub fn query<F>(&mut self, l: usize, r: usize, mut f: F)
    where
        F: FnMut(&mut T),
    {
        self.query_bool(l, r, |node| {
            f(node);
            true
        });
    }
}
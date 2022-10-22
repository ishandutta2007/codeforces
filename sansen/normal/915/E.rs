pub trait DFSTest: Clone {
    fn merge(&mut self, l: &Self, r: &Self);
    fn propagate(&mut self, c: &mut [Self]);
}

struct SegmentTree<T> {
    data: Vec<T>,
    size: usize,
    stack: Vec<(usize, usize, usize)>,
}

impl<T> SegmentTree<T>
where
    T: DFSTest,
{
    fn new(ini: Vec<T>) -> Self {
        let size = ini.len().next_power_of_two();
        let mut data = vec![ini[0].clone(); 2 * size];
        for (data, ini) in data[size..].iter_mut().zip(ini) {
            *data = ini;
        }
        for i in (1..size).rev() {
            let (f, t) = data.split_at_mut(2 * i);
            f[i].merge(&t[0], &t[1]);
        }
        Self {
            data,
            size,
            stack: vec![],
        }
    }
    fn update_bool<F>(&mut self, l: usize, r: usize, mut f: F)
    where
        F: FnMut(&mut T) -> bool,
    {
        self.stack.clear();
        self.stack.push((1, 0, self.size));
        while let Some((v, x, y)) = self.stack.pop() {
            if v >= 2 * self.size {
                let v = !v;
                let (f, t) = self.data.split_at_mut(2 * v);
                f[v].merge(&t[0], &t[1]);
                continue;
            }
            if l <= x && y <= r && f(&mut self.data[v]) {
                continue;
            }
            assert!(v < self.size);
            {
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
    fn update<F>(&mut self, l: usize, r: usize, mut f: F)
    where
        F: FnMut(&mut T)
    {
        self.update_bool(l, r, |node| {
            f(node);
            true
        });
    }
    fn query<F>(&mut self, l: usize, r: usize, mut f: F)
    where
        F: FnMut(&T),
    {
        self.stack.clear();
        self.stack.push((1, 0, self.size));
        while let Some((v, x, y)) = self.stack.pop() {
            if l <= x && y <= r {
                f(&self.data[v]);
                continue;
            }
            assert!(v < self.size);
            {
                let (f, t) = self.data.split_at_mut(2 * v);
                f[v].propagate(&mut t[..2]);
            }
            let mid = (x + y) / 2;
            if mid < r {
                self.stack.push((2 * v + 1, mid, y));
            }
            if l < mid {
                self.stack.push((2 * v, x, mid));
            }
        }
    }
}

#[derive(Clone)]
struct Node {
    sum: usize,
    len: usize,
}

impl Node {
    fn fill(&mut self, v: usize) {
        self.sum = v * self.len;
    }
}

impl DFSTest for Node {
    fn merge(&mut self, l: &Self, r: &Self) {
        self.sum = l.sum + r.sum;
        self.len = l.len + r.len;
    }
    fn propagate(&mut self, c: &mut [Self]) {
        for c in c.iter_mut() {
            if self.sum == 0 {
                c.fill(0);
            }
            if self.sum == self.len {
                c.fill(1);
            }
        }
    }
}

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
        ask: [(usize1, usize, u8); q],
    }
    let mut z = vec![0, n];
    for p in ask.iter() {
        z.push(p.0);
        z.push(p.1);
    }
    z.sort();
    z.dedup();
    let ini = z.windows(2).map(|z| {
        let len = z[1] - z[0];
        Node {
            sum: len,
            len: len,
        }
    }).collect::<Vec<_>>();
    let mut seg = SegmentTree::new(ini);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r, k) in ask {
        let l = z.binary_search(&l).unwrap();
        let r = z.binary_search(&r).unwrap();
        let k = (k - 1) as usize;
        seg.update(l, r, |node| {
            node.fill(k);
        });
        let mut ans = 0;
        seg.query(0, z.len() - 1, |node| ans += node.sum);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
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
// log
// beatslog 2...

#[derive(Clone, Debug)]
struct Node {
    max: u64,
    min: u64,
    sum: u64,
    len: u64,
}

impl Node {
    fn zero() -> Self {
        Node {
            max: 0,
            min: 1000000000,
            sum: 0,
            len: 0,
        }
    }
    fn new(v: u64) -> Self {
        Node {
            max: v,
            min: v,
            sum: v,
            len: 1,
        }
    }
    fn merge(&self, rhs: &Self) -> Self {
        let max = self.max.max(rhs.max);
        let min = self.min.min(rhs.min);
        let sum = self.sum + rhs.sum;
        let len = self.len + rhs.len;
        Node {
            max, min, sum, len,
        }
    }
    fn tag(&self, v: u64) -> bool {
        self.max <= v
    }
    fn update(&mut self, v: u64) {
        self.max = v;
        self.min = v;
        self.sum = v * self.len;
    }
    fn propagate(&self, c: &mut [Node]) {
        if self.max == self.min {
            let v = self.max;
            for c in c.iter_mut() {
                c.update(v);
            }
        }
    }
}

fn update(k: usize, l: usize, r: usize, x: usize, v: u64, seg: &mut [Node]) {
    if x <= l || seg[k].min >= v {
        return;
    }
    if r <= x && seg[k].tag(v) {
        seg[k].update(v);
        return;
    }
    {
        let (a, b) = seg.split_at_mut(2 * k);
        a[k].propagate(&mut b[..2]);
    }
    let m = (l + r) / 2;
    update(2 * k, l, m, x, v, seg);
    update(2 * k + 1, m, r, x, v, seg);
    seg[k] = seg[2 * k].merge(&seg[2 * k + 1]);
}

fn calc(k: usize, l: usize, r: usize, x: usize, v: &mut u64, seg: &mut [Node]) -> u64 {
    if r <= x || seg[k].min > *v || seg[k].len == 0 {
        return 0;
    }
    if x <= l && seg[k].sum <= *v {
        *v -= seg[k].sum;
        return seg[k].len;
    }
    {
        let (a, b) = seg.split_at_mut(2 * k);
        a[k].propagate(&mut b[..2]);
    }
    let m = (l + r) / 2;
    let mut ans = 0;
    ans += calc(2 * k, l, m, x, v, seg);
    ans += calc(2 * k + 1, m, r, x, v, seg);
    ans
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        q: usize,
        a: [u64; n],
        ask: [(u8, usize, u64); q],
    }
    let size = n.next_power_of_two();
    let mut seg = vec![Node::zero(); 2 * size];
    for (seg, a) in seg[size..].iter_mut().zip(a.iter()) {
        *seg = Node::new(*a);
    }
    for i in (1..size).rev() {
        seg[i] = seg[2 * i].merge(&seg[2 * i + 1]);
    }
    for (op, x, mut y) in ask {
        if op == 1 {
            update(1, 0, size, x, y, &mut seg);
        } else {
            let ans = calc(1, 0, size, x - 1, &mut y, &mut seg);
            writeln!(out, "{}", ans).ok();
        }
    }
}

fn main() {
    run();
}
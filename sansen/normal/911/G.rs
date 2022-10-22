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

#[derive(Default, Debug)]
struct Link(Option<Box<Node>>);

#[derive(Default, Debug)]
struct Node {
    left: Link,
    right: Link,
}

impl Link {
    fn new() -> Self {
        Link(Some(Box::new(Node::default())))
    }
    fn is_empty(&self) -> bool {
        self.0.as_ref().map_or(true, |p| p.left.0.is_none() && p.right.0.is_none())
    }
    fn merge(&mut self, rhs: &mut Self, l: usize, r: usize, s: usize, t: usize) {
        if r <= s || t <= l || rhs.0.is_none() {
            return;
        }
        if s <= l && r <= t && self.0.is_none() {
            *self = std::mem::take(rhs);
            return;
        }
        if self.0.is_none() {
            *self = Self::new();
        }
        let a = self.0.as_mut().unwrap();
        let b = rhs.0.as_mut().unwrap();
        let m = (l + r) / 2;
        a.left.merge(&mut b.left, l, m, s, t);
        a.right.merge(&mut b.right, m, r, s, t);
        if rhs.is_empty() {
            *rhs = Self::default();
        }
    }
    fn insert(&mut self, l: usize, r: usize, x: usize) {
        if self.0.is_none() {
            *self = Self::new();
        }
        if l + 1 == r {
            return;
        }
        let po = self.0.as_mut().unwrap();
        let m = (l + r) / 2;
        if x < m {
            po.left.insert(l, m, x);
        } else {
            po.right.insert(m, r, x);
        }
    }
    fn fill(&self, l: usize, r: usize, val: usize, ans: &mut [usize]) {
        if self.0.is_none() {
            return;
        }
        if l + 1 == r {
            ans[l] = val;
            return;
        }
        let m = (l + r) / 2;
        let po = self.0.as_ref().unwrap();
        po.left.fill(l, m, val, ans);
        po.right.fill(m, r, val, ans);
    }
}

fn run() {
    input! {
        n: usize,
        a: [usize1; n],
        q: usize,
        ask: [(usize1, usize, usize1, usize1); q],
    }
    let mut seg = (0..100).map(|_| Link::default()).collect::<Vec<_>>();
    for (i, a) in a.iter().enumerate() {
        seg[*a].insert(0, n, i);
    }
    for (l, r, x, y) in ask {
        if x != y {
            let mut p = std::mem::take(&mut seg[x]);
            seg[y].merge(&mut p, 0, n, l, r);
            seg[x] = p;
        }
    }
    let mut ans = vec![0; n];
    for (i, seg) in seg.iter().enumerate() {
        seg.fill(0, n, i, &mut ans);
    }
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a + 1));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
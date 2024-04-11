#[allow(dead_code)]
mod persistent_segment_tree {
    use std::rc::*;
    pub trait BinaryOperation {
        type T: Clone;
        fn fold(l: Self::T, r: Self::T) -> Self::T;
        fn e() -> Self::T;
    }
    type Link<R> = Option<Rc<Node<R>>>;
    struct Node<R: BinaryOperation> {
        val: R::T,
        left: Link<R>,
        right: Link<R>,
    }
    impl<R: BinaryOperation> Node<R> {
        fn new_node(left: Link<R>, right: Link<R>) -> Link<R> {
            Some(Rc::new(Node {
                val: R::fold(Node::get_val(&left), Node::get_val(&right)),
                left: left,
                right: right,
            }))
        }
        fn get_val(node: &Link<R>) -> R::T {
            node.as_ref().map_or(R::e(), |t| t.val.clone())
        }
        fn find(node: &Link<R>, l: usize, r: usize, x: usize, y: usize) -> R::T {
            if node.is_none() || y <= l || r <= x {
                return R::e();
            }
            let node = node.as_ref().unwrap();
            if x <= l && r <= y {
                node.val.clone()
            } else {
                let m = (l + r) / 2;
                R::fold(Node::find(&node.left, l, m, x, y), Node::find(&node.right, m, r, x, y))
            }
        }
        fn update(node: &Link<R>, l: usize, r: usize, x: usize, val: R::T) -> Link<R> {
            if l + 1 == r {
                return Some(Rc::new(Node {
                    val: val,
                    left: None,
                    right: None,
                }));
            }
            let mut left = None;
            let mut right = None;
            if let Some(node) = node.as_ref() {
                left = node.left.clone();
                right = node.right.clone();
            }
            let m = (l + r) / 2;
            if x < m {
                left = Node::update(&left, l, m, x, val);
            } else {
                right = Node::update(&right, m, r, x, val);
            }
            Node::new_node(left, right)
        }
    }
    pub struct PURQ<R: BinaryOperation> {
        root: Link<R>,
        left: usize,
        right: usize,
    }
    impl<R: BinaryOperation> std::clone::Clone for PURQ<R> {
        fn clone(&self) -> Self {
            PURQ {
                root: self.root.clone(),
                left: self.left,
                right: self.right,
            }
        }
    }
    impl<R: BinaryOperation> PURQ<R> {
        pub fn new(left: usize, right: usize) -> Self {
            PURQ {
                root: None,
                left: left,
                right: right,
            }
        }
        pub fn update(&mut self, x: usize, val: R::T) {
            assert!(self.left <= x && x < self.right);
            self.root = Node::update(&self.root, self.left, self.right, x, val);
        }
        pub fn find(&self, l: usize, r: usize) -> R::T {
            assert!(self.left <= l && l < r && r <= self.right);
            Node::find(&self.root, self.left, self.right, l, r)
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

//

use std::io::Write;
use persistent_segment_tree::*;

struct RMQ;
impl BinaryOperation for RMQ {
    type T = usize;
    fn fold(l: Self::T, r: Self::T) -> Self::T {
        std::cmp::min(l, r)
    }
    fn e() -> Self::T {
        std::usize::MAX
    }
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        root: usize1,
        a: [usize; n],
        e: [(usize1, usize1); n - 1],
        query: usize,
        ask: [(usize, usize); query],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut depth = vec![0; n];
    let mut q = vec![];
    let mut stack = vec![(root, root)];
    while let Some((v, p)) = stack.pop() {
        q.push(v);
        let child = &mut g[v];
        if let Some(k) = child.iter().position(|u| *u == p) {
            child.remove(k);
        }
        for &u in child.iter() {
            depth[u] = depth[v] + 1;
            stack.push((u, v));
        }
    }
    let mut size = vec![1; n];
    for &v in q.iter().rev() {
        for &u in g[v].iter() {
            size[v] += size[u];
        }
    }
    let mut seg = vec![PURQ::<RMQ>::new(0, 2 * n + 1); n];
    for &v in q.iter().rev() {
        let mut child = g[v].clone();
        if child.is_empty() {
            seg[v].update(depth[v], a[v]);
            continue;
        }
        child.sort_by_cached_key(|u| size[*u]);
        let mut dp = seg[child.pop().unwrap()].clone();
        for &u in child.iter() {
            for d in (depth[v] + 1).. {
                let val = seg[u].find(d, d + 1);
                if val > 1_000_000_000 {
                    break;
                }
                let p = std::cmp::min(val, dp.find(d, d + 1));
                dp.update(d, p);
            }
        }
        dp.update(depth[v], a[v]);
        seg[v] = dp;
    }
    let mut last = 0;
    for (x, k) in ask {
        let x = (x + last) % n;
        let k = (k + last) % n;
        let ans = seg[x].find(depth[x], depth[x] + k + 1);
        last = ans;
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}